#include "Player.h"
#include "ScreenInfo.h"
#include "SDL/Input.h"

void Player::update() {
    // Gravity
    velocity.y += fallSpeed;
    if (velocity.y > 1) {
        velocity.y = 1;
    }
    
    // Move
    position += velocity;
    
    // Collision
    if (position.y + height > SCREEN_HEIGHT/SCREEN_SCALE) {
        // Game over close
        exit(0);
    }
    
    if (position.y < 0) {
        exit(0);
    }
    
    if (isKeyPressed(SDL_SCANCODE_SPACE)) {
        velocity.y = -1;
    }
}

void Player::draw(SDL_Renderer *renderer) {
    // Body
    SDL_SetRenderDrawColor(renderer, 242, 223, 56, 255);
    SDL_Rect rect = {(int)position.x, (int)position.y, width, height};
    SDL_RenderFillRect(renderer, &rect);
    
    // Nose
    SDL_SetRenderDrawColor(renderer, 242, 83, 32, 255);
    SDL_Rect rect2 = {(int)position.x + 15, (int)position.y + 12, width - 10, height / 3};
    SDL_RenderFillRect(renderer, &rect2);
    
    // Eye
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_Rect rect3 = {(int)position.x + 20, (int)position.y + 5, width / 5, height / 5};
    SDL_RenderFillRect(renderer, &rect3);
}
