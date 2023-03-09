#pragma once
#include "MoveComponent.h"
#include <SDL_stdinc.h>
#include <SDL_scancode.h>

class InputComponent : public MoveComponent
{

public:

	InputComponent(Actor* ownerP);
	InputComponent() = delete;
	InputComponent(const InputComponent&) = delete;
	InputComponent& operator=(const InputComponent&) = delete;

	// Old controls system

	//void processInput(const Uint8* keyState);
	/*void setForwardKey(int key);
	void setBackKey(int key);
	void setClockwiseKey(int key);
	void setCounterClockwiseKey(int key);*/

	void processInput(const struct InputState& inputState);
	void setForwardKey(SDL_Scancode key);
	void setBackKey(SDL_Scancode key);
	void setClockwiseKey(SDL_Scancode key);
	void setCounterClockwiseKey(SDL_Scancode key);

	void setMaxForwardSpeed(float maxForwardSpeedP);
	void setMaxAngularSpeed(float maxAngularSpeedP);
	

private:

	float maxForwardSpeed;
	float maxAngularSpeed;

	// Old control system

	/*int forwardKey;
	int backKey;
	int clockwiseKey;
	int counterClockwiseKey;*/

	SDL_Scancode forwardKey;
	SDL_Scancode backKey;
	SDL_Scancode clockwiseKey;
	SDL_Scancode counterClockwiseKey;
};