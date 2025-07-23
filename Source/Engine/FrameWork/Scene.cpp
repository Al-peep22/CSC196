#include "Scene.h"
#include "Actor.h"
#include "../Core/StringHelper.h"
#include "Scene.h"
namespace viper{
	void Scene::Update(float dt) {
		for (auto& actor : actors) {
			actor->Update(dt);
		}
	}
	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : actors) {
			actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor)
	{
		actor->scene = this; // Set the scene for the actor
		actors.push_back(std::move(actor));
	}

	Actor* Scene::GetActorByName(const std::string& name)
	{
		for (auto& actor : actors) {
			if (toLower(actor->name) == name) {
				return actor.get();
			}
		}
		return nullptr;
	}
}