
//basic init function
#define SDL_MAIN_HANDLED
//basic init function

#include <SDL.h>
#include <iostream>
#include "bird.hpp"
#include "pipe.hpp"
#include "ring.hpp"
#include "text.hpp"
#include <list>
#include <string>
#include <SDL_ttf.h>
#include <vector>

// Load image as a texture
SDL_Texture* loadTexture(std::string path);

// Window to render to
SDL_Renderer* gameRenderer = NULL;

int main() {
    // https://stackoverflow.com/questions/48723523/lnk2019-unresolved-external-symbol-c-sdl2-library
    //SDL_SetMainReady();

    //start of colour loop var
    int r = 255;
    int g = 0;
    int b = 0;

    bool sec1 = true;
    const static int SCREEN_HEIGHT = 480;
    const static int SCREEN_WIDTH = 640;

    SDL_Window* window;
    SDL_Renderer* renderer;

    window = SDL_CreateWindow("Flapping Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Load the font file
    // TTF_Font *font = TTF_OpenFont("font.ttf", 16);

    // Assign color and the surface to draw on
    // SDL_Color color = {0, 0, 0};
    // SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Hello World", color);
    // SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    // Load the main menu surface 
    SDL_Surface* mainMenuSurface = SDL_LoadBMP("startScreen.bmp");
    SDL_Texture* mainMenuTexture = SDL_CreateTextureFromSurface(renderer, mainMenuSurface);

    // Load the game over surface 
    SDL_Surface* gameOverSurface = SDL_LoadBMP("gameOver.bmp");
    SDL_Texture* gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverSurface);

    // Load start button surface
    SDL_Surface* startButtonSurface = SDL_LoadBMP("startButton.bmp");
    SDL_Texture* startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);

    // Load start button surface
    SDL_Surface* quitButtonSurface = SDL_LoadBMP("quit.bmp");
    SDL_Texture* quitButtonTexture = SDL_CreateTextureFromSurface(renderer, quitButtonSurface);

    // loading bird texture
    SDL_Surface* birdSurface = SDL_LoadBMP("wingUp.bmp");

    SDL_Surface* birdSurface2 = SDL_LoadBMP("wingDown.bmp");

    // Load ring texture
    SDL_Surface* ringSurface = SDL_LoadBMP("ring1.bmp");

    // Load in the background texture
    SDL_Surface* bgSurface = SDL_LoadBMP("background1.bmp");

    SDL_Texture* background = NULL;

    // Load in the pipe texture
    SDL_Surface* pipeSurface = SDL_LoadBMP("pipe_Up.bmp");

    SDL_Surface* bottomPipeSurface = SDL_LoadBMP("pipe_Down.bmp");

    SDL_Surface* pipeSurface2 = SDL_LoadBMP("pipe_Up.bmp");

    SDL_Surface* bottomPipeSurface2 = SDL_LoadBMP("pipe_Down.bmp");

    SDL_Surface* pipeSurface3 = SDL_LoadBMP("pipe_Up.bmp");

    SDL_Surface* bottomPipeSurface3 = SDL_LoadBMP("pipe_Down.bmp");


    // Did the bird surface load?
    if (birdSurface == NULL) {
        std::cout << "Bird surface not loaded" << std::endl;
    }
    if (birdSurface2 == NULL) {
        std::cout << "Bird surface 2 not loaded" << std::endl;
    }
    else {
        std::cout << "Bird surfaces loaded" << std::endl;
    }

    // Did the ring surface load?
    if (ringSurface == NULL) {
        std::cout << "Ring surface not loaded" << std::endl;
    }
    else {
        std::cout << "Ring surface loaded" << std::endl;
    }

    // Check if the pipe texture loaded
    if (pipeSurface == NULL) {
        std::cout << "Pipe surface not loaded" << std::endl;
    }
    else {
        std::cout << "Pipe surface loaded" << std::endl;
    }

    // New instance of my Bird Class
    Bird* flappy = new Bird(50, 50, 30.5, 0.1);

    // New instance of text class
    Text* counterText = new Text(120, 150);

    // New instances of my ring Class
    Ring* ring = new Ring(90, 130, 0.05);
    Ring* ring1 = new Ring(180, 130, 0.05);
    Ring* ring2 = new Ring(290, 130, 0.05);
    Ring* ring3 = new Ring(400, 130, 0.05);

    // New instances of my Pipe Class
    Pipe* Tpipe = new Pipe(670, -300, 0.05);
    Pipe* Bpipe = new Pipe(670, 200, 0.05);
    Pipe* Tpipe2 = new Pipe(Tpipe->getX() + 200, -300, 0.05);
    Pipe* Bpipe2 = new Pipe(Tpipe->getX() + 200, 200, 0.05);
    Pipe* Tpipe3 = new Pipe(Tpipe2->getX() + 200, -300, 0.05);
    Pipe* Bpipe3 = new Pipe(Tpipe2->getX() + 200, 200, 0.05);

    // Create a list to store the pipes - pushback adds elements to the list
    std::list<Pipe> pipeList;
    Pipe* pipes[] = {Tpipe, Bpipe, Tpipe2, Bpipe2, Tpipe3, Bpipe3};
    for (int i = 0; i < 6; i++) {
      pipeList.push_back(*pipes[i]);
    }

    // Create textures for for the sprites
    background = SDL_CreateTextureFromSurface(renderer, bgSurface);

    if (ring->getIsVisible() == true)
    {
        ring->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
        ring1->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
        ring2->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
        ring3->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
    }

    Tpipe->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface);
    Bpipe->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface);

    Tpipe2->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface2);
    Bpipe2->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface2);

    Tpipe3->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface3);
    Bpipe3->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface3);
 
    flappy->wingUpTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
    flappy->wingDownTexture = SDL_CreateTextureFromSurface(renderer, birdSurface2);

    bool collisionDetected = false;
  
    // Rectangle to draw background image  
    SDL_Rect* bgRect = new SDL_Rect{0, 0, 640, 480};

    // Rectangle to draw the text
    SDL_Rect* textRect = new SDL_Rect{200, 100, 100, 100};

    // Rectangle to draw quit button
    SDL_Rect* menuRect = new SDL_Rect{0, 0, 640, 480};

    // Rectangle to draw game over screen
    SDL_Rect* gameOverRect = new SDL_Rect{0, 0, 640, 480};

    // Rectangle to draw start button
    SDL_Rect* startBRect = new SDL_Rect{200, 350, 102, 49};

    // Rectangle to draw quit button
    SDL_Rect* quitBRect = new SDL_Rect{400, 350, 108, 88};

    // Important boolean conditions
    SDL_Event event;
    bool menuActive = true;
    bool space_bar_hit = false;
    bool gameOver = false;
    bool quit = false;

    // Main menu display loop
    while (menuActive == true) {
        SDL_RenderCopy(renderer, mainMenuTexture, NULL, menuRect);
        SDL_RenderCopy(renderer, startButtonTexture, NULL, startBRect);
        SDL_RenderCopy(renderer, quitButtonTexture, NULL, quitBRect);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            // User requests quit
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            // User clicks a button
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                // Get mouse position
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= startBRect->x && x <= startBRect->x + startBRect->w && y >= startBRect->y && y <= startBRect->y + startBRect->h)
                {
                    menuActive = false;
                    break;
                }
                if (x >= quitBRect->x && x <= quitBRect->x + quitBRect->w && y >= quitBRect->y && y <= quitBRect->y + quitBRect->h)
                {
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                }
            }
        }
    }

    // Main game loop
    while (!gameOver) {
        // Listen for the space bar key event
        // If the Space Bar is pressed. Call the 
        while (SDL_PollEvent(&event))
        {
            // User requests quit
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    space_bar_hit = true;
                    flappy->flyUp();
                    break;
                default:

                    break;
                }
            }
            // Not a key down - need to move on to the game loop
            break;
        }

        // If the spacebar is not hit the bird will continue to drop
        if (space_bar_hit == false) {
            flappy->flyDown();
        }
        else {
            space_bar_hit = false;
        }


        // Move the rings from right to left of screen
        ring->moveLeft();
        ring1->moveLeft();
        ring2->moveLeft();
        ring3->moveLeft();

        // Call moveLeft() on each pipe in the list
        for (auto& pipe : pipeList) {
          pipe.moveLeft();
        }

        // Count the ticks at this point
        int TimeStarted = SDL_GetTicks();

        // For loop to iterate through list of pipes and check if the the rectangles around them have collided with the birds rectangle.
        for (auto pipe = pipeList.begin(); pipe != pipeList.end(); ++pipe) {
            if (SDL_HasIntersection(flappy->birdRect, pipe->pipeRect)) {
                std::cout << "The Bird has hit the Pipe " << std::endl;
                collisionDetected = true;
                gameOver = true;

                while (gameOver) {
                    // Dislay Main menu
                    SDL_RenderCopy(renderer, gameOverTexture, NULL, gameOverRect);
                    SDL_RenderCopy(renderer, startButtonTexture, NULL, startBRect);
                    SDL_RenderCopy(renderer, quitButtonTexture, NULL, quitBRect);
                    SDL_RenderPresent(renderer);

                    // Listening for user input
                    while (SDL_PollEvent(&event)) {
                        // User requests quit
                        if (event.type == SDL_QUIT)
                        {
                            quit = true;
                        }
                        // User clicks a button
                        else if (event.type == SDL_MOUSEBUTTONDOWN)
                        {
                            // Get mouse position
                            std::cout << "Button Clicked after game over" << std::endl;
                            int x, y;
                            SDL_GetMouseState(&x, &y);
                            if (x >= startBRect->x && x <= startBRect->x + startBRect->w && y >= startBRect->y && y <= startBRect->y + startBRect->h)
                            {
                                std::cout << "Restart requested after game over" << std::endl;
                                SDL_RenderClear(renderer);
                                gameOver = false;

                                // Reset pipes
                                Tpipe->setX(670);
                                Bpipe->setX(670);

                                Tpipe2->setX(Tpipe->getX() + 200);
                                Bpipe2->setX(Tpipe->getX() + 200);

                                Tpipe3->setX(Tpipe2->getX() + 200);
                                Bpipe3->setX(Tpipe2->getX() + 200);
                              
                                break;
                            }
                            if (x >= quitBRect->x && x <= quitBRect->x + quitBRect->w && y >= quitBRect->y && y <= quitBRect->y + quitBRect->h)
                            {
                                std::cout << "Quit requested after game over" << std::endl;
                                SDL_DestroyWindow(window);
                                SDL_Quit();
                            }
                        }
                    }
                }
                
                gameOver = false;
            }
        }  


        SDL_RenderClear(renderer);

        // Background render 
        SDL_RenderCopy(renderer, background, NULL, bgRect);

        // Collision Detection between bird and ring, 
        std::vector<Ring*> rings = { ring, ring1, ring2, ring3 };

        for (auto r : rings) {
          SDL_RenderCopy(renderer, r->ringTexture, NULL, r->ringRect);
          if (SDL_HasIntersection(flappy->birdRect, r->ringRect)) {
            std::cout << "Bird has touched a ring" << std::endl;
            r->setVisible(false);
              break; // break out of the loop after the first collision is detected
          }
        }
      
        // Text render
        // SDL_RenderCopy(renderer, textTexture, NULL, textRect);

        // Bird render
          SDL_Texture* birdTexture = TimeStarted % 500 > 250 ? flappy->wingUpTexture : flappy->wingDownTexture;
          SDL_RenderCopy(renderer, birdTexture, NULL, flappy->birdRect);

          // Render all pipe pairs
          Pipe* pipes[] = { Tpipe, Bpipe, Tpipe2, Bpipe2, Tpipe3, Bpipe3 };
           for (int i = 0; i < 6; i += 2) {
              SDL_RenderCopyEx(renderer, pipes[i]->pipeTexture, NULL, pipes[i]->pipeRect, 180, NULL, SDL_FLIP_VERTICAL);
              SDL_RenderCopy(renderer, pipes[i + 1]->pipeTexture, NULL, pipes[i + 1]->pipeRect);
          }
    
          // Some comment
          SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;

}


// Tasks Todo
// [x] Commit in my new repo or overwrite an one of my old repos
// [x] Get bird to drop by gravity 
// [x] Make movement less janky
// [x] When I tab on the space bar bird goes up
// [x] Pipe scroll on the screen moving from the right to left
// [x] Get multiple pipes to scroll across the window
// [x] Randomise the height of the pipes
// [x] Bird collision with pipes
// [x] Multi ring placement
// [x] Bird collision with rings
// [x] Ring disappears on collision
// [x] Buttons to restart
// [ ] Count rings and display them
// [ ] Background sound
// [ ] Sound for ring collision 
// [ ] Get rid of white background around bird
// [ ] game over show total rings collected
// --------------------------------

