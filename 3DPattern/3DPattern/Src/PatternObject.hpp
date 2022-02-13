#pragma once

#ifndef PATTERN_OBJECT_HPP
#define PATTERN_OBJECT_HPP

#include <glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class PatternObject
{
public:
	void Create3DObject(const glm::float32 width, const glm::float32 height);
	void ObjectLocation(const GLuint shaderProgramID);
	void TimerObjectPattern(const double previousTime);

	GLdouble GetTimerPattern(GLdouble previousTime);

private:
	glm::mat4 _model;
	glm::mat4 _view;
	glm::mat4 _proj;

	float_t _rotation = 0.0f;
};

#endif
