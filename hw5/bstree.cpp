///////////////// BINARY TREE METHOD IMPLEMENTATIONS /////////////////


#include <stdlib.h>
#include <queue>
#include "bstree.hpp"

// implementations

//-------------------- constructor & destructor --------------------\\

BTree::BTree() {}
BTree::~BTree() {}
//==================================================================\\



//------------------------- recursive add --------------------------\\
// will always take in the root node and a new value for a new node
struct BTree::node* BTree::addRecur(node *cur, int newData)
{
    node *newNode;    
    if (root == NULL) // if list is empty...
    {
        newNode = new node();
        newNode->val = newData;
        root = newNode; //... set new node to root
        return newNode;
    }
    if (cur == NULL) // if tracker reaches null,  it reached the new node's spot
    {
        newNode = new node();
        newNode->val = newData;
        return newNode;
    }
    if (newData <= cur->val) // if current is smaller/equal to new node...
        cur->left = addRecur(cur->left, newData); //... recur and move down left...
    else
        cur->right = addRecur(cur->right, newData); //...otherwise, do this
    return cur;
}
//===================================================================\\



//--------------- create 11 nodes in 3 different ways ---------------\\

void BTree::addLeftUnbalanced10()
{
    int nums [11] = {10, 7, 9, 5, 8, 6, 3, 4, 2, 1, 1};
    for(int i = 0; i <= 10; i++)
        addRecur(root, nums[i]);
}

void BTree::addRightUnbalanced10()
{
    int nums [11] = {3, 5, 8, 4, 10, 11, 7, 13, 6, 9, 11};
    for(int i = 0; i <= 10; i++)
        addRecur(root, nums[i]);
}

void BTree::addSymmetrical10()
{
    int nums [11] = {10, 8, 12, 11, 9, 16, 4, 1, 14, 20, 6};
    for(int i = 0; i <= 10; i++)
        addRecur(root, nums[i]);
}
//===================================================================\\



//------------ pre-order recursive traversal w/ printing ------------\\

void BTree::preOrderRecur(node *cur) // always takes in root node initially
{
    if (cur == NULL) // exits function when list is empty or has reached end
        return;
    
    print(cur); // prints out the roots first...
    preOrderRecur(cur->left); //... then left ...
    preOrderRecur(cur->right); //... then right
}
//===================================================================\\



//----------- post-order recursive traversal w/ printing ------------\\

void BTree::postOrderRecur(node *cur)
{
    if (cur == NULL)
        return;
    
    postOrderRecur(cur->left); // recurses down to left-most node & starts printing left...
    postOrderRecur(cur->right); //... then right ...
    print(cur); //... then root
}
//===================================================================\\



//------------ in-order recursive traversal w/ printing -------------\\

void BTree::inOrderRecur(node *cur)
{
    if (cur == NULL)
        return;
    
    inOrderRecur(cur->left); // recurses down to left-most node and prints left...
    print(cur); // ... then root ...
    inOrderRecur(cur->right); //... then right
}
//===================================================================\\



//--------------- extra credit: breadth-first search ----------------\\

string BTree::breadthFirstSearch(int num)
{
    if (bFS(root, num) == true)
        return "Found in the tree!";
    else
        return "Does not exist!";
}

bool BTree::bFS(node *root, int goal) // always takes in root initially & the number being searched
{
    queue<node*> q;
    q.push(root); // start with adding root to a new queue
    
    while(!q.empty())
    {
        node* cur = q.front(); // set tracker to front of queue
        q.pop(); // remove front of queue that is about to be checked for number being searched
        
        if(cur->val == goal) // if tracker == number being searched
            return true;
        else // add all non-NULL children to the queue so they can be checked
        {
            if(cur->left != NULL)
                q.push(cur->left);
            if(cur->right != NULL)
                q.push(cur->right);
        }
    }
    return false;
}
//===================================================================\\



//---------------------- print node parameter -----------------------\\

void BTree::print(node *someNode)
{
    cout << "Node value: " << someNode->val << endl;
}
//===================================================================\\



//----------------------- testing for main() ------------------------\\

void BTree::testing(string treeType)
{
    cout << "______________________________________________" << endl;
    cout << "TESTING: " << treeType << " tree" << endl << endl;
    
    if (treeType == "left-unbalanced")
        addLeftUnbalanced10();
    else if (treeType == "right-unbalanced")
        addRightUnbalanced10();
    else
        addSymmetrical10();
    
    cout << "created " << treeType << " tree..." << endl << endl;;
    
    cout << "Printing pre-order traversal:" << endl;
    preOrderRecur(root);
    cout << endl << "Printing post-order traversal:" << endl;
    postOrderRecur(root);
    cout << endl << "Printing in-order traversal:" << endl;
    inOrderRecur(root);
    
    cout << endl << "Printing breadth-first search: " << endl;
    cout << "Finding existing #10: " << breadthFirstSearch(10) << endl;
    cout << "Finding non-existent #0: " << breadthFirstSearch(0) << endl;
    
    cout << "==============================================" << endl << endl;
    
    root = NULL; // resets root node so a completely new tree can be created & tested correctly
}
//===================================================================\\


















