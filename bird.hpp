#pragma once
#include <SDL.h>

class Bird{
  private:
    int x;
    int y;
    void tick();
    void draw();
  public:
    Bird(int x, int y);
    void fly();
    void setX(int value);
    void setY(int value);
    int getX();
    int getY();
    SDL_Texture* wingUpTexture;
    SDL_Texture* wingDownTexture;

};