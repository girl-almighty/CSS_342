/////////////////////////////////// LINKED LIST OBJECT HEADER FILE /////////////////////////////////////

#ifndef ll_hpp
#define ll_hpp

#include <iostream>
#include "gotdecs.hpp"
using namespace std;


// forward declarations
class DLList
{
    
private:
    struct node
    {
        Friends Frnds;
        node *next = NULL, *prev = NULL;
    };
    
    node *head = NULL;
    node *tail = NULL;

public:
    DLList();
    ~DLList();
    
    void popUpMenu();
    int insertToEnd();
    void sort(int num);
    void ascendingSort(node **n1, node *n2);
    void descendingSort(node **n1, node *n2);
    void search();
    void print();
    void exit();
};


#endif
