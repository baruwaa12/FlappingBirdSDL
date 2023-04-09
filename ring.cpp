#include "ring.hpp"
#include <SDL.h>
#include <iostream>

Ring::Ring(float _x, float _y, float _v) {
  this->x = _x;
  this->y = _y;
  this->v = _v;
  ringRect = new SDL_Rect();
  ringRect->x = _x;
  ringRect->y = _y;
  ringRect->h = 60;
  ringRect->w = 60;
}

void Ring::randomY(){
  y = rand() % 400;
  ringRect->y = this->y;
}

void Ring::moveLeft(){
  x -= v;
  if (x < -61) {
    x = 660; 
  }
  ringRect->x = this->x;
}

void Ring::setX(float value){
  x = value;
}

void Ring::setY(float value){
  y = value;
}

void Ring::setV(float value){
  v = value;
}

float Ring::getX(){
  return x; 
}

float Ring::getY(){
  return y;
}

float Ring::getV(){
  return v; 
}
