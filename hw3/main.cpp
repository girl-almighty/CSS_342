///////////////////////////////////////////// EXECUTION ///////////////////////////////////////////////

#include <iostream>
#include "declarations.hpp"
#include "funcs.cpp"

// driver
int main()
{
    cout << "Greetings! Welcome to the 'Friends' sitcom linked list." << endl << endl;
    
    DLList<int> dll; // instantiating templates with ints
    dll.createTen();
    
    cout << "Here is the linked list of all the seasons in the 'Friends' sitcom:" << endl;
    dll.print();
    
    cout << "_______________________________________________" << endl << endl;
    cout << "Demonstrating succesful search of season 4: " << endl << endl;
    dll.search(4);
    cout << "_______________________________________________" << endl << endl;
    cout << "Demonstrating search of non-existent season 11: " << endl << endl;
    dll.search(11);
    cout << "_______________________________________________" << endl << endl;
    cout << "Demonstrating of search for season 4 after adding season 0: " << endl << endl;
    cout << "Adding season 0: ";
    dll.validAdd(0);
    cout << endl << "Here's the new list: " << endl;
    dll.print();
    cout << endl << "Now searching for season 4 again: " << endl;
    dll.search(4);
    cout << "_______________________________________________" << endl << endl;


    
    
    return 0;
}
