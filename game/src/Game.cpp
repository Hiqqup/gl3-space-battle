//
// Created by ju on 10/17/25.
//

#include "Game.h"

#include "Entity.h"


using namespace gl3;

void Game::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

Game::Game(int width, int height, const std::string &title) {
    if(!glfwInit()) {
        throw std::runtime_error("Failed to initialize glfw");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    window = glfwCreateWindow(width, height,  title.c_str(), nullptr, nullptr);
    if(window == nullptr) {
        throw std::runtime_error("Failed to create window");
    }
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    if(glGetError() != GL_NO_ERROR) {
        throw std::runtime_error("gl error");
    }
}

Game::~Game() {
    delete ship;
    glfwTerminate();
}

glm::mat4 Game::calculateMvpMatrix(glm::vec3 position, float zRotationInDegrees, glm::vec3 scale){
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, scale);
    model = glm::rotate(model, glm::radians(zRotationInDegrees), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 view = glm::lookAt(glm::vec3(0.0, 0.0, 90.0f),
                            glm::vec3(0.0f, 0.0f, 0.0),
                            glm::vec3(0.0, 1.0, 0.0));

    glm::mat4 projection = glm::perspective(glm::radians(2.0f), 1000.0f/600.0f, 0.1f, 100.0f);

    return projection * view * model;


}




void Game::update() {
    ship->update(window, deltaTime);
}
void Game::draw() {
    glClearColor(0.172f, 0.243f, 0.313f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ship->draw(this);
    glfwSwapBuffers(window);
}
void Game::updateDeltaTime() {
    float frameTime = glfwGetTime();
    deltaTime = frameTime - lastFrameTime;
    lastFrameTime = frameTime;
}
void Game::run() {
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    ship = new Ship();

    glfwSetTime(1.0/60);

    while(!glfwWindowShouldClose(window)) {

        update();
        draw();
        updateDeltaTime();
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);

}

