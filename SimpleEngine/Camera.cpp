#include "Camera.h"
#include "MoveComponent.h"
#include "Game.h"

Camera::Camera() : Actor(), moveComponent(nullptr), player(nullptr), offset(-500.0f, 0.0f, 0.0f), up(Vector3::unitZ), pitchMovement(0.0f), yawMovement(0.0f)
{
	// Old function
	//moveComponent = new MoveComponent(this);
}

void Camera::updateActor(float deltaTime)
{
	Actor::updateActor(deltaTime);

	// Compute new camera from this actor (first test & base values)
	Vector3 cameraPos = getPosition();
	Vector3 target = player->getPosition();

	// To do with the first test
	/*Vector3 up = Vector3::unitZ;
	setPosition(player->getPosition() - player->getForward() * 100.0f);
	setPosition(Vector3(getPosition().x, getPosition().y, 100.0f));*/

	// Follow Cam

	/*Vector3 cameraPos = getPosition();
	Vector3 target = player->getPosition();
	Vector3 up = Vector3::unitZ;
	setPosition(player->getPosition() - player->getForward() * 100.0f);
	setPosition(Vector3(getPosition().x, getPosition().y, 100.0f));*/


	// Orbit Cam

	if(rotation)
	{
		Quaternion yaw{ Vector3::unitZ, yawMovement * deltaTime };
		offset = Vector3::transform(offset, yaw);
		up = Vector3::transform(up, yaw);

		Vector3 forward = -1.0f * offset;
		forward.normalize();
		Vector3 right = Vector3::cross(up, forward);
		right.normalize();

		Quaternion pitch{ right, pitchMovement * deltaTime };
		offset = Vector3::transform(offset, pitch);
		up = Vector3::transform(up, pitch);

		target = player->getPosition();
		cameraPos = target + offset;
	}

	// Matrix view
	Matrix4 view = Matrix4::createLookAt(cameraPos, target, up);
	getGame().getRenderer().setViewMatrix(view);
}


// Old camera controls wich move the player with the camera

/*void Camera::actorInput(const Uint8* keys)
{
	float forwardSpeed = 0.0f;
	float angularSpeed = 0.0f;
	// wasd movement
	if (keys[SDL_SCANCODE_W])
	{
		forwardSpeed += 300.0f;
	}
	if (keys[SDL_SCANCODE_S])
	{
		forwardSpeed -= 300.0f;
	}
	if (keys[SDL_SCANCODE_A])
	{
		angularSpeed -= Maths::twoPi;
	}
	if (keys[SDL_SCANCODE_D])
	{
		angularSpeed += Maths::twoPi;
	}

	moveComponent->setForwardSpeed(forwardSpeed);
	moveComponent->setAngularSpeed(angularSpeed);
}*/

// New controls wich the player can move apart from the camera

void Camera::actorInput(const struct InputState& inputState)
{

}

void Camera::setPitchMovement(float newPitchMovement)
{
	pitchMovement = newPitchMovement;
}

void Camera::setYawMovement(float newYawMovement)
{
	yawMovement = newYawMovement;
}

void Camera::setRotation(float newRotation)
{
	rotation = newRotation;
}