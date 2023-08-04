#include "pipe.h"
#include <SDL.h>
#include <iostream>
#include <chrono>
#include <random>



// Set pi


const int PIPE_WIDTH = 80;
const int PIPE_HEIGHT = 400;
const int PIPE_GAP = 200;
const int PIPE_SPEED = 3; // Speed at which pipes are approaching
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;


Pipe::Pipe(int startX) {
    this->x = startX;
    topHeight = 0;
    bottomHeight = 0;
    initialY = 0;
    
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


void Pipe::newPipe(std::vector<Pipe>& pipes) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(50, SCREEN_HEIGHT - 50 - PIPE_GAP);

    int topHeight = dis(gen);
    int bottomHeight = SCREEN_HEIGHT - topHeight - PIPE_GAP;

    Pipe newPipe(SCREEN_WIDTH); // Spawn a new pipe at the right side of the screen
    newPipe.setTopHeight(topHeight);
    newPipe.setBottomHeight(bottomHeight);
    newPipe.setInitialY(0);

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
    return initialY + getTopHeight() + PIPE_GAP;
}

int Pipe::getTopY() const {
    return initialY;
}

int Pipe::getBottomY() const {
    return initialY + PIPE_GAP;
}



