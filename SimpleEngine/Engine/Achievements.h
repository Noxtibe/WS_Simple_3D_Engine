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
            if (!achieveEventOne)
            {
                std::cout << "Success achieved: First Exploration !" << std::endl;
                achieveEventOne = true;
            }
            break;
        case Event::I_SEE_YOU:
            if (!achieveEventTwo)
            {
                std::cout << "Success achieved: I See You !" << std::endl;
                achieveEventTwo = true;
            }
            break;
        case Event::INTO_THE_MIND:
            if (!achieveEventThree)
            {
                std::cout << "Success achieved: Into The Mind !" << std::endl;
                achieveEventThree = true;
            }
            break;
        default:
            break;
        }
    }

private:

    bool achieveEventOne = false;
    bool achieveEventTwo = false;
    bool achieveEventThree = false;

};