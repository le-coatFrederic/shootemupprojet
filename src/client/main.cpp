#include "Game.hpp"

int main(int argc, char *argv[]) {
    Game game;

    // Game loop
    while (game.getWindowState()) {
        // Update
        game.update();
        
        // Render
        game.render();
    }
    return 0;
}