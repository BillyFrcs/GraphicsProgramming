#include "VertexArray.hpp"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

void VertexArray::LinkAttribute(VertexBuffer& VBO, GLuint layout, GLuint numberComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();

	glVertexAttribPointer(layout, numberComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);

	VBO.Unbind();
}

void VertexArray::Bind() const
{
	glBindVertexArray(ID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void VertexArray::Delete() const
{
	glDeleteVertexArrays(1, &ID);
}