//
// Created by ju on 10/22/25.
//

#include "Game.h"
#include "Entity.h"

using namespace gl3;
Entity::Entity(Shader shader,
              Mesh mesh,
              glm::vec3 position,
              float zRotation,
              glm::vec3 scale,
              glm::vec4 color):
        shader(std::move(shader)),
        mesh(std::move(mesh)),
        position(position),
        zRotation(zRotation),
        scale(scale),
        color(color)
{
}

void Entity::update(GLFWwindow *window, float deltaTime) {
}

void Entity::draw(Game *game) {
    const glm::mat4 mvpMatrix = game->calculateMvpMatrix(position, zRotation, scale);
    shader.setMatrix("mvp", mvpMatrix);
    mesh.draw();
}
