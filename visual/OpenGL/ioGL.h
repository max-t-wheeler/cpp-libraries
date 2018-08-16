#include <iostream>
#include <glm/glm.hpp>

void output_vec3(glm::vec3 v) {
    for (int i = 0; i < 3; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

void output_vec4(glm::vec4 v) {
    for (int i = 0; i < 4; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

void output_mat3(glm::mat3 m) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        std::cout << m[i][j] << ' ';
      }
      std::cout << '\n';
    }
}

void output_mat4(glm::mat4 m) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        std::cout << m[i][j] << ' ';
      }
      std::cout << '\n';
    }
}