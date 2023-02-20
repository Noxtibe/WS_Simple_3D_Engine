#pragma once
#include "Component.h"
class MoveComponent : public Component
{
public:
	MoveComponent(Actor* ownerP, int updateOrder = 10); // By default, update before other components
	MoveComponent() = delete;
	MoveComponent(const MoveComponent&) = delete;
	MoveComponent& operator=(const MoveComponent&) = delete;

	float getForwardSpeed() const { return forwardSpeed; }
	float getAngularSpeed() const { return angularSpeed; }

	void setForwardSpeed(float forwardSpeedP);
	void setAngularSpeed(float angularSpeedP);

	void update(float dt) override;


private:
	float forwardSpeed;
	float angularSpeed;

};