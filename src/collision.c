#include "collision.h"
#include "blocks.h"

int checkCollision(Ball *ball, Block *block)
{
    int ballLeft = ball->rect.x;
    int ballRight = ball->rect.x + ball->rect.w;
    int ballTop = ball->rect.y;
    int ballBottom = ball->rect.y + ball->rect.h;

    int blockLeft = block->rect.x;
    int blockRight = block->rect.x + block->rect.w;
    int blockTop = block->rect.y;
    int blockBottom = block->rect.y + block->rect.h;

    // Check if there is no collision
    if (ballRight < blockLeft || ballLeft > blockRight || ballBottom < blockTop || ballTop > blockBottom)
    {
        return 0;
    }

    // Check the direction of the ball and update position accordingly
    if (ball->speedX > 0 && ballLeft < blockLeft)
    {
        ball->rect.x = blockLeft - ball->rect.w;
    }
    else if (ball->speedX < 0 && ballRight > blockRight)
    {
        ball->rect.x = blockRight;
    }

    if (ball->speedY > 0 && ballTop < blockTop)
    {
        ball->rect.y = blockTop - ball->rect.h;
    }
    else if (ball->speedY < 0 && ballBottom > blockBottom)
    {
        ball->rect.y = blockBottom;
    }
    
    decreaseBlockHealth(block); // Decrease the block's health on collision
    return 1;                   // Collision detected

    return 0; // No collision
}