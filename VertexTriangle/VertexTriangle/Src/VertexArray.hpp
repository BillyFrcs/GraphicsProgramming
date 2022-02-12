#pragma once

#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "VertexBuffer.hpp"

class VertexArray
{
public:
	VertexArray();

	void LinkVBO(VertexBuffer& VBO, GLuint layout);
	void Bind();
	void Unbind();
	void Delete();

public:
	GLuint ID;
};

#endif