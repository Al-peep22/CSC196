#pragma once
#include "../Math/Transform.h"
#include <memory>
//#include "../Renderer/Model.h"

namespace viper {
	class Actor {
	public:
		Actor() = default;
		Actor(const viper::Transform& transform, std::shared_ptr<class Model> model) :
			transform{ transform }, 
			model{ model } {}

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return transform; }

	protected:
		Transform transform;
		std::shared_ptr<Model> model;
		//Model* model;
	};
}