#include "Pipe.h"
#include "Player.h"

void Pipe::draw(SDL_Renderer *renderer) {
    // Top
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {(int)position.x, (int)position.y - 48, 50, -SCREEN_HEIGHT_SIZE};
    SDL_RenderFillRect(renderer, &rect);
    SDL_Rect rect2 = {(int)position.x-5, (int)position.y - 48 - 10, 60, 10};
    SDL_RenderFillRect(renderer, &rect2);
    
    // Bottom
    SDL_Rect rect3 = {(int)position.x, (int)position.y + 48, 50, SCREEN_HEIGHT_SIZE};
    SDL_RenderFillRect(renderer, &rect3);
    SDL_Rect rect4 = {(int)position.x-5, (int)position.y + 48, 60, 10};
    SDL_RenderFillRect(renderer, &rect4);
}

void Pipe::update(Player &player) {
    position.x -= pipeSpeed;
    
    // Collision
    if (player.position.x + player.width > position.x && player.position.x < position.x + 50) {
        if (player.position.y < position.y - 48 || player.position.y + player.height > position.y + 48) {
            // Game over close
            exit(0);
        }
    }
}