#include "text.hpp"
#include <SDL.h>
#include <SDL_ttf.h>

// Iniitialize the text
if (TTF_Init() == -1) {
    // Handle the error
    fprintf(stderr, "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    return 1;
}

Text::Text(float _x, float _y) {
  this->x = _x;
  this->y = _y;
  textRect = new SDL_Rect();
  textRect->x = _x;
  textRect->y = _y;
  textRect->h = 50;
  textRect->w = 60;
}