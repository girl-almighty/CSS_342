//----------------------- IRIS FAVOREAL / FALL '17 CSS 342 / HW1 / CPP FILE -------------------------//

#include "header.hpp"

// METHOD DEFINITIONS ARE IN HERE


//-------------------------------- CONSTRUCTOR & DESTRUCTOR ---------------------------------------//

SodaMachine::SodaMachine()
{
    numPopType = 0;
    PopType = "";
    PopSize = 0;
}

SodaMachine::~SodaMachine()
{}


//---------------------------------- CUSTOM CLASS METHODS -----------------------------------------//

// pre-condition: user input must be either 1 or 2 only.
// post-condition: 1 or 2 is returned, passed as an argument in PopType setter in main. 1=coke 2=pepsi
int SodaMachine::choosePopType()
{
    cout << "Choose the number of the pop type you would like" << endl;
    cout << "1 -> Coke" << endl << "2 -> Pepsi" << endl;
    cin >> numPopType;
    while ((numPopType != 1) && (numPopType != 2))
    {
        cout << "Incorrect input!!! Choose either 1 or 2 ONLY!!!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> numPopType;
    }
    return numPopType;
}

// pre-condition: user input must be either 16 or 24 only.
// post-condition: 16 or 24 is returned, passed as an argument in PopSize setter in main.
int SodaMachine::choosePopSize() // asks user to choose between 16 or 24 oz. for pop size
{
    cout << "What size in ounces of pop would you like? 16 or 24?" << endl;
    int x;
    cin >> x;
    while ((x != 16) && (x != 24))
    {
        cout << "Incorrect input!!! Only choose (in ounces) either 16 or 24!!!" << endl;
        cin >> x;
    }
    return x;
}

// pre-condition: must be called by SodaMachine instance
// post-condition: prints out size and type of instance calling the method
void SodaMachine::printPop()
{
    cout << PopSize << " oz. " << PopType << endl;
}


// ------------------------------------ SETTERS & GETTERS ----------------------------------------//

// pre-condition: must only take in 1 or 2, enforced by choosePopType() method passed to this in main
// post-condition: assigns 1 or 2 to instance's numPopType, and either coke/pepsi to instance's PopType
void SodaMachine::setPopType(int pop)
    {
        numPopType = pop;
        if(numPopType == 1)
            PopType = "Coke";
        else
            PopType = "Pepsi";
    }

// pre-condition: must be called by a SodaMachine instance
// post-condition: returns instance's PopType to function called in main
string SodaMachine::getPopType()
    {
        return PopType;
    }

// pre-condition: must only take in 16 or 24, enforced by choosePopSize() method passed to this in main
// post-condition: assigns 16 or 24 to instance's PopSize
void SodaMachine::setPopSize(int size)
{
    PopSize = size;
}

// pre-condition: must be called by a SodaMachine instance
// post-condition: returns instance's PopSize to function called in main
int SodaMachine::getPopSize()
{
    return PopSize;
}


//---------------------------------------- OPERATOR OVERLOADING --------------------------------------//

// pre-condition: arithmetic operand for 2 SodaMachine instances of same PopType
// post-condition: properties of 2 initial instances are added together and assigned to a new instance that is then returned to main
SodaMachine SodaMachine::operator+(const SodaMachine &SM) const
{
    SodaMachine result = *this;
    result += SM;
    return result;
}

// pre-condition: compound operand for 2 SodaMachine instances of same PopType
// post-condition: popSize of 2 initial instances are added together and assigned to first instance itself which is returned to main. 2nd instance is unchanged.
SodaMachine& SodaMachine::operator+=(const SodaMachine &SM)
{
    PopSize = PopSize + SM.PopSize;
    return *this;
}

// pre-condition: mainly used on 2nd instance itself after += is called to deplete its PopSize
// post-condition: PopSize of a reference to 2nd instance in += call is changed to 0, or PopSize of any reference to calling instance is changed to zero. (this is independent of the compound operand)
SodaMachine& SodaMachine::operator-()
{
    PopSize = 0;
    return *this;
}

// pre-condition: must be used by 2 SodaMachine instances
// post-condition: returns true ONLY if both instances are/have same PopSize and PopType
bool SodaMachine::operator==(const SodaMachine &SM) const
{
    return((PopSize == SM.PopSize) && (PopType == SM.PopType));
}
