#pragma once

#include <SDL.h>
#include "Vector2.h"


struct Player {
    Vector2 position = Vector2(64, 0);
    Vector2 velocity = Vector2(0, 0);
    
    const int width = 32;
    const int height = 24;
    
    const float fallSpeed = 0.01;
    
    void update();
    
    void draw(SDL_Renderer* renderer);
};
