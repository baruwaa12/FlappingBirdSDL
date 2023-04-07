#include <SDL.h>


class Ring {

  private:
    float x;
    float y;

  public:
    Ring(float x, float y);
    void setX(float value);
    void setY(float value);
    float getX();
    float getY();
    SDL_Texture *ringTexture;
    SDL_Rect *ringRect;
};