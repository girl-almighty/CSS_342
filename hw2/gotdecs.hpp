////////////////////////////////// NODE OBJECT, "FRIENDS", HEADER FILE /////////////////////////////////

#ifndef GOT_hpp
#define GOT_hpp

#include <iostream>
#include <stdio.h>
using namespace std;

// forward declarations
class Friends
{
private:
    int season;
public:
    Friends();
    ~Friends();
    int getSeason();
    void setSeason(int ssn);
};

#endif
