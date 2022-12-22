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

//find the maximum value in the binary search tree
NodeAddress * maximum(NodeAddress * root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL){
        return root;
    }
    else{
        return maximum(root->left);
    }   
}

//check if the value is the maximum value in the BST
int isMax(NodeAddress * root, int val){
    if(maximum(root)->val == val){
        return 1;       //if the value is the maximum value, return 1
    }
    else{
        return 0;       //if the value is not the maximum value, return 0
    }
}

//find the successor of the value in the BST
NodeAddress * successor(NodeAddress * root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->val == val){
        if(root->left != NULL){
            return root->left;
        }
        else{
            return NULL;
        }
    }
    if(val < root->val){
        return successor(root->right, val);
    }
    else{
        return successor(root->left, val);
    }
}

int main(){
    int a[] = {10, 7, 14, 20, 1, 5, 8};
    NodeAddress * root = arrayToBST(a, 7);
    prefixPrint(root);
    return 0;
}