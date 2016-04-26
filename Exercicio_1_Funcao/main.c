#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int SOMA_INTEIRO(int v1, int v2);

int main(int argc, char *argv[]) {
	
	int vv1, v2;
	printf("Digite valor 1");
	scanf("%i", &vv1);
	printf("Digite valor 2");
	scanf("%i", &v2);	
	printf("A soma eh: %i ", SOMA_INTEIRO(vv1,v2));
	return 0;
}

int SOMA_INTEIRO(int v1, int v2)
{	
	int i, soma;
	for(i=v1; i<=v2; i++)
		soma+= i;
	return soma;
}

