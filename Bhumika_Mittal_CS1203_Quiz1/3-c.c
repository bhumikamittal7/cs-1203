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

//distance between two values in the BST
int sortedDistance(NodeAddress * root, int x, int y){
    if(exists(root, x) == 0 || exists(root, y) == 0){
        return -1;      //if either of the values do not exist, return -1
    }
    if(x == y){
        return 0;       //if the values are the same, return 0 (as mentioned in the instructions, we expect this to never happen)
    }
    if(x > y){          //if x is greater than y, swap them. This is because we want to find the distance between the smaller value and the larger value
        int temp = x;
        x = y;
        y = temp;
    }

    int distance = -1;
    while(x != y){
        x = successor(root, x)->val;
        distance++;
    }
    return distance;
}

//driver function
int main(){
    int a[] = {10, 7, 14, 20, 1, 5, 8};
    int n = sizeof(a)/sizeof(a[0]);

    NodeAddress * root = arrayToReverseBST(a, n);
    printf("%d", sortedDistance(root, 1, 20));
    
    return 0;
}

