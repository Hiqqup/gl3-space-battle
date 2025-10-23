//
// Created by ju on 10/19/25.
//

#pragma once

#include <glad/glad.h>
#include <string>
#include <iostream>
#include <glm/glm.hpp>

namespace gl3 {
    class Shader {
    public:
        Shader(const std::string& fragmentShaderSource, const std::string& vertexShaderSource);
        void setMatrix(const std::string &uniformName, const glm::mat4 &matrix) const;
        void setVector(const std::string &uniformName, const glm::vec4 &vector) const;
        void use() const;
        virtual ~Shader();

        // Delete copy constructor
        Shader(const Shader &shader) = delete;

        // Explicit move constructor
        Shader(Shader &&other) noexcept {
            std::swap(this->shaderProgram, other.shaderProgram);
            std::swap(this->vertexShader, other.vertexShader);
            std::swap(this->fragmentShader, other.fragmentShader);
        }

    private:

        unsigned int shaderProgram = 0;
        unsigned int vertexShader = 0;
        unsigned int fragmentShader = 0;
        unsigned int loadAndCompileShader(GLuint shaderType, const std::string &shaderSource);


    };
}