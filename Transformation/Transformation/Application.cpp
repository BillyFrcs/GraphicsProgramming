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

	const char* title = "2D Transformation Perspective";
} Window;

auto z_position = 0.0f;
auto rotation_angle = 0.0f;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, z_position);
	glRotatef(rotation_angle, 0.f, 0.f, 1.f);
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -5.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.75f, 0.0f, -5.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -5.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.75f, -5.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -5.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.75f, 0.0f, -5.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -5.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, -0.75f, -5.0f);

	glEnd();
	glFlush();
	glutSwapBuffers();
}

void Initialize()
{
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluPerspective(45.0, (GLdouble)500.0 / (GLdouble)500.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void Resize(const int width, const int height)
{
	glViewport(0.0, 0.0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, static_cast<GLdouble>(width) / static_cast<GLdouble>(height), 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void TimeOut(const int value = 0)
{
	rotation_angle += 10.f;

	glutPostRedisplay();

	glutTimerFunc(100, TimeOut, value);
}

void Keyboard(const unsigned char key, int x, int y)
{
	if (key == '<' || key == ',')
	{
		z_position -= 0.1f;
	}

	if (key == '>' || key == '.')
	{
		z_position += 0.1f;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	const auto* window = new Window();

	glutInitWindowSize(window->width, window->height);
	glutInitWindowPosition(window->xPosition, window->yPosition);

	glutCreateWindow(window->title);

	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimeOut, 0);
	glutReshapeFunc(Resize);

	Initialize();

	glutMainLoop();

	return EXIT_SUCCESS;
}