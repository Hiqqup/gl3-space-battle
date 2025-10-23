//
// Created by ju on 10/23/25.
//

#pragma once
#include "Entity.h"


namespace gl3 {
    class Ship : public Entity{
        float translationSpeed = 1.0f;
        float rotationSpeed = 120.0f;
    public:
        explicit Ship(
            const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f),
            float zRotation =0.0f,
            const glm::vec3& scale = glm::vec3(0.25f));
        void update(GLFWwindow *window, float deltaTime);
    };
}
