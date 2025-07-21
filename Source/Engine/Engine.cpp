#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

namespace viper {
    bool Engine::Initialize()
    {
        this->renderer = std::make_unique<Renderer>();
        this->renderer->Initialize();
        this->renderer->CreateWindow("Screen", this->width, this->height);

        this->input = std::make_unique<InputSystem>();
        input->Initialize();

        this->audio = std::make_unique<AudioSystem>();
        this->audio->Initialize();

        return true;
    }

    void Engine::Shutdown()
    {
        this->renderer->ShutDown();
        this->input->ShutDown();
        this->audio->ShutDown();
    }

    void Engine::Update()
    {
        this->time.Tick();
        this->input->Update();
        this->audio->Update();

    }

    void Engine::Draw()
    {

    }

    Engine& GetEngine()
    {
        static Engine engine;
        return engine;
    }
}