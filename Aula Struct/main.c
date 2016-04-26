#include <stdio.h>
#include <stdlib.h>
// Definicao dos structs
struct carro{
	int id;
	char marca[30], cor[10];
	int ano;	
};

// definicao dos prototipos
void cadastrar(struct carro vet_carros[100]);
void consultar(struct carro vet_carros[100]);
void pesquisar(struct carro vet_carros[100], int id);
void alterar(struct carro vet_carros[100], int id);

int qtd_carro=0;

int main(int argc, char *argv[]) {
	int idPesquisa, idAlteracao, senha;
	struct carro lista_carros[100];
	char user[30];
	
	// Login
	do{
		system("cls");
		printf("\nLogin\n\n\n");
		printf("Digite o nome do usuario: ");
		scanf("%s", &user);
		printf("Digite a senha do usuario: ");
		scanf("%d", &senha);	
	}while(senha != 1234 || strcmp(user,"admin") != 0);
	
	printf("\n\nOla %s!", user);
	
	
	cadastrar(lista_carros);
	consultar(lista_carros);
	getch();
	system("cls");

	printf("\nDigite ID de pesquisa: ");
	scanf("%d", &idPesquisa);
	
	pesquisar(lista_carros, idPesquisa);
	getch();
	system("cls");

	printf("\nDigite ID da alteracao: ");
	scanf("%d", &idAlteracao);
	alterar(lista_carros, idAlteracao);
	pesquisar(lista_carros, idAlteracao);
}

void cadastrar(struct carro vet_carros[100]){
	int i;
	char opcao;
	for(i=qtd_carro;i<100;i++){
		printf("\nDigite Marca: ");
		scanf("%s", &vet_carros[i].marca);
		printf("\nDigite Cor: ");
		fflush(stdin);
		scanf("%s", &vet_carros[i].cor);
		printf("\nDigite Ano: ");
		fflush(stdin);
		scanf("%d", &vet_carros[i].ano);
		// cadastro do id realiza
		vet_carros[i].id = i+1;
		qtd_carro++;
		printf("Deseja Cadastrar Novamente s/n? ");
		fflush(stdin);
		scanf("%c", &opcao);
		
		if(opcao == 'n') break;
	}
}

void consultar(struct carro vet_carros[100]){
	int i;
	for(i=0;i<qtd_carro;i++){
		printf("\nID: %i", vet_carros[i].id);
		printf("\nMarca: %s", vet_carros[i].marca);
		printf("\nCor: %s", vet_carros[i].cor);
		printf("\nAno: %i", vet_carros[i].ano);
	}
}

void pesquisar(struct carro vet_carros[100], int id){
	int i;
	for(i=0;i<qtd_carro;i++){
		if(id == vet_carros[i].id){
			printf("\nID: %i", vet_carros[i].id);
			printf("\nMarca: %s", vet_carros[i].marca);
			printf("\nCor: %s", vet_carros[i].cor);
			printf("\nAno: %i", vet_carros[i].ano);
		}
	}
}

void alterar(struct carro vet_carros[100], int id){
	int i;
	for(i=0;i<qtd_carro;i++){
		if(id == vet_carros[i].id){
			printf("\nID: %i", vet_carros[i].id);
			printf("\nMarca: %s", vet_carros[i].marca);
			printf("\nCor: %s", vet_carros[i].cor);
			printf("\nAno: %i", vet_carros[i].ano);
			
			// alterar dados
			printf("\nDigite Marca: ");
			scanf("%s", &vet_carros[i].marca);
			printf("\nDigite Cor: ");
			fflush(stdin);
			scanf("%s", &vet_carros[i].cor);
			printf("\nDigite Ano: ");
			fflush(stdin);
			scanf("%d", &vet_carros[i].ano);
		}
	}
}

