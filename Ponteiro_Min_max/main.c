#include <stdio.h>
#include <stdlib.h>

/*
Escreva uma fun��o mm que receba um vetor inteiro v[0..n-1] e os 
endere�os de duas vari�veis inteiras, digamos min e max, 
e deposite nessas vari�veis o valor de um elemento m�nimo 
e o valor de um elemento m�ximo do vetor.   
Escreva tamb�m uma fun��o main que use a fun��o mm.
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

