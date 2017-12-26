////////////////////////////////// NODE OBJECT, "FRIENDS", HEADER FILE /////////////////////////////////

#ifndef GOT_hpp
#define GOT_hpp

#include <iostream>
#include <stdio.h>
using namespace std;

// forward declarations
template <class T>
class Obj
{
private:
    T x;
public:
    Obj();
    ~Obj();
    T get()
    {
        return x;
    }
    void set(T objData)
    {
        x = objData;
    }
};

#endif
