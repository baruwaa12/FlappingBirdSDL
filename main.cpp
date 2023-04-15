
//basic init function
#define SDL_MAIN_HANDLED
//basic init function

#include <SDL.h>
#include <iostream>
#include "bird.hpp"
#include "pipe.hpp"
#include "ring.hpp"
#include <list>
#include <string>

// Load image as a texture
SDL_Texture* loadTexture(std::string path);

// Window to render to
SDL_Renderer* gameRenderer = NULL;

int main(){
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

    window = SDL_CreateWindow("Flappy Chicken", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Load the main menu surface 
    SDL_Surface* mainMenuSurface = SDL_LoadBMP("startScreen.bmp");
    SDL_Texture* mainMenuTexture = SDL_CreateTextureFromSurface(renderer, mainMenuSurface);

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

    // New instance of my ring Class
    Ring* ring = new Ring(90, 130, 0.05);
    Ring* ring1 = new Ring(180, 130, 0.05);
    Ring* ring2 = new Ring(290, 130, 0.05);
    Ring* ring3 = new Ring(400, 130, 0.05);

    // New instance of my Pipe Class
    Pipe* Tpipe = new Pipe(670, -300, 0.05);
    Pipe* Bpipe = new Pipe(670, 200, 0.05);

    // 
    Pipe* Tpipe2 = new Pipe(Tpipe->getX() + 200, -300, 0.05);
    Pipe* Bpipe2 = new Pipe(Tpipe->getX() + 200, 200, 0.05);

    // 
    Pipe* Tpipe3 = new Pipe(Tpipe2->getX() + 200, -300, 0.05);
    Pipe* Bpipe3 = new Pipe(Tpipe2->getX() + 200, 200, 0.05);

    // Create a list to store the pipes - pushback adds elements to the list
    std::list<Pipe> pipeList;
    pipeList.push_back(*Tpipe);
    pipeList.push_back(*Bpipe);
    pipeList.push_back(*Tpipe2);
    pipeList.push_back(*Bpipe2);
    pipeList.push_back(*Tpipe3);
    pipeList.push_back(*Bpipe3);


    // Create textures for for the sprites
    background = SDL_CreateTextureFromSurface(renderer, bgSurface);

    if (ring->getIsVisible() == true)
    {
        ring->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
        ring1->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
        ring2->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
        ring3->ringTexture = SDL_CreateTextureFromSurface(renderer, ringSurface);
    }

    // 
    Tpipe->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface);
    Bpipe->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface);

    // 
    Tpipe2->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface2);
    Bpipe2->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface2);

    // 
    Tpipe3->pipeTexture = SDL_CreateTextureFromSurface(renderer, pipeSurface3);
    Bpipe3->pipeTexture = SDL_CreateTextureFromSurface(renderer, bottomPipeSurface3);

    // 
    flappy->wingUpTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
    flappy->wingDownTexture = SDL_CreateTextureFromSurface(renderer, birdSurface2);

    bool collisionDetected = false;
    
    // 
    SDL_Rect* bgRect = new SDL_Rect();
    bgRect->x = 0;
    bgRect->y = 0;
    bgRect->h = 480;
    bgRect->w = 640;

    // Some comment
    SDL_Rect* menuRect = new SDL_Rect();
    menuRect->x = 0;
    menuRect->y = 0;
    menuRect->h = 480;
    menuRect->w = 640;

    // Some comment
    SDL_Rect* startBRect = new SDL_Rect();
    startBRect->x = 200;
    startBRect->y = 350;
    startBRect->h = 49;
    startBRect->w = 102;

    // 
    SDL_Rect* quitBRect = new SDL_Rect();
    quitBRect->x = 400;
    quitBRect->y = 350;
    quitBRect->h = 88;
    quitBRect->w = 108;

    // Some comment
    SDL_Event event;
    bool menuActive = true;
    bool space_bar_hit = false;
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
    while (true) {
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
        // Move the pipes from right to left
        Tpipe->moveLeft();
        Bpipe->moveLeft();

        // Move the rings from right to left
        ring->moveLeft();
        ring1->moveLeft();
        ring2->moveLeft();
        ring3->moveLeft();

        Tpipe2->moveLeft();
        Bpipe2->moveLeft();

        Tpipe3->moveLeft();
        Bpipe3->moveLeft();

        // Count the ticks at this point
        int TimeStarted = SDL_GetTicks();

        // For loop to iterate through list of pipes and check if the the rectangles around them have collided with the birds rectangle.
        for (auto pipe = pipeList.begin(); pipe != pipeList.end(); ++pipe) {
            if (SDL_HasIntersection(flappy->birdRect, pipe->pipeRect)) {
                collisionDetected = true;
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
        }

        // Collision Detection between bird and ring, 
        if (SDL_HasIntersection(flappy->birdRect, ring->ringRect)) {
            std::cout << "Bird has touched a ring" << std::endl;
            ring->setVisible(false);
        }
        else if (SDL_HasIntersection(flappy->birdRect, ring1->ringRect)) {
            ring1->setVisible(false);
        }
        else if (SDL_HasIntersection(flappy->birdRect, ring2->ringRect)) {
            ring2->setVisible(false);
        }
        else if (SDL_HasIntersection(flappy->birdRect, ring3->ringRect)) {
            ring3->setVisible(false);
        }

        SDL_RenderClear(renderer);

        // Background render 
        SDL_RenderCopy(renderer, background, NULL, bgRect);

        SDL_RenderCopy(renderer, TimeStarted % 500 > 250 ? flappy->wingUpTexture : flappy->wingDownTexture, NULL, flappy->birdRect);

        // First pipe pair render
        SDL_RenderCopyEx(renderer, Tpipe->pipeTexture, NULL, Tpipe->pipeRect, 180, NULL, SDL_FLIP_VERTICAL);
        SDL_RenderCopy(renderer, Bpipe->pipeTexture, NULL, Bpipe->pipeRect);

        // Second pipe pair render
        SDL_RenderCopyEx(renderer, Tpipe2->pipeTexture, NULL, Tpipe2->pipeRect, 180, NULL, SDL_FLIP_VERTICAL);
        SDL_RenderCopy(renderer, Bpipe2->pipeTexture, NULL, Bpipe2->pipeRect);

        // Third pipe pair render
        SDL_RenderCopyEx(renderer, Tpipe3->pipeTexture, NULL, Tpipe3->pipeRect, 180, NULL, SDL_FLIP_VERTICAL);
        SDL_RenderCopy(renderer, Bpipe3->pipeTexture, NULL, Bpipe3->pipeRect);

        // Render the rings
        SDL_RenderCopy(renderer, ring->ringTexture, NULL, ring->ringRect);
        SDL_RenderCopy(renderer, ring1->ringTexture, NULL, ring1->ringRect);
        SDL_RenderCopy(renderer, ring2->ringTexture, NULL, ring2->ringRect);
        SDL_RenderCopy(renderer, ring3->ringTexture, NULL, ring3->ringRect);

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
    // [ ] Start screen and game over show total rings collected
    // [ ] Buttons to restart
    // [ ] Count rings and display them
    // [ ] Background sound
    // [ ] Sound for ring collision 
    // [ ] Get rid of white background around bird
    //
    // --------------------------------
