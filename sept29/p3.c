// insert and delete in a double-ly linked list

struct node{
    int val;
    struct node *next;
    struct node *prev;   
};
//to reach B, you need to go through A. 
//B->prev->next = B->next
//C->prev goes to A
//B->next->prev = B->prev
//Delete B

