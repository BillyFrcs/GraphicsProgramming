#pragma once

#ifndef BUFFER_H
#define BUFFER_H

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