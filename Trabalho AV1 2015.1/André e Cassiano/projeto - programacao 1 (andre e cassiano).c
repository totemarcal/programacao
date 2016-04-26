/*	Faculdade Dom Pedro II - Sistemas de Informação
	3º Semestre - Programação I

	Componentes: Cassiano Vellames
				 André Luiz

	Objetivo: Controlar na medida do possivel funcionarios e itens, gerando um relatório de movimentação de itens

	Observações: Não foi criado um padrão de programação definido ou feita uma analise mais critica, porem a dupla tem total ciencia que em um projeto real,
				 diversos outros fatores devem ser levados em conta.
				 Obviamente existe funcional¯\_(ツ)_/¯idades básicas em um sistema de controle de estoque que não foram encaixadas nesse programa por se tratar de um
				 aplicativo meramente didatico
*/

// Inclusao das bibliotecas usadas no projeto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES
#define NUM_MAX_REGISTROS 100
#define NUM_MAX_ESTOQUE 10000
#define NUM_MIN_ESTOQUE 0
#define NUM_MAX_MOVEST 999999

// DECLARAÇÃO DOS STRUCTS
struct Funcionarios{
	char Nome[100];
	char Nascimento[10];
	char Telefone[15];
	char Celular[15];
	char Cargo[50];
}typedef Funcionarios;

struct Itens{
	char Nome[100];
	char Quantidade[10];
	char Categoria[40];
}typedef Itens;

struct MovimentacaoEstoque{
	char Funcionario[100];
	char Item[100];
	char QtdInicial[10];
	char QtdFinal[10];
}typedef MovimentacaoEstoque;

// VARIAVEIS GLOBAIS
Itens 		 		VetorItens[NUM_MAX_REGISTROS];
Funcionarios 		VetorFuncionarios[NUM_MAX_REGISTROS];
MovimentacaoEstoque VetorMovEst[NUM_MAX_MOVEST];

int PosicaoItens 		= 0;
int PosicaoFuncionarios = 0;
int PosicaoMovEst 		= 0;
char FuncionarioLogado[100];

//Função de Login
int fncLogar(char usuario[32], char senha[32]);
int fncLogarFuncionario(char funcionario[100]);

// Funções de Menu
void fncMenuPrincipal();
void fncSubMenuFuncionarioItem(int menu);
void fncSubMenuEstoque();
void fncSubMenuRelatorios();
void fncTelaProgramacao();

// Funções de Validação
int fncValidaNumero(char num[20]);

// Funções de Funcionario
void fncCadastraFuncionario();
void fncConsultaTodosFuncionarios();
void fncConsultaFuncionarioPersonalizada(char consulta[200]);
void fncAlteraFuncionario(char altera[200]);
void fncNomeFuncionario();
void fncDeletaFuncionario(char funcionario[200]);

// Funções de Item
void fncCadastraItem();
void fncConsultaTodosItens();
void fncConsultaItemPersonalizada(char consulta[200]);
void fncAlteraItem(char altera[200]);
void fncDeletaItem(char item[200]);

// Funções de estoque
void fncInsereItem(char item[100], int quantidade);
void fncRetiraItem(char item[100], int quantidade);

// Funções de relatório
int fncMovimentacaoEstoque(char Funcionario[100], char Item[100], char QtdInicial[10], char QtdFinal[10]);
void fncExibeRelatorio();

// Função principal
void main(){ //OK
	//Login
	int tentativas = 0;
	int sucesso = 1;
	const int MAX_TENTATIVAS = 3;

	char login[32];
	char senha[32];
	do{
		tentativas++;
		system("cls");
		if (tentativas > 1)
			printf("\nLOGIN OU SENHA ERRADO(S), TENTE NOVAMENTE.(TENTATIVA %i DE %i.\n",tentativas,MAX_TENTATIVAS);
		// Pega os valores digitados para login e senha e implementa variavel de tentativas

fncTelaProgramacao();
printf("                             LOGIN -> ");		fflush(stdin);		gets(login);
printf("                             SENHA -> ");		fflush(stdin);		gets(senha);
		// Verifica se já foi estrapolado o numero maximo de tentativas
		if(tentativas == MAX_TENTATIVAS){
			sucesso = 0;
			printf("VOCE ESTRAPOLOU O N\751MERO M\665XIMO DE TENTATIVAS, O SISTEMA SER\665 FECHADO...\n");
			getch();
			goto PosLogin; // Brincadeirinha com GOTO apesar de não ser recomendado por bagunçar o fluxo do código estruturado xD
		}
	} while (fncLogar(login,senha) == 0);

	PosLogin: //GOTO
	if(sucesso == 0)
		getch();
	else
		fncMenuPrincipal();
}

