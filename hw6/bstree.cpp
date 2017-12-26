///////////////// BINARY TREE METHOD IMPLEMENTATIONS /////////////////


#include <stdlib.h>
#include <queue>
#include "bstree.hpp"

// implementations

//-------------------- constructor & destructor --------------------\\

BTree::BTree()
{
    root = new node();
    placeholder = new node();
    placeholder->students = new vector<Student>;
    root->someone.setName("Supervisor");
}

BTree::~BTree() {}
//==================================================================\\



//------------------- methods to add instructors -------------------\\
// recursively adds to tree unsortedly, filling in the left child then right
struct BTree::node* BTree::addInstructor(node *cur, string newInst)
{
    if (cur == NULL) // hits spot where new Instructor goes
    {
        node *newNode = new node();
        newNode->someone.setName(newInst);
        newNode->students = new vector<Student>;
        return newNode; // return new Instructor to that spot
    }
    if (cur->left != NULL && cur->right != NULL) // if current has left and right children...
        cur->left = addInstructor(cur->left, newInst); //... go down left subtree
    else if (cur->left == NULL) // if current has no left child...
        cur->left = addInstructor(cur->left, newInst); //... add new node to left child ...
    else if (cur->right == NULL)
        cur->right = addInstructor(cur->right, newInst); //... otherwise, add to right child
    return cur;
}

void BTree::add3Instructors() // adds string contents of an array to the binary tree of instructors
{
    string instructor [3] = {"Severus", "Albus", "Sirius"};
    for(int i = 0; i < 3; i++)
        addInstructor(root, instructor[i]);
}
//==================================================================\\


//---------- method to add student to specific instructor ----------\\
// breadth-first search of instructor
void BTree::addStudentToInstructor(string instructor, string newStudent)
{
    Student newStu;
    newStu.setName(newStudent);
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        node* cur = q.front();
        q.pop();
        
        if (cur->someone.getName() == instructor) // when instructor is found...
        {
            cur->students->push_back(newStu); //... we add new student to instructor's students vector...
            return; //... then exit function
        }
        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
    }
    // otherwise, if instructor is not found, below is reached
    cout << "Sorry, that instructor is not available." << endl;
}
//==================================================================\\



//------- method to add student using "formula" in HW prompt -------\\

void BTree::addStudent(node *cur, string newStu)
{
    Student newStudent;
    newStudent.setName(newStu);
    
    // if formula decider returns true, use formula for adding up to five per instructor...
    // ... or adding to instructors who have 8+ student - this formula distributes students evenly
    if (fittingFormula() == true) 
        fillToFiveOrFillPast8(root, &placeholder);
    // otherwise, use formula for adding students to instructors who have 5+ students
    // but not all have 8. adds students to one instructor until it has 8 before moving on.
    else
        fillFrom5To8(root, &placeholder);
    placeholder->students->push_back(newStudent);
}

bool BTree::fittingFormula() // formula decider: this decides what formula to use for adding a student
{
    node *smallest = root->left; // breadth-first search of the instructor node with smallest vector
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        node* cur = q.front();
        q.pop();
        
        if (cur->someone.getName() != "Supervisor"
           && cur->students->size() <= smallest->students->size()) // finds smallest student vector
            smallest = cur;
        
        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
    }
    // if smallest vector is 4 or less or 8 or more, it returns true to distribute students evenly
    // this will call fillToFiveOrFillPast8()
    if (smallest->students->size() < 5 || smallest->students->size() > 7)
        return true;
    return false; // otherwise, if smallest is 5-7, add students to one instructor until it reaches 8
}

// this is the formula for distributing students evenly when there is less than
// 5 students for each instructor or more than 7 students for each instructor.
struct BTree::node* BTree::fillToFiveOrFillPast8(node *cur, node **curSmallest)
{
    if (cur == NULL) // stopper
        return cur;
    
