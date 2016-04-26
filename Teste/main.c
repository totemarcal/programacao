#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//ponteiro pendurado
	/*int *p1, *p2;
	p1 = malloc(sizeof(int));
	p2 = p1;
	*p1 = 10;
	printf("\nP1: %d", *p1);
	printf("\nP2: %d", *p2);
	free(p1);
	printf("\nP1: %d", *p1);
	printf("\nP2: %d", *p2);
	*/
	//variaveis perdidas
	int *p1, *p2;
	p1 = malloc(sizeof(int));
	// situacao 1
	//p1 = malloc(sizeof(int));
	p2 = malloc(sizeof(int));
	p1=p2;
	
	
	
	
	
}
