#include "Enemy.h"
#include "Engine.h"
#include "./FrameWork/Scene.h"
#include "Player.h"
#include "FrameWork/Game.h"
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

	Actor::Update(dt);

	transform.position.x = math::wrap(transform.position.x, 0.0f, (float)GetEngine().GetRenderer().GetWidth());
	transform.position.y = math::wrap(transform.position.y, 0.0f, (float)GetEngine().GetRenderer().GetHeight());
}

void Enemy::OnCollision(Actor* other)
{
	if (other->tag != tag) {
		destroyed = true;
		scene->GetGame()->AddPoints(100);
		//game->AddPoints(100);
	}
}
