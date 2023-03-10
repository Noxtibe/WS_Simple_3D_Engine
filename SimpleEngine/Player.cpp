#include "Player.h"
#include "MoveComponent.h"
#include "MeshComponent.h"
#include "Game.h"
#include "Sphere.h"
#include "Assets.h"

Player::Player() : Actor()//, moveComponent(nullptr)
{
	moveComponent = new MoveComponent(this);
	playerSphere = new MeshComponent(this);
	playerSphere->setMesh(Assets::getMesh("Mesh_Sphere"));
}

/*void Player::updateActor(float deltaTime)
{
	Actor::updateActor(deltaTime);

	// Compute new camera from this actor
	Vector3 cameraPos = getPosition();
	Vector3 target = getPosition() + getForward() * 100.0f;
	Vector3 up = Vector3::unitZ;

	Matrix4 view = Matrix4::createLookAt(cameraPos, target, up);
	getGame().getRenderer().setViewMatrix(view);
}*/

// Old controls system

/*void Player::actorInput(const Uint8* keys)
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

void Player::actorInput(const struct InputState& inputState)
{
	float forwardSpeed = 0.0f;
	float angularSpeed = 0.0f;
	// wasd movement
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_W))
	{
		forwardSpeed += 300.0f;
	}
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_S))
	{
		forwardSpeed -= 300.0f;
	}
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_A))
	{
		angularSpeed -= sensitiveRota;
	}
	if (inputState.keyboard.getKeyValue(SDL_SCANCODE_D))
	{
		angularSpeed += sensitiveRota;
	}

	moveComponent->setForwardSpeed(forwardSpeed);
	moveComponent->setAngularSpeed(angularSpeed);

	/*Vector2 mousePosition = inputState.mouse.getPosition();
	float x = mousePosition.x;
	float y = mousePosition.y;
	if (inputState.mouse.getButtonState(3) == ButtonState::Held)
	{
		const float maxMouseSpeed = 500.0f;
		const float maxOrbitSpeed = Maths::pi * 8;
		float newYawSpeed = 0.0f;
		if (!Maths::nearZero(x))
		{
			newYawMovement = x / maxMouseSpeed;
			newYawMovement *= maxOrbitSpeed;
		}
		getGame().getCamera()->setYawMovement(newYawMovement);
		//yawMovement = newYawMovement;
		float newPitchMovement = 0.0f;
		if (!Maths::nearZero(y))
		{
			newPitchMovement = y / maxMouseSpeed;
			newPitchMovement *= maxOrbitSpeed;
		}
		getGame().getCamera()->setPitchMovement(newPitchMovement);
		pitchMovement = newPitchMovement;
	}*/
}