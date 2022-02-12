#pragma once

#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include <glad/glad.h>

class VertexBuffer
{
public:
	VertexBuffer(GLfloat* vertices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();

public:
	GLuint ID;
};

#endif 
