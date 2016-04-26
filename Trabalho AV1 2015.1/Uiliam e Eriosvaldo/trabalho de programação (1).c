	# include <stdlib.h>
	# include <stdio.h>
	# include <conio.h>
	# include <windows.h>
	# define SIZE 200
	#include <string.h>


	//VARIAVEIS GLOBAIS DO ALUNO//
	struct Aluno{
	char nome[50];
	int idade;
	char bairro[50];
	char curso [50];
	char email[50];
	char turno[50];
	int codigo;
	};

	struct professor{
		char nome[50];
		char disciplina[50];
		char turno_p[50];
	};

	// VETOR DE STRUCT//
	struct Aluno *a;
	int cont_aluno=0;

	struct professor lista_professor[SIZE];
	int cont_professor=0;

	// VARIAVEIS GLOBAIS EM GERAL//
	int procurar, procurar_p;
	int buscar, buscar_p;
	int op,i;
	char escolha;
    char escolha_p[50];
	char modificar[50] ;
	 int lista = 0;


	// FUN합ES CADASTRAR, EXIBIR, PESQUISAR & ALTERAR//
	void cadastro( struct Aluno *a );
	void exibir( struct Aluno *a );
	void pesquisar( struct Aluno *a );
	void alterar( struct Aluno *a );





	// ------------------------------------------ FUN플O PRINCIPAL ---------------------------------------//
	int main(void){

	int senha, u;
	senha=1234;



	system("color 79");
	printf("\n\n\n\n\n\n\n");
	printf("\n         | ------------------------------------------------------------- |");
	printf("\n         | ----------------------- BEM VINDO --------------------------- |");
	printf("\n         |---------------------------------------------------------------|");
	printf("\n         | ---------------------- DOM PEDRO II ------------------------- |");
	printf("\n         |---------------------------------------------------------------|");

	Sleep(1000);
	system("cls");

	// --------------------------------- CODIGO DE SEGURAN플 ----------------------------//
	do{
	printf("\n\n\n\n\n");
	printf("  | ----------------------------------------------------------------------- |\n");
	printf("  |                              ACESSO RESTRITO                            |\n");
	printf("  | ----------------------------------------------------------------------- |\n");
	printf("  |                           DIGITE A SENHA DE ACESSO                      |\n");
	printf("  | ----------------------------------------------------------------------- |\n");
	printf("\n\n              SENHA DE ACESSO :  ");
	scanf("%d",&u);
	fflush(stdin);

		if(senha==u){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n                            ACESSO LIBERADO");
		Sleep(1000);
		Sleep(1000);
		system("cls");
		}else{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n                           ACESSO NEGADO");
		getch();
		system("cls");
		}
	}while(senha!=u);

	// -----------------------------------MENU-------------------------------------------------//

	do{
		printf("\n\n\n");

	printf("\n         | ------------------------------------------------------------- |");
	printf("\n         |                              MENU                             |");
	printf("\n         | ------------------------------------------------------------- |");
	printf("\n         | --------------------------------------------------------------|");
	printf("\n         |    1 - CADASTRAR        ALUNOS                                |");
	printf("\n         | --------------------------------------------------------------|");
	printf("\n         |    2 - EXIBIR           ALUNOS                                |");
	printf("\n         | --------------------------------------------------------------|");
	printf("\n         |    3 - PESQUISAR        ALUNOS                                |");
	printf("\n         | --------------------------------------------------------------|");
	printf("\n         |    4 - ALTERAR          ALUNOS                                |");
	printf("\n         | --------------------------------------------------------------|");
	printf("\n         |    5 - CADASTRA        PROFESSOR                              |");
	printf("\n         | ------------------------------------------------------------- |");
	printf("\n         |    6 - PESQUISAR       PROFESSOR                              |");
	printf("\n         | --------------------------------------------------------------|");
	printf("\n         |    7 - ALTERAR         PROFESSOR                              |");
	printf("\n         | --------------------------------------------------------------|");
	printf("\n         |    8 - SAIR                                                   |");
	printf("\n         | --------------------------------------------------------------|");

	printf("\n\n");
	printf("              * DIGITE O NUMERO DA OPCAO DESEJADA : ");
	scanf("%d",&op);
	fflush(stdin);

		switch(op){


			case 1:
				system("cls");
				a = malloc(200*sizeof(struct Aluno));
				cadastro(a);
				break;

			case 2:
				system("cls");
				a = malloc(200*sizeof(struct Aluno));
				exibir(a);
				break;

			case 3:
				system("cls");
				a = malloc(200*sizeof(struct Aluno));
				pesquisar(a);
				break;

			case 4:
				system("cls");
				a = malloc(200*sizeof(struct Aluno));
				alterar(a);
				break;

			case 5:
				system("cls");


				for(i=cont_professor; i<SIZE; i++){
					printf("\n ------------------------- CADASTRAR PROFESSOR --------------------------- ");
					printf("\n DIGITE O NOME       : ");
					scanf("%s",&lista_professor[i].nome);
					printf("\n DIGITE A DISCIPLINA : ");
					scanf("%s",&lista_professor[i].disciplina);
					printf("\n DIGITE O TURNO      : ");
					scanf("%s",&lista_professor[i].turno_p);
					printf("\n\n DIGITE O '1' PARA CONINUAR OU OUTRO PARA ENCERRAR CADASTRO : ");
					scanf("%d",&op);
					cont_professor++;
					fflush(stdin);
				    if(op!=1)
                       break;
				}
				system("cls");
				break;

			case 6:
				system("cls");

				printf("\n ------------------------- PESQUISAR PROFESSOR -------------------------------- ");
				printf("\n\n");
				printf("\n DIGITE O NOME DO PROFESSOR: ");
				gets(modificar);
				fflush(stdin);
				for(i=0; i<cont_professor; i++){
					if(strcmp(modificar , lista_professor[i].nome) == 0){
									printf("\n\n NOME DO PROFESSOR       : %s",lista_professor[i].nome);
									printf("\n\n DISCIPLINA DO PROFESSOR : %s",lista_professor[i].disciplina);
									printf("\n\n");
                                    getch();
                                    break;
					}
                 }
                 break;
			case 7:
				do{

					system("cls");
					printf("\n ------------------------- ALTERAR PROFESSOR ----------------------------- ");
					printf("\n\n");
					printf("\n DIGITE O NOME DO PROFESSOR: ");
					gets(escolha_p);
					fflush(stdin);
					for(i=0; i<SIZE; i++){
					if(strcmp(escolha_p ,lista_professor[i].nome) == 0){
						printf("\n");
						printf("\n  DIGITE O NOME        : ");
						scanf("%s",&lista_professor[i].nome);
						fflush(stdin);
						printf("\n  DIGITE A DISCIPLINA  : ");
						scanf("%s",&lista_professor[i].disciplina);
						fflush(stdin);
						printf("\n  DIGITE O TURNO       : ");
						scanf("%s",&lista_professor[i].turno_p);
						fflush(stdin);
						}else
						{
							printf("\n\n\n NOME INCORRETO\n\n");
							break;
						}
					}
					printf("\n PARA CONTINUAR ALTERARANDO APERTE '1' SE NAO APERTE OUTRA TECLA: ");
					scanf("%d",&op);
					fflush(stdin);
					system("cls");
	   			}while(op==1);

				break;

				getch();
				break;
				}

		}while(op<8);
		system("cls");
		printf("\n\n\n\n\n\n ENCERRANDO SISTEMA...");
		Sleep(1000);
		Sleep(1000);
		printf("\n\n\n\n\n\n\n------------------FIM-------------------------");
		fflush(stdin);
		Sleep(1000);
		Sleep(1000);
        Sleep(1000);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		system("pause");
	}

	// ---------------------------------- FUN플O CADASTRO --------------------------------------//
	void cadastro( struct Aluno *a){

		printf("\n -------------------------CADASTRO DE ALUNO --------------------------------- ");
		printf("\n\n");
		int i;
		 FILE *aluno;
    	  aluno=fopen("dados.txt","u");

		for(i = cont_aluno;i<SIZE; i++){
			printf("\n  DIGITE O NOME .................  : ");
			scanf("%s", &a->nome);
			fprintf(aluno, "%s\n", a->nome);
			fflush(stdin);

			printf("\n  DIGITE A IDADE ................. : ");
			scanf("%d",&a->idade);
			fprintf(aluno, "%d\n", a->idade);
			fflush(stdin);

			printf("\n  DIGITE O BAIRRO ................ : ");
			scanf("%s",&a->bairro);
			fprintf(aluno, "%s\n", a->bairro);
			fflush(stdin);

		    printf("\n  DIGITE O CURSO ................. : ");
			scanf("%s",&a->curso);
			fprintf(aluno, "%s\n", a->curso);
			fflush(stdin);

		    printf("\n  DIGITE O EMAIL ................. : ");
			scanf("%s",&a->email);
			fprintf(aluno, "%s\n", a->email);
			fflush(stdin);

		    printf("\n  DIGITE O TURNO ................. : ");
			scanf("%s",&a->turno);
			fprintf(aluno, "%s\n", a->turno);
			fflush(stdin);

			printf("\n  DIGITE UM CODIGO PARA ENTRADA .. : ");
			scanf("%d",&a->codigo);
			fprintf(aluno, "%d\n", a->codigo);
			fflush(stdin);

	        cont_aluno++;
			printf("\n DIGITE O '1' PARA CONINUAR OU OUTRO PARA ENCERRAR CADASTRO : ");
			scanf("%d",&op);
			fflush(stdin);
			printf("\n --------------------------------------------------------------------------\n");
			if(op!=1)
	            break;

		}
		fclose(aluno);

 	 system("cls");
	}

	// ------------------------------------ FUN플O EXIBIR ------------------------------------------//
	void exibir(struct Aluno *a){
	int i;

	system("cls");
	printf("\n -------------------------EXIBIR ALUNO ------------------------------------- ");
	printf("\n\n");
		for(i=0; i<cont_aluno; i++){
	       printf("\n Nome.........:%s\n",a->nome);
	       printf("\n Nome.........:%d\n",a->idade);
	       printf("\n Nome.........:%s\n",a->bairro);
	       printf("\n Nome.........:%s\n",a->curso);
	       printf("\n Nome.........:%s\n",a->email);
	       printf("\n Nome.........:%s\n",a->turno);
	       printf("\n Nome.........:%d\n",a->codigo);
	       printf("\n\n");
		}
		getch();
	system("cls");
	}


	// ----------------------------------- FUN플O PESQUISA -----------------------------------//
	void pesquisar(struct Aluno *a){

		do{
			system("cls");
			printf("\n ------------------------- PESQUISAR ALUNO -------------------------------- ");
			printf("\n\n");
			printf("\n DIGITE O CODIGO DO ALUNO QUE DESEJA PESQUISA : ");
			scanf("%d",&procurar);
			fflush(stdin);

			for(i=0; i<=cont_aluno; i++){
				if(!strcmp((a+i)->codigo,procurar)==0){

				  	printf("\n Nome.........:%s\n",a->nome);
                    printf("\n Nome.........:%d\n",a->idade);
                    printf("\n Nome.........:%s\n",a->bairro);
                    printf("\n Nome.........:%s\n",a->curso);
                    printf("\n Nome.........:%s\n",a->email);
                    printf("\n Nome.........:%s\n",a->turno);
                    printf("\n Nome.........:%s\n",a->codigo);
                    printf("\n\n");


			}
		printf("\n\n\n APERTE '1' PARA CONTINUAR PESQUISANDO E OUTRA TECLA PARA ENCERRAR PESQUISA : ");
		scanf("%d",&op);
		fflush(stdin);
		system("cls");

		}while(op==1);


	}


	// --------------------------------- FUN플O ALTERAR ---------------------------------------//
	void alterar(struct Aluno *a){

		do{

		system("cls");
		printf("\n ------------------------- ALTERAR ALUNO --------------------------------- ");
		printf("\n");
		printf("\n DIGITE O CODIGO DO ALUNO QUE DESEJA ALTERAR: ");
		scanf("%d",&buscar);
		fflush(stdin);

			for(i=0; i<cont_aluno; i++){
				if(!strcmp((a+i)->codigo,buscar)==0){
					printf("\n");
					printf("\n  DIGITE O NOME   : ");
					scanf("%s",&a->nome);
					fflush(stdin);
					printf("\n  DIGITE A IDADE  : ");
					scanf("%d",&a->idade);
					fflush(stdin);
					printf("\n  DIGITE O BAIRRO : ");
					scanf("%S",&a->bairro);
					fflush(stdin);
					printf("\n  DIGITE O CURSO  : ");
					scanf("%s",&->curso);
					fflush(stdin);
					printf("\n  DIGITE O EMAIL  : ");
					scanf("%s",&a->email);
					fflush(stdin);
					printf("\n  DIGITE O TURNO  : ");
					scanf("%s",&a->turno);
					fflush(stdin);
					printf("\n  DIGITE O CODIGO : ");
					scanf("%d",&a->codigo);
					fflush(stdin);
					system("cls");
				}



		printf("\n PARA CONTINUAR PESQUISANDO PARA ALTERAR APERTE '1' SE NAO APERTE OUTRA TECLA: ");
		scanf("%d",&op);
		fflush(stdin);
		system("cls");
	   }while(op==1);

	}

