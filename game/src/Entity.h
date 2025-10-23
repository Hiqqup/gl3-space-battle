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

    public:
        [[nodiscard]] glm::vec3 getPosition() const {
            return position;
        }

        void setPosition(const glm::vec3 &position) {
            this->position = position;
        }

        [[nodiscard]] glm::vec3 getScale() const {
            return scale;
        }

        void setScale(const glm::vec3 &scale) {
            this->scale = scale;
        }

        [[nodiscard]] float getZRotation() const {
            return zRotation;
        }

        void setZRotation(float z_rotation) {
            zRotation = z_rotation;
        }

    protected:
        glm::vec3 scale;
        float zRotation;
        const glm::vec4 color;
    private:
        Shader shader;
        Mesh mesh;
    public:
        Entity(Shader shader,
                      Mesh mesh,
                      glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
                      float zRotation = 0.0f,
                      glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
                      glm::vec4 color = glm::vec4(0.4f, 0.2f, 0.8f, 1.0f));
        virtual ~Entity() = default;
        virtual void update();
        virtual void draw(Game* game);


    };
}
