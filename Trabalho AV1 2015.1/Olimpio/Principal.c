#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void login();      //---------------funcao login   ----------------
void menu();       //---------------funcao menu   ----------------
void Linha();      //---------------funcao linha   ----------------
void cabecalho();  //---------------funcao do cabecalho--------------------
void cadastracli();//---------------funcao cadastrar  cliente ----------------
void mostrarcli(); //---------------funcao mostrar cliente   ----------------
void cadastraorc();//---------------funcao cadastrar  orcamento --------------
void mostrarorc(); //---------------funcao mostrar orcamento   ----------------
struct cliente{
  	char nome[30];
  	char endereco[30];
  	char bairro[20];
  	char cidade[20];
  	char cep[10];
  	char estado[2];
} cliente[2];

struct orcamento{
  	char nome[30];
  	char produto[30];
	int quant;
	float vlunitario;
	float vltotal;
} orcamento[2];
//------Menu ------------------
int main(int argc, char *argv[]) {
	int i;  int cli[4];
    system("color 1F");
	login();
    menu();
	return 0;	
}
 
 //---------------funcao login   ----------------
void login(){
int senha;
char usuario[30];
char key;
	do {
	    cabecalho();
		printf("Digte o usuario\n");
		printf("==>");
		gets(usuario);
		printf("\n\n");
		printf("Digite a senha\n");
		printf("==>");
		scanf("%i",&senha);
		fflush(stdin);
	}while (senha !=123|| strcmp(usuario,"admin"));
	system("cls");
}

//---------------funcao menu   ----------------
void menu(){	
	int opcao,opcaocli,opcaopro;
    cabecalho();
    printf("\n\n");
	printf("               1 - \tCadastro de cliente\n\n");
	printf("               2 - \tCadastro de proposta\n\n");
	printf("               3 - \tSair \n");
	printf("\n\n");
	Linha();printf("==\n");
	printf("==>");
	scanf("%i",&opcao);
	getchar ();
	system ("cls"); //limpa a tela;
	switch(opcao){
 	case 1: // manutencao dos dados do cliente
 	  system("color 9F");
 	  cabecalho();	
	  printf("             1 - Cadastrar cliente\n\n");
	  printf("             2 - Exibir cliente\n\n");
	  printf("             3 - Sair\n");	  
	  printf("\n\n");
	  Linha();printf("==\n");
	  printf("==>");	  
	  scanf("%i",&opcaocli);
	  getchar ();
	  system ("cls"); //limpa a tela;
	  switch(opcaocli){
 	  case 1:
 	  	system("color 9F");
 	  	cabecalho();
	    printf("           INCLUSAO DE CLIENTE \n");
		cadastracli();
		menu();
		break;
      case 2:
      	system("color 9F");
      	cabecalho();
	    printf("           Lista dos dados do cliente \n");		
 	    mostrarcli();
 	    system("pause");	
	    menu();
		break;
	   case 3:
	      menu(); 		 
		  printf("Saindo do sistema...");
		  break;
 	 }
 	 break;
 	case 2: // manutencao dos dados do proposta
 	  system("color 2F");
 	  cabecalho(); 
	  printf("             1 - Cadastrar proposta\n\n");
	  printf("             2 - Exibir proposta\n\n");
	  printf("             3 - Sair\n");	  
	  printf("\n\n");
	  Linha();printf("==\n");
	  printf("==>");
	  scanf("%i",&opcaopro);
	  getchar ();
	  switch(opcaopro){
 	  case 1:
 	  	system("color 2F");
 	  	cabecalho();
	    printf("           INCLUSAO DE PROPOSTA \n");		
	    cadastraorc();
	    menu();
 	  break;
      case 2:
	    system("color 2F");
 	  	cabecalho();
		printf("           Lista dos dados da proposta \n");		
		mostrarorc();
		system("pause");	
		menu();
 	  break;
 	  case 3:
      menu();  		 
	  printf("Saindo do sistema...");
	  break;
 	  }		
 	case 3:
      printf("Saindo do sistema...");
	  break;	  
	}	
}
//---------------funcao do cabecalho--------------------
void cabecalho(){ 
        system ("cls"); //limpa a tela;
     	printf("\n\n");
		printf("\n\n");
		printf("%c",201);Linha();printf("%c",187);
		printf("\n");
		printf("%c",186);printf("                      CADASTRO DE ORCAMENTO                 ");printf("%c\n",186);		
		printf("%c",200);Linha();printf("%c",188);
		printf("\n\n");		
}
//---------------funcao linha   ----------------
void Linha(){
	int ln;
	for (ln=0;ln<60;ln++){
		printf("=");		
	}
}
//---------------funcao cadastrar cliente  ----------------
void cadastracli(){
  int i;  cliente[2];
  for (i=0;i<2;i++)	{
  	printf("Digite o nome");
  	scanf("%s",&cliente[i].nome);
	printf("Digite o endereco");
	scanf("%s",&cliente[i].endereco);
	printf("Digite o bairro");
	scanf("%s",&cliente[i].bairro);
	printf("Digite o cep");
	scanf("%s",&cliente[i].cep);
	printf("Digite o cidade");
	scanf("%s",&cliente[i].cidade);
	printf("Digite o UF");
	scanf("%s",&cliente[i].estado);  	
  }
}
//---------------funcao mostrar cliente   ----------------
void mostrarcli(){
  int i; 
  for (i=0;i<2;i++)	{
  	printf("Nome - %s",&cliente[i].nome);
	printf("Endereco - %s",&cliente[i].endereco);
	printf("Bairro - %s",&cliente[i].bairro);
	printf("CEP - %s",&cliente[i].cep);
	printf("Cidade - %s",&cliente[i].cidade);
	printf("UF - %s",&cliente[i].estado);  	
	printf("\n");
  }	
}
//---------------funcao cadastrar orcamento  ----------------
void cadastraorc(){
  int i;  orcamento[1];
  for (i=0;i<2;i++)	{
  	printf("Digite o nome cliente");
  	scanf("%s",&orcamento[i].nome);
	printf("Digite o produto");
	scanf("%s",&orcamento[i].produto);
	printf("Quantidade");
	scanf("%i",&orcamento[i].quant);
	printf("V. unitario");
	scanf("%f",&orcamento[i].vlunitario);
	printf("V. total");
	scanf("%f",&orcamento[i].vltotal); 	
  }
}

//---------------funcao mostrar orcamento   ----------------
void mostrarorc(){
  int i; 
  for (i=0;i<2;i++)	{
  	printf("Cliente - %s",&orcamento[i].nome);
	printf("Produto - %s",&orcamento[i].produto);
	printf("Quantidade - %i",&orcamento[i].quant);
	printf("V. unitario - %f2",&orcamento[i].vlunitario);
	printf("V. total - %f2",&orcamento[i].vltotal); 	
	printf(" \n");		
	
  }	
}
