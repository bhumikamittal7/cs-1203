#include <stdio.h>

int main(int argc, char **argv){
	int x, y, y1;
	x = 0;
	y = x++;
	y1 = ++x;
//	x = (y=5)*3;
	printf("x = %d; y = %d; y1 = %d\n", x, y,y1);
	return 0;

}
