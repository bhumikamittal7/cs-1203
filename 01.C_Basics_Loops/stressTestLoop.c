#include <stdio.h>

// 0.13+0.13+0.13 = 0.39 but the compiler returns 0.39000000000000001 which is not equal to 0.39 so the if statement is false

void main(){
int a = 0.13+0.13+0.13;
if (a == 0.39){
    printf("True");
    }
else{
    printf("Lol");
    }
}
