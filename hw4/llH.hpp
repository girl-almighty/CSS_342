///////////////////////////////////////////////////// LINKED LIST OBJECT HEADER FILE /////////////////////////////////////////////////////////

#ifndef ll_hpp
#define ll_hpp

#include <iostream>
#include "gotdecs.hpp"

// forward declarations
template <class T>
class LList
{
protected:
    struct node
    {
        T something;
        node *next = NULL, *prev = NULL;
    };
    node *head = NULL;
    
public:
    LList();
    ~LList();
    
    void validAdd(int vA);
    int insert(int i);
    bool deleteItem(int d);
    
    void sort();
    void ascendingSort(node **aS1, node *aS2);
    
    void search(int s);
    void print();
};

#endif
