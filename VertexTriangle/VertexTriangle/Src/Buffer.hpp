#pragma once

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad/glad.h>

class Buffer
{
public:
	Buffer(GLuint* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();

public:
	GLuint ID;
};

#endif