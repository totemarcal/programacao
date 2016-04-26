#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();
int menu_operacao();
void cadastrar_carro();
void exibir_carro();

int main(int argc, char *argv[]) {
	int op;
	
	do{
		op = menu();
		system("cls");
	}while(op != 4);
			
	return 0;
}

int menu(){
	int opcao, operacao;
		
	printf("1- Carro\n");
	printf("2- Cliente\n");
	printf("3- Aluguel\n");
	printf("4- Sair\n");
	scanf("%i", &opcao);
	system("cls");
	
	switch(opcao){
		case 1:
				do{
					operacao = menu_operacao();
					system("cls");
					switch(operacao){
						case 1: 
								cadastrar_carro();
								break;
						case 2: 
								exibir_carro();
								break;
						case 3: 
								//consultar_carro();
								break;
						case 4: 
								//alterar_carro();
								break;
					}						
				}while(operacao!=5);
				
				break;
		case 2:
				do{
					operacao = menu_operacao();
					
					system("cls");
				}while(operacao!=5);
				break;
		case 3:
				do{
					operacao = menu_operacao();
					system("cls");
				}while(operacao!=5);
				break;
		case 4:
				printf("Saindo do sistema...");
				break;
		default:
				printf("Opcao Invalida!");
				break;
	}
	
	return opcao;
	
}

int menu_operacao(){
	int operacao;
	printf("1- Cadastrar\n");
	printf("2- Exibir Todos\n");
	printf("3- Consultar\n");
	printf("4- Alterar\n");
	printf("5- Voltar\n");
	scanf("%i", &operacao);
	return operacao;
}

void cadastrar_carro(){
	printf("Nome: \n");
	printf("Ano: \n");
	printf("... \n");
	system("pause");
	system("cls");
}

void exibir_carro(){
	printf("Consulta de Carros!\n");
	printf("... \n");
	system("pause");
	system("cls");
}
