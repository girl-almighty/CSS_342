//
//  setCPP.hpp
//  HW4
//////////////////////////////////////////////////////// SET LINKED LIST HEADER FILE /////////////////////////////////////////////////////////

#ifndef setCPP_hpp
#define setCPP_hpp

#include <stdio.h>
#include "llH.hpp"

//forward declarations
template <class T>
class SetLL : public LList<T>
{
    
protected:
    
    struct key
    {
        int value;
        int counter;
        struct key *next = NULL;
    };
    key *head = NULL; // first node of set linked list
    
public:
    
    using LList<T>::insert;
    void validAdd(int vA);
    void create10(int arr[], int size);
    
    void sortK(); 
    void sortKeys(key ** sK, key * sK1);
    
    void keyLookUp(int kLU);
    void print();
    void printTop3(string x, string y);
 
};

#endif /* setCPP_hpp */
