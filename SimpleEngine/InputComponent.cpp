#include "InputComponent.h"
#include <SDL_scancode.h>
#include "InputManager.h"

InputComponent::InputComponent(Actor* ownerP) :
	MoveComponent(ownerP),
	maxForwardSpeed(100.0f),
	maxAngularSpeed(1.0f),
	forwardKey(SDL_SCANCODE_W),
	backKey(SDL_SCANCODE_S),
	clockwiseKey(SDL_SCANCODE_D),
	counterClockwiseKey(SDL_SCANCODE_A)
{
}

// Old controls system


/*void InputComponent::processInput(const Uint8* keyState)
{
	float forwardSpeed = 0.0f;
	if (keyState[forwardKey])
	{
		forwardSpeed += maxForwardSpeed;
	}
	if (keyState[backKey])
	{
		forwardSpeed -= maxForwardSpeed;
	}
	setForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (keyState[clockwiseKey])
	{
		angularSpeed -= maxAngularSpeed;
	}
	if (keyState[counterClockwiseKey])
	{
		angularSpeed += maxAngularSpeed;
	}
	setAngularSpeed(angularSpeed);
}*/

// New controls system

void InputComponent::processInput(const struct InputState& inputState)
{
	float forwardSpeed = 0.0f;
	if (inputState.keyboard.getKeyState(forwardKey) == ButtonState::Held)
	{
		forwardSpeed += maxForwardSpeed;
	}
	if (inputState.keyboard.getKeyState(backKey) == ButtonState::Held)
	{
		forwardSpeed -= maxForwardSpeed;
	}
	setForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (inputState.keyboard.getKeyState(clockwiseKey) == ButtonState::Held)
	{
		angularSpeed -= maxAngularSpeed;
	}
	if (inputState.keyboard.getKeyState(counterClockwiseKey) == ButtonState::Held)
	{
		angularSpeed += maxAngularSpeed;
	}
	setAngularSpeed(angularSpeed);
}

void InputComponent::setMaxForwardSpeed(float maxForwardSpeedP)
{
	maxForwardSpeed = maxForwardSpeedP;
}

void InputComponent::setMaxAngularSpeed(float maxAngularSpeedP)
{
	maxAngularSpeed = maxAngularSpeedP;
}

// Old controls system

/*void InputComponent::setForwardKey(int key)
{
	forwardKey = key;
}

void InputComponent::setBackKey(int key)
{
	backKey = key;
}

void InputComponent::setClockwiseKey(int key)
{
	clockwiseKey = key;
}

void InputComponent::setCounterClockwiseKey(int key)
{
	counterClockwiseKey = key;
}*/

// New controls system

void InputComponent::setForwardKey(SDL_Scancode key)
{
	forwardKey = key;
}

void InputComponent::setBackKey(SDL_Scancode key)
{
	backKey = key;
}

void InputComponent::setClockwiseKey(SDL_Scancode key)
{
	clockwiseKey = key;
}

void InputComponent::setCounterClockwiseKey(SDL_Scancode key)
{
	counterClockwiseKey = key;
}