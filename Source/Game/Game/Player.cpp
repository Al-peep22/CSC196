#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include <SDL3/SDL_scancode.h>
#include "Math/Math.h"

using namespace viper;

void Player::Update(float dt)
{
	speed = 200;
	rotationRate = 180;

	//rotation
	float rotate = 0;
	if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;

	transform.rotation += (rotate * rotationRate) * dt;

	//thrust
	float thrust = 0;
	if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;
	if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +1;

	viper::vec2 direction{1,0};
	viper::vec2 force = direction.Rotate(viper::math::degToRad(transform.rotation))*thrust*speed;
	velocity += force * dt;

	transform.position.x = math::wrap(transform.position.x, 0.0f, (float)GetEngine().GetRenderer().GetWidth());
	transform.position.y = math::wrap(transform.position.y, 0.0f, (float)GetEngine().GetRenderer().GetHeight());

	// check fire key pressed
	//spawn rocket at player position and rotation

	Actor::Update(dt);
}
