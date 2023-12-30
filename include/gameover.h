#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SDL2/SDL.h>

typedef struct {
    
    SDL_Rect rect;
} textBlock;

textBlock createTextBlock(int x, int y, int width, int height);
void renderTextBlock(SDL_Renderer *renderer, textBlock *block);
void removeTextBlock(textBlock *block);
void renderGameOver(SDL_Renderer *renderer);

#endif