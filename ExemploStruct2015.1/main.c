#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//structs
struct Pessoa{
	int idade;
	char nome[30];
	float altura;
} typedef Pessoa;
//prototipos
void cadastrarPessoa(Pessoa p[3]);
void exibirPessoas(Pessoa p[3]);

int main(int argc, char *argv[]) {
	Pessoa lista_pessoa[3];
	int i;
	for(i=0;i<3;i++){
		printf("Digite o nome \n");
		gets(lista_pessoa[i].nome);
		printf("Digite a idade \n");
		scanf("%d", &lista_pessoa[i].idade);
		fflush(stdin);
		printf("Digite a altura \n");
		scanf("%d", &lista_pessoa[i].altura);
		fflush(stdin);
	}

	for(i=0;i<3;i++){
		printf("Pessoa: %s \n", lista_pessoa[i].nome);
		printf("Idade Pessoa: %d \n", lista_pessoa[i].idade);	
		printf("Altura Pessoa: %d \n", lista_pessoa[i].altura);	
	}



//	cadastrarPessoa(p);
//	exibirPessoas(p);	
	return 0;
}








void cadastrarPessoa(Pessoa p[3]){
	int i;
	for(i=0;i<3;i++){
		printf("Digite o nome \n");
		gets(p[i].nome);
		printf("Digite a idade \n");
		scanf("%d", &p[i].idade);
		fflush(stdin);
	}
}

void exibirPessoas(Pessoa p[3]){
	int i;
	for(i=0;i<3;i++){
			printf("Pessoa: %s \n", p[i].nome);
			printf("Idade Pessoa: %d \n", p[i].idade);	
	}
}







