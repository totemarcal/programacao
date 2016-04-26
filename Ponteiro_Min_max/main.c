#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os 
endereços de duas variáveis inteiras, digamos min e max, 
e deposite nessas variáveis o valor de um elemento mínimo 
e o valor de um elemento máximo do vetor.   
Escreva também uma função main que use a função mm.
*/

void mm(int vet[10], int *min, int *max);

int main(int argc, char *argv[]) {
	int i, *vet, min, max;
	vet = malloc(10 * sizeof(int));
	for(i=0; i<10;i++)
	{
		printf("Digite o elemento vet[%i]", i);
		scanf("%i", &vet[i]);
	}
	min = vet[0];
	max = vet[0];
	mm(vet, &min, &max);
	printf("minimo %i \nMaximo %i", min, max); 
	return 0;
}
 void mm(int vet[10], int *min, int *max)
 {
	int i;
	for(i=0; i<10;i++)
	{
		if(vet[i] > *max)
		{
			*max = vet[i];
		}
		if(vet[i] < *min)
		{
			*min = vet[i];
		}
	}
 }

