/*
We have the following linked list - 
1 -> 22 -> 333 -> 555 -> 999 -> /
*/

//Binary Search Trees
//everything on right is bigger and left is smaller

#include <stdio.h>
#include <stdlib.h>

struct nodeType{
    int val;
    struct nodeType *left;      //left child - smaller than parent
    struct nodeType *right;     //right child - larger than parent
};

typedef struct nodeType *NodeAddress;

/*
4, left:2, right: 7
2, left:1, right:3
7, left:5, right:9
1,3,5,9 -> left: NULL, right: NULL
*/

NodeAddress search(NodeAddress root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->val == val){
        return root;
    }
    if(val < root->val){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}

NodeAddress search2(NodeAddress root, int val){
         return root?(val==root->val)?root:(val<root->val)?search2(root->left,val):search2(root->right,val):NULL;
}

//insert a node into the tree
NodeAddress insert(NodeAddress root, int val){
    if(root == NULL){
        root = (NodeAddress)malloc(sizeof(struct nodeType));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

