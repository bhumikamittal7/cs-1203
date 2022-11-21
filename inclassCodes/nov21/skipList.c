//vertical linked list - elevator story
//next[1] = *(next + 1)

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node **next; //array of pointers to nodes = *next[]
    int height;
};

typedef struct node NodeAddress;

/*
we go to every third floor - 1 points to 4, 4 points to 7, 7 points to 10
the length of next array is 1 in most cases, for some cases it is 2 (the lookahead is k)


c = head 
s = 1
if (count%5 == 0)
    s = s+1
    c -> next = malloc(sizeof(NodeAddress) * s)
    c -> next[s-1] = malloc(sizeof(NodeAddress))
    c -> next[s-1] -> val = count
    c = c -> next[s-1]
else
    c -> next = malloc(sizeof(NodeAddress))
    c -> next[0] = malloc(sizeof(NodeAddress))
    c -> next[0] -> val = count
    c = c -> next[0]

Randomize the jump size - if I don't know what I am doing, then my enemy can defientlyn never know what I am doing

x = (0, 1)
numE = 1
if (x<0.2)
    numE += 1
if (x<0.1)
    numE += 1
*/



NodeAddress *createNode(int val, int height) {
    NodeAddress *newNode = (NodeAddress *)malloc(sizeof(NodeAddress));  //create a new node and allocate memory for it
    newNode->val = val; //set the value of the new node
    newNode->height = height;   //set the height of the new node
    newNode->next = (NodeAddress **)malloc(sizeof(NodeAddress *) * height);     //allocate memory for the next array
    for (int i = 0; i < height; i++) {  //set all the pointers in the next array to NULL
        newNode->next[i] = NULL;    //set the next pointer to NULL
    }
    return newNode;
}

void insert(NodeAddress **root, int val, int height) {
    NodeAddress *x = *root; //set x to the root
    NodeAddress *y = NULL;  //set y to NULL
    NodeAddress *z = createNode(val, height);   //create a new node with the value val and height height
    while (x != NULL) { //while x is not NULL
        y = x;  //set y to x
        if (val < x->val) { //if the value of the new node is less than the value of x
            x = x->next[0]; //set x to the next pointer of x
        } else {    //if the value of the new node is greater than or equal to the value of x
            x = x->next[0];
        }
    }
    if (y != NULL) {
        *root = z;
    } else if (val < y->val) {
        y->next[0] = z;
    } else {
        y->next[0] = z;
    }
}

void printList(NodeAddress *root) {
    NodeAddress *x = root;
    while (x) {
        printf("%d ", x->val);
        x = x->next[0];
    }
    printf("\n");
}

int main() {
    NodeAddress *root = NULL;
    insert(&root, 1, 1);
    insert(&root, 4, 1);
    insert(&root, 7, 1);
    insert(&root, 10, 1);
    printList(root);
    return 0;
}