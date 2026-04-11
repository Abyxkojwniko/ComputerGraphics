# GeoPBR 项目面试核心知识点全览

> **项目定位**：基于“意图驱动（Intent-Driven）”的 AIGC PBR 材质生成管线。
> **核心价值**：解决 AIGC 生成纹理的“光照烘焙（Baked-in Lighting）”痛点，通过语义理解解决材质解耦中的“歧义性（Ambiguity）”。
<!--ID: 1773027655017-->


---

## 1. 整体架构 (Pipeline Architecture)

### 核心流程
项目分为三个串行阶段（Stage）：
1.  **Stage 1 (Generation)**: 几何感知的多视角 RGB 纹理生成。
2.  **Stage 2 (Decoupling)**: 物理属性解耦（De-lighting & PBR Estimation）。
3.  **Stage 3 (Optimization)**: 纹理空间修复与优化。
<!--ID: 1773027655020-->


### 🌟 易考点
* **Q: 为什么分三个阶段？能端到端吗？**
    * **A**: 目前端到端（如 MaterialMVP）需要大规模 3D PBR 数据集训练。分阶段设计允许我利用现有的强大 2D 模型（SDXL, ControlNet, CLIP）进行“降维打击”，灵活性更高，且支持“意图驱动”的干预。
* **Q: 输入输出是什么？**
    * **In**: 白模 Mesh (.obj) + 参考图 (Image) + 文本提示 (Prompt)。
    * **Out**: Albedo, Metallic, Roughness, Normal, Height 贴图（支持 Unity/Unreal 标准）。
<!--ID: 1773027655024-->


---

## 2. Stage 1: 几何感知生成 (Geometry-Aware Generation)
**代码文件**: `stage1_multiview.py`
<!--ID: 1773027655027-->


### 2.1 视点采样 (View Sampling)
* **知识点**: 使用 **斐波那契球采样 (Fibonacci Sphere Sampling)** 生成均匀分布的相机位置。
* **核心重点**: 相比随机采样或经纬度采样，斐波那契采样在球面上分布最均匀，保证模型无死角覆盖。
* **🌟 易考点**: 为什么不用固定的前后左右6个视角？（答：对于复杂拓扑的模型，6视图覆盖率不够，容易产生拉伸死角）。
<!--ID: 1773027655030-->


### 2.2 几何约束生成 (Conditional Generation)
* **知识点**:
    * **G-Buffer 渲染**: 利用 **PyTorch3D** 渲染每个视角的 Depth 和 Normal 图。
    * **ControlNet**: 输入 Depth/Normal，强约束 SDXL 的生成结构，保证“生成的纹理贴合模型几何”。
    * **IP-Adapter**: 输入参考图，提取 Style Feature 注入 Attention 层，保证“多视角风格一致性”。
* **🌟 易考点**: ControlNet 和 IP-Adapter 分别解决了什么问题？（答：ControlNet 解决**几何对齐**，IP-Adapter 解决**风格/色调一致性**）。
<!--ID: 1773027655032-->


### 2.3 纹理投影 (Texture Projection)
* **知识点**: 将 2D 生成图映射回 3D UV 空间。
* **核心重点**: **加权融合算法**。权重 $W = (N \cdot V)^k$。
    * 只选取“正对相机”的像素（$N \cdot V$ 大），剔除侧面拉伸的像素。
* **🌟 易考点**: 如何解决投影时的接缝和拉伸？（答：通过法线-视线夹角加权，并结合 Softmax 或最大值混合）。
<!--ID: 1773027655034-->


---

## 3. Stage 2: PBR 属性解耦 (Intent-Driven Decoupling) [🔥最核心]
**代码文件**: `stage2_pbr.py`
<!--ID: 1773027655037-->


### 3.1 意图驱动：材质分类 (Material Classification)
* **知识点**: 利用 **CLIP** 或 **HSV 启发式规则** 进行材质语义分割。
* **实现细节**:
    * 将纹理切片送入 CLIP，计算与 "metal", "wood", "rust" 等文本的相似度。
    * **Rust Detection (锈迹检测)**: 针对特定颜色范围（橙色高饱和）强制覆盖材质属性。
* **核心重点**: **解决歧义性**。看到灰色，AI 判断是“灰色塑料”还是“灰色金属”？传统算法做不到，必须靠语义先验。
<!--ID: 1773027655040-->


### 3.2 粗糙度估算 (Roughness Estimation)
* **知识点**: **多信号加权融合 (Multi-signal Fusion)**。
* **公式**: `Roughness = clamp(α * Micro + γ * Base - β * Specular)`。
    1.  **Micro (微观几何)**: 边缘强度 + 深度方差。代表高频噪点。
    2.  **Base (语义基准)**: 也是意图驱动，根据 "rusty" 或 "polished" 词条设定基准值。
    3.  **Specular (高光修正)**: HSV 检测高亮低饱和区域，强制减小粗糙度（变光滑）。
