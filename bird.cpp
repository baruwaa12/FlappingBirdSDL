#include "bird.hpp"
#include <SDL.h>
#include <iostream>
#include "pipe.hpp"

Bird::Bird(float _x, float _y, float _v, float _g) {
  this->x = _x;
  this->y = _y;
  this->v = _v;
  this->g = _g;
  birdReact = new SDL_Rect();
  birdReact->x = _x;
  birdReact->y = _y;
  birdReact->h = 32;
  birdReact->w = 32;
}

void Bird::flyUp(){
  this->y = this-> y - this->v;
  this->birdReact->y = this->y;
}

void Bird::flyDown(){
  this->y = this-> y + this->g;  
  birdReact->y = this->y;
}

void Bird::setX(float value){
  x = value;
}

void Bird::setY(float value){
  y = value;
}

void Bird::setV(float value){
  v = value;
}

void Bird::setG(float value){
  g = value;
}

float Bird::getX(){
  return x;
}

float Bird::getY(){
  return y;
}

float Bird::getG(){
  return g;
}

float Bird::getV(){
  return v;
}