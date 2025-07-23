#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include <SDL3/SDL_scancode.h>

void Player::Update(float dt)
{
	float speed = 200;
	float rotationRate = 180;

	//rotation
	float rotate = 0;
	if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_D)) rotate = +1;

	transform.rotation += (rotate * rotationRate) * dt;

	//thrust
	float thrust = 0;
	if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_W)) thrust = -1;
	if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_W)) thrust = +1;

	viper::vec2 direction{1,0};
	viper::vec2 force = direction.Rotate(viper::math::degToRad(transform.rotation))*thrust*speed;
	velocity += force * dt;

	Actor::Update(dt);

	/*if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_W)) direction.y = -1;
	if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_S)) direction.y = 1;
	if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_A)) direction.x = -1;
	if (viper::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_D)) direction.x = 1;*/

	
}
