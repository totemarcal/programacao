#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int opcao_principal, opcao_cadastro;
	
	do{
		system("cls");
		opcao_principal = menu_principal();
		switch(opcao_principal){
			case 1: 
					do{
						system("cls");
						opcao_cadastro = menu_cadastro();
						switch(opcao_cadastro){
							case 1: system("cls");
									cadastro_cliente();
									break;
							case 2: break;					
							case 3: break;
							default: printf("OPCAO INVALIDA!");
									 getch();
							}	
					}while(opcao_cadastro != 3);
					break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: printf("SAINDO...");
					return 1;
			default: printf("OPCAO INVALIDA!");
					 getch();
		}
		
	}while(opcao_principal != 5);
	
	return 0;
}

int menu_principal(){
	int opcao;
	
	printf("\n1- CADASTRAR: ");	
	printf("\n2- CONSULTAR: ");
	printf("\n3- ALTERAR: ");
	printf("\n4- VENDER: ");
	printf("\n5- SAIR\n");
	scanf("%d", &opcao);
	return opcao;
}

int menu_cadastro(){
	int opcao;
	
	printf("\n1- CLIENTE: ");	
	printf("\n2- COMIDA: ");
	printf("\n3- VOLTAR ");
	scanf("%d", &opcao);
	return opcao;
}

void cadastro_cliente(){
	printf("\nNOME: ");	
	printf("\nIDADE: ");
	printf("\nALTURA: ");
	getch();
}
