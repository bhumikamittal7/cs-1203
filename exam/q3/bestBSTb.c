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

//print the tree
void prefixPrint(NodeAddress * root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->val);
    prefixPrint(root->left);
    prefixPrint(root->right);
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
    if(root == NULL){
        return NULL;
    }
    NodeAddress * temp = search(root, val);
    if(temp == NULL){
        return NULL;
    }

    if(temp->left != NULL){
        temp = temp->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp;
    }
    else{
        NodeAddress * successor = NULL;
        NodeAddress * prev = root;
        while(prev != temp){
            if(temp->val < prev->val){
                successor = prev;
                prev = prev->right;
            }
            else{
                prev = prev->left;
            }
        }
        return successor;
    }
}

void successorReverseBST(NodeAddress * root, int k){
    if(exists(root, k) == 0){
        printf("Pudding");
    }
    else if(successor(root, k) == NULL){
        printf("Hamburger");
    }
    else{
        printf("%d", successor(root, k)->val);
    }
}

int main(){
    int a[] = {10, 7, 14, 20, 1, 5, 8};
    NodeAddress * root = arrayToReverseBST(a, 7);
   //prefixPrint(root);
    successorReverseBST(root, 10);
    return 0;
}

