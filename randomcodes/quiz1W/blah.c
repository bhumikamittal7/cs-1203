#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
//int *a[100]; //array of pointers

int *x;
int *y;
*x = 1; //the pointer x is not pointing to anything
*y = *x;    //the pointer y is not pointing to anything

printf("%d", *y);
}
