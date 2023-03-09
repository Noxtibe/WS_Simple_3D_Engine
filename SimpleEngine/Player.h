#pragma once
#include "Actor.h"

class Player : public Actor
{
public:

	Player();

	//void updateActor(float deltaTime) override;
	void actorInput(const struct InputState& inputState) override;
	//void actorInput(const Uint8* keys) override;

private:

	class MoveComponent* moveComponent;
	class MeshComponent* playerSphere;

	float sensitiveRota = Maths::twoPi;
};


