#include <SDL.h>


class Pipe{
  private:
    float x;
    float y;
    float v;

  public:
    Pipe(float x, float y, float v);
    void setX(float value);
    void setY(float value);
    void setV(float value);
    float getX();
    float getY();
    float getV();
    SDL_Texture* pipeUp;
    
};