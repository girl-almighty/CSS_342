//////////////////////////////////////////////////// LINKED LIST METHOD DEFINITIONS /////////////////////////////////////////////////////////

#include <cmath>
#include "llH.hpp"

using namespace std;

//------------------------------------- constructor & destructor -------------------------------------//

template <class T>
LList<T>::LList() {}

template <class T>
LList<T>::~LList()
{
    cout << "Goodbye." << endl;
}



//---------------------------- checks if season being added exists or not ----------------------------//

template <class T>
void LList<T>::validAdd(int newInt)
{
    if (insert(newInt) == 1) // insert function returns 1 if new season was added...
        cout << "Succesfully added!" << endl; // ... so it prints this
    else // if insert function does not return one, nothing was added because season exists already...
        cout << "That season already exists! Sorry." << endl; // ... so it prints this
}

template <class T>
int LList<T>::insert(int newInt) // every time something, is added the list is ascendingly sorted
{
    node *newNode = new node();
    node *current = head;
    newNode->something.set(newInt); // setting user input to season data of new node object
    
    if (head == NULL) // if list is empty, newNode is the head of list
    {
        head = newNode;
        sort();
        return 1;
    }
    else if (head->something.get() == newInt) // if newNode's season = head's season, print warning
        return 0;
    else // if more than one node exists...
    {
        while(current->next != NULL) // ...check rest of the list if a node's season = newNode's season
        {
            if(current->next->something.get() == newInt)
                return 0;
            current = current->next;
        }
        // if no node has the same season as newNode, do the rest of the method:
        current->next = newNode;
        newNode->prev = current;
        sort();
        return 1;
    }
}



//------------------------------------- delete node if it exists -------------------------------------//

template <class T>
bool LList<T>::deleteItem(int num)
{
    node *current;
    for (current = head; current != NULL; current = current->next) // visit each node
    {
        if (current->something.get() == num) // if found...
        {
            if (current->prev == NULL) // ... remove from beginning by fixing beginning pointer
                head = current->next;
            else if(current->next == NULL)  // ... remove from end
                current->prev->next = NULL;
            else // ... remove from middle
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;  // deallocate node
            return true;   // succesfully done with searching
        }
    }
    return false;  // not in the list
}



//------------------------------------------- sort methods ------------------------------------------//


template <class T>
void LList<T>::sort()// goes through the list, inserting every node into a sorted list of earlier nodes
{
    node *sorted = NULL, *current = head;
    while (current != NULL)
    {
        node* next = current->next;
        current->prev = current->next = NULL; // unlinks current node from list        
        ascendingSort(&sorted, current); // links current node to correct spot in ascendingly-sorted list
        current = next;
    }
    head = sorted;
}

template <class T>
void LList<T>::ascendingSort(node ** start, node * newNode)
{
    if (*start == NULL) // if list is empty
        *start = newNode;
    else if ((*start)->something.get() > newNode->something.get()) // if newNode goes before head node
    {
        newNode->next = *start;
        newNode->next->prev = newNode;
        *start = newNode;
    }
    else
    {
        node * current = *start;
        
        // traverse list for node that newNode will be inserted after
        while (current->next != NULL && current->next->something.get() < newNode->something.get())
            current = current->next;
        
        newNode->next = current->next; // insert node and update links accordingly
        if (current->next != NULL)
            newNode->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}



//------------------------------------------- linear search ------------------------------------------//

template <class T>
void LList<T>::search(int ssn)
{
    node *current = head;
    int counter = 1;
    while (current != NULL) // traversing list to check for user season
    {
        if (current->something.get() == ssn)
        {
            cout << "Object" << ssn << " was found at node #" << counter << endl << endl;
            return; // exits out of function if found...
        }
        current = current->next;
        counter++;
    }
    cout << "Sorry, no such object exists." << endl;}



//----------------------------------------- print out list -------------------------------------------//

template <class T>
void LList<T>::print()
{
    node *current = head;
    while (current != NULL) // traverses list, printing every node's season
    {
        cout << "Object value: " << current->something.get() << endl;
        current = current->next;
    }
}

template class LList<Obj<int> >;