    // finds instructor w/ least amount of students first...
    fillToFiveOrFillPast8(cur->left, curSmallest);
    if (cur->someone.getName() != "Supervisor"
        && cur->students->size() <= (*curSmallest)->students->size())
        *curSmallest = cur; //... and sets it to placeholder node of the BST instance...
    //... the addStudent() method will then add the student to this placeholder node
    fillToFiveOrFillPast8(cur->right, curSmallest);
    
    return cur;
}

// this is the formula to use when adding a student to a list of instructors
// who have 5-8 students each. if all instructors have 8, use formula above.
struct BTree::node* BTree::fillFrom5To8(node *cur, node **toBeFilled)
{
    if (cur == NULL)
        return cur;
    
    // finds first node with less than 8 students in an in-order sort...
    fillFrom5To8(cur->left, toBeFilled);
    if (cur->someone.getName() != "Supervisor" && cur->students->size() < 8)
        *toBeFilled = cur; // ... and sets it to placeholder node of BST instance....
    //... the addStudent() method will then add the student to this placeholder node
    fillFrom5To8(cur->right, toBeFilled);
    
    return cur;
}
//===================================================================\\


//------------------- methods to delete instructor -------------------\\
//breadth-first search of the instructor to be removed and its parent
void BTree::InstructorToBeRm(string rmInstructor)
{
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        node* cur = q.front();
        q.pop();
        
        if (cur->left->someone.getName() == rmInstructor)
            removeInstructor(cur->left, cur);
        else if (cur->right->someone.getName() == rmInstructor)
            removeInstructor(cur->right, cur);
        else
        {
            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
        }
    }
}

void BTree::removeInstructor(node *deleteThis, node *parentOfThis)
{
    // gets the students of the node to be deleted before it gets deleted
    vector<Student> *toBeAdded = deleteThis->students;
    cout << "Deleted Instructor " << deleteThis->someone.getName() << "." << endl;
    
    //if node to be deleted has no children
    if (deleteThis->left == NULL && deleteThis->right == NULL)
    {
        if (parentOfThis->left == deleteThis)
            parentOfThis->left = NULL;
        else
            parentOfThis->right = NULL;
    }
    // if it has one child
    else if (deleteThis->left == NULL || deleteThis->right == NULL)
    {
        if (deleteThis->left == NULL)
        {
            if(parentOfThis->left == deleteThis)
                parentOfThis->left = deleteThis->right;
            if(parentOfThis->right == deleteThis)
                parentOfThis->right = deleteThis->right;
        }
        else
        {
            if(parentOfThis->left == deleteThis)
                parentOfThis->left = deleteThis->left;
            if(parentOfThis->right == deleteThis)
                parentOfThis->right = deleteThis->left;
        }
    }
    // if it has both left and right children
    else
    {
        node *cur = deleteThis;
        node *tempParent = new node();
        while(cur->left != NULL) // finds left-most node and it's parent
        {
            tempParent = cur;
            cur = cur->left;
        }
        deleteThis = cur; // the left-most node then becomes the node that was deleted
        tempParent->left = NULL;
    }
    
    // the students of the deleted node is then distributed to other instructors appropriately
    for(vector<Student>::iterator it = toBeAdded->begin(); it != toBeAdded->end(); ++it)
        addStudent(root, it->getName());
}
//==================================================================\\


//---------- method to remove student based on given name ----------\\

void BTree::removeStudent(string rmStudent)
{
    // finds instructor where student is under and sets it to cur node
    node *cur = findInstructor(false, rmStudent);
    if (cur != NULL) // if student exists and is found...
    {
        //... we iterate through the cur node's vector, erase the student and exit function
        for(vector<Student>::iterator it = cur->students->begin(); it != cur->students->end(); ++it)
        {
            if(it->getName() == rmStudent)
            {
                cur->students->erase(it);
                cout << rmStudent << " is now removed!" << endl;
                return;
            }
        }
    }
    // otherwise, we reach down here
    cout << "Student does not exist - cannot be removed." << endl;
}
//===================================================================\\


