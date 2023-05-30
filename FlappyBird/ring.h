#include <SDL.h>


class Ring {

private:
    float x;
    float y;
    float v;
    bool isVisible;

public:
    Ring(float x, float y, float v);
    void setX(float value);
    void setY(float value);
    void setV(float value);
    void setVisible(bool value);
    bool getIsVisible();
    void randomY();
    bool collected();
    void moveLeft();
    float getX();
    float getY();
    float getV();
    SDL_Texture* ringTexture;
    SDL_Rect* ringRect;
};