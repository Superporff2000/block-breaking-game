#include "blocks.h"

Block createBlock(int x, int y, int width, int height, int health) {

    Block block;
    block.rect.x = x;
    block.rect.y = y;
    block.rect.w = width;
    block.rect.h = height;
    block.health = health;
    return block;
}

void renderBlock(SDL_Renderer* renderer, Block* block) {

    if (block->isVisible) {
        
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &block->rect);
    }
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

void renderBall(SDL_Renderer* renderer, Ball* ball) {

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &ball->rect);
}

void updateBallPosition(Ball* ball, int screenWidth, int screenHeight) {

    ball->rect.x += ball->speedX;
    ball->rect.y += ball->speedY;

    // Keep ball within the left and right bounds

    if (ball->rect.x < 0) {

        ball->rect.x = 0;
        ball->speedX = -ball->speedX;       // Reverse the X direction
    }

    else if ((ball->rect.x + ball->rect.w) > screenWidth) {

        ball->rect.x = screenWidth - ball->rect.w;
        ball->speedX = -ball->speedX;
    }

    // Keep the ball within top and bottom bounds

    if (ball->rect.y < 0) {

        ball->rect.y = 0;
        ball->speedY = -ball->speedY;       // Reverse the Y direction
    }
    
    else if ((ball->rect.y + ball->rect.h) > screenHeight) {

        ball->rect.y = screenHeight - ball->rect.h;
        ball->speedY = -ball->speedY;
    }
}

void decreaseBlockHealth(Block *block) {

    block->health--;
}