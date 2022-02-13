#pragma once

#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <glad/glad.h>
#include <stb_image.h>

#include "Shader.hpp"

class Textures
{
public:
	Textures(const char* image, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType);

	static void TextureUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind() const;
	void Unbind() const;
	void Delete() const;

public:
	GLuint ID;
	GLenum type;
};

#endif
