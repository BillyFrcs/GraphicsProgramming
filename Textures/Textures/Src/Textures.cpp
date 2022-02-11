#include "Textures.h"

Textures::Textures(const char* image, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType)
{
	this->type = textureType;

    // Texture image
    int width;
    int height;
    int numColumn;

    stbi_set_flip_vertically_on_load(true);

    unsigned char* bytes = stbi_load(image, &width, &height, &numColumn, 0);

    glGenTextures(1, &ID);
    glActiveTexture(slot);
    glBindTexture(textureType, ID);

    glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    /* Use this line of code if using GL_CLAMP_TO_BORDER
       float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
       glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);
    */

    glTexImage2D(textureType, 0, GL_RGBA, width, height, 0, format, pixelType, bytes);
    glGenerateMipmap(textureType);

    stbi_image_free(bytes);
    glBindTexture(textureType, 0);
}

void Textures::TextureUnit(Shader& ShaderProgram, const char* uniform, GLuint unit)
{
    // Create texture uniform
    const GLint textureUniform = glGetUniformLocation(ShaderProgram.ID, "Texture");
    ShaderProgram.Activate();
    glUniform1i(textureUniform, 0);
}

void Textures::Bind() const
{
    glBindTexture(type, this->ID);
}

void Textures::Unbind() const
{
    glBindTexture(type, GL_ZERO);
}

void Textures::Delete() const
{
    glDeleteTextures(1, &this->ID);
}