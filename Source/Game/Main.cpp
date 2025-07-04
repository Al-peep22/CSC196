//#include "../Engine/Math/Math.h"
#include "../Engine/Core/Random.h"
//#include <iostream>
//
using namespace std;
using namespace viper;
//
//#define NAME "Raymond\n"
//int main() {
//	//float deg = viper::radToDeg(viper::pi);
//	math::min(5, 3);
//
//	cout << NAME;
//	cout << "Hello, World\n";
//	cout << math::pi << endl;
//
//	for (int x = 0; x < 10; x++) {
//		cout << random::getRandomFloat() << endl;
//	}
//}

#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    int height = 1280;
    int width = 1024;
    SDL_Window* window = SDL_CreateWindow("SDL3 Project", height, width, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(renderer); // Clear the renderer

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle

        //Random Lines
        for (int i = 0; i < 10; i++) {
            // Set color            
            SDL_SetRenderDrawColor(renderer, random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);

            // Draw line
            SDL_RenderLine(renderer, random::getRandomInt(height), random::getRandomInt(width), random::getRandomInt(height), random::getRandomInt(width));
        }

        for (int i = 0; i < 20; i++) {
            // Set color
            SDL_SetRenderDrawColor(renderer, random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);
            
            // Draw point
            SDL_RenderPoint(renderer, random::getRandomInt(height), random::getRandomInt(width));
        }

        SDL_RenderPresent(renderer); // Render the screen
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}