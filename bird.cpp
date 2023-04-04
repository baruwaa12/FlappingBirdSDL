#include "bird.hpp"
#include <SDL.h>
#include <iostream>
#include "pipe.hpp"

Bird::Bird(float _x, float _y, float _v, float _g) {
  this->x = _x;
  this->y = _y;
  this->v = _v;
  this->g = _g;
  birdRect = new SDL_Rect();
  birdRect->x = _x;
  birdRect->y = _y;
  birdRect->h = 32;
  birdRect->w = 32;
}

// bool Bird::collisionDetected

void Bird::flyUp(){
  this->y = this-> y - this->v;
  this->birdRect->y = this->y;
}

void Bird::flyDown(){
  this->y = this-> y + this->g;  
  birdRect->y = this->y;
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