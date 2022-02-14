#pragma once

#ifndef SHAPES_H
#define SHAPES_H

#include <windows.h>
#include <GL/glut.h>
#include <GL/GL.h>
#include <iostream>

namespace ShapesObject
{
	class Shapes
	{
	public:
		static void InitWindow();
		static void PyramidShape();
		static void CubeShape();
		static void DisplayShapes();
		static void Timer(int value = GL_ZERO);
		static void Reshape(GLsizei width, GLsizei height);
		static void GLUVersion(GLenum version);
	};
}

#endif
