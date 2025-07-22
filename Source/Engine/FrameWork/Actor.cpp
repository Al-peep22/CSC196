#include "../FrameWork/Actor.h"
#include "../Renderer/Model.h"

namespace viper {
	void viper::Actor::Update(float dt)
	{
		transform.position += velocity * dt;
	}

	void viper::Actor::Draw(Renderer& renderer)
	{
		model->Draw(renderer, transform);

	}
}
