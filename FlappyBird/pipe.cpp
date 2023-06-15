#include "pipe.h"
#include <SDL.h>
#include <iostream>
#include <chrono>



// Set pi


const int PIPE_WIDTH = 80;
const int PIPE_HEIGHT = 400;
const int PIPE_GAP = 200;
const int PIPE_SPEED = 3; // Speed at which pipes are approaching


Pipe::Pipe(int startX) {
    this->x = startX;
    this->y = rand() % 300 + 50
    
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

void Pipe::move() {
    x -= PIPE_SPEED; // Move the pipe to the left at this speed
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

int Pipe::getWidth() const  {
    return PIPE_WIDTH;
}

int Pipe::getHeight() const {
    return WINDOW_HEIGHT - y;
}


