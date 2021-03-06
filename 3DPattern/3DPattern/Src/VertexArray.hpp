#pragma once

#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "VertexBuffer.hpp"

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