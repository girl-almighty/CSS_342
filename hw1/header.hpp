//---------------------- IRIS FAVOREAL / FALL '17 CSS 342 / HW1 / HEADER FILE -----------------------//

#ifndef main_hpp
#define main_hpp

#include <iostream>
#include <string>
using namespace std;


// Forward declarations
class SodaMachine
{
public:
    // constructor & destructor
    SodaMachine();
    ~SodaMachine();
    
    // custom class methods
    int choosePopType();
    int choosePopSize();
    void printPop();
    
    // setters & getters
    void setPopType(int pop);
    string getPopType();
    void setPopSize(int size);
    int getPopSize();
    
    // operator overloads
    bool operator==(const SodaMachine &SM) const; 
    SodaMachine operator+(const SodaMachine &SM) const;
    SodaMachine& operator+=(const SodaMachine &SM);
    SodaMachine& operator-();
    
    
private:
    int numPopType;
    string PopType;
    int PopSize;
};



#endif /* main_hpp */


