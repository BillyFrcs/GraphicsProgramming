#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void)
{
    // Initialize the library
    if (!glfwInit())
        return -1;

    // Hint desire value
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Application", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();

        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error!" << std::endl;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    unsigned int value;

    glGenBuffers(1, &value);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.5f, 0.3f, 0.7f, 1.0f); // Render color
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
