#include "Game.h"

int main() {
    try {
        gl3::Game(1280, 720, "Space Battle").run();
    }catch(const std::exception &e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}