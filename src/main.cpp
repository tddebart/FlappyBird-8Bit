#include <iostream>
#include "SDL/SetupSDL.h"
#include "Player.h"
#include "ScreenInfo.h"

Player player = Player();

int main() {
    std::cout << "Hello, World!" << std::endl;

    InitSDL();

    while (!done) {
        handleInput();

        // Half the render resolution
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH/SCREEN_SCALE, SCREEN_HEIGHT/SCREEN_SCALE);

        SDL_SetRenderDrawColor(renderer, 108, 186, 196, 255);
        SDL_RenderClear(renderer);
        
        player.update();
        player.draw(renderer);
        

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
