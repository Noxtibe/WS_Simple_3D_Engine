#include "Camera.h"
#include "MoveComponent.h"
#include "Game.h"

Camera::Camera() : Actor(), moveComponent(nullptr), player(nullptr)
{
	// Old function
	//moveComponent = new MoveComponent(this);

	up = Vector3::unitZ;
	setPosition(Vector3(0.0f, 0.0f, -100.0f));

	// Orbit Cam

	offset = Vector3(-500.0f, 0.0f, 0.0f);
	pitchMovement = 0.0f;
	yawMovement = 0.0f;

	// Follow Cam

	horizontalDist = 400.0f;
	verticalDist = 150.0f;
	targetDist = 150.0f;
	springConst = 64.0f;

	// First Person Cam

	maxPitch = Maths::pi / 3.0f;
	pitch = 0.0f;

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
		float dampening = 2.0f * Maths::sqrt(springConst);
		Vector3 idealPosition = calculateCamPos();
		Vector3 diff = actualPos - idealPosition;
		Vector3 accel = -springConst * diff - dampening * velocity;
		velocity += accel * deltaTime;
		actualPos += velocity * deltaTime;

		cameraPos = actualPos;
		target = player->getPosition() + player->getForward() * targetDist;
	}

	// First Person Cam

	if (firstPersonCam)
	{
		cameraPos = player->getPosition() + Vector3(0.0f, 0.0f, 50.0f);
		pitch += pitchMovement * deltaTime;
		pitch = Maths::clamp(pitch, -maxPitch, maxPitch);
		Quaternion q{ player->getRight(), pitch };
		Vector3 viewForward = Vector3::transform(player->getForward(), q);

		target = cameraPos + viewForward * 100.0f;
		up = Vector3::transform(Vector3::unitZ, q);
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

		if (rotation)
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
	// Achievement
	if (rotation)
	{
		notify(Event::FIRST_EXPLORATION);
	}
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
	// Achievement
	if (followCam)
	{
		notify(Event::I_SEE_YOU);
	}
	snappingFollowCam();
	up = Vector3::unitZ;
}

void Camera::setMaxPitch(float pitch)
{
	maxPitch = pitch;
}

void Camera::setFirstPersonCam(bool firstPersonCamP)
{
	firstPersonCam = firstPersonCamP;
	// Achievement
	if (firstPersonCam)
	{
		notify(Event::INTO_THE_MIND);
	}
}

Vector3 Camera::calculateCamPos() const
{
	Vector3 camPos = player->getPosition();
	camPos -= player->getForward() * horizontalDist;
	camPos += Vector3::unitZ * verticalDist;
	return camPos;
}