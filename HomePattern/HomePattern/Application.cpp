#include <GL/glut.h> // 
#include <Windows.h> //
#include <cmath>
#include <string>

class Pattern
{
public:
	static void Init() //
	{
		glClearColor(0.5f, 0.9f, 0.4f, 0.0f); //
		glMatrixMode(GL_PROJECTION); //
		gluOrtho2D(0.0, 800, 0.0, 600); //
	}

	static void Home()
	{
		// Roof
		glClear(GL_COLOR_BUFFER_BIT); //

		glColor3f(0.3f, 0.5f, 0.8f); //
		glBegin(GL_POLYGON); //
		glVertex2i(200, 500); //
		glVertex2i(600, 500); //
		glVertex2i(700, 350); //
		glVertex2i(300, 350); //
		glEnd();//

		// Top of Front Wall
		glColor3f(0.1f, 0.5f, 0.0f); //
		glBegin(GL_TRIANGLES); //
		glVertex2i(200, 500); //
		glVertex2i(100, 350); //
		glVertex2i(300, 350); //
		glEnd(); //

		// Front Wall
		glColor3f(0.7f, 0.2f, 0.3f); //
		glBegin(GL_POLYGON); //
		glVertex2i(100, 350); //
		glVertex2i(300, 350); //
		glVertex2i(300, 100); //
		glVertex2i(100, 100); //
		glEnd(); //

		// Front Door
		glColor3f(0.7f, 0.2f, 0.9f); //
		glBegin(GL_POLYGON); //
		glVertex2i(150, 250); //
		glVertex2i(250, 250); //
		glVertex2i(250, 100); //
		glVertex2i(150, 100); //
		glEnd();//

		// Front Door Lock
		glColor3f(0.3f, 0.7f, 0.9f); //
		glPointSize(15); //
		glBegin(GL_POINTS); //
		glVertex2i(170, 170); //
		glEnd();//

		//side Wall
		glColor3f(0.1f, 0.2f, 0.3f); //
		glBegin(GL_POLYGON); //
		glVertex2i(300, 350); //
		glVertex2i(700, 350); //
		glVertex2i(700, 100); //
		glVertex2i(300, 100); //
		glEnd(); //

		// window one
		glColor3f(0.2f, 0.4f, 0.3f); //
		glBegin(GL_POLYGON); //
		glVertex2i(330, 320); //
		glVertex2i(450, 320); //
		glVertex2i(450, 230); //
		glVertex2i(330, 230); //
		glEnd();//

		// line of window one
		glColor3f(0.1f, 0.7f, 0.5f); //
		glLineWidth(5); //
		glBegin(GL_LINES); //
		glVertex2i(390, 320); //
		glVertex2i(390, 230); //
		glVertex2i(330, 273); //
		glVertex2i(450, 273); //
		glEnd(); //

		// window two
		glColor3f(0.2f, 0.4f, 0.3f); //
		glBegin(GL_POLYGON); //
		glVertex2i(530, 320); //
		glVertex2i(650, 320); //
		glVertex2i(650, 230); //
		glVertex2i(530, 230); //
		glEnd();//

		// lines of window two
		glColor3f(0.1f, 0.7f, 0.5f); //
		glLineWidth(5); //
		glBegin(GL_LINES); //
		glVertex2i(590, 320); //
		glVertex2i(590, 230); //
		glVertex2i(530, 273); //
		glVertex2i(650, 273); //
		glEnd();//

		// Entrance Path
		glColor3f(0.3f, 0.5f, 0.7f); //
		glLineWidth(3); //
		glBegin(GL_POLYGON); //
		glVertex2i(150, 100); //
		glVertex2i(250, 100); //
		glVertex2i(210, 0); //
		glVertex2i(40, 0); //
		glEnd(); //

		glFlush(); //
	}
};

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //

	glutInitWindowPosition(200 * 2, 100); //
	glutInitWindowSize(500, 500); //
	glutCreateWindow("Home"); //

	Pattern::Init(); //

	glutDisplayFunc(Pattern::Home); //

	glutMainLoop(); //

	return EXIT_SUCCESS;
}