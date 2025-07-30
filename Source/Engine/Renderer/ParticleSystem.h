#pragma once
#include <vector>
#include "../Math/Vector3.h"
#include "../Math/Vector2.h"
#include "Renderer.h"

namespace viper {
	class Particle {
	public:
		bool active{ false };
		float lifespan;

		vec2 position;
		vec2 velocity;
		vec3 color;
	};

	class ParticleSystem {
	public:
		ParticleSystem() = default;

		bool Initialize();
		void ShutDown();

		void Update(float dt);
		void Draw(class Renderer& renderer);

		void AddParticle(Particle particle);
	private:
		Particle* GetFreeParticle();
	private:
		std::vector<Particle> particles;
	};
}