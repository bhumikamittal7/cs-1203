#include <stdio.h>

//experiment with pointers

int main (int argc, char **argv){
//	char *s = "abcd";
//	s[0] = "A";
//	printf("the character *(s+1) is \"%c\". \n", *(s+1));
//	printf("the string s is \"%s\". \n", s);

	const int x = 5;
	int *p = &x;
	*p = 6;
	printf("x = %d \n", x);
	printf("*p = %d \n", *p);


	return 0;

}
