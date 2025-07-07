#include "../Engine/Math/Math.h"
#include "../Engine/Math/Vector2.h"
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
#include "../Engine/Renderer/Renderer.h"

int main(int argc, char* argv[]) {
    Renderer renderer;

    int width = 1280;
    int height = 1024;

    renderer.Initialize();
    renderer.CreateWindow("Screen",width, height);

    /*SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", width, height, 0);
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
    }*/

    SDL_Event e;
    bool quit = false;

    vec2 v(30, 40);

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        renderer.SetColor(0,0,0);
        renderer.Clear();

        renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
        renderer.DrawLine(random::getRandomInt(width), random::getRandomInt(height), random::getRandomInt(width), random::getRandomInt(height));

        renderer.Present();



        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
        //SDL_RenderClear(renderer); // Clear the renderer

        //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        //SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle

        ////Random Lines
        //for (int i = 0; i < 10; i++) {
        //    // Set color            
        //    SDL_SetRenderDrawColor(renderer, random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);

        //    // Draw line
        //    SDL_RenderLine(renderer, random::getRandomInt(width), random::getRandomInt(height), random::getRandomInt(width), random::getRandomInt(height));
        //}

        ////Random Points
        //for (int i = 0; i < 20; i++) {
        //    // Set color
        //    SDL_SetRenderDrawColor(renderer, random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);
        //    
        //    // Draw point
        //    SDL_RenderPoint(renderer, random::getRandomInt(width), random::getRandomInt(height));
        //}

        //SDL_RenderPresent(renderer); // Render the screen
    }

    /*SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();*/

    renderer.ShutDown();

    return 0;
}