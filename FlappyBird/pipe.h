#pragma once
#include <SDL.h>
#include <chrono>
#include <vector>


class Pipe {
private:
    float x;
    float y;


public:
    Pipe(int startX);
    void move();
    void setX(float value);
    void setY(float value);
    void renderPipes(SDL_Renderer* gameRenderer,  std::vector<Pipe>& pipes);
    void newPipe(std::vector<Pipe>& pipes);
    float getX();
    float getY();
    int getWidth() const;
    int getHeight() const;
    SDL_Texture* pipeTexture;
    SDL_Rect* pipeRect;
    
};