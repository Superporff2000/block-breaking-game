#ifndef BLOCKS_H
#define BLOCKS_H


#include <SDL2/SDL.h>

typedef struct {
    
    SDL_Rect rect;
    int health;
    int isVisible;
} Block;

typedef struct {

    SDL_Rect rect;
    int speedX;
    int speedY;
} Ball;

Block createBlock(int x, int y, int width, int height, int health);
void renderBlock(SDL_Renderer* renderer, Block* block);

Ball createBall(int x, int y, int radius, int speedX, int speedY);
void renderBall(SDL_Renderer* renderer, Ball* ball);
void updateBallPosition(Ball* ball, int screenWidth, int screenHeight);

void decreaseBlockHealth(Block *block);

#endif