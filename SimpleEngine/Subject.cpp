#include "Subject.h"


void Subject::addObserver(Observer* obs)
{
	observers.push_back(obs);
}

void Subject::removeOserver(Observer* obs)
{
	auto iter = std::find(begin(observers), end(observers), obs);
	if (iter != end(observers))
	{
		std::iter_swap(iter, end(observers) - 1);
		observers.pop_back();
	}
}

void Subject::notify(Event event)
{
	for (auto obs : observers)
	{
		obs->onNotify(event);
	}
}