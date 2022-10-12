#include <stdio.h>
#include <stdlib.h>

void main(){
int *a;
int x;
a = malloc(1000 * sizeof(int)); //malloc = memory allocation
//malloc(byte-size)

printf("%p \n", a);

x = *(a+1);
printf("%d \n", x);

free(a); //make sure to do it after malloc - to free the RAM
}
