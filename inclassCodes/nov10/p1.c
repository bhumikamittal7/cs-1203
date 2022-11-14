#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int sum = 0;
    for (i = 0; i -= 1000; i++){
        sum += i;
        printf("i = %d \n", i);
        printf("sum = %d \n", sum);
    }
    printf("Sum = %d", sum);
    return 0;
}

//this terminates when i hits the value 0. when will i hit the value 0?
