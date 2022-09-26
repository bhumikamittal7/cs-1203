#include <stdio.h>

struct nodeType{
int val;
struct nodeType * next;
};

typedef struct nodeType Node;

int main(int argc, char **argv){
	int i, val;
	Node * head = NULL;

	i = 0;
	scanf("%d", &val);
	while (val>0){

		// temp is a pointer to a node rn.
		temp = malloc(sizeof(Node));
		//(*temp).value = val; Go to temp, fetch its value and set it to val
		temp->value = val;
		temp ->next = NULL;

		//if this is first time 
		//or else


		i = i+1;
		scanf("%d", &val);

	}


return 0;

}
