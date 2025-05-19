#include <SDL2/SDL.h>
#include <stdio.h>
#include <Time.hpp>

#include "classes/Player.h"
#include "utils/math.hpp"
using namespace Math;

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500


int main(int argc, char** argv){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Player Class Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == nullptr) {
        printf("Error creating window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        return 1;
    }

    bool running = true;
    Player player(0, 0, 50, 50, 5);

    SDL_Event event;
    
    Time::timeInit();
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            player.handleInput(event);
        }
        Time::frameStart();
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        player.update(Time::deltaTime);
        player.render(renderer);
        
        SDL_RenderPresent(renderer);
        Time::frameEnd();
    }    
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

