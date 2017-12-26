//////////////////////////////////// LINKED LIST METHOD DEFINITIONS ////////////////////////////////////

#include "declarations.hpp"



//------------------------------------- constructor & destructor -------------------------------------//

DLList::DLList()
{
    head = NULL;
}

DLList::~DLList()
{
    cout << "Goodbye." << endl;
}



//----------------------------------------- menu interface -------------------------------------------//

void DLList::popUpMenu()
{
    int choice = 0;
    
    while (choice != 6) // loops menu until user input is 6/exit
    {
        cout << endl << "What would you like to do?" << endl << endl;
        cout << "1 -> Search for a season" << endl << "2 -> Direct and add 10 seasons" << endl;
        cout << "3 -> Sort seasons ascendingly" << endl << "4 -> Sort seasons descendingly";
        cout  << endl << "5 -> See line-up" << endl << "6 -> Watch and exit" << endl;
    
        cin >> choice;
        cout << endl;
        while (choice < 1 || choice > 6) // checks user input for validity
        {
            cout << "Incorrect input!!! Choose from 1 - 6 ONLY!!!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> choice;
        }

        // prints warning when user tries to search/sort/print an empty list
        if(head == NULL)
        {
            if (choice == 1 || choice == 3 || choice == 4 || choice == 5)
            {
                cout << "Queue list is empty!" << endl;
                continue;
            }
        }
        
        switch(choice)
        {
            case 1:
                search();
                break;
            case 2:
            {
                int counter = 0;
                cout << "Let's create 10 seasons, NOW!" << endl << endl;
                while (counter != 10)
                {
                    int x = insertToEnd();
                    if (x == 1)
                    {
                        counter++;
                        cout << "[number " << counter << "]" <<  endl << endl;
                    }
                }
                break;
            }
            case 3:
                sort(0); // ascending sort
                break;
            case 4:
                sort(1); // descending sort
                break;
            case 5:
                print();
                break;
            case 6:
                exit();
                break;
        }
        
    }
}



//------------------------------- method to insert new node at list end ------------------------------//

int DLList::insertToEnd()
{
    node *newNode = new node();
    node *current = head;
    int newSeason;
 
    cout << "Type the number of season you would like to add: ";
    cin >> newSeason;
    while(!cin) // validating user input for season data for new node object
    {
        
        cout << "Incorrect input! Type a whole number: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> newSeason;
        cout << endl;
    }
    newNode->Frnds.setSeason(newSeason); // setting user input to season data of new node object
    
    if (head == NULL) // if list is empty, newNode is the head of list
    {
        head = newNode;
        cout << endl << "Succesfully added!" << endl;
        return 1;
    }
    else if (head->Frnds.getSeason() == newSeason) // if newNode's season = head's season, print warning
    {
        cout << endl << "That season already exists!" << endl;
        return 0;
    }
    else // if more than one node exists...
    {
        while(current->next != NULL) // ...check rest of the list if a node's season = newNode's season
        {
            if(current->next->Frnds.getSeason() == newSeason)
            {
                cout << endl << "That season already exists!" << endl;
                return 0; //
            }
            current = current->next;
        }
        // if no node has the same season as newNode, do the rest of the method:
        current->next = newNode;
        newNode->prev = current;
        cout << endl << "Succesfully added!" << endl;
        return 1;
    }
}



//------------------------------------------- sort methods ------------------------------------------//

// both descending and ascending sorts are done in 2 parts/methods
// both include the sort() method, as seen below

// goes through the list, inserting every node into a sorted list of earlier nodes
void DLList::sort(int sortType)
{
    node *sorted = NULL, *current = head;
    while (current != NULL)
    {
        node* next = current->next;
        current->prev = current->next = NULL; // unlinks current node from list
        if (sortType == 0)
            // links current node to correct spot in ascendingly-sorted list
            ascendingSort(&sorted, current); 
        else
            // links current node to correct spot in descendingly-sorted list
            descendingSort(&sorted, current);
        current = next;
    }
    head = sorted;
    cout << "Successfully sorted!" << endl;
}

void DLList::ascendingSort(node** start, node* newNode)
{
    node* current;

    // if list is empty
    if (*start == NULL)
        *start = newNode;
    
    // if newNode goes before head node
    else if ((*start)->Frnds.getSeason() > newNode->Frnds.getSeason())
    {
        newNode->next = *start;
        newNode->next->prev = newNode;
        *start = newNode;
    }
    
    else
    {
        current = *start;
        
        // traverse list for node that newNode will be inserted after
        while (current->next != NULL && current->next->Frnds.getSeason() < newNode->Frnds.getSeason())
            current = current->next;

        // insert node and update links accordingly
        newNode->next = current->next;
        if (current->next != NULL)
            newNode->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

// same as ascendingSort(), only difference being comparison conditions
void DLList::descendingSort(node **start, node *newNode)
{
    node *current;
    
    if (*start == NULL)
        *start = newNode;
    else if ((*start)->Frnds.getSeason() < newNode->Frnds.getSeason())
    {
        newNode->next = *start;
        newNode->next->prev = newNode;
        *start = newNode;
    }
    else
    {
        current = *start;
        while (current->next != NULL && current->next->Frnds.getSeason() > newNode->Frnds.getSeason())
            current = current->next;
        
        newNode->next = current->next;
        if (current->next != NULL)
            newNode->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}



//------------------------------------------- linear search ------------------------------------------//

void DLList::search()
{
    cout << "What season are you looking for? Type whole numbers only." << endl;
    int ssn;
    cin >> ssn;
    while(!cin) // validates input to be an integer
    {
        cout << "Please enter a correct whole number: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> ssn;
    }
    
    node *current = head;
    int counter = 1;
    while (current != NULL) // traversing list to check for user season
    {
        if (current->Frnds.getSeason() == ssn)
        {
            cout << "This season was found at CD #" << counter << endl;
            return; // exits out of function if found...
        }
        current = current->next;
        counter++;
    }
    cout << "Sorry, no such season has come out yet." << endl; //...otherwise, reaches down here
}



//----------------------------------------- print out list -------------------------------------------//

void DLList::print()
{
    cout << "Queue list:" << endl;
    node * current = head;
    while (current != NULL) // traverses list, printing every node's season
    {
        cout << "Season " << current->Frnds.getSeason() << endl;
        current = current->next;
    }
}



//-------------------------------- exit list and menu/program ends -----------------------------------//

void DLList::exit() // end of program and will exit menu loop
{
    cout << "Onto the player! Enjoy!" << endl;
}
