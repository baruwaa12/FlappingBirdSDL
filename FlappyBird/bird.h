#include <SDL.h>

class Bird {
private:
    float x;
    float y;
    float v;
    float g;

public:
    Bird(float x, float y, float v, float g);
    void jump();
    void flyDown();
    SDL_Texture* wingUpTexture;
    SDL_Texture* wingDownTexture;
    SDL_Rect* BirdRect;

};