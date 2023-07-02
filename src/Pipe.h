#pragma once

#include "Vector2.h"
#include "ScreenInfo.h"
#include "Player.h"
#include <SDL.h>


struct Pipe {
    inline static float pipeSpeed = 0.5;
    
    
    Vector2 position = Vector2(SCREEN_WIDTH/SCREEN_SCALE, rand() % 200 + 100);
    
    const SDL_Color color = {121, 190, 46, 255};
    
    void update(Player &player);
    
    void draw(SDL_Renderer* renderer);
};