// Menu principal da aplicação
void fncMenuPrincipal(){ //OK
	char Opcao[1];
	do {
		system("cls");
fncTelaProgramacao();
printf("                             [1] FUNCION\665RIO\n");
printf("                             [2] ITEM\n");
printf("                             [3] ESTOQUE\n");
printf("                             [4] RELAT\740RIO DE MOVIMENTA\200\707O DE ESTOQUE\n");
printf("                             [5] SAIR\n");
printf("                             ->  ");		fflush(stdin);		gets(Opcao);
	} while (fncValidaNumero(Opcao) == 0 || atoi(Opcao) > 5 || atoi(Opcao) < 1);


	switch(atoi(Opcao)){
		case 1:
		    	system("cls");
fncTelaProgramacao();
		    printf("                                 FUNCION\665RIO                                   \n\n");

			fncSubMenuFuncionarioItem(atoi(Opcao));
			break;
		case 2:
		    	system("cls");
fncTelaProgramacao();
            printf("                                 ITEM                                          \n\n");
			fncSubMenuFuncionarioItem(atoi(Opcao));
			break;
		case 3:
			fncSubMenuEstoque();
			break;
		case 4:
			fncExibeRelatorio();
			getch();
			break;
		case 5:
			printf("PRESSIONE QUALQUER TECLA PARA SAIR DO SISTEMA...\n\n");
			getch();
			break;
		default:
			fncMenuPrincipal();
			break;
	}
}

// Nessa função são chamadas outras funções relacionadas ao menu de funcionario e de item que possuem as mesmas caracteristicas
void fncSubMenuFuncionarioItem(int menu){//FUNCAO ALTERADA
	// Variavel que guarda a opção digitada
	char Opcao[1];
	// Guarda termo a ser pesquisado na consulta personalizada, Atualizar e Deletar
	char consultar[200];
	int loop = 0;

	do{
printf("                             [1] CADASTRAR                \n");
printf("                             [2] CONSULTAR TODOS     \n");
printf("                             [3] CONSULTA PERSONALIZADA     \n");
printf("                             [4] ATUALIZAR          \n");
printf("                             [5] DELETER             \n");
printf("                             [6] VOLTAR                 \n");
printf("                             ->  ");		fflush(stdin);		gets(Opcao);
	} while (fncValidaNumero(Opcao) == 0 || atoi(Opcao) > 6 || atoi(Opcao) < 1);

	puts(Opcao);

	switch(atoi(Opcao)){
		// Cadastrar
		case 1:
			switch(menu){
				// Funcionário
				case 1:
					fncCadastraFuncionario();
					break;
				// Item
				case 2:
					fncCadastraItem();
					break;
			}
		case 2:
		// Consultar Todos
			switch(menu){
				case 1:
					fncConsultaTodosFuncionarios();
					break;
				case 2:
					fncConsultaTodosItens();
					break;
			}
			break;
		case 3:
		// Consultar Personalizada
			switch(menu){
				case 1:
					// Recebe o nome a ser pesquisado
					system("cls");
					fncTelaProgramacao();
					// Garante que nenhum valor nulo será pesquisado
					do{
						if (loop > 0)
                        printf("CONSULTA PERSONALIZADA N\707O ACEITA PESQUISAS NULAS(VAZIAS).\n");
						printf("DIGITE O NOME DO FUNCION\665RIO A SER PESQUISADO. \n-> ");
						fflush(stdin);
						gets(consultar);
						loop++;
					} while(strlen(consultar) < 1);
					loop = 0;
					fncConsultaFuncionarioPersonalizada(consultar);
					break;
				case 2:
					// Recebe o nome a ser pesquisado
					system("cls");
					fncTelaProgramacao();
					// Garante que nenhum valor nulo será pesquisado
					do{
						if (loop > 0)
							printf("CONSULTA PERSONALIZADA N\707O ACEITA PESQUISAS NULAS(VAZIAS).\n");
						printf("DIGITE O NOME DO FUNCION\665RIO A SER PESQUISADO. \n-> ");
						fflush(stdin);
						gets(consultar);
						loop++;
					}while(strlen(consultar) < 1);
					loop = 0;
					fncConsultaItemPersonalizada(consultar);
					break;
			}
			break;
		case 4:
		// Alterar
			switch(menu){
				case 1:
					// Recebe o nome a ser pesquisado
					system("cls");
					fncTelaProgramacao();
					printf("DIGITE O NOME DO FUNCION\665RIO A SER ALTERADO. \n-> ");
					fflush(stdin);
					gets(consultar);
					fncAlteraFuncionario(consultar);
					break;
				case 2:
					// Recebe o nome a ser pesquisado
					system("cls");
					fncTelaProgramacao();
					printf("DIGITE O NOME DO ITEM A SER ALTERADO.\n-> ");
					fflush(stdin);
					gets(consultar);
					fncAlteraItem(consultar);
					break;
			}
			break;
		case 5:
			switch(menu){
				case 1:
					system("cls");
					fncTelaProgramacao();
					printf("DIGITE O NOME DO FUNCION\665RIO A SER DELETADO.\n-> ");
					gets(consultar);
					fncDeletaFuncionario(consultar);
					break;
				case 2:
					system("cls");
					fncTelaProgramacao();
					printf("DIGITE O NOME DO ITEM A SER DELETADO.\n-> ");
					gets(consultar);
					fncDeletaItem(consultar);
					break;
			}
			break;
		case 6:
			printf("PRESSIONE QUALQUER TECLA PARA VOLTAR...\n");
			getch();
			fncMenuPrincipal();
			break;
		default:
			fncMenuPrincipal();
			break;
	}
}

