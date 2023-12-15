#include "blocks.h"
#include "collision.h"

Block createBlock(int x, int y, int width, int height, int health) {

    Block block;
    block.rect.x = x;
    block.rect.y = y;
    block.rect.w = width;
    block.rect.h = height;
    block.health = health;
    return block;
}

void renderBlock(SDL_Renderer *renderer, Block *block) {
        
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &block->rect);
}

Ball createBall(int x, int y, int radius, int speedX, int speedY) {
    
    Ball ball;
    ball.rect.x = x;
    ball.rect.y = y;
    ball.rect.w = radius * 2;
    ball.rect.h = radius * 2;
    ball.speedX = speedX;
    ball.speedY = speedY;
    return ball;
}

void renderBall(SDL_Renderer *renderer, Ball *ball) {

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &ball->rect);
}

void updateBallPosition(Ball *ball, int screenWidth, int screenHeight) {

    ball->rect.x += ball->speedX;
    ball->rect.y += ball->speedY;

    handleBallWindowBounds(ball, screenWidth, screenHeight);
}

void decreaseBlockHealth(Block *block) {

    block->health--;
}

void removeBlock(Block *block) {
    
    block->rect.x = 0;
    block->rect.y = 0;
    block->rect.w = 0;
    block->rect.h = 0;
}