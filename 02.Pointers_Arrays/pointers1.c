#include <stdio.h>

//experiment with pointers

void main(){
int x = 3;
int *y;
y = &x;

*y = *y+1;

printf("%d",x);
//printf(*y);
//printf(y);
//print(*x);
}
 
/*
void main(){
int x = 3;
int w = 5;

w = x;
w = 2*w;

printf("%d  \n", w);
}

*/