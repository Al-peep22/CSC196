#pragma once
#include "../Math/Transform.h"
#include <string>
#include <memory>
//#include "../Renderer/Model.h"

namespace viper {
	class Actor {
	public:
		std::string name;
		std::string tag;

		vec2 velocity{0,0};

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
		
	};
}