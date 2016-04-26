#include <stdio.h>
#include <stdlib.h>

void cad(int v[10]);

int main(int argc, char *argv[]) {	
	int vet[10];
	exibir(vet);
	getch();
	cad(vet);
	exibir(vet);
}

int soma(int x, y)
{	
	return x+y;
}
int  divisao(int x, y)
{	
	printf("Resultado: %i", x/y)
}
void multiplicacao(int x, y)
{	
	printf("Resultado: %i", x*y)
}
void subtracao(int x, y)
{	
	printf("Resultado: %i", x-y)
}







void exibir(int v[10])
{	
	int i;
	for(i=0;i<10;i++)
	{
		printf("Valor: %i\n", v[i]);
	}
}
