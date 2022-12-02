
#include <stdio.h>
#include <stdlib.h>

void advancedFizzBuzz(int *a , int m, int *b , int nb , int * f , int nf ){
    int i,j;
    for(i=0;i<m;i++){
        int countf = 0;
        int countb = 0;
        for(j=0;j<nf;j++){
            if(a[i]%f[j]==0){
                //printf("fizz \n");
                countf+=1;
            }
        }
        for(j=0;j<nb;j++){
            if(a[i]%b[j]==0){
                //printf("buzz \n");
                countb+=1;
            }
        }
        if(countf>0 && countb>0){
            printf("fizzbuzz \n");
        }
        else if(countf>0){
            printf("fizz \n");
        }
        else if(countb>0){
            printf("buzz \n");
        }
        else{
            printf("%d \n",a[i]);
    }
}
}

//driver function
int main()
{
    int a[6]={19, 12, 13, 15, 55,33};
    int f[2]={3,5};
    int b[3]={11,13};
    advancedFizzBuzz(a,6,b,3,f,2);
    return 0;
}

