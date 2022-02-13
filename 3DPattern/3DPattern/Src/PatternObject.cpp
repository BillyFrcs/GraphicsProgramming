#include "PatternObject.hpp"

void PatternObject::Create3DObject(const glm::float32 width, const glm::float32 height)
{
    _model = glm::mat4(GL_ONE);
    _view = glm::mat4(GL_ONE);
    _proj = glm::mat4(GL_ONE);

    _model = glm::rotate(_model, glm::radians(this->_rotation), glm::vec3(GL_ZERO, 1.0f, GL_ZERO));
    _view = glm::translate(_view, glm::vec3(GL_ZERO, -0.5f, -2.0f));
    _proj = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.f);
}

void PatternObject::ObjectLocation(const GLuint shaderProgramID)
{
    // Model
    const int modelLocation = glGetUniformLocation(shaderProgramID, "model");
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(_model));

    // View
    const int viewLocation = glGetUniformLocation(shaderProgramID, "view");
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(_view));

    // Proj
    const int projLocation = glGetUniformLocation(shaderProgramID, "proj");
    glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(_proj));
}

void PatternObject::TimerObjectPattern(const double previousTime)
{
    GetTimerPattern(previousTime);
}

GLdouble PatternObject::GetTimerPattern(GLdouble previousTime)
{
    const auto currentTime = glfwGetTime();

    if (currentTime - previousTime >= 1.0 / 60.0)
    {
        this->_rotation += 0.05F;

        return previousTime = currentTime;
    }

    return GL_ZERO;
}