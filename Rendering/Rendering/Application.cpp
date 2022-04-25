#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <string>

typedef struct Window
{
	static constexpr int width = 500;
	static constexpr int height = 500;

	static constexpr int xPosition = 250;
	static constexpr int yPosition = 250;
} Window;

class Rendering
{
public:
	static void Display()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POLYGON);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
		glFlush();
	}

	static void Initialize()
	{
		glClearColor(0, 0, 0, 0);
		glMatrixMode(GL_PROJECTION_MATRIX);
		glLoadIdentity();
		glOrtho(-10.0f, 10.0, -10.0f, 10.0f, -10.0f, 10.0f);
	}

	static void Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3d(0, 250, 255);

		glBegin(GL_QUAD_STRIP);

		glVertex2f(-4.0f, -2.0f);
		glVertex2f(-4.0f, 2.0f);
		glVertex2f(-2.0f, -2.0f);
		glVertex2f(-2.0f, 2.0f);
		glVertex2f(6.0f, -6.0f);
		glVertex2f(6.0f, 6.0f);

		glEnd();
		glFlush();
	}
};

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(Window::width, Window::height);
	glutInitWindowPosition(Window::xPosition, Window::yPosition);

	glutCreateWindow("Rendering");

    Rendering::Initialize();

	glutDisplayFunc(Rendering::Draw);

	glutMainLoop();

	return EXIT_SUCCESS;
}