// Nessa função sao chamadas outras funções relacionadas ao estoque
void fncSubMenuEstoque(){
	char Opcao[1];
	char Item[100];
	char Quantidade[20];

	do{
		system("cls");
fncTelaProgramacao();
printf("                             [1] RETIRAR DO ESTOQUE    \n");
printf("                             [2] INSERIR NO ESTOQUE    \n");
printf("                             [3] VOLTAR                \n");
printf("                             ->  ");		fflush(stdin);		gets(Opcao);
	} while (fncValidaNumero(Opcao) == 0 || atoi(Opcao) > 3 || atoi(Opcao) < 1);

	switch(atoi(Opcao)){
		case 1:
			// Recebe e valida os campos
			system("cls");
			fncTelaProgramacao();
			printf("DIGITE O NOME DO ITEM A SER RETIRADO DO ESTOQUE.\n-> ");
			fflush(stdin);
			gets(Item);
			do{
				printf("\nDIGITE A QUANTIDADE A SER RETIRADA.\n-> ");
				fflush(stdin);
				gets(Quantidade);
			} while (fncValidaNumero(Quantidade) == 0);

			// Retira o item do estoque
			fncRetiraItem(Item,atoi(Quantidade));
			break;
		case 2:
			// Recebe e valida os campos
			system("cls");
			fncTelaProgramacao();
			printf("DIGITE O NOME DO ITEM A SER INSERIDO NO ESTOQUE.\n-> ");
			fflush(stdin);
			gets(Item);
			do{
				printf("\nDIGITE A QUANTIDADE A SER INSERIDA.\n-> ");
				fflush(stdin);
				gets(Quantidade);
			} while (fncValidaNumero(Quantidade) == 0);

			// Insere o item do estoque
			fncInsereItem(Item,atoi(Quantidade));
			break;
		case 3:
			fncMenuPrincipal();
			break;
		default:
			fncSubMenuEstoque();
			break;
	}
}

// Cadastra um funcionário
void fncCadastraFuncionario(){//FUNCAO ALTERADA
	char Opcao[1];
	int loop = 0;
	if(PosicaoFuncionarios<NUM_MAX_REGISTROS){
		do{
			system("cls");
fncTelaProgramacao();
			do{
				if(loop > 0)
					printf("NOME DO FUNCION\665RIO N\707O ACEITA VALORES NULOS(VAZIOS)\n");
				printf("                             NOME -> ");
				fflush(stdin);
				gets(VetorFuncionarios[PosicaoFuncionarios].Nome);
				loop++;
			} while (strlen(VetorFuncionarios[PosicaoFuncionarios].Nome) < 1);
			loop = 0;

			printf("                             DATA DE NASC. -> ");
			fflush(stdin);
			gets(VetorFuncionarios[PosicaoFuncionarios].Nascimento);

			printf("                             TELEFONE FIXO-> ");
			fflush(stdin);
			gets(VetorFuncionarios[PosicaoFuncionarios].Telefone);

			printf("                             TELEFONE CELULAR -> ");
			fflush(stdin);
			gets(VetorFuncionarios[PosicaoFuncionarios].Celular);

			printf("                             CARGO -> ");
			fflush(stdin);
			gets(VetorFuncionarios[PosicaoFuncionarios].Cargo);

			PosicaoFuncionarios++;

			printf("\n\n");

			printf("REGISTRO INSERIDO COM SUCESSO, DIGITE [1] PARA INSERIR UM NOVO REGISTO\n OU QUALQUER TECLA PARA VOLTAR...\n");
			gets(Opcao);
		}while((PosicaoFuncionarios<NUM_MAX_REGISTROS) && (atoi(Opcao) == 1));
	} else {
		printf("\n\n");
		printf("N\751MERO M\665XIMO DE REGISTROS SUPORTADO PELO SISTEMA, N\707O \220 POSS\726VEL GRAVAR MAIS\n NENHUM DADO EM FUNCION\665RIOS. PRESSIONE QUALQUER TECLA PARA VOLTAR...\n");
		getch();
	}
	fncMenuPrincipal();
}

