#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//void textbackground(1);

struct pessoa{
	char nome[30];
	int idade;
	int cpf;
	char rua[30];
	int numero;
}typedef funcionario;

struct disciplina{
	char disciplina[30];
	char professor[30];
	char curso[30];
	char turno[10];
	int carga_horaria;
	int sala;
	int qtd_alunos;
}typedef disciplina;

void funcionarios_cadastrados(funcionario p[10]);
void disciplinas_cadastradas(disciplina d[10]);

int funcionarios = 0, disciplinas = 0;

int main(int argc, char *argv[]) {

	
	
	char login[30], voltar;
	int senha;
	int escolha, i;
	funcionario p[10];
	disciplina d[10];
	
	do{
		printf("\t\t\t\tUsuario: ");
		gets(login);
		printf("\n\t\t\t\tSenha: ");
		scanf("%i", &senha);
		fflush(stdin);
		system("cls");
		if(senha != 1807 || strcmp(login, "ianrocha") != 0){
			printf("\n\n\t\t\t\tLogin ou Senha incorreto!\n");
			printf("\t\t\tPressione 'enter' para tentar novamente!\n");
			voltar = getchar();
			system("cls");
		} else {
			printf("\t\t\t\tBem Vindo!\n");
		}
	}while(senha != 1807 || strcmp(login, "ianrocha") != 0);
	
	do{
		printf("\t\t\t\tO que deseja fazer?\n\n\t\t\t1 - Cadastrar/consultar funcionario\n\t\t\t2 - Cadastrar/consultar disciplina\n");
		printf("\t\t\t3 - Sair\n\t\t\t\n\t\t\tEscolha: ");
		scanf("%i", &escolha);
		fflush(stdin);
		system("cls");
		switch(escolha){
			case 1:
				printf("\t\t\t\tMenu Funcionario\n\n");
				printf("\t\t\t1 - Cadastrar funcionario\n\t\t\t2 - Consultar funcionario\n\t\t\t3 - Voltar\n\t\t\t\n\t\t\tEscolha: ");
				scanf("%i", &escolha);
				fflush(stdin);
				system("cls");
				switch(escolha){
					case 1:
						printf("\t\t\t\tCadastrando funcionario\n\n");
						for(i = funcionarios; i < 10; i++){
							printf("\n\nNome: ");
							gets(p[i].nome);
							printf("Idade: ");
							scanf("%i", &p[i].idade);
							printf("CPF: ");
							scanf("%i", &p[i].cpf);
							fflush(stdin);
							printf("Rua: ");
							gets(p[i].rua);
							fflush(stdin);
							printf("Numero: ");
							scanf("%i", &p[i].numero);
							printf("\n\nCadastrar outro funcionario?\n1 - Sim\n2 - Nao\nEscolha: ");
							scanf("%i", &escolha);
							fflush(stdin);
							if(escolha == 2){
								break;
							}
						}
						funcionarios = i + 1;
						system("cls");
						break;
					case 2:
						funcionarios_cadastrados(p);
						break;
				}
				break;
			case 2:
				printf("\t\t\t\tMenu Disciplina\n\n");
				printf("\t\t\t1 - Cadastrar disciplina\n\t\t\t2 - Consultar disciplina\n\t\t\t3 - Voltar\n\t\t\t\n\t\t\tEscolha: ");
				scanf("%i", &escolha);
				fflush(stdin);
				system("cls");
				switch(escolha){
					case 1:
						printf("\t\t\t\tCadastrando disciplina\n\n");
						for(i = disciplinas; i < 10; i++){
							printf("\n\nDisciplina: ");
							gets(d[i].disciplina);
							printf("Professor: ");
							gets(d[i].professor);
							printf("Curso: ");
							gets(d[i].curso);
							printf("Sala: ");
							scanf("%i", &d[i].sala);
							printf("Carga Horaria: ");
							scanf("%i", &d[i].carga_horaria);
							fflush(stdin);
							printf("Turno: ");
							gets(d[i].turno);
							printf("Total de alunos: ");
							scanf("%i", &d[i].qtd_alunos);
							printf("\n\nCadastrar outra disciplina?\n1 - Sim\n2 - Nao\nEscolha: ");
							scanf("%i", &escolha);
							if(escolha == 2){
								break;
							}
						}
						disciplinas = i + 1;
						system("cls");
						break;
					case 2:
						disciplinas_cadastradas(d);
						break;
				}
				break;
			}
	}while(escolha != 3);
	return 0;
}

void funcionarios_cadastrados(funcionario p[10]){
	int i;
	printf("\t\t\t\tFuncionarios cadastrados");
	for(i = 0; i < funcionarios; i++){
		printf("\n\nNome: %s\n", p[i].nome);
		printf("Idade: %i\tCPF: %i\n", p[i].idade, p[i].cpf);
		printf("Rua: %s\tNumero: %i\n\n", p[i].rua, p[i].numero);
	}
}

void disciplinas_cadastradas(disciplina d[10]){
	int i;
	printf("\t\t\tDisciplinas cadastradas");
	for(i = 0; i < disciplinas; i++){
		printf("\n\nDisciplina: %s\n", d[i].disciplina);
		printf("Curso: %s\tProfessor: %s\n", d[i].curso, d[i].professor);
		printf("Sala: %i\t\tTurno: %s\n", d[i].sala, d[i].turno);
		printf("Carga Horaria: %i\tTotal de alunos: %i\n\n", d[i].carga_horaria, d[i].qtd_alunos);
	}
}
