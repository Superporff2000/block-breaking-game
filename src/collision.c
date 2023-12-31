#include "collision.h"
#include "blocks.h"

int checkCollision(Ball *ball, Block *block) {

    int ballLeft = ball->rect.x;
    int ballRight = ball->rect.x + ball->rect.w;
    int ballTop = ball->rect.y;
    int ballBottom = ball->rect.y + ball->rect.h;

    int blockLeft = block->rect.x;
    int blockRight = block->rect.x + block->rect.w;
    int blockTop = block->rect.y;
    int blockBottom = block->rect.y + block->rect.h;

    int ballHitBlockTop = 0;
    int ballHitBlockLeft = 0;
    int ballHitBlockBottom = 0;
    int ballHitBlockRight = 0;

    // Check if there is no collision
    if (ballRight < blockLeft || ballLeft > blockRight || ballBottom < blockTop || ballTop > blockBottom) {

        return 0;
    }

    // Check the direction of the ball and update position accordingly

    if (ball->speedX > 0 && ballLeft < blockLeft) {    // The ball is moving to the right and to the left of block

        ball->rect.x = blockLeft - ball->rect.w;        // Move x pos of ball to left of block
        ball->speedX = -ball->speedX;                   // Invert x, which doesnt work for some godforsaken reason
       //  ball->speedY = -ball->speedY;
        /*
        ball->rect.x = 0;
        ball->rect.y = 300;
        ball->speedX = 0;
        ball->speedY = 0; */
    }

    else if (ball->speedX < 0 && ballRight > blockRight) {

        ball->rect.x = blockRight;
        ball->speedX = -ball->speedX;
    }

    if (ball->speedY > 0 && ballTop < blockTop) {

        ball->rect.y = blockTop - ball->rect.h;
        ball->speedY = -ball->speedY;
    }

    else if (ball->speedY < 0 && ballBottom > blockBottom) {
        
        ball->rect.y = blockBottom;
        ball->speedY = -ball->speedY;
    }
    
    decreaseBlockHealth(block);
    return 1;
}

void handleBallWindowBounds(Ball *ball, int screenWidth, int screenHeight) {

    int ballHitTopBound = ball->rect.y < 0;
    int ballHitLeftBound = ball->rect.x < 0;
    int ballHitRightBound = (ball->rect.x + ball->rect.w) > screenWidth;

    if (ballHitTopBound) {

        ball->rect.y = 0;
        ball->speedY = -ball->speedY; // Reverse the Y direction
    }

    if (ballHitLeftBound) {

        ball->rect.x = 0;
        ball->speedX = -ball->speedX; // Reverse the X direction
    }

    if (ballHitRightBound) {

        ball->rect.x = screenWidth - ball->rect.w;
        ball->speedX = -ball->speedX;
    }
}

void handleMovableBlockWindowBounds(Block *block, int screenWidth) {

    int movableBlockHitLeftBound = block->rect.x < 0;
    int movableBlockHitRightBound = (block->rect.x + block->rect.w) > screenWidth;

    if (movableBlockHitLeftBound) {

        block->rect.x = 0;
    }

    if (movableBlockHitRightBound) {

        block->rect.x = screenWidth - block->rect.w;
    }
}