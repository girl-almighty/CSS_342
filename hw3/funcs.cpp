//////////////////////////////////// LINKED LIST METHOD DEFINITIONS ////////////////////////////////////

#include <cmath>
#include "declarations.hpp"



//------------------------------------- constructor & destructor -------------------------------------//
template <class T>
DLList<T>::DLList()
{
    head = NULL;
}

template <class T>
DLList<T>::~DLList()
{
    cout << "Goodbye." << endl;
}



//---------------------------- checks if season being added exists or not ----------------------------//

template <class T>
void DLList<T>::validAdd(T newSeason)
{
    if (insertToEnd(newSeason) == 1) // insert function returns 1 if new season was added...
        cout << "Succesfully added!" << endl; // ... so it prints this
    else // if insert function does not return one, nothing was added because season exists already...
        cout << "That season already exists! Sorry." << endl; // ... so it prints this
}


//----------------------------------- method to create 10 new nodes ----------------------------------//

template <class T>
void DLList<T>::createTen()
{
    T i;
    for(i=1; i <= 10; i++)
        insertToEnd(i); // creates season 1 - 10 nodes
}



//------------------------------------------- sort methods ------------------------------------------//

// goes through the list, inserting every node into a sorted list of earlier nodes
template <class T>
void DLList<T>::sort()
{
    node *sorted = NULL, *current = head;
    while (current != NULL)
    {
        node* next = current->next;
        current->prev = current->next = NULL; // unlinks current node from list
        // links current node to correct spot in ascendingly-sorted list
        ascendingSort(&sorted, current);
        current = next;
    }
    head = sorted;
    
    current = head;
    while(current->next != NULL)
        current = current->next;
    tail = current;
}

template <class T>
void DLList<T>::ascendingSort(node** start, node* newNode)
{
    node* current;
    
    // if list is empty
    if (*start == NULL)
        *start = newNode;
    
    // if newNode goes before head node
    else if ((*start)->something.get() > newNode->something.get())
    {
        newNode->next = *start;
        newNode->next->prev = newNode;
        *start = newNode;
    }
    else
    {
        current = *start;
        
        // traverse list for node that newNode will be inserted after
        while (current->next != NULL && current->next->something.get() < newNode->something.get())
            current = current->next;

        // insert node and update links accordingly
        newNode->next = current->next;
        if (current->next != NULL)
            newNode->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}



//------------------------------------------- linear search ------------------------------------------//

template <class T>
void DLList<T>::search(int ssn)
{
    node *current = head;
    int counter = 1;
    while (current != NULL) // traversing list to check for user season
    {
        if (current->something.get() == ssn)
        {
            cout << "Season " << ssn << " was found at CD #" << counter << endl << endl;
            printSuggestions(searchFound(counter));
            return; // exits out of function if found...
        }
        current = current->next;
        counter++;
    }
    cout << "Sorry, no such season has come out yet." << endl;
    printSuggestions(searchNotFound(ssn));//...otherwise, reaches down here
}

// ranking algorithm for when search finds the season we're looking for
// the parameter passed in is the spot/number of node at which the season was found
template <class T>
struct DLList<T>::rank* DLList<T>::searchFound(int num)
{
    node *current = head;
    rank* ranking = new rank();
    for(int counter = 1; counter < num; counter++) // sets current to the node/season found
        current = current->next;
    
    if (num == 1) // if found season = head, return the next 3 nodes
    {
        ranking->one = current->next;
        ranking->two = current->next->next;
        ranking->three = current->next->next->next;
    }
    else if (num == 2) // if found season = 2nd node, return what's after, before, after what's after
    {
        ranking->one = current->next;
        ranking->two = current->prev;
        ranking->three = current->next->next;
    }
    else if (current->next == NULL) // if found season = tail, return prev 3 nodes
    {
        ranking->one = current->prev;
        ranking->two = current->prev->prev;
        ranking->three = head;
    }
    else // if season isn't 1st/2nd/last, return what's after, before, head(in case they wanna rewatch)
    {
        ranking->one = current->next;
        ranking->two = current->prev;
        ranking->three = head;
    }
    return ranking;
}

// ranking algorithm for when the season we're looking for is not found
// parameter passed in is the season we're looking for
template <class T>
struct DLList<T>::rank* DLList<T>::searchNotFound(T input)
{
    node *current = head;
    rank *ranking = new rank();
    
    // if season would've gone before head node, return the first 3 nodes, starting with head
    if(input < head->something.get())
    {
        ranking->one = head;
        ranking->two = current->next;
        ranking->three = current->next->next;
    }
    
    // if season would've gone after tail node, return last 3 nodes, starting with tail downwards
    else if (input > tail->something.get())
    {
        ranking->one = tail;
        ranking->two = tail->prev;
        ranking->three = tail->prev->prev;
    }
    
    // if season would've gone between the head and tail nodes...
    else
    {
        while (current->next != NULL && current->next->something.get() < input)
            current = current->next; // ... look for the node it would've gone after ...
        
        // calculating the distance between the season of the node that would've been before it and the season we're looking for
        T diffCurr = abs (input - current->something.get());
        // calculating the distance between the season of the node that would've been after it and the season we're looking for
        T diffNext = abs (input - current->next->something.get());
        
        // if the node before the season we're looking for is closer...
        if (diffCurr <= diffNext)
        {
            ranking->one = current; // return that node...
            ranking->two = current->next; // ... then the node following it...
            if(ranking->one == head) // if head has been returned already...
                ranking->three = current->next->next; // return this
            else
                ranking->three = head; //..otherwise return head last, in case they wanna rewatch series
        }
        
        // if the node after the season we're looking for is closer...
        else
        {
            ranking->one = current->next; // return that node...
            ranking->two = current; // then the node before it ...
            if(ranking->two == head) // if the head's been returned already...
                ranking->three = current->next->next; // ...return this instead...
            else
                ranking->three = head; // ...otherwise return head last
        }
    }
    return ranking; // the ranks will be returned to a function that'll print it out
}

// ranks are printed out
template <class T>
void DLList<T>::printSuggestions(rank* ranks)
{
    cout << "Here are some suggestions: " << endl;
    cout << "Season " << ranks->one->something.get() << endl;
    cout << "Season " << ranks->two->something.get() << endl;
    cout << "Season " << ranks->three->something.get() << endl << endl;
}

//----------------------------------------- print out list -------------------------------------------//

template <class T>
void DLList<T>::print()
{
    cout << "Queue list:" << endl;
    node *current = head;
    while (current != NULL) // traverses list, printing every node's season
    {
        cout << "Season " << current->something.get() << endl;
        current = current->next;
    }
}