* **🌟 易考点**: 粗糙度和法线贴图的区别？（答：法线是**像素级/中观**凹凸，粗糙度是**亚像素级/微观**凹凸的统计学表达）。
<!--ID: 1773027655043-->


### 3.3 固有色还原 (Albedo De-lighting)
* **知识点**: **本征分解 (Intrinsic Decomposition)**。
* **实现**: 将 RGB 转为 **Lab 空间**。假设色度 (a, b) 不变，亮度 (L) 的剧烈变化是光照 (Shading)，将其分离。
* **核心重点**: `AlbedoAuthor` 模块分离 Low-freq (Base) 和 High-freq (Detail)，去光只作用于 Base 层，防止纹理细节丢失。
<!--ID: 1773027655054-->


### 3.4 细节法线 (Detail Normal)
* **知识点**: 使用 **Marigold** (基于 Diffusion 的法线估计) 或 Depth Anything 生成微表面法线。
* **🌟 易考点**: 为什么不用 Sobel 算子算梯度？（答：Sobel 容易把颜色纹理误判为凹凸，Marigold 有语义理解，知道“黑色墨水”是平的，“黑色裂缝”是凹的）。
<!--ID: 1773027655057-->


---

## 4. Stage 3: 纹理优化 (Optimization)
**代码文件**: `stage3_optimization.py`
<!--ID: 1773027655061-->


### 4.1 空洞填充 (Inpainting)
* **知识点**: 识别 `weight < threshold` 的区域，调用 **SD Inpainting** 补全。
<!--ID: 1773027655064-->

### 4.2 接缝消除 (Seam Smoothing)
* **知识点**: 在 UV 边界处使用 **梯度域混合 (Gradient Domain Blending)** 或简单的膨胀腐蚀，确保纹理连续性。
<!--ID: 1773027655066-->


---

## 5. 图形学与渲染基础 (Engineering & Theory)

### 5.1 PBR 渲染方程与能量守恒
* **知识点**: 在 `complete_pipeline.py` 的 `SimplePBRShader` 中体现。
* **实现逻辑**:
    * **Dielectric (非金属)**: Diffuse = Albedo, Specular = 0.04 (白色)。
    * **Metal (金属)**: Diffuse = 0, Specular = Albedo (带颜色)。
* **🌟 易考点**: 金属度 (Metallic) 为 1 时，Diffuse 为什么是 0？（答：金属内部没有次表面散射，光线要么被吸收，要么被表面反射）。
<!--ID: 1773027655069-->


### 5.2 GPU 光追关联 (Ray Tracing)
* **知识点**:
    * **Closest Hit Shader**: 采样你生成的 Albedo/Normal/Roughness 贴图。
    * **Importance Sampling (重要性采样)**: 你的 Roughness Map 决定了光线反射的波瓣 (Lobe) 宽度。Roughness 越低，采样越集中。
* **🌟 易考点**: 你的项目怎么支持光追？（答：我生成的 PBR 资产直接作为光追 Shader 的 BRDF 参数输入，Roughness 的准确性直接影响光追采样的收敛速度和噪点）。
<!--ID: 1773027655072-->


---

## 6. 面试必问 Q&A (Cheat Sheet)

### Q1: 你的“意图驱动”到底体现在哪？
**A**: 体现在 Stage 2 的 **歧义性消除** 上。
传统方法看到“黑色”，不知道是“黑材质”还是“阴影”。我通过 **CLIP 语义分类** (MaterialClassifier) 和 **文本引导** (RoughnessEstimator)，让 AI 理解这是“生锈的铁”，从而强制设定 Metallic=0, Roughness=0.8，而不是瞎猜。
<!--ID: 1773027655074-->


### Q2: 为什么生成的法线贴图是蓝色的？
**A**: 因为它存储在 **切线空间 (Tangent Space)**。
$(0, 0, 1)$ 代表法线垂直于表面，映射到 RGB 就是 $(0.5, 0.5, 1.0)$，即浅蓝色。这允许法线贴图在物体旋转变形时依然有效。
<!--ID: 1773027655077-->


### Q3: 你的去光 (De-lighting) 效果如何验证？
**A**: 我实现了 `SimplePBRShader` 进行 **Relighting (重打光)** 测试。
如果去光不干净，光照旋转时，纹理上会有“死阴影”不动。我的方法通过 Lab 分解和高光检测，在大部分情况下能消除这种 Artifact。
<!--ID: 1773027655079-->


### Q4: 相比于腾讯的 MaterialMVP，你的优缺点？
**A**:
* **MaterialMVP**: 数据驱动，端到端一致性好，但难以人工控制，需要海量 3D 数据。
* **GeoPBR (我)**: 意图驱动，无需 3D 训练数据（Zero-shot），可控性强（可以通过 Prompt 修改材质），但物理一致性依赖启发式算法，目前不如端到端精准（这也是我未来想引入可微渲染改进的点）。
<!--ID: 1773027655083-->
