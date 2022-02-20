#include "Lines.hpp"

void Lines::VerticalLine()
{
	glClearColor(255.0f / 255.0f, 148.0f / 255.0f, 43.0f / 255.0f, 255.0f / 255.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glClearColor(1, 1, 1, 1);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex3f(GL_ZERO, -0.3f, GL_ZERO);
	glVertex3f(-GL_ZERO, 10.0f, 15.0f);
	glEnd();

	glFlush();
}