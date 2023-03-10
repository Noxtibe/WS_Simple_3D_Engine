#pragma once
#include "Observer.h"
#include <iostream>

class Achievements : public Observer
{

public:

    virtual void onNotify(Event event)
    {
        switch (event)
        {
        case Event::FIRST_EXPLORATION:
            std::cout << "Success achieved: First Exploration !" << std::endl;
            break;
        case Event::I_SEE_YOU:
            std::cout << "Success achieved: I See You !" << std::endl;
            break;
        default:
            break;
        }
    }
};