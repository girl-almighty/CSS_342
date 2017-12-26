

////////////////////////////////////////// SET LINKED LIST CPP FILE/FUNCTION IMPLEMENTATIONS ////////////////////////////////////////////////

#include "setH.hpp"

//---------------------------------------------------- adding node alongside a key --------------------------------------------------------//

template <class T>
void SetLL<T>::validAdd(int i)
{
    if(insert(i) == 1) // if succesfully added, because value is unique
    {
        key * newK = new key(); // create new key
        newK->value = i;
        newK->counter++;;
        
        if(head == NULL) // if list empty, set new key to head
            head = newK;
        else // otherwise, add new key to end
        {
            key * cur = head;
            while (cur->next != NULL)
                cur = cur->next;
            cur->next = newK;
        }
    }
    else if (insert(i) == 0) // if node not added because value exists...
    {
        key * cur = head;
        while (cur->value != i) //... find where the key w/ same value ...
            cur = cur->next;
        cur->counter++; //... then increment
    }
    sortK();
}



//------------------------------------------------------- creates node with a key ---------------------------------------------------------//

template <class T>
void SetLL<T>::create10(int arr[], int s)
{
    for(int counter = 0; counter < s; counter++)
        validAdd(arr[counter]);
}



//---------------------------------------------------- descending sort of counters --------------------------------------------------------//

template <class T>
void SetLL<T>::sortK()
{
    key *sorted = NULL, *current = head;
    while (current != NULL)
    {
        key* next = current->next;
        current->next = NULL; // unlinks node/key from list
        sortKeys(&sorted, current); // call to method below will link node/key back to list in a sorted manner
        current = next;
    }
    head = sorted;
}

template <class T>
void SetLL<T>::sortKeys(key ** start, key * newK)
{
    key *current;
    
    if (*start == NULL)
        *start = newK;
    else if ((*start)->counter < newK->counter)
    {
        newK->next = *start;
        *start = newK;
    }
    else
    {
        current = *start;
        while (current->next != NULL && current->next->counter > newK->counter)
            current = current->next;
        newK->next = current->next;
        current->next = newK;
    }
}



//-------------------------------------------------- looks up key based on its value -------------------------------------------------------//

template <class T>
void SetLL<T>::keyLookUp(int val)
{
    for(key * cur = head; cur != NULL; cur = cur->next) // look through every node...
    {
        if(cur->value == head->value) //... if node has same value...
        {
            cout << "Key value: " << cur->value << " has counter: " << cur->counter << endl; //... print this...
            return; // ... then exit out of function
        }
    }
    cout << "No such key exists yet. Sorry." << endl; // if this is reached, value non-existent
}



//-------------------------------------------------- prints out key value/counter ---------------------------------------------------------//

template <class T>
void SetLL<T>::print()
{
    for(key * cur = head; cur != NULL; cur = cur->next) // iterate through every node, printing each one's contents
        cout << "Key value: " << cur->value << ", with counter: " << cur->counter << endl;
}


//--------------------------------------------- prints out keys with top 3 biggest counters -----------------------------------------------//

template <class T>
void SetLL<T>::printTop3(string x, string y) // takes in strings to be assigned to interpretation of key and value
{
    key * cur = head; // iterator for all top 3 counters
    
    // NOTE: list of keys is descendingly sorted, automatically
    cout << "-------------------------------" << endl;
    key * top1 = head; // so head is assigned as top 1/highest counter
    cout << "Top 1 counter(s): " << endl;
    for(cur = cur; cur != NULL && cur->counter == top1->counter; cur = cur->next) // goes through list for all keys w/ same value then prints
        cout << x << ": " << cur->value << ", " << y << ": " << cur->counter << endl;
    
    cout << "-------------------------------" << endl;
    key * top2 = cur; // iterator is now set at second highest value
    cout << "Top 2 counter(s): " << endl;
    for (cur = cur; cur != NULL && cur->counter == top2->counter; cur = cur->next) // checking list for all keys w/ same value then prints
        cout << x << ": " << cur->value << ", " << y << ": " << cur->counter << endl;
    
    cout << "-------------------------------" << endl;
    key * top3 = cur; // same as top 1 and top 2 counters
    cout << "Top 3 counter(s): " << endl;
    for (cur = cur; cur != NULL && cur->counter == top3->counter; cur = cur->next)
        cout << x << ": " << cur->value << ", " << y << ": " << cur->counter << endl;
    
    cout << "-------------------------------" << endl;
}



//------------------------------------------------------------------------------------------------------------------------------------------//


template class SetLL<Obj<int> >;
