#pragma once

enum class Event
{
	FIRST_EXPLORATION,
	I_SEE_YOU,
	INTO_THE_MIND
};

class Observer
{

public:

	virtual ~Observer() {};
	virtual void onNotify(Event event) = 0;
};