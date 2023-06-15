#pragma once
#include <SDL.h>
#include <chrono>


class Pipe {
private:
    float x;
    float y;


public:
    Pipe(int startX);
    void move();
    void setX(float value);
    void setY(float value);
    float getX();
    float getY();
    int getWidth() const;
    int getHeight() const;
    SDL_Texture* pipeTexture;
    SDL_Rect* pipeRect;
    
};