//
// Created by ju on 10/19/25.
//

#pragma once
#include <vector>
#include "glad/glad.h"

namespace gl3 {
    class Mesh {
        public:
        explicit Mesh(const std::vector<float> &vertices);
        void draw() const;
        virtual ~Mesh();
        // Delete copy constructor
        Mesh(const Mesh &other) = delete;

        // Explicit move constructor
        Mesh(Mesh &&other) noexcept {
            std::swap(this->VBO, other.VBO);
            std::swap(this->numberOfVertices, other.numberOfVertices);
        }
        private:
        unsigned int VBO{};
        int numberOfVertices;

    };
}
