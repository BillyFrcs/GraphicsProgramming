#pragma once

#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

class VertexBuffer
{
public:
	VertexBuffer(GLfloat* vertices, GLsizeiptr size);

	void Bind() const;
	static void Unbind();
	void Delete() const;

public:
	GLuint ID;
};

#endif 
