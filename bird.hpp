#pragma once
#include <SDL.h>

class Bird{
  private:
    int x;
    int y;

  public:
    Bird(int x, int y);
    void fly();
    void setX(int value);
    SDL_Texture* wingUpTexture;
    SDL_Texture* wingDownTexture;
};