#pragma once

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glut.h>
#include <gl/GL.h>

namespace Window
{
	struct Screen
	{
		static const GLint width;
		static const GLint height;

		static const GLint x;
		static const GLint y;

		static const char* title;
	};

	constexpr GLint Screen::width = 700;
	constexpr GLint Screen::height = 500;

	constexpr GLint Screen::x = 80;
	constexpr GLint Screen::y = 80;

	const char* Screen::title = "3D Shapes Animation";
}

#endif