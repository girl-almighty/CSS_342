///////////////////////////////////////////// EXECUTION ///////////////////////////////////////////////

#include <iostream>
#include "declarations.hpp"

// driver
int main()
{
    cout << "Greetings! Welcome to the 'Friends' sitcom queue list." << endl;
    
    DLList dll;
    dll.popUpMenu();
    
// search() big-O analysis
// my search method is O(N) because it traverses the list of nodes whose length
// depends on user input because the user creates the nodes. at each
// node during the traversal, a constant amount of time and work is being spent
// to compare node with what the user is looking for. basically, constant work (c)
// is being done n times according to how many nodes (n) a user creates, so the
// big-O notation is O(N) + c or just O(N).
    
// ascendingSort() big-O analysis
// my ascendingSort() can be O(N) at best, or O(N^2) at worse. either way,
// both traverses the list at least one time--this initial traversal is when
// each node is unlinked from the list to be linked back into the sorted list
// of all the previously unlinked nodes. when the current node from the initial
// traversal is being inserted into the sorted list, three things can happen.
// the first two are constant work taking constant time. the node can be initialized
// to the head node if the list is empty [O(1)], or the node can be placed before
// the head node if it goes before it [O(1)]. when either of these first two conditions
// happen, the total time complexity added to the initial traversal is O(N) + c
// or just O(N). however, insertion can go a third path, which is to traverse the
// list once more to find the node after which the current node from the initial
// traversal will go to. this would mean that for every node in the initial traversal,
// another traversal can occur, resulting in a O(N^2) time complexity.
    
// descendingSort() big-O analysis
// the time complexity of this method is exactly the same as the ascendingSort()
// method for the same exact reasons. they are the same algorithm with the only
// difference of a couple comparison conditions. this is also O(N) at best, or
// O(N^2) at worst.
    
    return 0;
}
