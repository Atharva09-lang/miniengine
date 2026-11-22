#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // 1. Start SDL (wake up the video system)
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init failed: " << SDL_GetError() << "\n";
        return 1;
    }

    // 2. Create a window: title, position, width, height
    SDL_Window* window = SDL_CreateWindow(
        "MiniEngine",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        0
    );
    if (!window) {
        std::cout << "Window failed: " << SDL_GetError() << "\n";
        return 1;
    }

    // 3. Create a renderer (the "paintbrush" that draws in the window)
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    // 4. THE GAME LOOP: runs again and again until we quit
    bool running = true;
    while (running) {

        // 4a. INPUT: check what the player did
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;   // clicked the X button
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;   // pressed Esc
            }
        }

        // 4b. UPDATE: game logic goes here (nothing yet!)

        // 4c. RENDER: draw everything
        SDL_SetRenderDrawColor(renderer, 0, 225, 0, 255);   // dark blue-grey
        SDL_RenderClear(renderer);                            // paint the whole screen

        SDL_Rect box = { 200, 350, 50, 50 };                  // x, y, width, height
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // yellow
        SDL_RenderFillRect(renderer, &box);                   // draw the box

        SDL_RenderPresent(renderer);                          // show it on screen
    }

    // 5. Clean up (give memory back)
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}