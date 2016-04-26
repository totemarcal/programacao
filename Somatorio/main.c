#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int somatorio(int n);
int main(int argc, char *argv[]) {
	int num;
	
	printf("Informe o numero do somatorio: ");
	scanf("%i", &num);
	printf("Total do Somatorio: %i", somatorio(num));
	
	return 0;
}

int somatorio(int n)
{
	if(n == 0)
		return 0;
	else
		return n + somatorio(n-1);
}






