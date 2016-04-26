#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

/* Constantes */
#define tipo_usuario 1;
#define tipo_adm 0;

	/* Criando Structs */
	struct registro_rc{
		char usuario_vinculado[30];
		char descricao[30];
		float valor;
		int vazio;
	} registro_receitas[30];

	struct registro_dp{
		char usuario_vinculado[30];
		char descricao[30];
		float valor;
		int vazio;
	} registro_despesa[30];

	struct registro_user{
		char cpf[12];
		char nome[30];
		int senha;
		int vazio;
		int tipo; /* 1 É gerente e 0 É usuário */
		int cod;
	} registro_usuarios[30];


	struct centro_custo{
		char cod[6];
		char nome[20];
		int vazio;
	} registro_cc[30];


	/* Variáveis globais */
	char cpf[12];
	char cod[6];

	/* Declarando o protótipo das funções criadas e que serão utilizadas no projeto */
	void cadastrar_usuario();
	void alterar_usuario();
	void cadastrar_receita();
	void cadastrar_despesa();
	void cadastrar_cc();
	void alterar_cc();
	void imprimir_receitas_adm(); //Receitas Geral _ ADM
	void imprimir_receitas();
	void imprimir_despesas_adm(); //Despesas Geral _ ADM
	void imprimir_despesas();
	void alterar_senha();
	void excluir_usuario();
	
	void menu_adm();
	void menu_user();
	
	void imprimir_cc();

	int verificareceita();
	int verifica_posuser();
	int verifica_pos();
	int verifica_poscc();
	
	int main () {		
		
		/* Log e Logsenha, utilizados para tratamento de erros - Falta Implementar */
			int log = 0;
			int logsenha = 0;
			int senha = 0;
			int erro = 0;

		do {
			/* Implemento a primeira posição da struct com um usuário adm padrão */
			strcpy(registro_usuarios[0].cpf , "admin");
			strcpy(registro_usuarios[0].nome, "Administrador");
			registro_usuarios[0].senha = 123;
			registro_usuarios[0].vazio = 1;
			registro_usuarios[0].tipo = tipo_adm;
			
			/* Implemento a segunda posição da struct com um usuário padrão PARA TESTE */
			strcpy(registro_usuarios[1].cpf , "1");
			strcpy(registro_usuarios[1].nome, "1");	
			registro_usuarios[1].senha = 1;
			registro_usuarios[1].vazio = 1;
			registro_usuarios[1].tipo = tipo_usuario;			
		
			system("cls");
	                
			printf ("---------------------------------------------------------\n");
			printf ("------------------------BEM-VINDO------------------------\n");
			printf ("---------------------------------------------------------\n");
                
			printf ("\n\tusuario (CPF): ");
			scanf ("%s", &cpf);
    	
			int i = 0;           
		
			while (i <= 30) {

				if (strcmp(registro_usuarios[i].cpf, cpf) == 0) {
					if (registro_usuarios[i].vazio == 1) {						
						printf ("\tsenha: ");
						scanf ("%i", &senha);						
							if (registro_usuarios[i].senha == senha) {	
														
									log = 1;
									logsenha = 1;
									erro = 1;
									
										if (registro_usuarios[i].tipo == 0) {
											menu_adm ();		
										}
										
										else {
											menu_user();
										}
									
									break;
							}
                                                                                              
							else {
								logsenha = 0;
								erro == 0;
								printf ("\n\tSenha Invalida");
								Sleep(1000);
								break;
							}
					}
				}
			
				i ++;

			}					
		} while (log != 1);		
	}

