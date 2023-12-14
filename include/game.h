#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

SDL_Window* initializeSDL(void);
SDL_Renderer* createRenderer(SDL_Window *window);

void runGameLoop(SDL_Renderer *renderer);
void cleanupSDL(SDL_Window *window, SDL_Renderer *renderer);

#endif