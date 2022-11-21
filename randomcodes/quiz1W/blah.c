#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
int *x;
int *y;
*x = 1;
*y = *x;
printf("%d", *y);
}