void menu_adm () {
	
	int opcao = 0;

	do {
	
		system("cls");

		printf ("\n\t1 - Cadastrar Usuario");		
		printf ("\n\t2 - Cadastrar Centro de Custo");
		printf ("\n\t3 - Excluir Usuario");
		printf ("\n\t4 - Alterar Centro de Custo");	
		printf ("\n\t5 - Imprimir CC");
		printf ("\n\t6 - Imprimir Total de Receitas");
		printf ("\n\t7 - Imprimir Total de Despesas");
		printf ("\n\t8 - Voltar");
			
		printf ("\n\tOpcao: ");
		scanf ("%i", &opcao);
		
		switch (opcao) {
			
			case 1: {
				cadastrar_usuario();
				break;
			}
			
			case 2: {
				cadastrar_cc();
				break;
			}
			
			case 3: {
				excluir_usuario();
				break;
			}
			
			case 4: {
				alterar_cc();
				break;
			}
			
			case 5: {
				imprimir_cc();
				break;
			}
			
			case 6: {
				imprimir_receitas_adm();
				break;
			}
			
			case 7: {
				imprimir_despesas_adm();
				break;
			}
			
			case 8: {
				main();
				break;
			}
			
			default: printf ("\n\tOpcao Invalida\n");
			Sleep (1000);

		}

	} while (opcao != 8);

	getch ();

}

void menu_user(){
	
	int opcao = 0;

	do {
	
		system("cls");

		printf ("\n\t1 - Cadastrar Receita");
		printf ("\n\t2 - Cadastrar Despesa");
		printf ("\n\t3 - Imprimir Receitas");
		printf ("\n\t4 - Imprimir Despesas");
		printf ("\n\t5 - Trocar Senha");
		printf ("\n\t6 - Voltar");
		
		printf ("\n\n\tOpcao: ");
		scanf ("%i", &opcao);
		
		system("cls");
		
		switch (opcao) {
			
			case 1: {
				cadastrar_receita();
				system("cls");
				break;
			}
			
			case 2: {
				cadastrar_despesa();
				system("cls");
				break;
			}
			
			case 3: {
				imprimir_receitas();
				system("cls");
				break;	
			}
			
			case 4: {
				imprimir_despesas();
				system("cls");
				break;
			}
			
			case 5: {
				alterar_senha();
				system("cls");
			}
			
			case 6: {
				main();
			}
			
			default: printf ("\n\tOpcao Invalida\n");
			Sleep (1000);					
		}
	} while (opcao != 6);
}

void cadastrar_receita() {
	
	int i = 0;
	int j = 0;
	float valor;
	char descricao[30];

	system("cls");

	printf ("---------------------------------------------------------\n");
	printf ("       				Cadastro de Receita				  \n");
	printf ("---------------------------------------------------------\n");
	
	printf ("\t \t \t \t   Usuario logado: %s\n", &cpf);
	
	printf ("Descricao da Receita: ");
	scanf ("%s", &descricao);
	
	while (i <= 30) {
		
		if (strcmp (cpf, registro_usuarios[i].cpf) == 0) {
			
			while (j <= 30) {
				
				if (registro_receitas[j].vazio == 0) {	
					strcpy(registro_receitas[j].usuario_vinculado, cpf);
					strcpy(registro_receitas[j].descricao, descricao);				
					registro_receitas[j].vazio = 1;
					
					printf ("Valor: R$ ");
					scanf ("%f", &registro_receitas[j].valor);		

					j = 30;
				
				}
				
				j ++;
				
			}
				
		}
		
		i ++;		
		
	}
					
		Sleep(2000);	
		system("cls");	
	
}

void cadastrar_despesa() {
	int i = 0;
	int j = 0;
	float valor;
	char descricao[30];

	system("cls");

	printf ("---------------------------------------------------------\n");
	printf ("       				Cadastro de Despesa				  \n");
	printf ("---------------------------------------------------------\n");
	
	printf ("\t \t \t \t   Usuario logado: %s\n", &cpf);
	
	printf ("Descricao da Receita: ");
	scanf ("%s", &descricao);
	
	while (i <= 30) {
		
		if (strcmp (cpf, registro_usuarios[i].cpf) == 0) {
			
			while (j <= 30) {
				
				if (registro_despesa[j].vazio == 0) {	
					strcpy(registro_despesa[j].usuario_vinculado, cpf);
					strcpy(registro_despesa[j].descricao, descricao);				
					registro_despesa[j].vazio = 1;
					
					printf ("Valor: R$ ");
					scanf ("%f", &registro_despesa[j].valor);		
					break;
				
				}
				
				j ++;
				
			}
				
		}
		
		i ++;		
		
	}
					
		Sleep(2000);	
		system("cls");	
	
}



