#include <stdio.h>
#include <stdlib.h>

int blah(int val){
    int x;             //local variable - declared within a function, destroyed when function ends
    int *pointer = &x;
    x = val*val;
    return pointer; //doesn't return the valid address of x
    //if we malloc something, it won't be automatically destroyed when the function ends
}


int main(int argc, char **argv){
    int *b = blah(5);
    printf("%d \n", *b);
    return 0;
}

