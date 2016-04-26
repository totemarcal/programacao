#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	/*
	int lista[5];
	int *pLista;
    pLista = lista;
    pLista = &lista[0];
    
	lista[0] = 1; lista[1] = 2; lista[2] = 3; lista[3] = 4; lista[4] = 5;
    
    
	printf("\nEndereco de Lista: %u", lista);
    printf("\nEndereco de pLista: %u", pLista);    
    printf("\nConteudo 3: %i", lista[2]);
    printf("\nConteudo 3: %i", *(pLista+2));
    printf("\nConteudo 3: %i", *(lista+2));
    */
    /*printf("\nPosicao 0: %i", *pLista);
    printf("\nPosicao 0: %i", lista[0]);
	printf("\nPosicao 1: %i", *(pLista+1));
    printf("\nPosicao 1: %i", lista[1]);    
	printf("\nEndereco [2]: %i", &lista[1]);
    printf("\nEndereco [2]: %i", pLista+1);
	printf("\nEndereco [2]: %i", lista+1);
	*/
	
	struct pessoa{
		int num;
		char nome[30];
	};
	int num;
	
	int i;
	struct pessoa * vet;
	vet =  malloc(10 * sizeof(struct pessoa));
	for(i=0;i<10;i++)
	{
		scanf("%i", &(vet+i)->num);
	}
	
	for(i=0;i<10;i++)
	{
		printf("\n%i", (vet+i)->num);
	}
	
	/*
	*pNum = 5;  // Posição 0 
	*(pNum+1) = 4;  // Posição 1
	*(pNum+2) = 3;  // Posição 2
	*(pNum+3) = 2;  // Posição 3
	*(pNum+4) = 1;  // Posição 4
	*/
	getch();
    
	return 0;
}
