#include "Texture.h"
#include "stb.h" // 确保这里包含正确


Texture::Texture(const std::string& path, const TextureParameters& params)
    : m_RenderedID(0), m_FilePath(path), m_LocalBuffer(nullptr), width(0), height(0), nrChannels(0)
{
    // 1. 翻转图片（OpenGL 坐标系 y 轴向上，图片通常向下）
    stbi_set_flip_vertically_on_load(1);

    // 2. 注意这里传的是 &m_Width 等地址
    m_LocalBuffer = stbi_load(path.c_str(), &width, &height, &nrChannels, 4); // 强制转为 4 通道 RGBA

    glGenTextures(1, &m_RenderedID);
    glBindTexture(GL_TEXTURE_2D, m_RenderedID);

    // 设置参数
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, params.minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, params.magFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, params.wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, params.wrapT);


    if (m_LocalBuffer) {
        // 因为上面强制加载为 4 通道，这里统一用 GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    if (m_LocalBuffer)
        stbi_image_free(m_LocalBuffer);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_RenderedID); // 真正从显存删除
}

void Texture::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot); // 选择纹理单元
    glBindTexture(GL_TEXTURE_2D, m_RenderedID);
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::setBorderColor(float v0, float v1, float v2, float v3) {
    float borderColor[] = { v0, v1, v2, v3 };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
}