#include "pipe.hpp"

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

void Pipe::setX(float value){
  x = value; 
}

void Pipe::setY(float value){
  y = value;
}

void Pipe::setV(float value){
  v = value;
}

float Pipe::getV(){
  return v;
}

void Pipe::moveLeft(){
  x -= v;
  if (x < -61) {
    x = 680; 
  }
  pipeRect->x = this->x;
}

float Pipe::getX(){
  return x;
}

float Pipe::getY(){
  return y; 
}

