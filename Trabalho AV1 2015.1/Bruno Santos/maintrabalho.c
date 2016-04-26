#include <stdio.h>
#include <stdlib.h>


typedef struct cadastro{
	 char nome[30];
	 int idade;
	 char end[30];
	 int tel;
}CADASTRO;

  
typedef struct cadastro_carro{
	  char nome[20];
	  char modelo [20];
	  char marca [15];
	  int placa [15];	  
  } CARRO;
  
int menu();
void cadastra(CADASTRO vetc[10]);
void consulta();
void alterar();
void cadastrarcarro(CARRO vet[10]);
void consultacarro();

CADASTRO vetc[3];
CARRO vet[3];

int main(int a, char **b) {
    
    	
    int op;
	int senha=123;
    char VET[5];

printf("Digite seu login:\n");
scanf("%s",&VET[0]);
while (strcmp(VET,"bruno")){
       printf("\nLogin incorreto! \nDigite novamente:\n");
       scanf("%s",&VET[0]); 
}

printf("\nDigite sua senha numerica:\n");
scanf("%d",&senha); 
while(senha != 123){
      printf("\nSenha incorreta! \n Digite novamente:\n");
      scanf("%d",&senha); 
} 


printf("Seja Bem-Vindo!\n"); 

     
		    do{
		    	
		    	op = menu();
		    	
		    }while(op!=6);
		
	
	return 0;
}

int menu(){
int opcao;
system("cls");	
  printf(" 1 - Cadastar Cliente\n");
  printf(" 2 - Consultar Cliente\n");
  printf(" 3 - Alterar Cliente\n");
  printf(" 4 - Cadastrar carros\n");
  printf(" 5 - Consulta carros\n");
  printf(" 6 - sair\n ");
  printf(" Informe a sua opcao: ");
  scanf("%d", &opcao);
  system("cls");
 
 
switch(opcao){
	case 1:cadastra(vetc); break;
    case 2:consulta(); break;
	case 3:alterar();break;
    case 4:cadastrarcarro(vet); break;
	case 5:consultacarro(); break;
	case 6:printf("Volte Sempre!!!");break;
}
return opcao;
}
 	
void cadastra(CADASTRO vetc[10]){
	
     int i=0;
     char OUTRO;
     for(i=0;i<10;i++){  
	    printf("Informe o nome\n");
		scanf("%s",&vetc[i].nome);
		fflush(stdin);
        printf("Informe a idade\n");
        scanf("%d",&vetc[i].idade);
        fflush(stdin);
        printf("Informe o endereço\n");
        scanf("%s",&vetc[i].end);
        fflush(stdin);
        printf("Informe o telefone\n");
        scanf("%d",&vetc[i].tel);
        fflush(stdin);
        printf("Cadastro Realizar com Sucesso\n"); 
        printf("Deseja cadastrar outro? (S/N)\n"); 
		scanf("%c",&OUTRO);
		
	
		if ((OUTRO=='N')|| (OUTRO=='n')){
	
			break;
	
		}
		
      }
	          
} 
	       
void consulta(){

	char nome[30];
	int i=0;
	
    printf("Informe o nome que deseja consultar ?\n");
	fflush(stdin);
	scanf("%s",&nome[0]);     
    
   
    for(i=0;i<10;i++){
   
    	if (strcmp(vetc[i].nome,nome)==0)
    	{
    		printf("\n Nome.........:%s\n",vetc[i].nome);
    		printf("\n Idade........:%d\n",vetc[i].idade);
    		printf("\n Endereço.....:%s\n",vetc[i].end);
    		printf("\n Telefone.....:%d\n",vetc[i].tel);
            system("pause");
			continue;
    	}
    }
    printf("Consulta Realizar com Sucesso\n");  
}

void alterar(){
	

	char nome[30];
	int i=0;
	
    printf("Informe o nome que queria alterar ?\n");
	scanf("%s",&nome);
	fflush(stdin);
     	
	
    for(i=0;i<10;i++){
    	if (!strcmp(nome,vetc[i].nome))
    	{
    	    printf("Informe o nome\n");
    		scanf("%s",&vetc[i].nome);
    		fflush(stdin);
            printf("Informe a idade\n");
            scanf("%d",&vetc[i].idade);
            fflush(stdin);
            printf("Informe o endereço\n");
            scanf("%s",&vetc[i].end);
            fflush(stdin);
            printf("Informe o telefone\n");
            scanf("%d",&vetc[i].tel);
            fflush(stdin);
            printf("Cadastro Realizar com Sucesso\n"); 
            system("pause");
            system("cls");      
            printf("Precione uma tecla para volta para o menu\n");
    	}
    }	  
}

void cadastrarcarro(CARRO vet[3]){


     int i=0;
     char OUTRO;
     for(i=0;i<10;i++){
	 printf("Digite o nome do veiculo:\n ");
	 scanf("%d",&vet[i].nome);
	 fflush(stdin);
	 printf("Digite o modelo do carro:\n ");
	 gets(vet[i].modelo);
	 fflush(stdin);
	 printf("Digite a marca do carro:\n ");
	 gets(vet[i].marca);
	 fflush(stdin);
	 printf("Digite a placa do carro: \n ");
	 scanf("%d",&vet[i].placa);
	 fflush(stdin);
	 printf("Deseja cadastrar veiculo? (S/N)\n"); 
	 scanf("%c",&OUTRO);
		
			
		if ((OUTRO=='N')|| (OUTRO=='n')){
	
			break;

      } 
  }
}
  
void consultacarro(){

char nome[30];
	int i=0;
	
    printf("Informe o nome que deseja consultar ?\n");
	fflush(stdin);
	scanf("%s",&nome[0]);     
    
   
    for(i=0;i<10;i++){
   
    	if (strcmp(vetc[i].nome,nome)==0)
    	{
    		    		
    		printf("\n Nome.........:%s\n",vet[i].nome);
    		printf("\n Modelo.......:%s\n",vet[i].modelo);
    		printf("\n Marca........:%s\n",vet[i].marca);
    		printf("\n Placa........:%d\n",vet[i].placa);
            system("pause");
			continue;
    	}
    }
    printf("Consulta Realizar com Sucesso\n");  
}




