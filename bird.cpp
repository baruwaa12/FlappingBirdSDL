#include "bird.hpp"
#include <SDL.h>
#include <iostream>

Bird::Bird(int x, int y){
  this->x = x;
  this->y = y;
}

void Bird::fly(){
  std::cout<<"Flying!" << std::endl;
}

void Bird::setX(int value){
  x = value;
}


void Bird::setY(int value){
  y = value;
}

int Bird::getX(){
  return x;
}

int Bird::getY(){
  return y;
}