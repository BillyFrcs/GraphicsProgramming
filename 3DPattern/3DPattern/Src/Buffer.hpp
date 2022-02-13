#pragma once

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad/glad.h>

class Buffer
{
public:
	Buffer(GLuint* vertices, GLsizeiptr size);

	void Bind() const;
	void Unbind() const;
	void Delete() const;

public:
	GLuint ID;
};

#endif