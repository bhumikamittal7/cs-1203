#include <stdio.h>
#include <stdlib.h>

struct nodeType{
    int val;
    struct nodeType *left;      //left child - smaller than parent
    struct nodeType *right;     //right child - larger than parent
};

typedef struct nodeType NodeAddress;

NodeAddress *search(NodeAddress *root, int val){
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

NodeAddress *search2(NodeAddress *root, int val){
         return root?(val==root->val)?root:(val<root->val)?search2(root->left,val):search2(root->right,val):NULL;
}

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

int main(){
    int a[] = {5, 3, 7, 1, 4, 6, 8};
    NodeAddress * root = arrayToBST(a, 7);
    NodeAddress * temp = search(root, 4);
    printf("%d ", temp->val);
    return 0;
}