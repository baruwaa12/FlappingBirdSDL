#pragma once
#include <SDL.h>

class Bird{
  private:
    float x;
    float y;
    float v;
    float g;
    
  public:
    Bird(float x, float y, float v, float g);
    void flyDown();
    void flyUp();
    void setX(float value);
    void setY(float value);
    void setV(float value);
    void setG(float value);
    float getX();
    float getY();
    float getV();
    float getG();
    SDL_Texture* wingUpTexture;
    SDL_Texture* wingDownTexture;
};