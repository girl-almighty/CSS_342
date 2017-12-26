/////////////////////////////////// LINKED LIST OBJECT HEADER FILE /////////////////////////////////////

#ifndef ll_hpp
#define ll_hpp

#include <iostream>
#include "gotdecs.hpp"
#include "gotfuncs.cpp"
using namespace std;



// forward declarations
template <class T>
class DLList
{
    
private:
    struct node
    {
        Obj<T> something;
        node *next = NULL, *prev = NULL;
    };
    struct rank
    {
        node *one = NULL, *two = NULL, *three = NULL;
    };
    node *head;
    node *tail;
    
public:
    DLList();
    ~DLList();    

    T validInput(string warn, T &input)
    {
        cout << warn << endl;
        input = 0;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> input;
        cout << endl;
        return input;
    }
    
    void validAdd(T vA);
    void createTen();
    T insertToEnd(T newData) // every time something, is added the list is ascendingly sorted
    {
        node *newNode = new node();
        node *current = head;
        newNode->something.set(newData); // setting user input to season data of new node object
        
        if (head == NULL) // if list is empty, newNode is the head of list
        {
            head = newNode;
            sort();
            return 1;
        }
        else if (head->something.get() == newData) // if newNode's season = head's season, print warning
            return 0;
        else // if more than one node exists...
        {
            while(current->next != NULL) // ...check rest of the list if a node's season = newNode's season
            {
                if(current->next->something.get() == newData)
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
    
    void sort();
    void ascendingSort(node **aS1, node *aS2);
    
    void search(int s);
    struct rank* searchFound(int sF);
    struct rank* searchNotFound(T sNF);
    void printSuggestions(rank* pS);
    
    void print();
};


#endif
