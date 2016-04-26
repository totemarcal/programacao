#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b, total, opcao, num1, num2;
	
	do{
	
		opcao = menu();
		
		if(opcao != 5){
			printf("Digite Valor 1:");
			scanf("%d", &num1);
			printf("Digite Valor 2:");
			scanf("%d", &num2);
		}
		switch(opcao){
			case 1: total = somar(num1, num2);
					break;
			case 2: total = subtrair(num1, num2);
					break;
			case 3: total = multiplicar(num1, num2);
					break;
			case 4: total = divisao(num1, num2);
					break;
			case 5: return 1;
					break;
			default: printf("Opcao Invalida!");
		}
		printf("TOTAL: %d", total);
		getch();
		system("cls");
	}while(opcao!=5);
	
	return 0;
}


int somar(int x, int y){
	return (x+y);
}

int subtrair(int x, int y){
	return (x-y);
}
int divisao(int x, int y){
	return (x/y);
}
int multiplicar(int x, int y){
	return (x*y);
}

int menu(){
	int opcao;
	printf("\n1 - SOMAR:");
	printf("\n2 - SUBTRAIR:");
	printf("\n3 - MULTIPLICAR:");
	printf("\n4 - DIVIDR:");
	printf("\n5 - SAIR:");
	scanf("%d", &opcao);
	system("cls");
	return opcao;
}
