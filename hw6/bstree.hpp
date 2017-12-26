////////////////// BINARY TREE METHOD DECLARATIONS //////////////////

#ifndef bstree_hpp
#define bstree_hpp

#include <iostream>
#include <vector>
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

using namespace std;


// declarations
class BTree
{
private:
    struct node
    {
        Instructor someone;
        vector<Student> *students;
        node *left, *right = NULL;
    };
    node *root;
    node *placeholder;
public:
    BTree();
    ~BTree();
    
    struct node* addInstructor(node *rt, string newInstructor);
    void add3Instructors();
    
    void addStudentToInstructor(string Instructor, string Student);
    
    void addStudent(node *rt, string newStudent);
    bool fittingFormula();
    struct node* fillToFiveOrFillPast8(node *rt, node **holder);
    struct node* fillFrom5To8(node *rt, node **holder);
    
    void InstructorToBeRm(string rmInstructor);
    void removeInstructor(node *toBeRm, node *parent);
    
    void removeStudent(string rmStudent);
    
    struct node* findInstructor(bool givenName, string instructor);

    void display(node *rt);
    void print(node *rt);
    
    void personTracker(node *rt);
    void instructorTracker(node *rt);
    void studentTracker(node *rt);
    
    void divider();
    void testing();
};

#endif
