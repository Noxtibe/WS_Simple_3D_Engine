/*#include "Astroid.h"
#include <Engine/Utilitaire/Random.h>
#include <Engine/Window.h>
#include <Engine/Maths/Maths.h>
#include <Engine/ActorsComponents/SpriteComponent.h>
#include <Engine/ActorsComponents/MoveComponent.h>
#include <Engine/AssetsManager/Assets.h>
#include <Engine/Game.h>

/*Astroid::Astroid() : Actor()
{
	Vector2 randPos = Random::getVector(Vector2::zero, Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));
	setPosition(randPos);
	setRotation(Random::getFloatRange(0.0f, Maths::twoPi));

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Astroid"));
	MoveComponent* mc = new MoveComponent(this);
	mc->setForwardSpeed(150.0f);

	collision = new CircleCollisionComponent(this);
	collision->setRadius(40.0f);

	getGame().addAstroid(this);
}

Astroid::~Astroid()
{
	getGame().removeAstroid(this);
}
*/