/* Consulta todos os funcionários, sem nenhum filtro */
void fncConsultaTodosFuncionarios(){//FUNCAO ALTERADA
	int i;
	int reg = 1;
	system("cls");
	fncTelaProgramacao();
	for (i = 0; i < PosicaoFuncionarios; ++i){
		if((strlen(VetorFuncionarios[i].Nome) > 0) && (strlen(VetorFuncionarios[i].Nascimento) > 0) &&
		(strlen(VetorFuncionarios[i].Telefone) > 0) && (strlen(VetorFuncionarios[i].Celular) > 0) &&
		(strlen(VetorFuncionarios[i].Cargo) > 0) ){


printf("============================== REGISTRO N\751MERO: %i =============================\n\n", reg);
printf("                               NOME -> %s\n", 		VetorFuncionarios[i].Nome);
printf("                               DATA DE NASC. -> %s\n",  VetorFuncionarios[i].Nascimento);
printf("                               TELEFONE FIXO -> %s\n", 	VetorFuncionarios[i].Telefone);
printf("                               TELEFONE CELULAR -> %s\n", 	VetorFuncionarios[i].Celular);
printf("                               CARGO -> %s\n\n", 	VetorFuncionarios[i].Cargo);
			reg++;
		}

	}
	printf("PRESSIONE QUALQUER TECLA PARA VOLTAR...\n");
	getch();
	fncMenuPrincipal();
}

