//Linked List implementation of Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct nodeType{
    int val;
    struct nodeType *left;      //left child - smaller than parent
    struct nodeType *right;     //right child - larger than parent
};

typedef struct nodeType *NodeAddress;

NodeAddress LLtoBST(NodeAddress head, int n){
    if(n <= 0){
        return NULL;
    }
    NodeAddress left = LLtoBST(head, n/2);
    NodeAddress root = head;
    root->left = left;
    head = head->right;
    root->right = LLtoBST(head, n-n/2-1);
    return root;
}

//given an array, make a linked list and print it
NodeAddress * arrayToList(int * a, int n){
    NodeAddress * head = NULL;
    NodeAddress * current = NULL;
    for(int i=0;i<n;i++){
        NodeAddress * temp = malloc(sizeof(NodeAddress));
        temp->val = a[i];
        temp->next = NULL;
        if (i==0){
            head = temp;
            current = temp;
        }
        else{
            current->next = temp;
            current = temp;
        }
    }
    return head;
}

//print the tree
void prefixPrint(NodeAddress root){
    if(root == NULL){
        return;
    }
    prefixPrint(root->left);
    printf("%d ", root->val);
    prefixPrint(root->right);
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);
    NodeAddress * head = arrayToList(a, n);
    NodeAddress root = LLtoBST(head, n);
    prefixPrint(root);
    return 0;
}