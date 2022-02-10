#include <cstdlib>
#include <iostream>

// #include <GL/glew.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Buffer.h"

// Window screen
constexpr auto WIDTH = 640;
constexpr auto HEIGHT = 480;

// Vertices coordinates
GLfloat vertices[] =
{
    -0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
    0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
    0.0f, 0.5f * static_cast<float>(sqrt(3)) * 2 / 3, 0.0f,
    -0.5f / 2, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f,
    0.5f / 2, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f,
    0.0f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f,
};

// Vertices indices
GLuint indices[] =
{
    0, 3, 5, // Lower left triangle
    3, 2, 4, // Lower right triangle
    5, 4, 1 // Upper triangle
};

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
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Vertex Triangle", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();

        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0, 0, WIDTH, HEIGHT);

    /*
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error!" << std::endl;
    }
    */

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    Shader ShaderProgram("Shaders/Vertex.vert", "Shaders/Fragment.frag");

    auto* VAO = new VertexArray();
    VAO->Bind();

    VertexBuffer* VBO = new VertexBuffer(vertices, sizeof(vertices));

    Buffer* EBO = new Buffer(indices, sizeof(indices));

    VAO->LinkVBO(*VBO, 0);

    VAO->Unbind();
    VBO->Unbind();
    EBO->Unbind();

    glfwSwapBuffers(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Render color
        glClear(GL_COLOR_BUFFER_BIT);
        ShaderProgram.Activate();

        VAO->Bind();

        // Draw the triangle
        // glDrawArrays(GL_TRIANGLES, 0, 3); // Draw default triangle
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0); // Draw triangle with index buffer

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Delete all the objects
    VAO->Delete();
    VBO->Delete();
    EBO->Delete();

    ShaderProgram.Delete();

    // Delete window before ending the program
    glfwDestroyWindow(window);

    glfwTerminate();

    return EXIT_SUCCESS;
}