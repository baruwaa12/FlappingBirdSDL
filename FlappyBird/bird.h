#include <SDL.h>
#include <chrono>

class Bird {
private:
    float x;
    float y;
    float v;
    float g;
    std::chrono::steady_clock::time_point lastGravityUpdate;
    SDL_TimerID timerID;

    

public:
    Bird(float x, float y, float v, float g);
    void jump();
    void flyDown();
    void updatePosition();
    void StartTimer();
    void StopTimer();
    SDL_Texture* wingUpTexture;
    SDL_Texture* wingDownTexture;
    SDL_Rect* BirdRect;
};