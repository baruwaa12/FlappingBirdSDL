#include "pipe.h"
#include <SDL.h>
#include <iostream>
#include <chrono>

Pipe::Pipe(float _x, float _y, float _v) {
    this->x = _x;
    this->y = _y;
    this->v = _v;
    pipeRect = new SDL_Rect();
    pipeRect->x = _x;
    pipeRect->y = _y;
    pipeRect->h = 402;
    pipeRect->w = 60;
}

void Pipe::setX(float value) {
    x = value;
}

void Pipe::setY(float value) {
    y = value;
}

void Pipe::setV(float value) {
    v = value;
}

void Pipe::StopTimer() {

    if (timerID != 0) {
        SDL_RemoveTimer(timerID);
        timerID = 0;
    }
}

void Pipe::moveLeft() {
    this->x = this->x - this->v;
    this->pipeRect->x = this->pipeRect->x - this->x;
}

void Pipe::StartTimer() { // Create a timer event 


    timerID = SDL_AddTimer(1000, [](Uint32 interval, void* param) -> Uint32 { Pipe* pipe1 = static_cast<Pipe*>(param);
    pipe1->moveLeft(); return interval; }, this); if (timerID == 0) { std::cerr << "Failed to create timer: " << SDL_GetError() << std::endl; }

    if (timerID == 0) {
        std::cerr << "Failed to create timer: " << SDL_GetError() << std::endl;
    }
}


float Pipe::getX() {
    return x;
}

float Pipe::getY() {
    return y;
}

float Pipe::getV() {
    return v;
}

