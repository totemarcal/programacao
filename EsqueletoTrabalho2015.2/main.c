#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1º Passo: Definir as estrutuas: Cliente
   2º Passo: Definir os requisitos
             1- Cadastrar Cliente
             2- Consultar Cliente
   3º Passo: Criar interface
      
 */

//1º Passo
typedef struct cliente{
	int id;
	char nome[30];
	int idade;
}Cliente;

void cadastrarCliente(struct cliente cli[10]);
void consultarTodosCliente(struct cliente cli[10]);
void consultarPorCliente(struct cliente cli[10]);

int qtd_cli=0;

int main(int argc, char *argv[]) {
	
	struct cliente cli[10];
	
	
	int opcao;
	
	do{
		system("cls");
		printf("1- Cadastrar\n");
		printf("2- Consultar Todos\n");
		printf("3- Consultar por Nome\n");
		printf("4- Sair\n");
		scanf("%i", &opcao);
		system("cls");
		switch (opcao){
			case 1: {
				cadastrarCliente(cli);
				//getch();
				break;
			}
			case 2: {
				consultarTodosCliente(cli);
				getch();
				break;
			}
			case 3: {
				consultarPorCliente(cli);
				getch();
				break;
			}
			case 4: {
				printf("Saindo do sistema!");
				break;
			}
			default: {
				printf("Opcao Invalida!");
				getch();
			}
		}	
	}while(opcao!=4);
	
	return 0;
}

void cadastrarCliente(struct cliente cli[10])
{
	int i;
	char cont;
	for(i=qtd_cli; i<10; i++){
		printf("Cadastro de Cliente.\n\n\n");	
		printf("Informe o Nome: ");	
		fflush(stdin);
		gets(cli[i].nome);	
		printf("Informe a idade: ");		
		scanf("%i", &cli[i].idade);
		cli[i].id = i;
		qtd_cli++;		
		printf("\n\nDeseja cadastro outro cliente s\\n?");
		fflush(stdin);
		scanf("%c", &cont);
		if(cont == 'n')
			break;
	}
}

void consultarTodosCliente(struct cliente cli[10])
{
	int i;
	printf("Consulta de Cliente. \n\n\n");
	for(i=0; i<qtd_cli; i++){
		printf("ID: %i \n", cli[i].id);
		printf("Nome: %s \n", cli[i].nome);	
		printf("Idade: %i \n", cli[i].idade);			
	}
}

void consultarPorCliente(struct cliente cli[10])
{
	int i;
	char nome_cli[30];
	printf("Consulta de Cliente. \n\n\n");
	fflush(stdin);
	printf("Digite o nome do cliente:");
	gets(nome_cli);
	for(i=0; i<qtd_cli; i++){
		if(!strcmp(nome_cli,cli[i].nome)){
			printf("ID: %i \n", cli[i].id);
			printf("Nome: %s \n", cli[i].nome);	
			printf("Idade: %i \n", cli[i].idade);			
		}
	}
}
