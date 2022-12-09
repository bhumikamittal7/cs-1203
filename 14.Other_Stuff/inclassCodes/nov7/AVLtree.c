//AVL Trees - Adelson, Velski and Landis 

//Binary Search Trees
//everything on right is bigger and left is smaller

/*
5
3 | 8
2 | 4 || 7 | 10

get min element by going left and max element by going right

having balanced tree results in the log_2(n) time instead of O(n)

wherever you are, decide left or right (think of it is a recursion or probably a for loop with if-else condition)

NOTE -- AVL says that the difference between the height of left and right subtree should be atmost 1
*/


struct nodeType{
    int val;
    struct nodeType *left;      //left child - smaller than parent
    struct nodeType *right;     //right child - larger than parent
    struct nodeType *parent;
    
    //if something is a leaf node, set height to 0 or maybe -1
    //your height is +1 the height of your taller child - we are kinda looking for the longest path down the tree
    //if you are a leaf node, your height is 0

    int height;                 // NODE AUGMENTATION 

};

typedef struct nodeType *NodeAddress;

NodeAddress find Root (NodeAddresss x)
if (!x) return NULL;

while (x -> parent )
    x = x -> parent;

return x;

/*
x 
A (height k-1) | y (height k)
|| B (height k-1) | C (height k-1)

SITUATION 1:    Now we add a new elemenet, so now the height of C is k
                Now the height of y is k+1
                Difference between height of A and y is 2 - NOT OKAY
                Direction of x heaviness is right and y heaviness is right - same direction (or equally balanced)

THERE IS A PROBLEM (Panic, something's wrong) - Call a function to fix it (Left rotate because it is right heavy)
After left rotate - 
y (k+1)
x (k) | C (k)
A (k-1) | B (k-1) || 
==============================================================================================================================================

x 
A (height k-1) | z (height k+1)
|| y (height k) | D (height k-1)
||| B (height k-1) | C (height k-1) ||


SITUATION 2:  Now the height of z is k+1
              Difference between height of A and z is 2 - NOT OKAY
              Direction of x heaviness is right and z heaviness is left - different direction
        
There's a huge problem now :(
    - So we do a right rotate on y
x
A (height k-1) | y (height k+1)
|| B (height k-1) | z (height k)
||| || C (height k-1) | D (height k-1)

    - Now we are back to Situation 1 and then we do a left rotate on x
y
x (height k) | z (height k)
A (height k-1) | B (height k-1) || C (height k-1) | D (height k-1)

MATH BEHIND IT - when perfect, then we have log_2 (n), when we have height difference of 1 then we have log_(phi) (n)
This stuff has relation to the golden ratio and fibonacci numbers - all these 1 adds upto the golden ratio
*/

//AVL rotation functions
NodeAddress leftRotate (NodeAddress x)
{
    NodeAddress y = x -> right;
    x -> right = y -> left;
    if (y -> left)
        y -> left -> parent = x;
    y -> parent = x -> parent;
    if (!x -> parent)
        root = y;
    else if (x == x -> parent -> left)
        x -> parent -> left = y;
    else
        x -> parent -> right = y;
    y -> left = x;
    x -> parent = y;
}

NodeAddress rightRotate (NodeAddress x)
{
    NodeAddress y = x -> left;
    x -> left = y -> right;
    if (y -> right)
        y -> right -> parent = x;
    y -> parent = x -> parent;
    if (!x -> parent)
        root = y;
    else if (x == x -> parent -> right)
        x -> parent -> right = y;
    else
        x -> parent -> left = y;
    y -> right = x;
    x -> parent = y;
}

//AVL tree insertion
NodeAddress insert (NodeAddress root, int val)
{
    NodeAddress x = root;
    NodeAddress y = NULL;
    NodeAddress z = (NodeAddress) malloc (sizeof (struct nodeType));
    z -> val = val;
    z -> left = NULL;
    z -> right = NULL;
    z -> height = 0;
    while (x)
    {
        y = x;
        if (val < x -> val)
            x = x -> left;
        else
            x = x -> right;
    }
    z -> parent = y;
    if (!y)
        root = z;
    else if (val < y -> val)
        y -> left = z;
    else
        y -> right = z;
    return root;
}

//AVL tree deletion
NodeAddress delete (NodeAddress root, int val)
{
    NodeAddress x = root;
    while (x && x -> val != val)
    {
        if (val < x -> val)
            x = x -> left;
        else
            x = x -> right;
    }
    if (!x)
        return root;
    if (!x -> left)
        transplant (x, x -> right);
    else if (!x -> right)
        transplant (x, x -> left);
    else
    {
        NodeAddress y = minimum (x -> right);
        if (y -> parent != x)
        {
            transplant (y, y -> right);
            y -> right = x -> right;
            y -> right -> parent = y;
        }
        transplant (x, y);
        y -> left = x -> left;
        y -> left -> parent = y;

    }
    return root;
}

//AVL tree search
NodeAddress search (NodeAddress root, int val)
{
    NodeAddress x = root;
    while (x && x -> val != val)
    {
        if (val < x -> val)
            x = x -> left;
        else
            x = x -> right;
    }
    return x;
}

//AVL tree minimum
NodeAddress minimum (NodeAddress root)
{
    NodeAddress x = root;
    while (x -> left)
        x = x -> left;
    return x;
}

//AVL tree maximum
NodeAddress maximum (NodeAddress root)
{
    NodeAddress x = root;
    while (x -> right)
        x = x -> right;
    return x;
}

//AVL tree successor
NodeAddress successor (NodeAddress x)
{
    if (x -> right)
        return minimum (x -> right);
    NodeAddress y = x -> parent;
    while (y && x == y -> right)
    {
        x = y;
        y = y -> parent;
    }
    return y;
}

