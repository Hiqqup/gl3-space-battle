//
// Created by ju on 10/23/25.
//

#include "Ship.h"


using namespace gl3;
const char * vertexShaderSource = R"(
    #version 460 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 mvp;
    void main() {
        gl_Position = mvp * vec4(aPos.xyz, 1.0);    // <-- now using the mvp matrix to transform the position
    }
)";


 const char * fragmentShaderSource = R"(
    #version 460 core
    out vec4 fragColor;
    uniform vec4 color = vec4(0.4f, 0.2f, 0.8f, 1.0f);
    void main() {
        fragColor = color;
    }
)";
const std::vector<float> hardcodedVertices =  {
        -0.5f, 0.05f, 0.0f,
        0.5f, 0.05f, 0.0f,
        -0.2f,  0.35f, 0.0f,

        -0.5f, -0.05f, 0.0f,
        0.5f, -0.05f, 0.0f,
        -0.2f,  -0.35f, 0.0f
      };
Ship::Ship(const glm::vec3 &position, float zRotation, const glm::vec3 &scale):
Entity(Shader(fragmentShaderSource,vertexShaderSource), Mesh(hardcodedVertices),position, zRotation, scale)
{
}
void Ship::update(GLFWwindow *window, float deltaTime){
    const float entityZRotation = getZRotation();
    const glm::vec3 entityPosition = getPosition();
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        setZRotation(entityZRotation + rotationSpeed * deltaTime);
    }

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        setZRotation(entityZRotation - rotationSpeed * deltaTime);
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        setPosition(glm::vec3(
        entityPosition.x + sin(glm::radians(90-entityZRotation)) * translationSpeed * deltaTime,
        entityPosition.y + cos(glm::radians(90-entityZRotation)) * translationSpeed * deltaTime,
            0));
    }

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        setPosition(glm::vec3(
        entityPosition.x - sin(glm::radians(90-entityZRotation)) * translationSpeed * deltaTime,
        entityPosition.y - cos(glm::radians(90-entityZRotation)) * translationSpeed * deltaTime,
            0));
    }

}
