#include <GL/glut.h> // Utility library to run OpenGL for perform system level I/O
#include <Windows.h> // Windows specific header	file C/C++ and declarations API
#include <cmath>
#include <string>

class Pattern
{
public:
	static void Init() // Initialization
	{
		glClearColor(0.5f, 0.10f, 0.5f, 0.0f); // Clear background color
		glMatrixMode(GL_PROJECTION); // Set the current matrix mode
		gluOrtho2D(0.0, 800, 0.0, 600); // Define 2D ortho graphics
	}

	static void Home() // Method to create a house 
	{
		// Roof
		glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer
								
		glColor3f(0.3f, 0.5f, 0.8f); // Color RGB
		glBegin(GL_POLYGON); // Delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(200, 500); // Specify a vertex with x and y coordinates
		glVertex2i(600, 500); // Specify a vertex with x and y coordinates
		glVertex2i(700, 350); // Specify a vertex with x and y coordinates
		glVertex2i(300, 350); // Specify a vertex with x and y coordinates
		glEnd(); //	End of drawing polygon

		// Top of Front Wall
		glColor3f(0.1f, 0.5f, 0.0f); // Color RBG
		glBegin(GL_TRIANGLES); // Delimit the vertices of a primitive or a group of like primitives (Drawing Triangles)
		glVertex2i(200, 500); // Specify a vertex with x and y coordinates
		glVertex2i(100, 350); // Specify a vertex with x and y coordinates
		glVertex2i(300, 350); // Specify a vertex with x and y coordinates
		glEnd(); //	End of drawing triangles

		// Front Wall
		glColor3f(0.7f, 0.2f, 0.3f); // Color RGB
		glBegin(GL_POLYGON); // Delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(100, 350); // Specify a vertex with x and y coordinates
		glVertex2i(300, 350); // Specify a vertex with x and y coordinates
		glVertex2i(300, 100); // Specify a vertex with x and y coordinates
		glVertex2i(100, 100); // Specify a vertex with x and y coordinates
		glEnd(); //	End of drawing polygon

		// Front Door
		glColor3f(0.7f, 0.2f, 0.9f); // Color RGB
		glBegin(GL_POLYGON); // Delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(150, 250); // Specify a vertex with x and y coordinates
		glVertex2i(250, 250); // Specify a vertex with x and y coordinates
		glVertex2i(250, 100); // Specify a vertex with x and y coordinates
		glVertex2i(150, 100); // Specify a vertex with x and y coordinates
		glEnd(); // End of drawing polygon

		// Front Door Lock
		glColor3f(0.3f, 0.7f, 0.9f); // Color RGB 
		glPointSize(15); //	Specifies the diameter of antialiased point
		glBegin(GL_POINTS); // delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(170, 170); // Specify a vertex with x and y coordinates
		glEnd(); // End of drawing point

		// Side Wall
		glColor3f(0.1f, 0.2f, 0.3f); // Color RGB
		glBegin(GL_POLYGON); // Delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(300, 350); // Specify a vertex with x and y coordinates
		glVertex2i(700, 350); // Specify a vertex with x and y coordinates
		glVertex2i(700, 100); // Specify a vertex with x and y coordinates
		glVertex2i(300, 100); // Specify a vertex with x and y coordinates
		glEnd(); //	End of drawing polygon 

		// Window one
		glColor3f(0.2f, 0.4f, 0.3f); // Color RGB
		glBegin(GL_POLYGON); // Delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(330, 320); // Specify a vertex with x and y coordinates
		glVertex2i(450, 320); // Specify a vertex with x and y coordinates
		glVertex2i(450, 230); // Specify a vertex with x and y coordinates
		glVertex2i(330, 230); // Specify a vertex with x and y coordinates
		glEnd(); // End of drawing polygon

		// Line of window one
		glColor3f(0.1f, 0.7f, 0.5f); // Color RGB
		glLineWidth(5); // Set the width of drawing lines
		glBegin(GL_LINES); // Delimit the vertices of a primitive or a group of like primitives (Drawing Lines)
		glVertex2i(390, 320); // Specify a vertex with x and y coordinates
		glVertex2i(390, 230); // Specify a vertex with x and y coordinates
		glVertex2i(330, 273); // Specify a vertex with x and y coordinates
		glVertex2i(450, 273); // Specify a vertex with x and y coordinates
		glEnd(); // End of drawing lines

		// Window two
		glColor3f(0.2f, 0.4f, 0.3f); // Color RGB
		glBegin(GL_POLYGON); //	Delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(530, 320); // Specify a vertex with x and y coordinates
		glVertex2i(650, 320); // Specify a vertex with x and y coordinates
		glVertex2i(650, 230); // Specify a vertex with x and y coordinates
		glVertex2i(530, 230); // Specify a vertex with x and y coordinates
		glEnd(); // End of drawing polygon

		// Lines of window two
		glColor3f(0.1f, 0.7f, 0.5f); // Color RGB
		glLineWidth(5); // Set the width of drawing lines
		glBegin(GL_LINES); // Delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(590, 320); // Specify a vertex with x and y coordinates
		glVertex2i(590, 230); // Specify a vertex with x and y coordinates
		glVertex2i(530, 273); // Specify a vertex with x and y coordinates
		glVertex2i(650, 273); // Specify a vertex with x and y coordinates
		glEnd(); // End of drawing lines

		// Entrance Path
		glColor3f(0.3f, 0.5f, 0.7f); // Color RGB
		glLineWidth(3); // Set the width of drawing lines
		glBegin(GL_POLYGON); //	delimit the vertices of a primitive or a group of like primitives (Drawing Polygon)
		glVertex2i(150, 100); // Specify a vertex with x and y coordinates
		glVertex2i(250, 100); // Specify a vertex with x and y coordinates
		glVertex2i(210, 0); // Specify a vertex with x and y coordinates
		glVertex2i(40, 0); // Specify a vertex with x and y coordinates
		glEnd(); // End of drawing polygon

		glFlush(); // Empties all the command in the buffers
	}
};

int main(int argc, char** argv) // Main function of C++
{
	glutInit(&argc, argv); // GLUT Initialization library sub API

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode 

	glutInitWindowPosition(200 * 2, 100); // Set the window position
	glutInitWindowSize(500, 500); // Set the window size
	glutCreateWindow("Home"); // Used to create a window

	Pattern::Init(); // Initialization OpenGL

	glutDisplayFunc(Pattern::Home); // Set the display callback for the current window

	glutMainLoop(); // Enters the GLUT event processing loop

	return EXIT_SUCCESS; // Like return 0
}