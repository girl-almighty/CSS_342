//---------------------- IRIS FAVOREAL / FALL '17 CSS 342 / HW1 / DRIVER FILE -----------------------//

#include <iostream>
#include <string>
#include "header.hpp"

using namespace std;

// DRIVER
int main() {
    cout << "Thanks for using the Soda Machine!" << endl;
    
    SodaMachine Pop1, Pop2; // instantiation of 2 SodaMachine objects
    SodaMachine * Pop1LOC = &Pop1; // pointer to Pop1 instance's memory location
    SodaMachine * Pop2LOC = &Pop2; // pointer to Pop2 instance's memory location
    Pop1.setPopType(Pop1.choosePopType());
    Pop1.setPopSize(Pop1.choosePopSize());
    Pop2.setPopType(Pop2.choosePopType());
    Pop2.setPopSize(Pop2.choosePopSize());
    cout << endl;
    
    cout << "-------------------------------------------------" << endl;
    cout << "You ordered: " << endl;
    cout << "SKU no. " << Pop1LOC << ": ";
    Pop1.printPop();
    cout << "SKU no. " << Pop2LOC << ": ";
    Pop2.printPop();
    cout << endl;
    
    if(Pop1 == Pop2) // overloaded == checks if both have the same PopSize and PopType
        cout << "FYI, you ordered two of the same thing :)" << endl;
    if(Pop1.getPopType() == Pop2.getPopType()) // where we mix instances, only if same PopType
    {
        cout << "If you add them together (Pop1 + Pop2), you get a: ";
        SodaMachine mixer = *Pop1LOC + *Pop2LOC; // * on a pointer variable dereferences itself
        mixer.printPop();
        cout << endl;
        
        cout << "You wanna add them together? Y/N" << endl;
        char x;
        cin >> x;
        if ((x == 'y') || (x == 'Y'))
        {
            Pop1 += Pop2; // overloaded += adds the prop. of these instances together into prop. of Pop1
            -Pop2; // overloaded - : since we added Pop1 & Pop2 into Pop1, Pop2 should be empty (0 oz.)
            cout << endl << "Pop1 += Pop2 = Pop1; Pop1: ";
            Pop1.printPop();
            cout << "-Pop2: ";
            Pop2.printPop();
        }
    }
    else
        cout << "You ordered a Pepsi & a Coke..." << endl << "No good in mixing those!" << endl;
    
    cout << endl << "To summarize, you now have: " << endl;
    cout << "SKU no. " << Pop1LOC << ": ";
    Pop1.printPop();
    cout << "SKU no. " << Pop2LOC << ": ";
    Pop2.printPop();
    cout << endl << "Goodbye!" << endl << endl << endl;
    return 0;
}

