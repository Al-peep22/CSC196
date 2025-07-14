#include "AudioSystem.h"
#include <iostream>
#include "../ThirdParty/fmod/core/inc/fmod_errors.h"

using namespace std;
namespace viper {

    bool AudioSystem::CheckFMODResult(FMOD_RESULT result)
    {
        return false;
    }

    bool viper::AudioSystem::Initialize()
    {
        FMOD_RESULT result = FMOD::System_Create(&system);
        if (result != FMOD_OK) {
            std::cerr << FMOD_ErrorString(result) << std::endl;
            return true;
        }

        void* extradriverdat = nullptr;
        result = system->init(32, FMOD_INIT_NORMAL, extradriverdat);
        if (result != FMOD_OK) {
            std::cerr << FMOD_ErrorString(result) << std::endl;
        }

    }

    void viper::AudioSystem::ShutDown()
    {
        CheckFMODResult(system->release());
    }

    void viper::AudioSystem::Update()
    {
        CheckFMODResult(system->update());
    }
    
    bool AudioSystem::AddSound(std::string& filename, const std::string& name)
    {
        return false;
    }

    bool AudioSystem::PlaySound(const std::string& name)
    {
        return false;
    }

}