// Consulta os funcionários, porem com filtro de nome
void fncConsultaFuncionarioPersonalizada(char consulta[200]){
	system("cls");
	fncTelaProgramacao();
	int i;
	int encontrado = 0;
	// Percorre todo vetor
	for (i = 0; i < PosicaoFuncionarios; ++i){
		// Verifica se o nome atual é o mesmo do passado pelo parametro, se for imprime
if(strcmp(VetorFuncionarios[i].Nome,consulta) == 0){

printf("============================== REGISTRO N\751MERO: %i ============================\n", (i+1));
printf("                               NOME -> %s\n", 		VetorFuncionarios[i].Nome);
printf("                               DATA DE NASC. -> %s\n",  VetorFuncionarios[i].Nascimento);
printf("                               TELEFONE FIXO-> %s\n", 	VetorFuncionarios[i].Telefone);
printf("                               TELEFONE CELULAR -> %s\n", 	VetorFuncionarios[i].Celular);
printf("                               CARGO -> %s\n\n", 	VetorFuncionarios[i].Cargo);

			encontrado++;
		}
	}
	// Exibe mensagens
	if(encontrado == 0)
		printf("\n\nNENHUM REGISTRO FOI ENCONTRADO COM ESSAS CARACTER\726STICAS.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n");
	else if (encontrado == 1)
		printf("\n\nFOI ENCONTRADO %i REGISTRO.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	else
		printf("\n\nFORAM ECONTRADOS %i REGISTROS.\n PRESSIONE QUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	getch();
	fncMenuPrincipal();
}

// Altera um funcionário
void fncAlteraFuncionario(char altera[200]){
	system("cls");
	fncTelaProgramacao();
	int i;
	int encontrado = 0;
	int loop = 0;
	for (i = 0; i < PosicaoFuncionarios; ++i){
		// Verifica se o nome atual é o mesmo do passado pelo parametro
		if(strcmp(VetorFuncionarios[i].Nome,altera) == 0){
			printf("\nREGISTRO ENCONTRADO (N\751MERO %i). POR FAVOR DIGITE NOVOS VALORES DO REGISTRO.\n\n", (i+1));

			do{
				if(loop > 0)
					printf("NOME DO FUNCION\665RIO N\707O ACEITA VALORES NULOS(VAZIOS).\n");
				printf("                             NOME -> ");
				fflush(stdin);
				gets(VetorFuncionarios[i].Nome);
				loop++;
			} while (strlen(VetorFuncionarios[i].Nome) < 1);
			loop = 0;

			printf("                             DATA DE NASCIMENTO -> ");
			fflush(stdin);
			gets(VetorFuncionarios[i].Nascimento);

			printf("                             TELEFONE FIXO -> ");
			fflush(stdin);
			gets(VetorFuncionarios[i].Telefone);

			printf("                             TELEFONE CELULAR -> ");
			fflush(stdin);
			gets(VetorFuncionarios[i].Celular);

			printf("                             CARGO -> ");
			fflush(stdin);
			gets(VetorFuncionarios[i].Cargo);

			encontrado++;
		}
	}

	// Exibe mensagens
	if(encontrado == 0)
		printf("\n\nNENHUM REGISTRO FOI ENCONTRADO COM ESSAS CARACTER\726STICAS.\nPRESSIONAR QUALQUER TECLA PARA CONTINUAR...\n");
	else if (encontrado == 1)
		printf("\n\nFOI EDITADO %i REGISTRO.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	else
		printf("\n\nFORAM EDITADOS %i REGISTRADOS.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	getch();
	fncMenuPrincipal();
}

// Cadastra um item
void fncCadastraItem(){
	char Opcao[1];
	int loop = 0;
	if(PosicaoFuncionarios<NUM_MAX_REGISTROS){
		do{
			system("cls");
            fncTelaProgramacao();
			do{
				if(loop > 0)
					printf("NOME DO ITEM N\707O ACEITA VALORES NULOS/VAZIOS.\n");
							printf("                             NOME -> ");
				fflush(stdin);
				gets(VetorItens[PosicaoItens].Nome);
				loop++;
			} while(strlen(VetorItens[PosicaoItens].Nome) < 1);
			loop = 0;

			// Força um numero a ser inserido
			do{
				if (loop > 0)
					printf("\220 OBRIGAT\740RIO A DIGITA\200\707O DE UM N\751MERO.\n");
							printf("                             QUANTIDADE -> ");
				fflush(stdin);
				gets(VetorItens[PosicaoItens].Quantidade);
				loop++;
			} while (fncValidaNumero(VetorItens[PosicaoItens].Quantidade) == 0);
			loop = 0;

						printf("                             CATEGORIA -> ");
			fflush(stdin);
			gets(VetorItens[PosicaoItens].Categoria);

			PosicaoItens++;

			system("cls");
			fncTelaProgramacao();
			printf("REGISTRO INSERIDO COM SUCESSO, DIGITE [1] PARA INSERIR NOVO REGISTRO OU QUALQUER OUTRA TECLA PARA VOLTAR...\n");
			gets(Opcao);
		}while((PosicaoItens<NUM_MAX_REGISTROS) && (atoi(Opcao) == 1));
	} else {
		system("cls");
		fncTelaProgramacao();
		printf("N\751MERO M\665XIMO REGISTROS SUPORTADOS PELO SISTEMA. N\707O E POSS\726VEL GRAVAR MAIS NENHUM DADO EM ITENS. PRESSIONE QUALQUER TECLA PARA CONTINUAR...\n");
		getch();
	}
	fncMenuPrincipal();
}

// Consulta todos os itens, sem nenhum filtro
void fncConsultaTodosItens(){
	int i;
	// So conta o registros validos
	int reg = 1;
	system("cls");
	fncTelaProgramacao();
	for (i = 0; i < PosicaoItens; ++i){
		if( (strlen(VetorItens[i].Nome) > 0 ) && (strlen(VetorItens[i].Quantidade) > 0 ) && (strlen(VetorItens[i].Categoria) > 0 ) ){
			printf("============================== REGISTRO N\751MERO: %i ==============================\n", reg);
			printf("                               NOME -> %s\n", 		VetorItens[i].Nome);
			printf("                               QUANTIDADE -> %s\n",  VetorItens[i].Quantidade);
			printf("                               CATEGORIA -> %s\n\n", VetorItens[i].Categoria);
			reg++;
		}

	}
	printf("PRESSIONE QUALQUER TECLA PARA VOLTAR...\n");
	getch();
	fncMenuPrincipal();
}

// Consulta os itens, porem com filtro de nome
void fncConsultaItemPersonalizada(char consulta[200]){
	system("cls");
	fncTelaProgramacao();
	int i;
	int encontrado = 0;
	// Percorre todo vetor
	for (i = 0; i < PosicaoItens; ++i){
		// Verifica se o nome atual é o mesmo do passado pelo parametro, se for imprime
		if(strcmp(VetorItens[i].Nome,consulta) == 0){
			printf("============================== REGISTRO N\751MERO: %i ==============================\n", (i+1));
			printf("                               NOME -> %s\n", 		VetorItens[i].Nome);
			printf("                               QUANTIDADE -> %s\n",  VetorItens[i].Quantidade);
			printf("                               CATEGORIA -> %s\n\n", VetorItens[i].Categoria);

			encontrado++;
		}
	}
	// Exibe mensagens
	if(encontrado == 0)
		printf("\n\nNENHUM REGISTRO FOI ENCONTRADO COM ESSAS CARACTERI\726STICAS.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n");
	else if (encontrado == 1)
		printf("\n\nFOI ENCONTRADO %i REGISTRO.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	else
		printf("\n\nFORAM ENCONTRADOS %i REGISTROS.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	getch();
	fncMenuPrincipal();
}

// Altera um item
void fncAlteraItem(char altera[200]){
	system("cls");
	fncTelaProgramacao();
	int i;
	int encontrado = 0;
	int loop = 0;
	for (i = 0; i < PosicaoItens; ++i){
		// Verifica se o nome atual é o mesmo do passado pelo parametro
		if(strcmp(VetorItens[i].Nome,altera) == 0){
			printf("\nREGISTRO ENCONTRADO (N\751MERO %i). POR FAVOR DIGITE OS NOVOS VALORES DO REGISTRO.\n\n", (i+1));
			do{
				if(loop > 0)
					printf("NOME DO ITEM N\707O ACEITA VALORES NULOS/VAZIOS.\n");
				printf("                               NOME -> ");
				fflush(stdin);
				gets(VetorItens[i].Nome);
				loop++;
			} while(strlen(VetorItens[i].Nome) < 1);
			loop = 0;

			// Força um numero a ser inserido
			do{
				if (loop > 0)
					printf("\220 OBRIGAT\740RIO A DIGITA\200\740AO DE UM N\751MERO.\n");
				printf("                               QUANTIDADE -> ");
				fflush(stdin);
				gets(VetorItens[i].Quantidade);
				loop++;
			} while (fncValidaNumero(VetorItens[i].Quantidade) == 0);
			loop = 0;

			printf("                               CATEGORIA -> ");
			fflush(stdin);
			gets(VetorItens[i].Categoria);

			encontrado++;
		}
	}

	// Exibe mensagens
	if(encontrado == 0)
		printf("\n\nNEHUM REGISTRO FOI ENCONTRADO COM ESSAS CARACTER\726STICAS.\nPRESSIONE QUALQUER TELCLA PARA CONTINUAR...\n");
	else if (encontrado == 1)
		printf("\n\nFOI EDITADO %i REGISTRO.\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	else
		printf("\n\nFORAM DIGITADOS %i REGISTROS.\nPRESSIONEQUALQUER TECLA PARA CONTINUAR...\n", encontrado);
	getch();
	fncMenuPrincipal();
}

// Retira uma quantidade no item
void fncRetiraItem(char item[100], int quantidade){

	// Seta o nome do funcionário que irá dar baixa no estoque
	fncNomeFuncionario();

	// Verifica se item existe
	int i;
	int QuantidadeFinal;
	char QtdInicial[20];
	char QtdFinal[20];
	int Entrou = 0;
	char Opcao[1];

	// Percorre vetor a procura do item digitado
	for (i = 0; i < PosicaoItens; ++i){
		//Verifica se são iguais
		if(strcmp(VetorItens[i].Nome,item) == 0){
			Entrou = 1;
			// Atribuindo valores de quantidades
			QuantidadeFinal  = atoi(VetorItens[i].Quantidade) - quantidade;
			strcpy(QtdInicial,VetorItens[i].Quantidade);
			// Verifica se o novo valor do estoque ultrapassa o valor máximo permitido
			if(QuantidadeFinal < NUM_MIN_ESTOQUE){
				printf("\nA QUANTIDADE DESEJADA PARA RETIRADA DO ITEM, DEIXAR\665 O MESMO COM VALOR INFERIOR PELA REGRA DE NEG\740CIO, POR FAVOR TENTE NOVAMENTE...\n");
				getch();
				fncSubMenuEstoque();
			}
			else{
				itoa(QuantidadeFinal, QtdFinal ,10); // Converte INT para STRING
				strcpy(VetorItens[i].Quantidade,QtdFinal);
				if (fncMovimentacaoEstoque(FuncionarioLogado,VetorItens[i].Nome,QtdInicial,QtdFinal) == 1){
					printf("\nA QUANTIDADE DESEJADA FOI RETIRADA COM SUCESSO DO ESTOQUE. PRESSIONE [1] PARA REALIZAR UMA NOVA OPERA\200\707, OU QUALQUER OUTRA TECLA PARA RETORNAR AO MENU PRINCIPAL...\n-> ");
					fflush(stdin);
					gets(Opcao);
					if(strcmp(Opcao,"1") == 0)
						fncSubMenuEstoque();
					else
						fncMenuPrincipal();
				} else {
					printf("O N\751MERO M\665XIMO DE REGISTROS DE ESTOQUE FOIESTRAPOLADA. POREM A A\200\707 FOI COMPUTADA.\n");
					getch();
				}

			} // ELSE
		} // IF STRCMP
	} // FOR

	if(Entrou == 0){
		printf("\nITEM INEXISTENTE, TENTE NOVAMENTE...\n");
		getch();
		fncSubMenuEstoque();
	}
}

// Adiciona uma quantidade ao item
void fncInsereItem(char item[100], int quantidade){

	// Seta o nome do funcionário que irá dar baixa no estoque
	fncNomeFuncionario();

	// Verifica se item existe
	int i;
	int QuantidadeFinal;
	char QtdFinal[20];
	char QtdInicial[20];
	int Entrou = 0;
	char Opcao[1];

	// Percorre vetor a procura do item digitado
	for (i = 0; i < PosicaoItens; ++i){
		//Verifica se são iguais
		if(strcmp(VetorItens[i].Nome,item) == 0){
			Entrou = 1;
			// Atribuindo valores de quantidades
			QuantidadeFinal = atoi(VetorItens[i].Quantidade) + quantidade;
			strcpy(QtdInicial,VetorItens[i].Quantidade);
			// Verifica se o novo valor do estoque ultrapassa o valor máximo permitido
			if(QuantidadeFinal > NUM_MAX_ESTOQUE){
				printf("\nA QUANTIDADE DESEJADA PARA INSER\200\707ODO ITEM DEIXAR\665 O MESMO COM UM VALOR SUPERIOR AO DEFINIDO PELA REGRA DE NEG\740CIO, POR FAVOR TENTE NOVAMENTE.\n");
				getch();
				fncSubMenuEstoque();
			}
			else{
				itoa(QuantidadeFinal, QtdFinal ,10); // Converte INT para STRING
				strcpy(VetorItens[i].Quantidade,QtdFinal);
				if (fncMovimentacaoEstoque(FuncionarioLogado,VetorItens[i].Nome,QtdInicial,QtdFinal) == 1){
					printf("\nA QUANTIDADE DESEJADA FOI INSERIDA COM SUCESSO DO ESTOQUE.PRESSIONE [1] PARA REALIZAR UMA NOVA OPERA\200\707 OU PRESSIONE QUALQUER OUTRA TECLA PARA RETORNAR AO MENU PRINCIPAL.\n-> ");
					fflush(stdin);
					gets(Opcao);
					if(strcmp(Opcao,"1") == 0)
						fncSubMenuEstoque();
					else
						fncMenuPrincipal();
				} else {
					printf("O N\751MERO M\665XIMO DE REGISTROS DE ESTOQUE FOI ESTRAPOLADA. POREM A A\200\707O FOI COMPUTADA.\n");
					getch();
				}

			} // ELSE
		} // IF STRCMP
	} // FOR

	if(Entrou == 0){
		printf("\nITEM INEXISTENTE, POR FAVOR TENTE NOVAMENTE.\n-> ");
		getch();
		fncSubMenuEstoque();
	}
}

// Insere movimentação no vetor de estoque
int fncMovimentacaoEstoque(char Funcionario[100], char Item[100], char QtdInicial[10], char QtdFinal[10]){

	if(PosicaoMovEst == NUM_MAX_MOVEST)
		return 0;

	strcpy(VetorMovEst[PosicaoMovEst].Funcionario,Funcionario);
	strcpy(VetorMovEst[PosicaoMovEst].Item,Item);
	strcpy(VetorMovEst[PosicaoMovEst].QtdInicial,QtdInicial);
	strcpy(VetorMovEst[PosicaoMovEst].QtdFinal,QtdFinal);
	PosicaoMovEst++;
	return 1;
}

void fncExibeRelatorio(){
	int i;
	system("cls");
	fncTelaProgramacao();
	for (i = 0; i < PosicaoMovEst; ++i){

		printf("| FUNCION\665RIO : %s | ITEM : %s | QTD_INICIAL : %s | QTD_FINAL : %s |\n\n", VetorMovEst[i].Funcionario, VetorMovEst[i].Item, VetorMovEst[i].QtdInicial, VetorMovEst[i].QtdFinal);
	}
	puts("\nPRESSIONE QUALQUER TECLA PARA RETORNAR...");
	getch();
	fncMenuPrincipal();
}

/* Valida o login do usuário, se a entrada digitada for igual a do men*/
int fncLogar(char usuario[32], char senha[32]){
	if( (strcmp(usuario,"master") == 0) && (strcmp(senha,"master") == 0) )
		return 1;
	else
		return 0;
}

/* Valida se o valor digitado é um numero */
int fncValidaNumero(char num[20]){

	int i;
	for (i = 0; i < strlen(num); ++i)
	{
		if ((num[i] < 48) || (num[i] > 57)) return 0;
	}
	return 1;
}

void fncNomeFuncionario(){

	char Nome[200];
	int i;
	int achou = 0;

	printf("\nDIGITE O NOME DO USU\665RIO QUE IR\665 MOVIMENTAR NO ESTOQUE.\n-> ");
	gets(Nome);

	for (i = 0; i < PosicaoFuncionarios; ++i){
		if(strcmp(Nome,VetorFuncionarios[i].Nome) == 0){
			achou = 1;
			strcpy(FuncionarioLogado,VetorFuncionarios[i].Nome);
		}
	}

	if(achou == 0){
		printf("O FUNCION\665RIO N\707O FOI ENCONTRADO, VOC\722 SER\665 REDIRECIONADO PARA O MENU DE FUNCION\665RIO.\n");
		getch();
		fncSubMenuFuncionarioItem(1);
	}
}

void fncDeletaFuncionario(char funcionario[200]){
	int i;
	int entrou = 0;
	for (i = 0; i < PosicaoFuncionarios; ++i){
		// Verifica se o nome atual é o mesmo do passado pelo parametro
		if(strcmp(VetorFuncionarios[i].Nome,funcionario) == 0){
			// Finaliza string
			VetorFuncionarios[i].Nome[0] 		= '\0';
			VetorFuncionarios[i].Nascimento[0] 	= '\0';
			VetorFuncionarios[i].Telefone[0]  	= '\0';
			VetorFuncionarios[i].Celular[0]  	= '\0';
			VetorFuncionarios[i].Cargo[0]  		= '\0';
			printf("REGISTRO APAGADO COM SUCESSO.\n");
			entrou = 1;
		}
	}

	if(entrou = 0)
		printf("NENHUM REGISTRO COM ESSAS CARACTER\726STICAS FOI ENCONTRADO.\n");

	getch();
	fncSubMenuFuncionarioItem(1);
}

void fncDeletaItem(char item[200]){
	int i;
	int entrou = 0;
	for (i = 0; i < PosicaoItens; ++i){
		// Verifica se o nome atual é o mesmo do passado pelo parametro
		if(strcmp(VetorItens[i].Nome,item) == 0){
			// Finaliza string
			VetorItens[i].Nome[0] 		= '\0';
			VetorItens[i].Quantidade[0] = '\0';
			VetorItens[i].Categoria[0]  = '\0';
			printf("REGISTRO APAGADO COM SUCESSO.\n");
			entrou = 1;
		}
	}

	if(entrou = 0)
		printf("NENHUM REGISTRO COM ESSAS CARACTER\726STICAS FOI ENCONTRADO.\n");

	getch();
	fncSubMenuFuncionarioItem(2);
}

void fncTelaProgramacao(){
printf("===============================================================================\n");
printf("===    ___   ___   ___   ___   ___   ___   _    _   ___   ___  ___   ___    ===\n");
printf("===   |   | |   | |   | |   | |   | |   | | \\  / | |   | |    |   | |   |   ===\n");
printf("===   |___/ |___/ |   | | __  |___/ |___| |  \\/  | |___| |    |___| |   |   ===\n");
printf("===   |     |  \\  |   | |   | |  \\  |   | |      | |   | |    |   | |   |   ===\n");
printf("===   |     |   \\ |___/ |___| |   \\ |   | |      | |   | |___ |   | |___/   ===\n");
printf("===============================================================================\n\n");
}
