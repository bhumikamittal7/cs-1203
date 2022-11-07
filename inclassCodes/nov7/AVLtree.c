//AVL Trees - Adelson, Velski and Landis 

//Binary Search Trees
//everything on right is bigger and left is smaller

/*
5
3 | 8
2 | 4 || 7 | 10

get min element by going left and max element by going right


*/ 

struct nodeType{
    int val;
    struct nodeType *left;      //left child - smaller than parent
    struct nodeType *right;     //right child - larger than parent
};

typedef struct nodeType *NodeAddress;

NodeAddress find Root (NodeAddresss x)
if (!x) return NULL;

while (x -> parent )
    x = x -> parent;

return x;

/*
having balanced tree results in the log_2(n) time instead of O(n)

wherever you are, decide left or right (think of it is a recursion or probably a for loop with if-else condition)

*/
