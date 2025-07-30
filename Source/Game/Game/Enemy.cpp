#include "Enemy.h"
#include "Engine.h"
#include "./FrameWork/Scene.h"
#include "Player.h"
#include "FrameWork/Game.h"
#include "Rocket.h"
#include "GameData.h"
#include <Math/Vector3.h>
#include "Renderer/Model.h"
using namespace viper;
void Enemy::Update(float dt)
{

	Player* player = scene->GetActorByName<Player>("player");
	if (player) {
		vec2 direction{0, 0};
		direction = player->transform.position - transform.position;
		direction = direction.Normalized();
		transform.rotation = math::radToDeg(direction.Angle()); // Adjust rotation to face the player
	}

	
	vec2 direction{ 1, 0 };
	vec2 force = vec2{1,0}.Rotate(math::degToRad(transform.rotation)) * speed;
	velocity += force * dt;

	transform.position.x = math::wrap(transform.position.x, 0.0f, (float)GetEngine().GetRenderer().GetWidth());
	transform.position.y = math::wrap(transform.position.y, 0.0f, (float)GetEngine().GetRenderer().GetHeight());

	fireTimer -= dt;
	if (fireTimer <= 0) {
		fireTimer = fireTime;
		std::shared_ptr<viper::Model> rocket_model = std::make_shared<viper::Model>(GameData::rocket_points, viper::vec3{ 1, 0, 0 });
		viper::Transform transform{ this->transform.position,this->transform.rotation , 2 };
		auto rocket = std::make_unique<Rocket>(transform, rocket_model);

		rocket->speed = 500.0f;
		rocket->lifespan = 1.5f;
		rocket->name = "rocket";
		rocket->tag = "enemy";

		scene->AddActor(std::move(rocket));
	}
	

	Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other)
{
	if (other->tag != tag) {
		destroyed = true;
		scene->GetGame()->AddPoints(100);
		//game->AddPoints(100);
	}
}
