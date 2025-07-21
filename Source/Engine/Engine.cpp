#include "Engine.h"


bool viper::Engine::Initialize()
{
    this->renderer = std::make_unique<Renderer>();
    this->renderer->Initialize();
    this->renderer->CreateWindow("Screen", this->width, this->height);

    this->input = std::make_unique<InputSystem>();
    this->input->Initialize();

    this->audio = std::make_unique<AudioSystem>();
    this->audio->Initialize();

    return true;
}

void viper::Engine::Shutdown()
{
    this->renderer->Shutdown();
    this->input->Shutdown();
    this->audio->Shutdown();
}

void viper::Engine::Update()
{
    this->time.Tick();
    this->input->Update();
    this->audio->Update();

}

void viper::Engine::Draw()
{

}

Engine& viper::GetEngine()
{
    static Engine engine;
    return engine;
}
