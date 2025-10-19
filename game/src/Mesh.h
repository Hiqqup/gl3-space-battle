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
        private:
        unsigned int VBO{};
        int vertexCount;

    };
}
