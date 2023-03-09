#pragma once
#include <vector>
#include "Actor.h"
#include "SpriteComponent.h"
#include "Window.h"
#include "Vector2.h"
#include "RendererOGL.h"
#include "Camera.h"
#include "Player.h"
#include "InputManager.h"

using std::vector;

class Game
{

public:

	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

private:

	Game() : isRunning(true), isUpdatingActors(false), player(nullptr), camera(nullptr) {}

public:

	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);
	RendererOGL& getRenderer() { return renderer; }

	// Camera
	void changeCamera(int mode);
	Camera* getCamera() { return camera; }

private:

	void processInput();
	void update(float dt);
	void render();

	bool isRunning;
	Window window;
	RendererOGL renderer;
	InputManager inputManager;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;
	Player* player;
	Camera* camera;
};

