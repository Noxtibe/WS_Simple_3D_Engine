#pragma once
#include "Actor.h"

class Camera : public Actor
{

public:

	Camera();

	void updateActor(float deltaTime) override;
	void actorInput(const Uint8* keys) override;

	void setPlayer(class Player* playerP) { player = playerP; }

private:

	float yaw = 0.0f;
	float pitch = 0.0f;
	bool rotation = true;

	class MoveComponent* moveComponent;
	class Player* player;

};