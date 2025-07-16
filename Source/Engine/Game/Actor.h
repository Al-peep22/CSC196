#pragma once
#include "../Math/Transform.h"
//#include "../Renderer/Model.h"

namespace viper {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform transform, class Model* model) : 
			transform{ transform }, 
			model{ model } {}

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return transform; }

	protected:
		Transform transform;
		Model* model;
	};
}