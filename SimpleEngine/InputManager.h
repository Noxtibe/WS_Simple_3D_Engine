#pragma once
#include "KeyboardState.h"
#include "MouseState.h"
#include <SDL_events.h>

enum class ButtonState
{
	None,
	Pressed,
	Released,
	Held
};

struct InputState
{
	KeyboardState keyboard;
	MouseState mouse;
};

class InputManager
{

public:

	InputManager();

	bool initialize();
	void close();

	const InputState getInputState() const { return inputState; }

	bool processEvent(SDL_Event& event); // Returns isRunning status
	void preUpdate();
	void update();

	bool getIsCursorDisplayed() const { return isCursorDisplayed; }
	void setMouseCursor(bool isCursorDisplayedP);
	void setMouseRelativeMode(bool isMouseRelativeOnP);

private:

	InputState inputState;
	bool isCursorDisplayed;
};