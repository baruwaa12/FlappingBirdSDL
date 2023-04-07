#include "ring.hpp"

Ring::Ring(float _x, float _y) {
  this->x = _x;
  this->y = _y;
  ringRect = new SDL_Rect();
  ringRect->x = _x;
  ringRect->y = _y;
  ringRect->h = 100;
  ringRect->w = 200;
}

void Ring::setX(float value){
  x = value;
}

void Ring::setY(float value){
  y = value;
}

float Ring::getX(){
  return x; 
}

float Ring::getY(){
  return y;
}
