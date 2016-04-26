#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int a, b, c;
	int *p, *q;
	a=10;
	b=8;
	p=&a;
	q=&b;
	c=*p+q;
	
	printf("total: %i", c); 
	if(p == &a)
		printf("\n\nIgual!");
	return 0;
}
