#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <GL/GL.h>

#include "Shapes.hpp"
#include "Window.h"

int main(int argc, char** argv)
{
    ShapesObject::Shapes::GLUVersion(GLU_VERSION); // Check the OpenGL version

    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(Window::Screen::width, Window::Screen::height);   // Set the window's initial width & height
    glutInitWindowPosition(Window::Screen::x, Window::Screen::y); // Position the window's initial top-left corner
    glutCreateWindow(Window::Screen::title); // Create window with the given title
    glutDisplayFunc(ShapesObject::Shapes::DisplayShapes);       // Register callback handler for window re-paint event
    glutReshapeFunc(ShapesObject::Shapes::Reshape);       // Register callback handler for window re-size event
    ShapesObject::Shapes::InitWindow();                       // OpenGL window initialization
    glutTimerFunc(GL_ZERO, ShapesObject::Shapes::Timer, GL_ZERO);     // First timer call immediately
    glutMainLoop();

    return GLUT_NORMAL;
}