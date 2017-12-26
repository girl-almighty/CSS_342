////////////////// BINARY TREE METHOD DECLARATIONS //////////////////

#ifndef bstree_hpp
#define bstree_hpp

#include <iostream>
using namespace std;


// declarations
class BTree
{
private:
    struct node
    {
        int val;
        node *left = NULL, *right = NULL;
    };
    node *root = NULL;
public:
    BTree();
    ~BTree();
    
    struct node* addRecur(node *rt, int newVal);
    void addLeftUnbalanced10();
    void addRightUnbalanced10();
    void addSymmetrical10();
    
    void preOrderRecur(node *rt);
    void postOrderRecur(node *rt);
    void inOrderRecur(node *rt);
    
    string breadthFirstSearch(int findNum);
    bool bFS(node *rt, int findNum);
    
    void print(node *rt);
    void testing(string binaryTreeType);
};

#endif
