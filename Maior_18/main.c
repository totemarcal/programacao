#include <stdio.h>
#include <stdlib.h>

struct pessoa{
	char nome[30];
	int idade;
};

struct aluguel{
	char nome[30];
	int livro[30];
};

int maior_idade();
void exibe_aluguel();
void aluguel();
int pessoa_existe(char nome[30]);

struct pessoa p[10];
struct aluguel a[10];
int qtd_aluguel=0;

int main(int argc, char *argv[]) {
	int i;
	char nome_alterado[30];
	printf("******* Cadastro de Pessoa ******** ");
	for(i=0;i<10;i++){
		printf("\nDigite o nome da pessoa %i: ", i+1);
		gets(p[i].nome);
		fflush(stdin);
		printf("Digite a idade da pessoa %i: ", i+1);
		scanf("%i",&p[i].idade);
		fflush(stdin);
	}
	
	exibe();
	getch();
	system("cls");	
	printf("******* Aluguel ******** ");
	char opcao;
	do{
		aluguel();
		printf("\nDeseja alugar novamente?");
		fflush(stdin);
		scanf("%c",&opcao);
		fflush(stdin);
	}while(opcao=='s');
	exibe_aluguel();
	
	
	printf("\nQuantidade maior que 18: %i ", maior_idade());
	
	printf("\nInforme o nome da pessoa que deseja alterar a idade: ");
	gets(nome_alterado);
	for(i=0;i<10;i++){
		if(strcmp(nome_alterado, p[i].nome)==0)
		{
			printf("Deseja alterar a idade de %i ? ", p[i].idade);
			scanf("%i", &p[i].idade);
			printf("\nIdade alterada com sucesso!!!!");
		}
	}
	exibe();
	
	return 0;
}

void aluguel()
{
	char nome[30];
	printf("Digite o nome: ");
	gets(nome);
	if(pessoa_existe(nome)==1)
	{
		strcpy(a[qtd_aluguel].nome,nome);
	}else
	{
		printf("Nome não existe!");
		return;
	}
	fflush(stdin);
	printf("Digite livro: ");
	gets(a[qtd_aluguel].livro);
	fflush(stdin);	
	qtd_aluguel++;
}

int maior_idade()
{
	int i,qtd=0;
	for(i=0;i<10;i++){
		if(p[i].idade > 18)
			qtd++;
	}
	return qtd;
}

void exibe()
{
	int i;
	for(i=0;i<10;i++){
		printf("\nNome: %s", p[i].nome);
		printf("\nIdade: %i", p[i].idade);
	}
}

void exibe_aluguel()
{
	int i;
	for(i=0;i<qtd_aluguel;i++){
		printf("\nNome: %s", a[i].nome);
		printf("\nLivro: %s", a[i].livro);
	}
}

int pessoa_existe(char nome[30])
{
	int i;
	for(i=0;i<10;i++){
		if(strcmp(nome, p[i].nome)==0)
		{
			return 1;
		}
	}
	return 0;
}

