//Array implementation of Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct nodeType{
    int val;
    struct nodeType *left;      //left child - smaller than parent
    struct nodeType *right;     //right child - larger than parent
};

typedef struct nodeType NodeAddress;

//insert a node into the tree
NodeAddress * insert(NodeAddress * root, int val){
    if(root == NULL){
        root = malloc(sizeof(NodeAddress));
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

//array to BST
NodeAddress * arrayToBST(int *a, int n){
    NodeAddress * root = malloc(sizeof(NodeAddress));
    root -> val = a[0];
    root->left = NULL;
    root->right = NULL;
    NodeAddress * temp = root;
    int i;
    for(i=1;i<n;i++){
        temp = insert(temp, a[i]);
    }
    return root;
}

//print the tree
void prefixPrint(NodeAddress * root){
    if(root == NULL){
        return;
    }
    prefixPrint(root->left);
    printf("%d ", root->val);
    prefixPrint(root->right);
}

int main(){
    int a[] = {10, 7, 14, 20, 1, 5, 8};
    NodeAddress * root = arrayToBST(a, 7);
    prefixPrint(root);
    return 0;
}