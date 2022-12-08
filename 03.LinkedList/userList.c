#include<stdio.h>

//make linked list using user inputs till the user enters 0.

struct nodeType{
    int val;
    struct nodeType * next;
};

typedef struct nodeType Node;

int main(){
    
    int i, val;		//i is a counter, val is the value of the node
	Node * head = NULL;		//head is a pointer to the first node

	i = 0;
	scanf("%d", &val);
	while (val>0){

		// temp is a pointer to a node rn.
		Node *temp = malloc(sizeof(Node));
		//(*temp).value = val; Go to temp, fetch its value and set it to val
		temp->val = val;
		temp ->next = NULL;

		//if this is first time 
		if (i==0){
			head = temp;
		}
		//or else
		else{
			//go to the last node
			//set its next to temp
			//temp is the last node now
			Node * last = head;
			while(last->next != NULL){
				last = last->next;
			}
			last->next = temp;
		}

		i = i+1;
		scanf("%d", &val);

	}

	//print the list
	Node * temp = head;
	while(temp != NULL){
		printf("%d", temp->val);
		temp = temp->next;
	}
    return 0;
}