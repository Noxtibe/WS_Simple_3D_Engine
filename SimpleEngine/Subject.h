#pragma once
#include "Observer.h"
#include <vector>

class Subject
{

public:

	void addObserver(Observer* obs);
	void removeOserver(Observer* obs);

protected:

	void notify(Event event);

private:

	std::vector<Observer*> observers;
};