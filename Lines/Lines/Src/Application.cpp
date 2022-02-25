#include <GL/glut.h>
#include <cmath>
#include <iostream>

#include "Lines.hpp"

typedef struct Window
{
	static constexpr int width = 500;
	static constexpr int height = 500;
} Window;

int main(int argc, char** argv)
{
        std::cerr << "Glut version: " << gluGetString(GLU_VERSION) << std::endl;

	glutInit(&argc, argv);
	glutInitWindowSize(Window::width, Window::height);
	glutCreateWindow("Lines");
	glutDisplayFunc(Lines::VerticalLine);
	glutMainLoop();

	return EXIT_SUCCESS;
}
