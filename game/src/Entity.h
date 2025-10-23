//
// Created by ju on 10/22/25.
//

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include "Mesh.h"
#include "Shader.h"

namespace gl3{
    class Game;
    class Entity {
        protected:
        glm::vec3 position;
        glm::vec3 scale;
        float zRotation;
        glm::vec4 color;
    private:
        Shader shader;
        Mesh mesh;
    public:
        Entity(Shader shader,
                      Mesh mesh,
                      glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
                      float zRotation = 0.0f,
                      glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
                      glm::vec4 color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        virtual ~Entity() = default;
        virtual void update(GLFWwindow *window, float deltaTime);
        virtual void draw(Game *game);


    };
}
