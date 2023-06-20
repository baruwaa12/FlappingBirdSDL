#include "pipe.h"
#include <SDL.h>
#include <iostream>
#include <chrono>



// Set pi


const int PIPE_WIDTH = 80;
const int PIPE_HEIGHT = 400;
const int PIPE_GAP = 200;
const int PIPE_SPEED = 3; // Speed at which pipes are approaching
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;


Pipe::Pipe(int startX) {
    this->x = startX;
    this->y = rand() % 300 + 50;
    
}

void Pipe::move() {
    x -= PIPE_SPEED; // Move the pipe to the left at this speed
}


void Pipe::setX(float value) {
    x = value;
}

void Pipe::setY(float value) {
    y = value;
}

void Pipe::renderPipes(SDL_Renderer *gameRenderer,  std::vector<Pipe>& pipes) {

    for (auto& pipe : pipes) {
        SDL_Rect upperPipeRect = { pipe.getX(), 0, pipe.getWidth(), pipe.getY() };
        SDL_Rect lowerPipeRect = { pipe.getX(), pipe.getY() + PIPE_GAP, pipe.getWidth(), pipe.getHeight() };

        SDL_RenderFillRect(gameRenderer, &upperPipeRect);  // Render upper pipe
        SDL_RenderFillRect(gameRenderer, &lowerPipeRect);  // Render lower pipe
    }
}

void Pipe::newPipe(std::vector<Pipe>& pipes) {
    Pipe newPipe(SCREEN_WIDTH);  // Spawn a new pipe at the right side of the screen
    pipes.push_back(newPipe);
}

float Pipe::getX() {
    return x;
}

float Pipe::getY() {
    return y;
}

int Pipe::getWidth() const  {
    return PIPE_WIDTH;
}

int Pipe::getHeight() const {
    return WINDOW_HEIGHT - y;
}


