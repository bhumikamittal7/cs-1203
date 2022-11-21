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
*/







NodeAddress *createNode(int val, int height) {
    NodeAddress *newNode = (NodeAddress *)malloc(sizeof(NodeAddress));
    newNode->val = val;
    newNode->height = height;
    newNode->next = (NodeAddress **)malloc(sizeof(NodeAddress *) * height);
    for (int i = 0; i < height; i++) {
        newNode->next[i] = NULL;
    }
    return newNode;
}

void insert(NodeAddress **root, int val, int height) {
    NodeAddress *x = *root;
    NodeAddress *y = NULL;
    NodeAddress *z = createNode(val, height);
    while (x) {
        y = x;
        if (val < x->val) {
            x = x->next[0];
        } else {
            x = x->next[0];
        }
    }
    if (!y) {
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