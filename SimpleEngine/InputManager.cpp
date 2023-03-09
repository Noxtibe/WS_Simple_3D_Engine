#include "InputManager.h"
#include "Vector2.h"
#include <SDL_keyboard.h>
#include <cstring>
#include <SDL_mouse.h>

InputManager::InputManager() : inputState()
{
}

bool InputManager::initialize()
{
	// Keyboard
	// Assign current state pointer
	inputState.keyboard.currentState = SDL_GetKeyboardState(nullptr);
	// Clear previous state memory
	memset(inputState.keyboard.previousState, 0, SDL_NUM_SCANCODES);

	// Mouse (just set everything to 0)
	inputState.mouse.currentButtons = 0;
	inputState.mouse.previousButtons = 0;

	return true;
}

void InputManager::close()
{
}

bool InputManager::processEvent(SDL_Event& event)
{
	bool isRunning = true;
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEWHEEL:
		inputState.mouse.scrollWheel = Vector2(
			static_cast<float>(event.wheel.x),
			static_cast<float>(event.wheel.y));
		break;
	default:
		break;
	}
	return isRunning;
}

void InputManager::preUpdate()
{
	// Copy current state to previous
	// Keyboard
	memcpy(inputState.keyboard.previousState, inputState.keyboard.currentState, SDL_NUM_SCANCODES);
	// Mouse
	inputState.mouse.previousButtons = inputState.mouse.currentButtons;
	inputState.mouse.scrollWheel = Vector2::zero;
}

void InputManager::update()
{
	// Mouse
	int x = 0, y = 0;
	if (inputState.mouse.isRelativeMode)
	{
		inputState.mouse.currentButtons = SDL_GetRelativeMouseState(&x, &y);
	}
	else
	{
		inputState.mouse.currentButtons = SDL_GetMouseState(&x, &y);
	}

	inputState.mouse.position.x = static_cast<float>(x);
	inputState.mouse.position.y = static_cast<float>(y);


}

void InputManager::setMouseCursor(bool isCursorDisplayedP)
{
	isCursorDisplayed = isCursorDisplayedP;
	if (isCursorDisplayedP)
	{
		SDL_ShowCursor(SDL_TRUE);
	}
	else
	{
		SDL_ShowCursor(SDL_FALSE);
	}
}

void InputManager::setMouseRelativeMode(bool isMouseRelativeOnP)
{
	SDL_bool set = isMouseRelativeOnP ? SDL_TRUE : SDL_FALSE;
	SDL_SetRelativeMouseMode(set);

	inputState.mouse.isRelativeMode = isMouseRelativeOnP;
}