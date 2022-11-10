//Dispatch tables
//Array of function pointers

#include <stdio.h>
#include <stdlib.h>

int (*table [VCHAR_MAX + 1]) (int);

int i,c;

for (i = 0; i <= VCHAR_MAX; i++){
    table[i] = put char;
}

while ((c = getchar()) != EOF){
    table[c] (c);
}
table['a'] = blah;
table['e'] = blah;
table['i'] = blah;
table['o'] = blah;
table['u'] = blah;
