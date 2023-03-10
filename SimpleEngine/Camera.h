#pragma once
#include "Actor.h"
#include "Subject.h"

class Camera : public Actor, public Subject
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

	void snappingFollowCam();

	// Setters for the follow cam
	void setHorizontalDist(float distance);
	void setVerticalDist(float distance);
	void setTargetDist(float distance);
	void setSpringConst(float springConstP);
	void setFollowCam(bool followCamP);

private:

	class MoveComponent* moveComponent;
	class Player* player;

	// Parameters Orbit cam
	float yawMovement = 0.0f;
	float pitchMovement = 0.0f;
	float mouseSensitivity = 600.0f;
	bool rotation = true;

	// Parameters Follow cam
	Vector3 calculateCamPos() const;
	bool followCam = false;
	Vector3 actualPos;
	Vector3 velocity;
	float horizontalDist;
	float verticalDist;
	float targetDist;
	float springConst;

	Vector3 offset;
	Vector3 up;

};