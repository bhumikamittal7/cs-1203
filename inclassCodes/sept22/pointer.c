#include <stdio.h>

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
