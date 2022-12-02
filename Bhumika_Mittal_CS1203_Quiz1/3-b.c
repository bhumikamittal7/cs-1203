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
    if(val > root->val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

//array to BST
NodeAddress * arrayToReverseBST(int *a, int n){
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

//search for a value in the reverse BST
NodeAddress * search(NodeAddress * root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->val == val){
        return root;
    }
    if(val > root->val){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}

//check if the value exists in the BST
int exists(NodeAddress * root, int val){
    if(search(root, val) == NULL){
        return 0;       //if the value is not found, return 0
    }
    else{
        return 1;       //if the value is found, return 1
    }
}

//find the successor (next largest element) of the value in the BST
NodeAddress * successor(NodeAddress * root, int val){
    if(root == NULL){       //if the tree is empty, return NULL
        return NULL;
    }
    NodeAddress * temp = search(root, val);     //search for the value in the BST
    if(temp == NULL){
        return NULL;
    }

    if(temp->left != NULL){     //if the value has a left child, set temp to the left child
        temp = temp->left;
        while(temp->right != NULL){     //while the right child of temp is not NULL, set temp to the right child
            temp = temp->right;
        }
        return temp;
    }
    else{                                   //if the value does not have a left child
        NodeAddress * successor = NULL;      //set successor to NULL
        NodeAddress * prev = root;           //set prev to the root of the BST
        while(prev != temp){                  //while prev is not equal to temp, check if the value is greater than the value of prev and update successor and prev accordingly
            if(temp->val < prev->val){
                successor = prev;
                prev = prev->right;
            }
            else{
                prev = prev->left;
            }
        }
        return successor;                   //return successor
    }
}

void successorReverseBST(NodeAddress * root, int k){
    if(exists(root, k) == 0){                       //if the value does not exist in the BST
        printf("Pudding");
    }
    else if(successor(root, k) == NULL){            //if the value is the largest element in the BST
        printf("Hamburger");
    }
    else{
        printf("%d", successor(root, k)->val);      //print the value of the successor
    }
}

int main(){
    int a[] = {10, 7, 14, 20, 1, 5, 8};
    int n = sizeof(a)/sizeof(a[0]);

    NodeAddress * root = arrayToReverseBST(a, n);
    successorReverseBST(root, 5);

    return 0;
}

