#pragma once
#include "Actor.h"
#include "MeshComponent.h"

class Player : public Actor
{
public:

	Player();

	void updateActor(float deltaTime) override;
	void actorInput(const Uint8* keys) override;

private:

	class MoveComponent* moveComponent;
	class MeshComponent* playerSphere;
};


