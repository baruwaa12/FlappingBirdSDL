//basic init function
#include <SDL.h>
#include <iostream>

int main()
{
  //start of colour loop var
  int r = 255;
  int g = 0;
  int b = 0;

  bool sec1 = true;
  //end of colour loop var


  SDL_Window* window;
  SDL_Renderer* renderer;

  window = SDL_CreateWindow( "Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 2000, 2000, SDL_WINDOW_BORDERLESS);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  while (true) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(40);


    // colour loop, not the best but gets the job done.
    if (g < 255 && sec1 == true) {
      g++;
    }
    else if (g >= 255 && r > 0) {
      r -= 1;
    }
    else if (b < 255 && r <= 0) {
      b++;
    }
    
    if (b >= 255 && g > 0) {
      sec1 = false;
      g -= 1;
    }
    if (g <= 0 && sec1 == false && r < 255) {
      r++;
    }
    if (sec1 == false && r == 255) {
      if (b != 0) {
        b -= 1;
      }
      else {
        sec1 = true;
      }
    }
  }
  

  SDL_DestroyWindow( window );
  
  SDL_Quit();

  return 0;
}