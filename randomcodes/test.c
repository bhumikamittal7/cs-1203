#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Write a function in C (no need to write the complete program) that will take as input two character strings and produce an output string by
// interleaving the two input strings in alternative positions. For example, if the input strings are "abc" and "def", the output string should be
// "adbecf". If the two input strings are of different lengths, the remaining characters of the longer string should be appended to the output string.
// For example, if the input strings are "abc" and "defgh", the output string should be "adbecfgh".

int main(){
    char *s1 = "abcdef";
    char *s2 = "xyzw";
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = len1>len2?len1:len2;
    char *s3 = malloc((len1+len2+1)*sizeof(char));
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<len1 && j<len2){
        s3[k++] = s1[i++];
        s3[k++] = s2[j++];
    }
    while(i<len1){
        s3[k++] = s1[i++];
    }
    while(j<len2){
        s3[k++] = s2[j++];
    }
    s3[k] = '\0';
    printf("%s", s3);
    free(s3);
    return 0;
}
