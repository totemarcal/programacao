#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int opcao_menu, opcao_cadastrar;
	
	do{
		system("cls");
		opcao_menu = menu();
		switch(opcao_menu){
			case 1: 
					do{
						system("cls");
						opcao_cadastrar = menu_cadastrar();
						switch(opcao_cadastrar){
							case 1: system("cls");
									cadastro_cliente();
									break;
							case 2: break;
							default: printf("OPCAO INVALIDA!");
						}
					}while(opcao_cadastrar!=3);
					break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: printf("SAINDO...");
					getch();
					return 1;
					break;
			default: printf("OPCAO INVALIDA!");
					getch();
		}
		
	}while(opcao_menu!=5);
	
	
	return 0;
}

int menu(){
	int opcao;
	printf("\n1- CADASTRAR: ");
	printf("\n2- ALTERAR: ");
	printf("\n3- CONSULTAR: ");
	printf("\n4- VENDER: ");
	printf("\n5- SAIR\n");
	scanf("%d", &opcao);
	return opcao;
}

int menu_cadastrar(){
	int opcao;
	printf("\n1- CLIENTE: ");
	printf("\n2- COMIDA: ");
	printf("\n3- VOLTAR\n");
	scanf("%d", &opcao);
	return opcao;
}

int cadastro_cliente(){
	printf("\nNOME: ");
	printf("\nIDADE: ");
	printf("\nDATA");
	getch();
}

