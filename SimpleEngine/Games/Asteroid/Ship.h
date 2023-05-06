/*#pragma once
#include <Engine/ActorsComponents/Actor.h>
#include <SDL_stdinc.h>

class Ship : public Actor
{
public:
	Ship();

	//void actorInput(const Uint8* keyState) override;
	void actorInput(const struct InputState& inputState) override;
	void updateActor(float dt) override;


private:
	float laserCooldown;
};
*/