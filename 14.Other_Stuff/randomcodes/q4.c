#include<stdio.h>
int main()
{
char str[80], ch;
printf("Enter a string, then a blank space and then any single character\n");

scanf("%s\n", str);
scanf("%c", &ch);
printf("%s\n", str);
printf("%c", ch);
return 0;
}

//in the above code, we input a string (which is read by scanf("%s", str);) and then a character (which is read by scanf("%c", &ch);). 
//The problem is that the character is not read. Why is that? 
// The character is not read because the scanf("%c", &ch); is reading the newline character that is left in the input buffer after the scanf("%s", str);.

//The solution is to use scanf("%c", &ch); before the scanf("%s", str);.

//same program with malloc
#include<stdio.h>
#include<stdlib.h>
int main()
{
char *str, ch;
printf("Enter a string, then a blank space and then any single character\n");

str = (char *)malloc(80 * sizeof(char));
scanf("%s\n", str);
scanf("%c", &ch);
printf("%s\n", str);
printf("%c", ch);
return 0;
}


/*  Grading stuff
-2/3 for almost correct
- 5 for half correct
-7 for barely something
-9 for geniune attempt
-10 for no attempt



*/