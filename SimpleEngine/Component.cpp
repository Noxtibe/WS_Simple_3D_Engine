#include "Component.h"
#include "Actor.h"

Component::Component(Actor* ownerP, int updateOrderP) :
	owner(*ownerP),
	updateOrder(updateOrderP)
{
	owner.addComponent(this);
}

Component::~Component()
{
	owner.removeComponent(this);
}

// Old System controls

/*void Component::processInput(const Uint8* keyState)
{

}*/

void Component::processInput(const struct InputState& inputState)
{

}

void Component::update(float dt)
{
}
