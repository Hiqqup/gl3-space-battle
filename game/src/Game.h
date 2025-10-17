//
// Created by ju on 10/17/25.
//
#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace gl3 {
    class Game {
        public:
        void run();
        Game(int width, int height, const std::string &title);
        virtual ~Game();
        private:
        glm::mat4 calculateMvpMatrix(glm::vec3 position, float zRotationInDegrees, glm::vec3 scale);
        void processInput(GLFWwindow *window);
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

        void update();
        void draw();
        void updateDeltaTime();

        unsigned int shaderProgram;
        GLFWwindow *window;
        float zRotation = 0.0f;
        float rotationSpeed = 120.0f;
        float xTranslate = 0.0f;
        float yTranslate = 0.0f;
        float translationSpeed = 1.0f;
        float deltaTime = 1.0f/60;
        float lastFrameTime = 1.0f/60;


        const char *vertexShaderSource = R"(
    #version 460 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 mvp;
    void main() {
        gl_Position = mvp * vec4(aPos.xyz, 1.0);    // <-- now using the mvp matrix to transform the position
    }
)";


        const char *fragmentShaderSource = R"(
    #version 460 core
    out vec4 fragColor;
    void main() {
        fragColor = vec4(0.4f, 0.2f, 0.8f, 1.0f);
    }
)";
        float vertices[18] = {
            -0.5f, 0.05f, 0.0f,
            0.5f, 0.05f, 0.0f,
            -0.2f,  0.35f, 0.0f,

            -0.5f, -0.05f, 0.0f,
            0.5f, -0.05f, 0.0f,
            -0.2f,  -0.35f, 0.0f
          };
    };
}