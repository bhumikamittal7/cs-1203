#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
struct nodeType * next;
};

typedef struct nodeType Node;

//make a node, set its value to val, and return it
Node * makeNode(int val){
	Node * temp;
	temp = malloc(sizeof(Node));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

int main(){
	printf("Value of the node: %d\n",*makeNode(5));
	printf("Address of the node: %p",makeNode(5));
	
	return 0;

}
