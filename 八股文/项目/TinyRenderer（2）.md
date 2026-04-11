# TinyRenderer 核心知识点深度复盘

这份文档涵盖了从零手写软光栅化渲染器（TinyRenderer）的所有核心技术点，针对腾讯 IEG 客户端/图形向面试设计。
<!--ID: 1773027654931-->


---

## 目录
1. [基础数学与几何](#1-基础数学与几何)
2. [光栅化算法 (Rasterization)](#2-光栅化算法)
3. [变换矩阵 (The Pipeline)](#3-变换矩阵-pipeline)
4. [深度测试 (Z-Buffer)](#4-深度测试-z-buffer)
5. [透视校正插值 (Perspective Correction)](#5-透视校正插值-核心考点)
6. [着色与光照 (Shading & Lighting)](#6-着色与光照)
7. [纹理与法线映射 (Textures & Normal Mapping)](#7-纹理与法线映射)
8. [阴影映射 (Shadow Mapping)](#8-阴影映射)
<!--ID: 1773027654934-->


---

## 1. 基础数学与几何

### 1.1 齐次坐标 (Homogeneous Coordinates)
* **定义**：在 3D 坐标 $(x, y, z)$ 基础上增加 $w$ 分量，变成 $(x, y, z, w)$。
* **为什么需要它？**
    1.  **统一表示**：能用矩阵乘法同时表示线性变换（缩放、旋转）和**平移**（平移在 3D 空间非线性，但在 4D 空间是线性的）。
    2.  **透视除法**：$w$ 存储了透视投影后的深度信息，用于将视锥体压缩成标准立方体。
* **点与向量的区别**：
    * **点**：$w=1$。受平移影响。
    * **向量**：$w=0$。不受平移影响（表示方向和大小）。
<!--ID: 1773027654938-->


### 1.2 叉乘 (Cross Product)
* **几何意义**：得到一个垂直于两个输入向量的新向量。
* **用途**：
    * 计算面法线（Face Normal）。
    * **判断点在三角形内**（重心坐标推导的基础）。
    * 背面剔除（判断三角形朝向）。
<!--ID: 1773027654941-->


---

## 2. 光栅化算法

### 2.1 画线算法 (Bresenham's Line Algorithm)
* **核心思想**：仅使用**整数加法和位运算**，避免浮点数计算。
* **逻辑**：根据斜率（$k$）累加误差（error）。当误差超过 0.5 时，y 坐标进位，并将误差减 1。
* **面试考点**：为什么比 DDA 算法快？（去除了浮点数和除法）。
这是面试的高光时刻。我们要把浮点数 $y$ 和斜率 $k$ 全部干掉。
**1. 引入误差变量 `error`：**
我们不直接存浮点数 $y$，而是存一个 `error`。
- $x$ 每走一步，$y$ 想增加 $k$ (即 $dy/dx$)。
- 我们让 `error += dy/dx`。
- 如果 `error > 0.5`，说明积累的误差超过半个像素了，$y$ 应该往上走一步 ($y += 1$)，同时把误差减掉 1 (`error -= 1.0`)。
**2. 消除除法（两边同乘 $dx$）：**
- 原来的逻辑：`error += dy / dx`
- 我们定义新变量 `error2 = error * dx`。
- 新的增量：`error2 += dy` （看！除法没了！）
- 新的阈值：原来是判断 `error > 0.5`，现在两边乘 $dx$，变成判断 `error2 > dx * 0.5`。
**3. 消除 0.5（两边同乘 2）：**
- 浮点数 $0.5$ 还是很讨厌。
- 我们把所有相关项再乘 2。
- **最终变量 `derror2`：** `std::abs(dy) * 2`。
- **最终阈值：** 判断 `error2 > dx`。
```
void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) { 
    bool steep = false; 
    // 1. 处理陡峭直线：如果高大于宽，交换 xy，以 y 为主轴遍历
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    // 2. 保证从左往右画
    if (x0 > x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    } 
    
    int dx = x1 - x0; 
    int dy = y1 - y0; 
    // 3. 核心优化：用整数运算代替浮点斜率
    // derror2 代表每次 x+1 时，y 偏离了多少（放大了 2*dx 倍）
    int derror2 = std::abs(dy) * 2; 
    int error2 = 0; 
    int y = y0; 
    
    for (int x = x0; x <= x1; x++) { 
        // 4. 如果是陡峭模式，说明坐标被交换过，画点时要换回来
        if (steep) { 
            image.set(y, x, color); 
        } else { 
            image.set(x, y, color); 
        } 
        
        // 5. 更新误差
        error2 += derror2; 
        
        // 6. 如果累积误差超过一个像素（阈值是 dx，因为我们放大了 2*dx 倍，原本阈值 0.5 变成了 dx）
        if (error2 > dx) { 
            y += (y1 > y0 ? 1 : -1); // 根据 y 的方向决定是向上还是向下走
            error2 -= dx * 2;        // 减去一个像素的误差权重
        } 
    } 
}
```
<!--ID: 1773027654943-->

### 2.2 三角形光栅化 (Triangle Rasterization)
**方法一：扫描线算法 (Scanline Sweeping)**
* **逻辑**：将三角形按 y 坐标排序，切分成上下两半平底/平顶三角形，逐行填充。
* **缺点**：逻辑复杂（要处理分叉），难以并行，GPU 不用这个。
**方法二：包围盒 + 重心坐标 (Bounding Box + Barycentric)**
* **逻辑**（TinyRenderer 采用）：
    1.  计算三角形的 AABB 包围盒 (`min_x, min_y, max_x, max_y`)。
    2.  遍历包围盒内所有像素。
    3.  计算像素点的**重心坐标** $(u, v, w)$。
    4.  如果 $u \ge 0, v \ge 0, w \ge 0$，则像素在三角形内，画它！
* **优点**：算法极其简单，像素之间无依赖，**极易并行化**（现代 GPU 的做法）。
<!--ID: 1773027654946-->

### 2.3 重心坐标 (Barycentric Coordinates)
* **定义**：三角形平面内任意一点 $P$ 可以表示为三个顶点的加权和：$P = uA + vB + wC$，且 $u+v+w=1$。
* **计算方法**：利用**叉乘**计算面积比。
    * $u$ = (三角形PBC面积) / (三角形ABC面积)
* **核心用途**：**插值**。
    * 如果一个点在三角形内，它的所有属性（Z深度、颜色、法线、UV）都可以通过重心坐标加权插值得到。
    * $Attr_P = u \cdot Attr_A + v \cdot Attr_B + w \cdot Attr_C$
---
<!--ID: 1773027654949-->

## 3. 变换矩阵 (Pipeline)

公式：$P_{screen} = Viewport \cdot Projection \cdot View \cdot Model \cdot P_{local}$
<!--ID: 1773027654952-->

### 3.1 Model Matrix (模型变换)
* **作用**：Local Space $\to$ World Space。
* **顺序**：通常是 $T \cdot R \cdot S$（先缩放，再旋转，最后平移）。**注意矩阵乘法从右向左**。
<!--ID: 1773027654954-->

### 3.2 View Matrix (视图变换 / Camera)
* **作用**：World Space $\to$ Camera Space（相机位于原点，看向 $-Z$）。
* **LookAt 矩阵推导**：
    1.  **位移**：相机在 $E$，要移回原点，矩阵是 $T(-E)$。
    2.  **旋转**：
        * 计算相机坐标系的基向量：Right($\vec{r}$), Up($\vec{u}$), Forward($\vec{f}$)。
        * 正向变换（相机 $\to$ 世界）的旋转矩阵 $R$ 是将基向量**竖着放**（列向量）。
        * View 变换是逆变换。因为旋转矩阵是**正交矩阵**，逆矩阵 = 转置矩阵。
        * 所以 View 的旋转矩阵是将基向量**横着放**（行向量）。
    * **结果**：$M_{view} = R^T \cdot T^{-1}$。
<!--ID: 1773027654957-->

### 3.3 Projection Matrix (投影变换)
* **作用**：Camera Space $\to$ Clip Space (裁剪空间)。
* **透视投影 (Perspective)**：
    * **核心动作**：将视锥体（Frustum）挤压成 CVV（规范视图体，Cube $[-1, 1]^3$）。
    * **关键一行**：矩阵最后一行是 $[0, 0, -1, 0]$。
    * **效果**：变换后的 $w_{clip} = -z_{view}$。这一步保留了深度信息用于后续的透视除法。
<!--ID: 1773027654960-->

### 3.4 透视除法 (Perspective Division)
* **硬件自动执行**：将 $(x, y, z, w)$ 全都除以 $w$。
* **结果**：得到 NDC (Normalized Device Coordinates)。所有可见点都在 $[-1, 1]$ 之间。
* **几何意义**：实现“近大远小”。
<!--ID: 1773027654963-->

### 3.5 Viewport Matrix (视口变换)
* **作用**：NDC $\to$ Screen Space。
* **公式**：
    * $x_{screen} = (x_{ndc} + 1) \cdot \frac{Width}{2}$
    * $y_{screen} = (y_{ndc} + 1) \cdot \frac{Height}{2}$
    * $z_{screen}$ 映射到 $[0, 255]$ 或 $[0, 1]$ 用于 Z-Buffer。
---
<!--ID: 1773027654966-->

## 4. 深度测试 (Z-Buffer)

### 4.1 算法流程
1.  初始化一个与屏幕同分辨率的 buffer，存无限远。
2.  在光栅化时，计算当前像素插值得到的 $z$。
3.  `if (z < zbuffer[x][y])`:
    * `zbuffer[x][y] = z`
    * `colorbuffer[x][y] = pixel_color`
4.  否则：丢弃（被遮挡）。
<!--ID: 1773027654968-->

### 4.2 深度非线性 (Non-linearity)
* **考点**：NDC 里的 $z$ 和相机空间的 $z$ 是线性关系吗？
* **答案**：**不是**。
* **公式**：$z_{ndc} = \frac{A}{z_{view}} + B$。
* **后果**：Z-Buffer 在**近处精度很高，远处精度很低**。
* **Z-Fighting**：远处两个物体靠得近，深度值算出来一样，导致闪烁。
---
<!--ID: 1773027654971-->

## 5. 透视校正插值 (Perspective Correction) [核心考点]

### 5.1 问题
在屏幕空间（2D）直接用重心坐标插值属性（如颜色、UV），结果是**错的**。因为投影变换是非线性的，3D 空间的中点投影到 2D 后不再是中点。
<!--ID: 1773027654974-->

### 5.2 解决方案
必须对 **$1/z$** 进行插值。
* **推导结论**：虽然 $Attr$ 关于屏幕坐标不线性，但 $\frac{Attr}{z}$ 关于屏幕坐标是线性的。
* **正确步骤**：
    1.  在顶点着色器计算每个顶点的 $\frac{1}{z}$ 和 $\frac{UV}{z}$。
    2.  在光栅化时，用重心坐标插值出当前像素的 $\frac{1}{z}_{interp}$ 和 $\frac{UV}{z}_{interp}$。
    3.  **恢复**：$UV_{final} = \frac{\frac{UV}{z}_{interp}}{\frac{1}{z}_{interp}}$。
---
<!--ID: 1773027654977-->


## 6. 着色与光照 (Shading & Lighting)

### 6.1 着色频率
* **Flat Shading**：一个三角形一个颜色（面法线）。
* **Gouraud Shading**：顶点算颜色，中间插值颜色（缺点：高光由于插值会消失/变样）。
* **Phong Shading**：插值法线，每个像素算颜色（TinyRenderer 默认方式，效果最好）。
<!--ID: 1773027654979-->

### 6.2 Phong 光照模型 (Blinn-Phong)
$L = Ambient + Diffuse + Specular$
* **Diffuse (漫反射)**：$k_d \cdot (N \cdot L)$。Lambert余弦定律。
* **Specular (高光)**：
    * **Phong**: $k_s \cdot (R \cdot V)^\alpha$。计算反射向量 $R$，看它和视线 $V$ 的夹角。
    * **Blinn-Phong**: $k_s \cdot (N \cdot H)^\alpha$。计算半程向量 $H = \frac{L+V}{|L+V|}$。
    * **区别**：Blinn-Phong 计算更快（不用求反射向量），且高光过渡更柔和。
---
<!--ID: 1773027654982-->

## 7. 纹理与法线映射

### 7.1 纹理映射 (Texture Mapping)
* 利用重心坐标插值得到 $uv$ 坐标。
* 从纹理图片中 `sample(u, v)` 得到颜色。
<!--ID: 1773027654984-->

### 7.2 法线映射 (Normal Mapping) [重点]
* **目的**：在不增加几何面的情况下增加细节。
* **空间问题**：法线贴图存的是 **Tangent Space (切线空间)** 的法线（蓝色 $(0,0,1)$ 代表垂直表面）。
* **TBN 矩阵**：用于将 Tangent Space 转换到 World Space。
    * 由 Tangent ($T$), Bitangent ($B$), Normal ($N$) 三个向量组成。
    * **计算**：通常在 Shader 里计算，或者预计算好传入。
    * **变换逻辑**：$N_{world} = TBN \cdot N_{texture}$。
---
<!--ID: 1773027654987-->

## 8. 阴影映射 (Shadow Mapping)

### 8.1 Two-Pass 算法
1.  **Pass 1 (Light View)**：把相机放在光源位置，渲染一遍场景。**只存深度**，不存颜色。得到 **Shadow Map**。
2.  **Pass 2 (Camera View)**：正常渲染。
    * 对于每个像素，将其坐标变换到光源空间。
    * 比较：`current_depth` vs `shadow_map_depth`。
    * 如果 `current_depth > shadow_map_depth`，说明在阴影里。
<!--ID: 1773027654990-->


### 8.2 常见问题 (Artifacts)
* **Shadow Acne (自遮挡)**：由于精度问题，表面自己遮挡自己，产生黑色条纹。
    * **解法**：加一个 Bias (偏移量)。
* **Peter Panning (悬浮)**：Bias 加大了，导致阴影和物体分离。
* **硬阴影**：边缘锯齿严重。
    * **解法**：PCF (Percentage Closer Filtering)，多次采样取平均，做软阴影。
---
<!--ID: 1773027654992-->

## 9. 总结：TinyRenderer 渲染一个三角形的完整流
*(面试时按这个顺序讲)*
1.  **Vertex Processing**: 读顶点，乘 MVP 矩阵，转到 Clip Space。
2.  **Primitive Assembly**: 视口变换，转到 Screen Space。
3.  **Rasterization**: 找包围盒，遍历像素，算重心坐标。
4.  **Early-Z**: 如果开启，先做深度测试。
5.  **Interpolation**: 透视校正插值得到 $z, uv, normal$。
6.  **Fragment Shader**:
    * 采样纹理 (Albedo)。
    * 采样法线贴图，用 TBN 变换法线。
    * 计算光照 (Blinn-Phong)。
    * 计算阴影 (Shadow Map lookup)。
7.  **Output**: 写入 Framebuffer。
<!--ID: 1773027654995-->
