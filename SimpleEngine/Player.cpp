#include "Player.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Sphere.h"
#include "Assets.h"

Player::Player() : Actor(), moveComponent(nullptr)
{
	moveComponent = new MoveComponent(this);
	playerSphere = new MeshComponent(this);
	playerSphere->setMesh(Assets::getMesh("Mesh_Sphere"));
}

void Player::updateActor(float deltaTime)
{
	Actor::updateActor(deltaTime);

	// Compute new camera from this actor
	Vector3 cameraPos = getPosition();
	Vector3 target = getPosition() + getForward() * 100.0f;
	Vector3 up = Vector3::unitZ;

	Matrix4 view = Matrix4::createLookAt(cameraPos, target, up);
	getGame().getRenderer().setViewMatrix(view);
}

void Player::actorInput(const Uint8* keys)
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
}