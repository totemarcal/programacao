#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int func_soma(int x, int y);
void compara_numeros(int x, int y);
int soma_vetor(int vet[10]);
void cadastrar(int vet[10]);
void cadastrar_matriz(int mat[3][3]);
void exibir_matriz(int mat[3][3]);

int main(int argc, char *argv[]) {
	//int px, py, soma, i, vet[10], vet2[10];
	int mat[3][3]; 
	cadastrar_matriz(mat);
	exibir_matriz(mat);
	/*printf("Digite dois numeros:");
	scanf("%i %i", &px, &py);
	soma = func_soma(px,py);
	printf("O resultado eh:%i", soma);
	compara_numeros(px,py);
	cadastrar(vet);
	soma = soma_vetor(vet);
	printf("A soma eh: %i", soma);	
	cadastrar(vet2);
	soma = soma_vetor(vet2);
	printf("A soma eh: %i", soma);
	*/
	return 0;
}
void exibir_matriz(int mat[3][3])
{
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("\nInforme mat[%i][%i]: %i", i,j, mat[i][j]);
		}
	}
}

void cadastrar_matriz(int mat[3][3])
{
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Informe mat[%i][%i]", i,j);
			scanf("%i", &mat[i][j]);
		}
	}
}

void cadastrar(int vet[10])
{
	int i;
	for(i=0; i<10; i++)
	{
		printf("Informe vet[%i]", i);
		scanf("%i", &vet[i]);
		if(vet[i] % 2 != 0){
			i--;
			fflush(stdin);
		}
			
	}
}
int soma_vetor(int vet[10])
{
	int i, soma=0;
	for(i=0; i<10; i++)
	{
		soma = soma+vet[i];
	}
	return soma;
}
void compara_numeros(int x, int y)
{
	if(x>y){
		printf("\nX eh maior");
	}else if(x<y){
		printf("\nY eh maior");
	}else{
		printf("\nX igual a Y");
	}
}

int func_soma(int x, int y)
{
	return x+y;
}
