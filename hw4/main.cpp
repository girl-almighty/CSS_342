//////////////////////////////////////////////////////////////// DRIVER FILE ///////////////////////////////////////////////////////////////

#include <iostream>
#include "setH.hpp"

int main()
{
 
    SetLL<Obj<int> > derived; // instantiation of set derived instance
    // array of ints where ints are used to create objects and keys w/ no duplicate grades
    int grades [20] = {19,20,10,12,20,16,18,16,19,8,13,19,20,19,18,14,16,17,20,20};
    
    derived.create10(grades, 20);
    cout << "Given an array of 20 grades from a Cybersecurity class," << endl;
    cout << "we parse each grade into a linked list and a set of unique grades." << endl << endl;
    
    cout << "Printing linked list: " << endl;
    derived.LList<Obj<int> >::print(); // calling base print to print out linked list
    cout << endl << "Printing set: " << endl;
    derived.print(); // calling derived print to print out set
    
    cout << endl << endl <<"Here is the key for value 20: " << endl;
    derived.keyLookUp(20); // checks if key w/ value 20 exists and prints it out
    derived.validAdd(20);
    cout << endl << "After adding another grade of 20, here is the key for value 20:" << endl;
    derived.keyLookUp(20);
    
    cout << endl << endl << "Printing set interpretation & the top 3 counters a.k.a. grades: " << endl;
    derived.printTop3("Grade", "received by amount of people");
    
    cout << endl << "Printing updated set: " << endl;
    derived.print();
    cout << endl;
    
    return 0;
}
