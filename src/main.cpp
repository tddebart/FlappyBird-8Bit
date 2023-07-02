#include <iostream>
#include <vector>
#include "SDL/SetupSDL.h"
#include "Player.h"
#include "ScreenInfo.h"
#include "Pipe.h"

Player player = Player();

std::vector<Pipe> pipes;

unsigned long nextPipeTime = 0;

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
        
        // Add pipe every 2 seconds
        if (SDL_GetTicks() > nextPipeTime) {
            Pipe pipe = Pipe();
            pipes.push_back(pipe);
            
            nextPipeTime = SDL_GetTicks() + rand() % 2500 + 1500;
            
            Pipe::pipeSpeed += 0.001;
        }
        
        // Update and draw pipes
        for (auto & pipe : pipes) {
            pipe.update(player);
            pipe.draw(renderer);
        }

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
