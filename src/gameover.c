#include "gameover.h"

textBlock createTextBlock(int x, int y, int width, int height) {

    textBlock block;
    block.rect.x = x;
    block.rect.y = y;
    block.rect.w = width;
    block.rect.h = height;
    return block;
}

void renderTextBlock(SDL_Renderer *renderer, textBlock *block) {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &block->rect);
}

void removeTextBlock(textBlock *block) {

    block->rect.x = 0;
    block->rect.y = 0;
    block->rect.w = 0;
    block->rect.h = 0;
}

void renderGameOver(SDL_Renderer *renderer) {

    // Define the positions and sizes for each box
    int boxWidth = 5;
    int boxHeight = 10;

    // Define the starting position for 'G'
    int startX = 90;
    int startY = 50;

    // Define the ASCII art for 'GAME OVER'
    const char *asciiArt =
        "     .!JJJYYYYYYJ~         :?JJJJJ!:         .~J7^    :?J~.       .?JJJYYYYYYYYJ~.\n"
        "   .7Y#@&GYYYYYYY!.      :J5@@B5&@#P7^     .!YB@&P?  J5@@B5!:   :J5@@#PYYYYYYYYJ~.\n"
        " :?Y&@#P7^             ^JP@@G5~.75#@#P7^   ^P@@@@@&  @@@@@@5~   !@@@@Y~           \n"
        ".^&@@@5!               7@@@&J:   :5@@@#?   ^P@@@@@@@@@@@@@@5~   ~&@@@Y~           \n"
        ".^#@@@P! .~YJJJJ?~.    7@@@@GYJJJYB@@@B7   ^P@@@&5G@@P5&@@@5~   ~&@@@B5JJJJJJJJJ~.\n"
        ".^#@@@P! .!YY5G@@GY~   7@@@@B5YYY5#@@@B7   ^P@@@B!^YJ^^&@@@5~   ~&@@@BPYYYYYYYYJ~.\n"
        ".^#@@@5!     .!@@@@Y   7@@@&J:   :P@@@B7   ^P@@@B7    ~&@@@5~   ~&@@@Y~           \n"
        ".^&@@@B5!^   .!@@@@Y   7@@@&J^   ^P@@@B7   ^P@@@B7    ~&@@@5~   ~&@@@5~           \n"
        " :J5&@@@G7   .!@@@@Y   7@@@&J^   ^P@@@B7   ^P@@@B7    ~&@@@5~   !@@@@Y~           \n"
        "   .?5#@#PJJJYP@@B5!   7@@@@J^   ^P@@@#?   ^P@@@B7    ~&@@@5~   :Y5@@B5JJJJJJJJ?~.\n"
        "     .7YYYYYYYYYJ~.    ^YYYY!.   .7YYY?~   .7YYY?^    :JYYY!:     :JYYYYYYYYYY5Y~.\n"
        "                                                                                  \n"
        "                                                                                  \n"
        "                                                                                  \n"
        "   .~7777777777!!:.    :!!!!^.   .~7!7~:     .^777777777777~:     .!777777777!:   \n"
        " .!?#@&BPPPPPGB@@P?^:  7@@@@J^   ^P@@@B?   .~?G@&BPPPPPPPPP?^   .7J&@#GPPPG#@&5!: \n"
        ".^#@@@5!     .!@@@@Y!  7@@@&J^   ^P@@@B7   ^P@@@B7             .~@@@@Y~   :J@@@&? \n"
        ".^#@@@P!     .!@@@@Y~  7@@@&J^   ^P@@@B7   ^P@@@B7             .~&@@@Y~   :J@@@&? \n"
        ".^#@@@P!     .!@@@@Y~  7@@@&J^   ^P@@@B7   ^P@@@#5777777777~:  .~&@@@GJ77!75BPP5! \n"
        ".^#@@@P!     .!@@@@Y~  7@@@&J^   ^P@@@B7   ^P@@@&BGPPPPPPPG?^  .~&@@@#GPG&@#Y~:   \n"
        ".^#@@@P!     .!@@@@Y~  7@@@&J:   :P@@@B?   ^P@@@B7             .~&@@@Y~  ?G#@&5!: \n"
        ".^#@@@P!     .!@@@@Y~  ~PB@@P?:.~?B@&BY~   ^P@@@B7             .~&@@@5~   :J@@@&? \n"
        ".^#@@@5!     .!@@@@Y^   .^PG@@P?#@&BJ~     ^P@@@B7             .~&@@@5~   :J@@@&? \n"
        ".:5G&@BY!777!7Y@@#G7:     .:5G@@&B?^       :JG#@#5777777777^.  .~@@@@5~   :J@@@&? \n"
        "   :YPPPGGGGGGPPP!.          :YG?^           :7GPPGGGGGGGGG?^  .^PPPP?^   .7PPP5! \n";

    // Iterate over each character in the ASCII art
    for (int i = 0; i < strlen(asciiArt); i++) {

        char currentChar = asciiArt[i];

        // Skip newline characters
        if (currentChar == '\n') {

            startX = 90; // Reset X position for the next line
            startY += boxHeight;
            continue;
        }

        // Skip spaces
        if (currentChar == ' ') {
            
            startX += boxWidth;
            continue;
        }

        // Create a textBlock for the current character and render it
        textBlock block = createTextBlock(startX, startY, boxWidth, boxHeight);
        renderTextBlock(renderer, &block);

        // Update the X position for the next character
        startX += boxWidth;
    }
}