void cadastrar_usuario () {
	
	int i = 0;
            
	system("cls");

	printf ("---------------------------------------------------------\n");
	printf ("\t\t\tConsulta CPF \t \t\n");
	printf ("---------------------------------------------------------\n");
            
	printf ("\n\tIdentificacao (CPF): ");
	scanf ("%s", &cpf);
	fflush (stdin);
	
	while (i < 30) {
		if (strcmp (cpf, registro_usuarios[i].cpf) == 0) {
			if (registro_usuarios[i].vazio == 1) {
				printf ("\n\tUsuario ja possui cadastro");
				Sleep (2000);
				break;
			}
		}
	
		i ++;
		
	}
		
		if (i >= 30) {
			
			i = verifica_posuser();
		
			strcpy(registro_usuarios[i].cpf, cpf);
		
    		printf("\n\tNome: ");
    		gets(registro_usuarios[i].nome);
    		fflush (stdin);
    
    		printf ("\tSenha: ");
	   		scanf ("%i", &registro_usuarios[i].senha);
    		fflush (stdin);
	
			registro_usuarios[i].vazio = 1;
			registro_usuarios[i].tipo = 1;
	
			printf("\tUsuario Cadastrado!\n\n");
		
		}		
	Sleep(2000);	
	system("cls");	
}

void cadastrar_cc() {
	
	system("cls");
	
	printf ("---------------------------------------------------------\n");
	printf ("\t\t\tCadastrar CC \t \t\n");
	printf ("---------------------------------------------------------\n");
	
	int i = 0;
	
	printf ("Digite o Codigo do Centro de Custo");
	scanf ("%s", &cod);
	
	while (i <= 30) {	
		if (strcmp (cod, registro_cc[i].cod) == 0) {
			if (registro_cc[i].vazio == 1) {
				printf ("Codigo ja Cadastrado");
				Sleep(1000);
				break;
			}
		}
		
		i ++;	
		
	}
	
	if (i > 30) {
			
		i = verifica_poscc();
		
			if (registro_cc[i].vazio == 0) {
			
				strcpy(registro_cc[i].cod, cod);
				
				printf ("Nome: ");
				fflush (stdin);
				gets(registro_cc[i].nome);	
				fflush (stdin);
								
				registro_cc[i].vazio = 1;
	
				printf("\tUsuario Cadastrado!\n\n");
				Sleep(2000);
			}		
	}
	
}



void alterar_senha () {

	int i = 0;
	
	while (i <= 30) {
		
		if (strcmp(registro_usuarios[i].cpf, cpf) == 0) {
			printf ("\n\tDigite nova senha: ");
			scanf ("%i", &registro_usuarios[i].senha);
			fflush (stdin);
				
			printf ("\n\tSenha alterada com sucesso.");
			Sleep (2000);
			break;
		}
		
		i ++;
		
	}
}


void imprimir_cc () {
	
	int i = 0;
	
	while (i <= 30) {
			if (registro_cc[i].vazio == 1) {
				printf ("\nCodigo: %s", &registro_cc[i].cod);
				printf ("\nNome: %s", &registro_cc[i].nome);
			}			
		i ++;		
	}
	
	Sleep(2000);
}


void imprimir_receitas_adm() {
	
	double total = 0;
	
	int i = 0;
	
	while (i <= 30) {
			if (registro_receitas[i].vazio == 1) {
				total = total + registro_receitas[i].valor;
			}			
		i ++;		
	}
	
	printf ("\n\tTotal de Receitas: R$ %.2f", total);
	Sleep(2000);
	
}

