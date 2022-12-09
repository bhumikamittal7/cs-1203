//write a program to accept an alphanumeric string and determine if it is a palindrome or not.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);

    int flag = 0;
    int len = strlen(str);
    int i = 0;
    if (len>50 && len<1){
        printf("Enter an alphanumeric string of length less than 50");
        return 0;
    }
    else{
        while (i<len){
            if(tolower(str[0]) != tolower(str[len-1])){
                flag = 1;
                i++;
                break;
            }
            else{
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%s is not a palindrome", str);
        }    
        else {
            printf("%s is a palindrome", str);
        }
    }
    return 0;
}