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

#include "Shader.h"
#include "Mesh.h"
#include "Entity.h"
#include "Ship.h"

namespace gl3 {
    class Game {
        public:
        void run();
        Game(int width, int height, const std::string &title);
        virtual ~Game();
        glm::mat4 calculateMvpMatrix(glm::vec3 position, float zRotationInDegrees, glm::vec3 scale);
        private:
        Shader* shader;
        Ship *ship;

        void processInput(GLFWwindow *window);
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

        void update();
        void draw();
        void updateDeltaTime();

        GLFWwindow *window;
        float zRotation = 0.0f;
        float rotationSpeed = 120.0f;
        float xTranslate = 0.0f;
        float yTranslate = 0.0f;
        float translationSpeed = 1.0f;
        float deltaTime = 1.0f/60;
        float lastFrameTime = 1.0f/60;




    };
}