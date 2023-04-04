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
    void moveLeft();
    // bool collidesWith(Bird bird);
    void varyY();
    float getX();
    float getY();
    float getV();
    SDL_Texture* pipeTexture;
    SDL_Rect* pipeRect;
};