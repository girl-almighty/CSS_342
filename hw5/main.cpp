/////////////// BINARY TREE DRIVER FILE FOR TESTING ////////////////


#include "bstree.hpp"

// driver
int main()
{
    BTree bt;
    
    bt.testing("left-unbalanced");
    bt.testing("right-unbalanced");
    bt.testing("symmetrical");
    
    return 0;
}
