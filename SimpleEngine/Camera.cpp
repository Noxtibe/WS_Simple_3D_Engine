#include "Camera.h"
#include "MoveComponent.h"
#include "Game.h"

Camera::Camera() : Actor(), moveComponent(nullptr), player(nullptr)
{
	// Old function
	//moveComponent = new MoveComponent(this);

	up = Vector3::unitZ;

	// Orbit Cam

	offset = Vector3(-500.0f, 0.0f, 0.0f);
	pitchMovement = 0.0f;
	yawMovement = 0.0f;

	// Follow Cam

	horizontalDist = 350.0f;
	verticalDist = 150.0f;
	targetDist = 150.0f;
	springConst = 64.0f;

}

void Camera::updateActor(float deltaTime)
{
	Actor::updateActor(deltaTime);

	// Compute new camera from this actor (first test & base values)

	Vector3 cameraPos = getPosition();
	Vector3 target = player->getPosition();


	// Orbit Cam

	if (rotation)
	{
		// Achievement
		notify(Event::FIRST_EXPLORATION);

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

	// Follow cam
	// Calculate new camera
	
	if (followCam)
	{
		// Achievement
		notify(Event::I_SEE_YOU);

		cameraPos = getPosition();
		target = player->getPosition();
		up = Vector3::unitZ;

		setPosition(player->getPosition() - player->getForward() * 100.0f);
		setPosition(Vector3(getPosition().x, getPosition().y, 100.0f));
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
	if (rotation)
	{
		Vector2 mousePosition = inputState.mouse.getPosition();
		float x = mousePosition.x;
		float y = mousePosition.y;

		if (inputState.mouse.getButtonState(3) == ButtonState::Held && rotation)
		{
			const float maxMouseSpeed = 600.0f;
			const float maxOrbitSpeed = Maths::pi * 8;

			float newYawMovement = 0.0f;
			if (!Maths::nearZero(x))
			{
				newYawMovement = x / maxMouseSpeed;
				newYawMovement *= maxOrbitSpeed;
			}
			yawMovement = newYawMovement;

			float newPitchMovement = 0.0f;
			if (!Maths::nearZero(y))
			{
				newPitchMovement = y / maxMouseSpeed;
				newPitchMovement *= maxOrbitSpeed;
			}
			pitchMovement = newPitchMovement;
		}
	}
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

void Camera::snappingFollowCam()
{
	actualPos = calculateCamPos();
	velocity = Vector3::zero;
	Vector3 target = player->getPosition() + player->getPosition() * targetDist;

	Matrix4 view = Matrix4::createLookAt(actualPos, target, Vector3::unitZ);
	getGame().getRenderer().setViewMatrix(view);
}

void Camera::setHorizontalDist(float distance)
{
	horizontalDist = distance;
}

void Camera::setVerticalDist(float distance)
{
	verticalDist = distance;
}

void Camera::setTargetDist(float distance)
{
	targetDist = distance;
}

void Camera::setSpringConst(float springConstP)
{
	springConst = springConstP;
}

void Camera::setFollowCam(bool followCamP)
{
	followCam = followCamP;
}

Vector3 Camera::calculateCamPos() const
{
	Vector3 camPos = player->getPosition();
	camPos -= player->getForward() * horizontalDist;
	camPos += Vector3::unitZ * verticalDist;
	return camPos;
}