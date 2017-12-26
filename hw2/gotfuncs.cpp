///////////////////////////// NODE OBJECT, "FRIENDS," METHOD DEFINITIONS ///////////////////////////////

#include "gotdecs.hpp"

// constructor
Friends::Friends()
{
    int season = 0;
}

// destructor
Friends::~Friends()
{
}

// getter
int Friends::getSeason()
{
    return season;
}

// setter
void Friends::setSeason(int s)
{
    season = s;
}
