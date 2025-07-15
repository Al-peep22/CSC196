#pragma once
#include "../ThirdParty/fmod/core/inc/fmod.hpp"
#include <iostream>

namespace viper {
	class AudioSystem {
	public:
		AudioSystem() = default;

		bool Initialize();
		void ShutDown();

		void Update();
		bool AddSound(std::string& filename, const std::string& name);
		bool PlaySound(const std::string& name);
	private:
		bool CheckFMODResult(FMOD_RESULT result);
	private:
		FMOD::System* system = nullptr;
	};
}