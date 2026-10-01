
#include "../engine/include/engine.hpp"
#include <iostream>

int main() {
    Engine gameEngine;
    if (!gameEngine.init(800, 600, "My aga")) {
        std::cerr << "Bro";
        return -1;
    }

    while (!gameEngine.shouldClose()) {
        gameEngine.update();
    }

    gameEngine.shutdown();
    return 0;
}
