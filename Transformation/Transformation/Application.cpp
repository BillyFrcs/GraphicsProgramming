#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <string>

typedef struct Window
{
	const int width = 500;
	const int height = 400;

	const int xPosition = 400;
	const int yPosition = 100;

	const char* title = "Transformation";
} Window;

class Rendering
{
public:
	static void Initialize()
	{
		glClearColor(1, 1, 1, 1);
		glMatrixMode(GL_PROJECTION_MATRIX);
		glLoadIdentity();
		glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	}

	static void Display()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POLYGON);

		glColor3d(0, 250, 255);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
		glFlush();
	}
};

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	const auto* window = new Window();

	glutInitWindowSize(window->width, window->height);
	glutInitWindowPosition(window->xPosition, window->yPosition);

	glutCreateWindow(window->title);

	Rendering::Initialize();

	glutDisplayFunc(Rendering::Display);

	glutMainLoop();

	return EXIT_SUCCESS;
}