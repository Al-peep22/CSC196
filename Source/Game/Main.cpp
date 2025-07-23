#include "Audio/AudioSystem.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Transform.h"
#include "FrameWork/Actor.h"
#include "FrameWork/Scene.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Game/Player.h"
#include "Game/SpaceGame.h"
#include <fmod.hpp>  
#include <vector>
#include <iostream>
#include <SDL3/SDL.h>
#include <memory>
#include "Engine.h"

//#include <ranges>
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

//define RENDERER viper::GetEngine().GetRenderer()

int main(int argc, char* argv[]) {
    //std::unique_ptr<Time> time = std::make_unique<Time>();
    ////Time time;

    //int width = 1280;
    //int height = 1024;

    //std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
    ////Renderer renderer;
    //renderer->Initialize();
    //renderer->CreateWindow("Screen",width, height);

    //std::unique_ptr<InputSystem> input = std::make_unique<InputSystem>();
    ////InputSystem input;
    //input->Initialize();
    GetEngine().Initialize();

    // Initialize Game
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
    game->Initialize();

    //// FONT CREATION
    Font* font = new Font();
    font->Load("ka1.ttf", 20);

    //// TEXT CREATION
    Text* text = new Text(font);
    text->Create(GetEngine().GetRenderer(), "Hello World", vec3{ 1, 1, 1});

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
    

    
    /*std::vector<viper::vec2> ship_points{ 
        { 6, 0 },
        { -2, -4 },
        { -2, -6 },
        { -4, -6 },
        { -4, -2 },
        { 4, 0 },
        { -4, 2 },
        { -4, 6 },
        { -2, 6 },
        { -2, 3 },
        { 6, 0 },
        { -3, 0 },
        { -2, -4 },
        { -3, 0 },
        { -2, 3 }
    };
    viper::Model ship_Model{ ship_points, viper::vec3{ 255, 255, 255} };*/

    //std::vector<viper::vec2> sqr_points{ 
    //    viper::vec2{-5,-5}, 
    //    viper::vec2{5,-5}, 
    //    viper::vec2{5,5}, 
    //    viper::vec2{-5,5},
    //    viper::vec2{-5,-5}
    //};
    //viper::Model sqr_model{ sqr_points, viper::vec3{ 255, 255, 255} };
    //std::shared_ptr<viper::Model> model = std::make_shared<viper::Model>(sqr_points, viper::vec3{ 255, 255, 255 });
    ////viper::Model* model = new Model{ sqr_points, viper::vec3{ 255, 255, 255} };

    //Scene scene;

    //std::vector<viper::vec2> boat_points{
    //    viper::vec2{0,2},
    //    viper::vec2{0,5},
    //    viper::vec2{-3,2},
    //    viper::vec2{0,2},
    //    viper::vec2{0,1},
    //    viper::vec2{-3,1},
    //    viper::vec2{-2,-1},
    //    viper::vec2{2,-1},
    //    viper::vec2{3,1},
    //    viper::vec2{0,1}
    //};
    //viper::Model boat_Model{ boat_points, viper::vec3{ 255, 255, 255} };

    //viper::Transform transform{ {640,512}, 0 , 20 };
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
    


    //std::vector<std::unique_ptr<viper::Actor>> actors;
    ///*for (int i = 0; i < 10; i++) {
    //    viper::Transform m_transform{ {viper::random::getRandomFloat() * GetEngine().GetRenderer().GetWidth(), viper::random::getRandomFloat() * GetEngine().GetRenderer().GetHeight() },(float)viper::random::getRandomInt(360),(float)viper::random::getRandomInt(50) };
    //    std::unique_ptr<Player> player = std::make_unique<Player>(m_transform,model);
    //    scene.AddActor(std::move(player));
    //}*/
    //viper::Transform ship_transform{ {640,512}, 0 , 20 };
    //std::unique_ptr<Player> player = std::make_unique<Player>(ship_transform, ship_Model);
    //scene.AddActor(std::move(player));
    //viper::Actor actor{ transform, model};

    // initialize sounds
    //std::vector<FMOD::Sound*> sounds;

    /*GetEngine().GetAudio().AddSound("bass.wav", "bass");
    GetEngine().GetAudio().AddSound("snare.wav", "snare");
    GetEngine().GetAudio().AddSound("open-hat.wav", "openhat");
    GetEngine().GetAudio().AddSound("clap.wav", "clap");
    GetEngine().GetAudio().AddSound("cowbell.wav", "cowbell");
    GetEngine().GetAudio().AddSound("close-hat.wav", "closehat");*/

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
        stars.push_back(vec2{ random::getRandomFloat() * GetEngine().GetRenderer().GetWidth(), random::getRandomFloat() * GetEngine().GetRenderer().GetHeight() });
    }
    //vec2 v(30, 40);

    // Define a rectangle
    //SDL_FRect greenSquare{ 270, 190, 200, 200 };

    //std::vector<viper::vec2> points;
    

    //MAIN LOOP
    while (!quit) {
        //time->Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }          
        }

        GetEngine().Update();
        game->Update();

        if (GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        //// update engine systems
        //audio->Update();
        //
        ////audio->update();
        //input->Update();
        //
        /*
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

        if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            cout << "Pressed \n";
        }

        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            cout << "mouse pressed \n";
        }
        */
        //vec2 mouse = GetEngine().GetInput().GetMousePosition();
        //cout << mouse.x << " " << mouse.y << endl;
        //
        //if (input.getKeyDown(SDL_SCANCODE_A)) { transform.rotation += viper::math::degToRad(90) * time.GetDeltaTime(); }
        //if (input.getKeyDown(SDL_SCANCODE_D)) { transform.rotation -= viper::math::degToRad(90) * time.GetDeltaTime(); }
        //
        //int sqr_speed = 1;
        //
        /*if (input.getKeyDown(SDL_SCANCODE_W)) transform.position.y -= sqr_speed;
        if (input.getKeyDown(SDL_SCANCODE_S)) transform.position.y += sqr_speed;
        if (input.getKeyDown(SDL_SCANCODE_A)) transform.position.x -= sqr_speed;
        if (input.getKeyDown(SDL_SCANCODE_D)) transform.position.x += sqr_speed;*/
        /*viper::vec2 direction{ 0,0 };
        if (GetEngine().GetInput().getKeyDown(SDL_SCANCODE_W)) direction.y = -1;
        if (GetEngine().GetInput().getKeyDown(SDL_SCANCODE_S)) direction.y = 1;
        if (GetEngine().GetInput().getKeyDown(SDL_SCANCODE_A)) direction.x = -1;
        if (GetEngine().GetInput().getKeyDown(SDL_SCANCODE_D)) direction.x = 1;
        //
        if (direction.Lengthsqr() != 0) {
            direction = direction.Normalized();
        }*/
        //transform.position += (direction * sqr_speed) * time.GetDeltaTime();
        /*for (auto& actor : actors) {
            actor->Update(GetEngine().GetTime().GetDeltaTime());
        }*/

        vec3 color{0,0,0};
        GetEngine().GetRenderer().SetColor(color.x, color.y, color.z);
        GetEngine().GetRenderer().Clear();

        //// DRAW TEXT
        text->Draw(GetEngine().GetRenderer(), 40.0f, 40.0f);

        game->Draw();

        //model.Draw(renderer,input.GetMousePosition(),viper::math::halfPi * 0.5f,10.0f);
        /*scene.Draw(GetEngine().GetRenderer());
        for (auto& actor : actors) {
            actor->Draw(GetEngine().GetRenderer());
        }*/

        //sqr_model.Draw(GetEngine().GetRenderer(), GetEngine().GetInput().GetMousePosition(),GetEngine().GetTime().GetTime(), 10.0f);
        //boat_Model.Draw(GetEngine().GetRenderer(), {640,512}, GetEngine().GetTime().GetTime(), 50.0f);

        //ship_Model.Draw(GetEngine().GetRenderer(), transform); // Draws Ship (Not Actor)


        ////Draw Rainbow Line Stuff
      
        //if (GetEngine().GetInput().GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
        //    viper::vec2 position = GetEngine().GetInput().GetMousePosition();
        //    if (points.empty()) points.push_back(position);
        //    else if ((position - points.back()).Length() > 10) points.push_back(position);
        //}
        //
        //
        //for (int i = 0; i < (int)points.size() - 1; i++) {
        //    GetEngine().GetRenderer().SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
        //    GetEngine().GetRenderer().DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        //}

        vec2 star_speed{ -140.0f,0.0f };
        float length = star_speed.Length();

        for (auto& star : stars) {
            star += star_speed * GetEngine().GetTime().GetDeltaTime();
            //star = star.Add(speed);

            if (star[0] > GetEngine().GetRenderer().GetWidth()) star[0] = 0;
            if (star[0] < 0) star[0] = GetEngine().GetRenderer().GetWidth();
            GetEngine().GetRenderer().SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
            GetEngine().GetRenderer().DrawPoint(star.x, star.y);
        }

        /*for (int i = 0; i < 100; i++) {
            renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
            renderer.DrawLine(random::getRandomInt(width), random::getRandomInt(height), random::getRandomInt(width), random::getRandomInt(height));

            renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256));
            renderer.DrawPoint(v.x,v.y);
            renderer.DrawPoint(random::getRandomFloat() * width, random::getRandomFloat()* height);
        }*/
        GetEngine().GetRenderer().Present();



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

    //delete model;
    
    GetEngine().Shutdown();
    game->Shutdown();

    return 0;
}