#include "pipe.hpp"

Pipe::Pipe(float _x, float _y, float _v) {
  this->x = _x;
  this->y = _y;
  this->v = _v;
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


void Pipe::moveLeft(){
  x -= v;
  if (x < -61) {
    x = 680;
  }
}

float Pipe::getX(){
  return x;
}

float Pipe::getY(){
  return y; 
}

float Pipe::getV(){
  return v;
}