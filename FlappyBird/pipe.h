#pragma once
#include <SDL.h>
#include <chrono>


class Pipe {
private:
    float x;
    float y;
    float v;
    std::chrono::steady_clock::time_point lastPipeUpdate;
    SDL_TimerID timerID;


public:
    Pipe(float x, float y, float v);
    void StartTimer();
    void StopTimer();
    void moveLeft();
    void setX(float value);
    void setY(float value);
    void setV(float value);
    float getX();
    float getY();
    float getV();
    SDL_Texture* pipeTexture;
    SDL_Rect* pipeRect;

};