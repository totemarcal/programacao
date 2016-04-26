#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,aux, vet[10];
	
	for(i=0;i<10;i++)
	{
		printf("Digite o numero %i : ", i);
		scanf("%i", &vet[i]);
	}
	
	for(i=0; i<10; i++)
	{
		for(j=i; j<10; j++)
		{
			if(vet[j] < vet[i])
			{
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
	
	for(i=0;i<10;i++)
	{
		printf("\n %i: ", vet[i]);
	}
	
	getch();
	return 0;
}
