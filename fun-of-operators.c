#include <stdio.h>
int main()
{
	int a = - - -3;
	int b;
	b = - - a++;
	printf("b: %d\na: %d\n",b,a); // output: 
				      // b: -3
				      // a: -2
}
