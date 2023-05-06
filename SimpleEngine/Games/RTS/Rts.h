#pragma once
#include <Engine/Game.h>

void launch()
{
	auto& game = Game::instance();
	bool is_game_init = game.initialize("RTS", 1920, 1080, Color::black);

	if (is_game_init)
	{
		game.loadScene(new StoneshardScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}