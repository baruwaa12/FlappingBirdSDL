#pragma once
#ifndef PIPE_H
#define PIPE_H
#include <SDL.h>
#include <chrono>
#include <vector>


class Pipe {

private:
    float x;
    float y;
    int topHeight;
    int bottomHeight;
    int initialY;


public:
    Pipe(int startX);
    void move();
    void setX(float value);
    void setY(float value);
    void renderPipes(SDL_Renderer* gameRenderer,  std::vector<Pipe>& pipes);
    void newPipe(std::vector<Pipe>& pipes);
    float getX();
    float getY();
    int getWidth() const;
    int getHeight() const;
    int getTopHeight() const {
        return topHeight;
    };
    int getBottomHeight() const {
        return bottomHeight;
    };
    int getInitialY() const {
        return initialY;
    }
    int setInitialY(int newY) {
        initialY = newY;
        return initialY;
    }
    int getTopY() const;
    void setBottomHeight(int height) { bottomHeight = height; }
    void setTopHeight(int height) { topHeight = height; };
    int getBottomY() const;
    SDL_Texture* pipeTexture;
    SDL_Rect* pipeRect;
    
};

#endif //PIPE H