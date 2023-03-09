#pragma once
#include "Actor.h"

class Camera : public Actor
{

public:

	Camera();

	void updateActor(float deltaTime) override;
	//void actorInput(const Uint8* keys) override;
	void actorInput(const struct InputState& inputState) override;


	void setPlayer(class Player* playerP) { player = playerP; }

	// Getters for the orbit cam
	float getPitchMovement() const { return pitchMovement; }
	float getYawMovement() const { return yawMovement; }

	// Setters for the orbit camera
	void setPitchMovement(float newPitchMovement);
	void setYawMovement(float newYawMovement);
	void setRotation(float newRotation);


private:

	class MoveComponent* moveComponent;
	class Player* player;

	float yawMovement = 0.0f;
	float pitchMovement = 0.0f;
	bool rotation = true;

	Vector3 offset;
	Vector3 up;

};