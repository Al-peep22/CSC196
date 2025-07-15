#include "../Engine/Math/Math.h"
#include "../Engine/Math/Vector2.h"
#include "../Engine/Core/Random.h"
#include "../Engine/Core/Time.h"
#include <vector>
#include <iostream>
#include <SDL3/SDL.h>
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Renderer/Model.h"
#include "../Engine/Input/InputSystem.h"
//#include <ranges>
#include <fmod.hpp>  
#include "../Engine/Audio/AudioSystem.h"

//#include "Audio/AudioSystem.h"

// Ensure the file "../Engine/Audio/AudioSystem.h" exists in the specified path relative to the current file.  
// If the file is missing, create it with the necessary content or verify the path is correct.  

// Example content for "../Engine/Audio/AudioSystem.h" if missing:  
// ResponseType: Code  
// File: Source/Engine/Audio/AudioSystem.h  
// Content:  
//
//#include "../Engine/Audio/AudioSystem.h"
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
using namespace std;
using namespace viper;

int main(int argc, char* argv[]) {
    Time time;
    Renderer renderer;

    int width = 1280;
    int height = 1024;

    renderer.Initialize();
    renderer.CreateWindow("Screen",width, height);

    InputSystem input;
    input.Initialize();


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

    // create audio system
    viper::AudioSystem audio;
    audio.Initialize();

    std::vector<viper::vec2> sqr_points{ 
        viper::vec2{-5,-5}, 
        viper::vec2{5,-5}, 
        viper::vec2{5,5}, 
        viper::vec2{-5,5},
        viper::vec2{-5,-5}
    };
    viper::Model model{ sqr_points, viper::vec3{ 255, 255, 255} };

    std::vector<viper::vec2> boat_points{
        viper::vec2{0,2},
        viper::vec2{0,5},
        viper::vec2{-3,2},
        viper::vec2{0,2},
        viper::vec2{0,1},
        viper::vec2{-3,1},
        viper::vec2{-2,-1},
        viper::vec2{2,-1},
        viper::vec2{3,1},
        viper::vec2{0,1}
    };
    viper::Model boat_Model{ boat_points, viper::vec3{ 255, 255, 255} };

    /*FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);*/
    //
    //FMOD::Sound* sound = nullptr;
    //
    //
    //audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);
    //
    //audio->playSound(sound, 0, false, nullptr);
    

    // initialize sounds
    //std::vector<FMOD::Sound*> sounds;

    audio.AddSound("bass.wav", "bass");
    audio.AddSound("snare.wav", "snare");
    audio.AddSound("open-hat.wav", "openhat");
    audio.AddSound("clap.wav", "clap");
    audio.AddSound("cowbell.wav", "cowbell");
    audio.AddSound("close-hat.wav", "closehat");

    //audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
   /* sounds.push_back(sound);

    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("cowbell.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
        sounds.push_back(sound);*/

    //create stars
    vector<vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{ random::getRandomFloat() * 1280, random::getRandomFloat() * 1024 });
    }
    //vec2 v(30, 40);

    // Define a rectangle
    //SDL_FRect greenSquare{ 270, 190, 200, 200 };

    std::vector<viper::vec2> points;
    //MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }          
        }

        if (input.GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        // update engine systems
        audio.Update();

        //audio->update();


        if (input.getKeyDown(SDL_SCANCODE_Q) && !input.getPrevKeyDown(SDL_SCANCODE_Q))
        {
            // play bass sound, vector elements can be accessed like an array with [#]
            audio.PlaySound("bass");
        }

        if (input.getKeyDown(SDL_SCANCODE_W) && !input.getPrevKeyDown(SDL_SCANCODE_W))
        {
            // play snare sound, vector elements can be accessed like an array with [#]
            audio.PlaySound("snare");
        }

        if (input.getKeyDown(SDL_SCANCODE_E) && !input.getPrevKeyDown(SDL_SCANCODE_E))
        {
            // play open-hat sound, vector elements can be accessed like an array with [#]
            //audio->playSound(sounds[2], nullptr, false, nullptr);
            audio.PlaySound("openhat");
        }

        if (input.getKeyDown(SDL_SCANCODE_A) && !input.getPrevKeyDown(SDL_SCANCODE_A))
        {
            // play clap sound, vector elements can be accessed like an array with [#]
            //audio->playSound(sounds[3], nullptr, false, nullptr);
            audio.PlaySound("clap");
        }

        if (input.getKeyDown(SDL_SCANCODE_S) && !input.getPrevKeyDown(SDL_SCANCODE_S))
        {
            // play cowbell sound, vector elements can be accessed like an array with [#]
            //audio->playSound(sounds[4], nullptr, false, nullptr);
            audio.PlaySound("cowbell");
        }

        if (input.getKeyDown(SDL_SCANCODE_D) && !input.getPrevKeyDown(SDL_SCANCODE_D))
        {
            // play close-hat sound, vector elements can be accessed like an array with [#]
            //audio->playSound(sounds[5], nullptr, false, nullptr);
            audio.PlaySound("closehat");
        }

        input.Update();
        if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            cout << "Pressed \n";
        }

        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            cout << "mouse pressed \n";
        }

        vec2 mouse = input.GetMousePosition();
        //cout << mouse.x << " " << mouse.y << endl;

        renderer.SetColor(0,0,0);
        renderer.Clear();

        //model.Draw(renderer,input.GetMousePosition(),viper::math::halfPi * 0.5f,10.0f);

        //model.Draw(renderer,input.GetMousePosition(),time.GetTime(), 10.0f);
        boat_Model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10.0f);


        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            viper::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }


        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        vec2 speed{ -140.0f,0.0f };
        float length = speed.Length();

        for (auto& star : stars) {
            star += speed * time.GetDeltaTime();
            //star = star.Add(speed);

            if (star[0] > width) star[0] = 0;
            if (star[0] < 0) star[0] = width;
            renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
            renderer.DrawPoint(star.x, star.y);
        }

        /*for (int i = 0; i < 100; i++) {
            renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
            renderer.DrawLine(random::getRandomInt(width), random::getRandomInt(height), random::getRandomInt(width), random::getRandomInt(height));

            renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
            renderer.DrawPoint(v.x,v.y);
            renderer.DrawPoint(random::getRandomFloat() * width, random::getRandomFloat()* height);
        }*/
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
    audio.ShutDown();

    return 0;
}