//
// Created by ju on 10/19/25.
//

#include "Mesh.h"

using namespace gl3;

Mesh::Mesh(const std::vector<float> &vertices) {
    vertexCount = (vertices.size() +1) / 3;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);

}

void Mesh::draw() const {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) nullptr);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

}

Mesh::~Mesh() {

    glDeleteVertexArrays(1, &VBO);
}
