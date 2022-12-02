
#include <stdio.h>
#include <stdlib.h>

void basicFizzBuzz(int x){
    if(x%33==0 || x%39==0|| x%55==0|| x%65==0){
        printf("fizzbuzz \n");
    }
    else if(x%3==0 || x%5==0){
        printf("fizz \n");
    }
    else if(x%11==0 || x%13==0){
        printf("buzz \n");
    }
    else{
        printf("%d \n",x);
    }
}

//driver function
int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    basicFizzBuzz(x);
    return 0;
}

