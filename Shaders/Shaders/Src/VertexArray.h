#pragma once

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "VertexBuffer.h"

class VertexArray
{
public:
	VertexArray();

	static void LinkAttribute(VertexBuffer& VBO, GLuint layout, GLuint numberComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Bind() const;
	static void Unbind();
	void Delete() const;

public:
	GLuint ID;
};

#endif