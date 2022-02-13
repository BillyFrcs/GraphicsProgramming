#include <cstdlib>
#include <iostream>

// #include <GL/glew.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "Buffer.hpp"
#include "Textures.hpp"
#include "PatternObject.hpp"

// Window screen
namespace Window
{
    static constexpr auto WIDTH = 640;
    static constexpr auto HEIGHT = 480;
}

namespace Transform
{
    // Vertices coordinates
    GLfloat vertices[] =
    {
        // Coordinates      // Color             // Texture
        -0.5f, 0.1f,  0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
        -0.5f, 0.1f, -0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f,
         0.5f, 0.1f, -0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    	 0.5f, 0.1f,  0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f,
         0.0f, 0.9f,  0.0f, 0.92f, 0.86f, 0.76f, 2.5f, 5.0f
    };

    // Vertices indices
    GLuint indices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };
}

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
    GLFWwindow* window = glfwCreateWindow(Window::WIDTH, Window::HEIGHT, "3D Pattern", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();

        throw("Failed to create a Window!");

        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0, 0, Window::WIDTH, Window::HEIGHT);

    // Check OpenGL version
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    Shader ShaderProgram("Shaders/Vertex.vert", "Shaders/Fragment.frag");

    // Create object
    const auto* VAO = new VertexArray();

    // Bind vertex buffer
    VAO->Bind();

    auto* VBO = new VertexBuffer(Transform::vertices, sizeof(Transform::vertices));

    const Buffer* EBO = new Buffer(Transform::indices, sizeof(Transform::indices));

    // Link the vertex attribute
    VertexArray::LinkAttribute(*VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), static_cast<void*>(0));
    VertexArray::LinkAttribute(*VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VertexArray::LinkAttribute(*VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    // Unbind vertex
    VertexArray::Unbind();
    VertexBuffer::Unbind();
    EBO->Unbind();

    // Create shader uniform
    const GLint shaderUniform = glGetUniformLocation(ShaderProgram.ID, "scale");

    // Textures object
    Textures* TextureImage = new Textures("Textures/Nise.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

    Textures::TextureUnit(ShaderProgram, "Texture", GL_ZERO);

    // Pattern 3D object
    PatternObject* Pattern = new PatternObject();

    // Init timer
    const double previousTime = glfwGetTime();

    glEnable(GL_DEPTH_TEST);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.1f, 0.14f, 0.3f, 1.0f); // Render background color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ShaderProgram.Activate();

        // Make simple timer to rotate the object
        Pattern->TimerObjectPattern(previousTime);

        // Create pattern 3D object
        Pattern->Create3DObject(Window::WIDTH, Window::HEIGHT);

        // Set the object location
        Pattern->ObjectLocation(ShaderProgram.ID);

        glUniform1f(shaderUniform, 0.5f);

        TextureImage->Bind();
        VAO->Bind();

        // Draw the pattern
        glDrawElements(GL_TRIANGLES, sizeof(Transform::indices) / sizeof(int), GL_UNSIGNED_INT, GLM_NULLPTR);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Delete all the vertex objects
    VAO->Delete();
    VBO->Delete();
    EBO->Delete();

    // Delete texture
    TextureImage->Delete();

    // Delete shader program
    ShaderProgram.Delete();

    // Delete window before ending the program
    glfwDestroyWindow(window);

    glfwTerminate();

    return GL_ZERO;
}