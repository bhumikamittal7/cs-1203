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

// print the tree
void prefixPrint(NodeAddress * root){
    if(root == NULL){
        return;
    }
    prefixPrint(root->left);
    printf("%d ", root->val);
    prefixPrint(root->right);
}

//delete a node from the tree
NodeAddress * delete(NodeAddress * root, int val){
    if(root == NULL){
        return NULL;
    }
    if(val < root->val){
        root->left = delete(root->left, val);
    }
    else if(val > root->val){
        root->right = delete(root->right, val);
    }
    else{
        if(root->left == NULL){
            NodeAddress * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            NodeAddress * temp = root->left;
            free(root);
            return temp;
        }
        else{
            NodeAddress * temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = delete(root->right, temp->val);
        }
    }
    return root;
}

int main(){
    int a[] = {5, 3, 7, 1, 4, 6, 8};
    NodeAddress * root = arrayToBST(a, 7);

    prefixPrint(root);
    delete(root, 3);

    printf("\nafter delete:\n");
    prefixPrint(root);  
    
    return 0;
}