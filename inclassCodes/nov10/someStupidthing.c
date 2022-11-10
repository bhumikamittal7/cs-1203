#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a[1000];
    int i = -1234567;
    printf(" %d \n", a[i]);
    
    return 0;
}

void blah(int *a, int *func(int *x), int n){
    for (int i = 0; i < n; i++){
        func(a[i]);
    }
}
