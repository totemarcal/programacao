#include <stdio.h>
#include <stdlib.h>

void troca( int *i, int *j) {
   int *temp = malloc(sizeof(int));
   *temp = *i; 
   *i = *j; 
   *j = *temp;
}

int main(int argc, char *argv[]) {
	int x, y;
	x=10;
	y=5;
	troca(&x,&y);
	printf("X = %i \n Y = %i ", x,y);
	
	return 0;
}