//---------- method to find instructor based on given name ----------\\
// breadth-first search of instructor based on either student/instructor name
struct BTree::node* BTree::findInstructor(bool instructorName, string name)
{
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        node* cur = q.front();
        q.pop();
        
        // if bool parameter is true, given name is an instructor name
        if (instructorName == true && cur->someone.getName() == name)
        {
            cout << "Found Instructor " << cur->someone.getName() << "!" << endl;
            return cur;
        }
        // if false, given name is student name, so find instructor based on student name
        else if (instructorName == false)
        {
            for (vector<Student>::iterator student = cur->students->begin();
                 student != cur->students->end(); ++student)
            {
                if(student->getName() == name)
                {
                    cout << "Found student, " << name;
                    cout << ", under " << cur->someone.getName() << "!" << endl;
                    return cur;
                }
            }
        }
        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
    }
    return NULL;
}
//===================================================================\\



//------------------------ methods to display ------------------------\\
// in-order print of all nodes but Supervisor
void BTree::display(node *cur)
{
    if (cur == NULL)
        return;
    
    display(cur->left);
    if(cur->someone.getName() != "Supervisor")
        print(cur);
    display(cur->right);
}

// prints out contents of node
void BTree::print(node *someNode)
{
    cout << "* Instructor: " << someNode->someone.getName() << endl;
    if (someNode->students->size() > 0)
    {
        for(vector<Student>::iterator it = someNode->students->begin();
            it != someNode->students->end(); ++it)
            cout << "\t - " << it->getName() << endl;
    }
    cout << endl;
}
//===================================================================\\



//---------------------- extra credit: trackers ----------------------\\

void BTree::personTracker(node *cur)
{
    instructorTracker(root);
    studentTracker(root);
}

void BTree::instructorTracker(node *cur)
{
    if (cur == NULL)
        return;
    
    instructorTracker(cur->left);
    if (cur->someone.getName() != "Supervisor")
        cur->someone.trackMe();
    instructorTracker(cur->right);
}

void BTree::studentTracker(node *cur)
{
    if (cur == NULL)
        return;
    
    studentTracker(cur->left);
    if (cur->someone.getName() != "Supervisor")
    {
        for (vector<Student>::iterator it = cur->students->begin(); it != cur->students->end(); ++it)
            it->trackMe();
    }
    studentTracker(cur->right);
}
//===================================================================\\



//----------------------- testing for main() ------------------------\\

void BTree::divider()
{
    cout << "--------------------------------------------------------------" << endl;
}

void BTree::testing()
{
    divider();
    cout << "Added 3 instructors." << endl;
    add3Instructors();
    cout << endl << "DISPLAYING RESULT..." << endl << endl;
    display(root);
    divider();
    
    cout << "Added 19 students, with one student specifically to Instructor Severus." << endl;
    addStudent(root, "Harry Potter");
    addStudent(root, "Hermione Granger");
    addStudent(root, "Ron Weasley");
    addStudent(root, "Iris Favoreal");
    for (int i = 0; i < 14; i++)
        addStudent(root, "Some student");
    addStudentToInstructor("Severus", "Draco Malfoy");
    cout << endl << "DISPLAYING RESULT..." << endl << endl;
    display(root);
    divider();
    
    InstructorToBeRm("Severus");
    cout << endl << "DISPLAYING RESULT..." << endl << endl;
    display(root);
    divider();
    
    cout << "Adding new student previously removed instructor, Severus:" << endl;
    addStudentToInstructor("Severus", "Tom Riddle");
    divider();
    
    cout << "*** EXTRA CREDIT ***" << endl << endl;
    cout << "Displaying person tracker: " << endl;
    personTracker(root);
    cout << endl << "Displaying instructor tracker: " << endl;
    instructorTracker(root);
    cout << endl << "Displaying student tracker: " << endl;
    studentTracker(root);
    divider();
}
//===================================================================\\

