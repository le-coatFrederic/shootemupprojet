#include "Game.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Game game;

    // Game loop
    std::cout << "je rentre dans la boucle\n";
    while (game.getWindowState()) {
        // Update
        game.update();
        
        // Render
        game.render();
    }
    return 0;
}