void imprimir_receitas() {
	
	double total = 0;
	
	int i = 0;
	
	while (i <= 30) {		
		if (strcmp(registro_receitas[i].usuario_vinculado, cpf) == 0) {
				total = total + registro_receitas[i].valor;
		}
			
			i ++;

	}
		
		printf ("\n\tTotal de Receitas: R$ %.2f", total);
		Sleep(2000);
}

void imprimir_despesas() {
	
	double total = 0;
	
	int i = 0;
	
	while (i <= 30) {		
		if (strcmp(registro_despesa[i].usuario_vinculado, cpf) == 0) {
				total = total + registro_despesa[i].valor;			
		}
			
			i ++;

	}
		
		printf ("\n\tTotal de Despesas: R$ %.2f", total);
		Sleep(2000);
}

void imprimir_despesas_adm() {
	
	double total = 0;
	
	int i = 0;
	
	while (i <= 30) {
			if (registro_despesa[i].vazio == 1) {
				total = total + registro_despesa[i].valor;
			}			
		i ++;		
	}
	
	printf ("\n\tTotal de Despesas: R$ %.2f", total);
	
	Sleep(2000);	
	
}

void excluir_usuario() {
	
	int i = 0;
	
	printf ("Informe CPF do usuario: ");
	scanf ("%s", &cpf);
	
	while (i <= 30) {	
		if (strcmp (cpf, registro_usuarios[i].cpf) == 0) {
			if (registro_usuarios[i].vazio == 1) {			
				strcpy(registro_usuarios[i].cpf, " ");
				registro_usuarios[i].vazio = 0;				
				break;
			}
		}
		
		i ++;	
		
	}
	
	i = 0;
	
	while (i <= 30) {	
		if (strcmp (cpf, registro_despesa[i].usuario_vinculado) == 0) {
			if (registro_despesa[i].vazio == 1) {				
				strcpy(registro_despesa[i].usuario_vinculado, "");
				registro_despesa[i].vazio = 0;				
				break;
			}
		}
		
		i ++;	
		
	}
	
	i = 0;
	
	while (i <= 30) {	
		if (strcmp (cpf, registro_receitas[i].usuario_vinculado) == 0) {
			if (registro_receitas[i].vazio == 1) {
				
				strcpy(registro_receitas[i].usuario_vinculado, "");
				registro_receitas[i].vazio = 0;
				break;
			}
		}
		
		i ++;	
		
	}
	
	printf ("\n\tUsuario Excluido\n");
	Sleep(1000);

}

void alterar_cc() {
	
	int i = 0;
	
	printf ("Informe o codigo do Centro de Custo: ");
	scanf ("%s", &cod);
	
	while (i <= 30) {
		
		if (strcmp(registro_cc[i].cod , cod) == 0) {
			printf ("\n\tDigite novo codigo: ");
			scanf ("%s", &registro_cc[i].cod);
			fflush (stdin);
			printf ("Digite novo nome: ");
			scanf ("%s", registro_cc[i].nome);
							
			printf ("\n\tCentro de Custo Alterado.");
			Sleep (2000);
			break;
		}
		
		i ++;
		
	}
		
}

int verifica_pos () {
	
	int i = 0;
	while (i <= 30) {
		if (registro_usuarios[i].vazio == 0)
			return (i);
			i ++;
	}
	return (-1);
}

int verifica_posuser () {	
	int i = 0;
	while (i <= 30) {
		if (registro_usuarios[i].vazio == 0)
			return (i);
			i ++;
	}
	return (-1);
}

int verifica_poscc () {	
	int i = 0;
	while (i <= 30) {
		if (registro_cc[i].vazio == 0)
			return (i);
			i ++;
	}		
	return (-1);
}

int verifica_posreceita () {	
	int i = 0;
	while (i <= 30) {
		if (registro_usuarios[i].vazio == 0)
			return (i);
			i ++;
	}
	return (-1);
}
