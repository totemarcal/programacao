#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

  // DECLARAÇÃO DE PARAMETROS //
  
  	    
  void cadastrar_funcionario(void);
  void cadastro_cliente(void);
  void cadastro_categoria(void);
  void cadastro_games(void);
  
  void listar_todos(void);
  void pesquisar_elemento(void);
  void editar(void);
  void excluir(void);
  
  void listar_todos_funcionarios(void);
  void listar_todos_clientes(void);
  void listar_todos_categoria(void);
  void listar_todos_games(void);
  
  void pesquisar_elemento_funcionario(void); 
  void pesquisar_elemento_cliente(void);
  void pesquisar_elemento_categoria(void);
  void pesquisar_elemento_games(void);
  
  void editar_funcionario(void);
  void editar_cliente(void);
  void editar_categoria(void);
  void editar_games(void);
  
  int realizar_venda();
  
  int funcionario_existe(char nome[30]);
  int cliente_existe(char nome[30]);
  int games_existe(char nome[30]);
  
  int gerar_relatorio();
  
  // DECLARAÇÃO DE VARIAVEIS GLOBAIS //
   
  int  i;
  char n[1];
  int  op;
  char opcao;
  int  quantidade_funcionario=0;
  int  quantidade_cliente=0;
  int  quantidade_categoria=0;
  int  quantidade_games=0;
  int  quantidade_venda=0;
  int  quantidade_relatorio=0;
  
  char  nome_funcionario[30], nome_cliente[30], nome_categoria[30], nome_games[30] ;
  float total_pagamento, valor_games;
  
  // DECLARAÇÃO DE STRUCTS //
  
    struct funcionario{
        char nome[30];
       	int  codigo;
		int  cpf;
		int  rg;
        char endereco[20];
        int  telefone;
        };    
    
    struct cliente{
    	int  codigo;
        char nome[20];
        int  rg;
        int  cpf;
        char endereco[30];
        int  telefone;
       };
       
    struct categoria{
       	int  codigo;
		char nome[20];
       	
	   };
	
	struct games{
        int   codigo;
		char  nome[20];
        char  categoria[10];
        float preco;
		};
    
	struct venda{
		   
	   char nome_cliente[30];
	   char game_nome[10];
		 
	};	 
	   

struct funcionario cadastro_funcionario[100];
struct cliente Lcadastro_cliente[100];
struct categoria Gcadastro_categoria[100];	
struct games Ccadastro_games[100];
struct venda games[100];
	    
int main(int argc, char *argv[]){
    
	int senha, adm;
    char log[10];
   

// TELA DE LOGIN //
system("color D ");
system("cls");              
printf("\n\n\n");
printf("\t\t ##############################################\n");	
printf("\t\t ##                 GIRLS GAMES              ##\n");
printf("\t\t ##############################################\n");
printf("\t\t ##          ***                  ***        ##\n");                                                                                               
printf("\t\t ##         *****                *****       ##\n");
printf("\t\t ##           ##                  ##         ##\n");
printf("\t\t ##            ##                ##          ##\n");
printf("\t\t ##       #############################      ##\n");
printf("\t\t ##     #######    ########    #########     ##\n");
printf("\t\t ##      ######    ########    ########      ##\n");
printf("\t\t ##      ##############################      ##\n");
printf("\t\t ##         #########    #########           ##\n");
printf("\t\t ##             ###############              ##\n");
printf("\t\t ##             ###############              ##\n");
printf("\t\t ##             ###############              ##\n");
printf("\t\t ##             ##           ##              ##\n");
printf("\t\t ##         #####             #####          ##\n");
printf("\t\t ##	     ######              #######         ##\n");
printf("\t\t ##############################################\n");
printf("\t\t ##                 LOGIN                    ##\n");
printf("\t\t ##############################################\n");

   do{	
     printf("\t\t USUARIO: ");
     gets(log);
     fflush(stdin);
     printf("\t\t SENHA: ");
     scanf("%d", &senha);
     fflush(stdin);
     if(log != "adm" && senha != 123)
     printf("\t\t login ou senha incorreta\n");
   }
   while(strcmp(log, "adm") || senha!=123);
   system("cls");
      
      printf("\n\n");
	  printf("\t\t Data :%s\n\n",__DATE__); 
      printf("\n\n\t\t\t\t  Girls Games \n\n");
     
	 do{
    	
	   printf("\t\t INSIRA O NUMERO 1 PARA CADASTRAR FUNCIONARIO\n");
       printf("\t\t INSIRA O NUMERO 2 PARA CADASTRAR CLIENTE\n");
       printf("\t\t INSIRA O NUMERO 3 PARA CADASTRAR CATEGORIA\n");
	   printf("\t\t INSIRA O NUMERO 4 PARA CADASTRAR GAMES\n");	
	   printf("\t\t INSIRA O NUMERO 5 PARA LISTAR TODOS\n");
	   printf("\t\t INSIRA O NUMERO 6 PARA PESQUISAR ELEMENTO\n");
	   printf("\t\t INSIRA O NUMERO 7 PARA EDITAR\n");
	   printf("\t\t INSIRA O NUMERO 8 PARA REALIZAR VENDA\n");
	   printf("\t\t INSIRA O NUMERO 9 PARA GERAR RELATORIO\n");
	   printf("\t\t INSIRA O NUMERO 10 PARA SAIR DO SISTEMA\t\n\t\t ");
	   scanf("\t\t %d", &op);
       getchar();
	   switch(op){
       	
       	case 1:
       	   	 cadastar_funcionario();
       		
			   break;
       	case 2:
		    cadastro_cliente();	
       	   
			  break;
       	   
       	case 3:
		   cadastro_categoria();
		   
			break;
			
		case 4:
	        cadastro_games();
	     
		  break;	 	
	    case 5:
	    	
	       listar_todos();
 
	      break;
		case 6:
			
		   pesquisar_elemento();
        
		case 7:
			
		    editar();
   
		case 8:
		   	
		   	realizar_venda();
		   	
		  break;
		  
		case 9:
			
			gerar_relatorio();
		
		 break;
		 
		case 10:
		   	
			   exit(0);
		default:
			
			printf("\t\t Opcao Invalida tente novamente!\n");
				   
	   }
       
	
	
     }while(op != 10);
	 
	 system("pause>>null");
   
    return 0;	
  
}
// FUNÇÃO CADASTRO DE FUNCIONARIO //

void cadastar_funcionario(void)

 {  
	
	  
	   
       for(i=quantidade_funcionario; i<100; i ++){
     	printf("\t\t Informe o Nome do Funcionario:\n\t\t "); 
        scanf("%s", &cadastro_funcionario[i].nome);
		printf("\t\t Informe o CPF do Funcionario:\n\t\t "); 
        scanf("%d", &cadastro_funcionario[i].cpf);
		printf("\t\t Informe o RG do Funcionario:\n\t\t "); 
        scanf("%d", &cadastro_funcionario[i].rg);
		printf("\t\t Informe o Endereco do Funcionario:\n\t\t "); 
        scanf("%s", &cadastro_funcionario[i].endereco);
		printf("\t\t Informe o Telefone do Funcionario:\n\t\t ");
		scanf("%d", &cadastro_funcionario[i].telefone);	
        
		cadastro_funcionario[i].codigo=i;
        fflush(stdin);
    
        quantidade_funcionario++;
        
       	printf("\t\t Deseja cadastrar um novo funcionario: [S/N]?\n\t\t ");
        scanf("%s", &opcao);
        if(opcao== 'n')
        break;
        
        }
 	   
	   
 }


// FUNÇÃO CADASTRO DE CLIENTE//
 
void cadastro_cliente(void)
{
 
   
      for(i=quantidade_cliente; i<100; i++){
      	fflush(stdin);
        printf("\t\t Informe o Nome do Cliente:\n\t\t ");
        scanf("%s", &Lcadastro_cliente[i].nome);
        printf("\t\t Informe o CPF do Cliente:\n\t\t ");
        scanf("%d", &Lcadastro_cliente[i].cpf);
        printf("\t\t Informe o RG do Cliente:\n\t\t ");
        scanf("%d", &Lcadastro_cliente[i].rg);
        printf("\t\t Informe o Endereco do Cliente:\n\t\t ");
        scanf("%s", &Lcadastro_cliente[i].endereco);
        printf("\t\t Informe o Telefone do Cliente:\n\t\t ");
        scanf("%d", &Lcadastro_cliente[i].telefone);
        Lcadastro_cliente[i].codigo=i;
        fflush(stdin);
        
        quantidade_cliente++;
        
  	    printf("\t\t Deseja cadastrar uma novo clinte?: [S/N]?\n\t\t ");
        scanf("%s", &opcao);
        if(opcao== 'n')
        break;
      }
      	
      
      
}

// FUNÇÃO CADASTRO DE CATEGORIA //

void cadastro_categoria(void)
{
	
 
	
	for(i=quantidade_categoria; i<100; i++){
	    printf("\t\t Informe o Nome da categoria:\n\t\t ");
		scanf("%s", &Gcadastro_categoria[i].nome);
	    printf("\t\t Informe o codigo da categoria:\n\t\t ");
		scanf("%s", &Gcadastro_categoria[i].codigo);
		Gcadastro_categoria[i].codigo=i;
        fflush(stdin);
        
        quantidade_categoria++;
        
  	    printf("\t\t Deseja cadastar uma nova categoria: [S/N]?\n\t\t ");
  	    scanf("%s", &opcao);
  	    
        if(opcao== 'n')
        break;
      }
     
     
      
	
}



// FUNÇÃO CADASTRO DE GAMES //

void cadastro_games(void)
{

    
		
	for(i=quantidade_games; i<100; i++){
		printf("\t\t Informe o Nome do games\n\t\t ");
		scanf("%s", &Ccadastro_games[i].nome);	
		printf("\t\t Informe a categoria dos games\n\t\t ");
		scanf("%s", &Ccadastro_games[i].categoria);
		printf("\t\t Informe o Preco do games\n\t\t ");
		scanf("%f", &Ccadastro_games[i].preco);
		Ccadastro_games[i].codigo=i;
        fflush(stdin);
        
  	    quantidade_games++;
  	    
		printf("\t\t Deseja cadastar um novo games: [S/N]?\n\t\t ");
  	    scanf("%s", &opcao);
        if(opcao== 'n')
        break;
      }
      	
     
      
	 
	
}



// LISTAR TODOS //

void listar_todos(void)
{
		
	
	
	do{
	
      printf("\t\t DIGITE 1 PARA LISTAR TODOS OS FUNCIONARIOS\n");
      printf("\t\t DIGITE 2 PARA LISTAR TODOS OS CLIENTES\n");
	  printf("\t\t DIGITE 3 PARA LISTAR TODAS AS CATEGORIAs\n");
	  printf("\t\t DIGITE 4 PARA LISTAR  OS GAMES\n");	
	  printf("\t\t DIGITE 5 PARA SAIR\t\n\t\t ");
	  scanf("\t\t %d", &op);
	  switch(op){
		
		case 1:
		    
		    listar_todos_funcionarios();
		    
		    
			break;
			
		case 2:
		
		  listar_todos_clientes();
		  
		    break;
	    			
		case 3:
		
		 listar_todas_categoria();
		
			break;
			
		case 4:
		   
	    	listar_todos_games();
	    	
		   break;
		   
		case 5:
			
		   system("exit");
		   
		   break; 
			
		default:
		    
		    printf("Opcao Invalida!\n");
		
		  
	  }
	
	
    }while(op != 5);
}



// FUNÇÃO LISTAR  TODOS OS FUNCIONARIOS //

void listar_todos_funcionarios(void)

{
	 int i;
	 
	 for(i=0; i<quantidade_funcionario; i++){
        
        printf("\t\t Codigo  do Funcionario he:%d\n", cadastro_funcionario[i].codigo); 	
		printf("\t\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
		printf("\t\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		printf("\t\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		printf("\t\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		printf("\t\t Telefone do Funcionario he:%d\n", cadastro_funcionario[i].telefone);
        
      }
}

// LISTAR TODOS CLIENTES//

 void listar_todos_clientes(void)
{
   
   int i;
   
   for(i=0; i<quantidade_cliente; i++){
   	
   	    printf("\t\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
        printf("\t\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
        printf("\t\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
        printf("\t\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
        printf("\t\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
        printf("\t\t O Telefone do Cliente he:%d\n", Lcadastro_cliente[i].telefone);
       
   }	
	
	
}	
	

// LISTAR TODAS CATEGORIAS //

void listar_todas_categoria(void)
{
	int i;
	
	for(i=0; i<quantidade_categoria; i++){
	 
	 	printf("\t\t Codigo  da categoria:%d\n", Gcadastro_categoria[i].codigo); 	
		
	}
	
}	

// LISTAR TODOS OS GAMES //	

 void listar_todos_games(void){
 	
 	 int i;
 	 for(i=0; i<quantidade_games; i++){
 		
 	   	printf("\t\t Codigo  do games:%d\n", Ccadastro_games[i].codigo); 	
		printf("\t\t Nome do games he:%s\n", Ccadastro_games[i].nome ); 
		printf("\t\t categoria do games he:%s\n", Ccadastro_games[i].categoria); 
		printf("\t\t Preco do games he:R$:%.2f\n", Ccadastro_games[i].preco); 
		
 	  }
 	
 }
 


// FUNÇÃO PESQUISAR ELEMENTO //

void pesquisar_elemento(void)

{
  
  do{
  
    printf("\t\t DIGITE 1 PARA PESQUISAR ELEMENTO FUNCIONARIO\n");
    printf("\t\t DIGITE 2 PARA PESQUISAR ELEMENTO CLIENTE\n");
	printf("\t\t DIGITE 3 PARA PESQUISAR ELEMENTO CATEGORIA\n");
	printf("\t\t DIGITE 4 PARA PESQUISAR ELEMENTO GAMES\n");	
	printf("\t\t DIGITE 5 PARA SAIR\t\n\t\t ");
	scanf("%d", &op);
    switch(op){
  	   
		 case 1:
		     
		     pesquisar_elemento_funcionario();
			 
			 break;
		 case 2:
		 	 
		 	 pesquisar_elemento_cliente();
		 	 
		 	 break;
		  case 3:
		     
		      pesquisar_elemento_categoria();
		     
			 break; 
		 case 4:
		 	 
		 	 pesquisar_elemento_games();
		 	 
		 	 break;
		case 5:
		     system("exit");
			 
			 break;
		default:
		 
		   printf("opcao invalida\n");
		 	
    }
  }while(op != 5);
}

//PESQUISAR ELEMENTO FUNCIONARIO//
 
void pesquisar_elemento_funcionario(void) 
{ 
     int cpf_pesquisa;
     int i;
	 
	 printf("\t\t Informe o CPF do Funcionario:\n");
	 scanf("\t\t %d", &cpf_pesquisa);     
     fflush(stdin);
	 for(i=0; i<quantidade_funcionario; i++)     
     { 
         if(cadastro_funcionario[i].cpf==cpf_pesquisa){
         	
         	printf("\t\t Codigo  do Funcionario he:%d\n", cadastro_funcionario[i].codigo); 	
	  	    printf("\t\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
	 	    printf("\t\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		    printf("\t\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		    printf("\t\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		    printf("\t\t Telefone do Funcionario he:%d\n", cadastro_funcionario[i].telefone);
        
           }
          else if(cadastro_funcionario[i].cpf!=cpf_pesquisa){
         	
         	printf("\t\t Funcionario nao encontrado!\n");
	    
          }
         	
           
        
	 } 
	   
	
}

// PESQUISAR ELEMENTO CLIENTE //	

void pesquisar_elemento_cliente(void)

{
	
	 int i;
     int cpf_cliente;
     
   printf("\t\t Informe o CPF do cliente:\n");
   scanf("%d", &cpf_cliente);
   for(i=0; i<quantidade_cliente; i++){
   	    if(Lcadastro_cliente[i].cpf==cpf_cliente){
   	         printf("\t\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
             printf("\t\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
             printf("\t\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
             printf("\t\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
             printf("\t\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
             printf("\t\t O Telefone do Cliente he:%d\n", Lcadastro_cliente[i].telefone);
             
   	       }    
   	      else{
   	      	  
   	           printf("\t\t Cliente nao encontrado!\n");	
   	         }
   }
	
	
	
}

//PESQUISAR ELEMENTO CATEGORIA//	


void pesquisar_elemento_categoria(void)
{
	int i;
	int codigo_categoria;
	
	printf("\t\t Informe o codigo da categoria\n");
	scanf("%d", &codigo_categoria);
	for(i=0; i<quantidade_categoria; i++){
	    
        if(Gcadastro_categoria[i].codigo==codigo_categoria){
	      printf("\t\t Codigo  da categoria:%d\n", Gcadastro_categoria[i].codigo); 	
	 
		
		}
	 	else{
	 		
	 	  printf("\t\t Categoria nao encontrada\n");
	 		
	 	}
	 	
	}
	

	
}


//PESQUISAR ELEMENTO GAMES//


void pesquisar_elemento_games(void)
{
   
   int i;
   char nome_games[20];
     
     
      printf("\t\t Informe o nome do games:\n");
      scanf("\t\t %s", &nome_games);
	  fflush(stdin);	
 	  for(i=0; i<quantidade_games; i++){
 		  
 	       printf("%i \n\n", strcmp(Ccadastro_games[i].nome, nome_games));
           if(!strcmp(Ccadastro_games[i].nome, nome_games)){
           
 	   	     printf("\t\t Codigo  do games:%d\n", Ccadastro_games[i].codigo); 	
		     printf("\t\t Nome do games he:%s\n", Ccadastro_games[i].nome ); 
		     printf("\t\t Categoria do games he:%s\n", Ccadastro_games[i].categoria); 
		     printf("\t\t Preco do games he:R$:%.2f\n", Ccadastro_games[i].preco); 
			
 		   }
 	      else{
 	    	
 	    	printf("\t\t Games nao encontrado\n");
 	    	
 	     }
	   
	  }
	
}


// FUNÇÃO EDITAR //

void editar(void)

{   
    int codigo_funcionario;
    int codigo_cliente;
	int codigo_codigo;
	int codigo_games;
  do{
  
	printf("\t\t DIGITE 1 PARA EDITAR FUNCIONARIO\n");
    printf("\t\t DIGITE 2 PARA EDITAR CLEINTE\n");
	printf("\t\t DIGITE 3 PARA EDITAR CATEGORIA\n");
	printf("\t\t DIGITE 4 PARA EDITAR GAMES\n");	
	printf("\t\t DIGITE 5 PARA SAIR\n");
	scanf("%d", &op);
	
     switch(op){
  	   
		 case 1:
		    editar_funcionario();
				
			 break;
		 case 2:
		 	editar_cliente();
		  
		     break;
		  case 3:
		     editar_categoria();
		      
			 break;
			 
		  case 4:
		 	  editar_games();
		 	 
			  break;
		 case 5:
		     printf("\t\t saindo..\n");
			 
			 break;
		 default:
		 
		   printf("opcao invalida\n");
			 	
			
  	 }
  }while(op != 5);
}


 void editar_funcionario(void)
{
	char nome_editar_funcionario[30];
	int cpf_editar_funcionario;
	int rg_editar_funcionario;
	char endereco_editar_funcionario[30];
	int telefone_editar_funcionario;
	
	printf("\t\t ***************Editar Funcionario****************\n\n");
	
	printf("\t\t DIGITE 1 PARA EDITAR O NOME DO FUNCIONARIO\n");
	printf("\t\t DIGITE 2 PARA EDITAR O CPF DO FUNCIONARIO\n");
	printf("\t\t DIGITE 3 PARA EDITAR O RG DO FUNCIONARIO\n");
	printf("\t\t DIGITE 4 PARA EDITAR O ENDERECO DO FUNCIONARIO\n");
    printf("\t\t DIGITE 5 PARA EDITAR O TELEFONE DO FUNCIONARIO\n");
    printf("\t\t DIGITE 6 PARA SAIR");
    scanf("\t\t %d", &op);
    switch(op){
       
	   case 1:
	   	     printf("Informe o nome:\n");
	   	     scanf("%s", &nome_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		        if(strcmp(nome_editar_funcionario, cadastro_funcionario[i].nome)==0){
		        	printf("Informe o novo nome do funcionario\n");
		        	scanf("%s", &cadastro_funcionario[i].nome);
		        	
		        	
		        }
		
	        }   
	   break;
	       
	   case 2:
	   	    printf("Informe o CPF:\n");
	   	   scanf("%d", &cpf_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		        if(cpf_editar_funcionario==cadastro_funcionario[i].cpf){
		        	printf("Informe o novo CPF do funcionario:\n");
		        	scanf("%d", &cadastro_funcionario[i].cpf);
		        	
		        }
		
	        }
	   break;
	   
	   case 3:
	   	    printf("Informe o RG:\n");
	   	    scanf("%d", &rg_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		      if(rg_editar_funcionario==cadastro_funcionario[i].rg){
		      	printf("Informe o novo RG do funcionario:\n");
		      	scanf("%d", &cadastro_funcionario[i].rg);
		      }
		
	        }
	   break;
	   
	   case 4:
	   	    printf("Informe o endereco:\n");
	   	    scanf("%s", &endereco_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		       if(strcmp(endereco_editar_funcionario, cadastro_funcionario[i].endereco)==0){
		       	 printf("Informe o novo endereco do funcionario:\n");
		       	 scanf("%s", &cadastro_funcionario[i].endereco);
		       	
		       }
		
	        }
	   break;
	   
	   case 5:
	   	     printf("Informe o telefone:\n");
	   	     scanf("%d", &telefone_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		        if(telefone_editar_funcionario== cadastro_funcionario[i].telefone){
		        	printf("Informe o novo telefone do funcionario:\n");
		        	scanf("%d", &cadastro_funcionario[i].telefone);
		        	
		        }
		
	        }
	   break;
	   
	   case 6:
	   	   printf("\t\t Saindo\n");
	   	
	   	break;
	   
	   default:
	   
	   printf("\t\t Opcao invalida");
	           
              
	}
	  

}

// FUNÇÃO EDITAR CLIENTE //

void editar_cliente(void)
{ 
    char nome_editar_cliente[30];
	int cpf_editar_cliente;
	int rg_editar_cliente;
	char endereco_editar_cliente[30];
	int telefone_editar_cliente;
	
	printf("\t\t ***********Editar Cliente**************:\n\n");
	
	printf("\t\t DIGITE 1 PARA EDITAR O NOME DO CLEINTE\n");
	printf("\t\t DIGITE 2 PARA EDITAR O CPF DO CLEINTE\n");
	printf("\t\t DIGITE 3 PARA EDITAR O RG DO CLEINTE\n");
	printf("\t\t DIGITE 4 PARA EDITAR O ENDERECO DO CLEINTE\n");
	printf("\t\t DIGITE 5 PARA EDITAR O TELEFONE DO FORNECEDOR\n");
	printf("\t\t DIGITE 6 PARA SAIR\n");
	scanf("%d", &op);
	
	 switch(op){
       
	   case 1:
	       printf("Informe o nome:\n");
	       scanf("%s", &nome_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(strcmp(nome_editar_cliente, Lcadastro_cliente[i].nome)==0){
	       		printf("Informe o novo nome do cleinte:\n");
	       		scanf("%s", &Lcadastro_cliente[i].nome);
	       		
	       		
	       	}
	       	
	       }
	   break;
	   
	   case 2:
	       printf("Informe o CPF");
	       scanf("%d", &cpf_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(cpf_editar_cliente==Lcadastro_cliente[i].cpf){
	       		
	       		printf("Informe o novo CPF do cleinte:\n");
	       		scanf("%d", &Lcadastro_cliente[i].cpf);
	       	}
	       	
	       }
	   break;
	       
	   case 3:
	       printf("Inforem o RG:\n");
	       scanf("%d", &rg_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(rg_editar_cliente==Lcadastro_cliente[i].rg){
	       		printf("Informe o novo RG do clliente:\n");
	       		scanf("%d", &Lcadastro_cliente[i].rg);
	       		
	       	}
	       	
	       }
	   break;
	   
	   case 4:
	      printf("Informe o endereco:\n");
	      scanf("%s", &endereco_editar_cliente);
	      for(i=0; i<quantidade_cliente; i++){
	       	if(strcmp(endereco_editar_cliente, Lcadastro_cliente[i].endereco)==0){
	       		printf("Informe o novo endereco do cleinte:\n");
	       		scanf("%s", &Lcadastro_cliente[i].endereco);
	       		
	       	}
	       	
	      }
	   break;
	   
	   case 5:
	        printf("Informe o telefone:\n");
	        scanf("%d", &telefone_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(telefone_editar_cliente==Lcadastro_cliente[i].telefone){
	       	     printf("Informe o novo telefone do cliente:\n");
	       	     scanf("%d", &Lcadastro_cliente[i].telefone);
			   }
	       	 
	       }
	   break;
	   
	   case 6:
	   	   printf("\t\t Saindo");
	   	break;
	   default:
	   
	   printf("\t\t Opcao invalida" );
	           
              
	}
	
	
}

// FUNÇÃO EDITAR CATEGORIA //

 void editar_categoria(void)
{   
    char nome_editar_categoria[30];
    int codigo_editar_categoria;
	
	
	printf("\t\t *************Editar Categoria**********\n\n");
	
	printf("\t\t DIGITE 1 PARA EDITAR O NOME DA CATEGORIA\n");
	printf("\t\t DIGITE 2 PARA EDITAR O CODIGO DA CATEGORIA\n");
    printf("\t\t DIGITE 3 PARA SAIR\n\t\t ");
    scanf("\t\t %d", &op);
    switch(op){
       
	   case 1:
	       printf("\t\t informe o nome:");
           scanf("%s", &nome_editar_categoria);
            for(i=0; i<quantidade_categoria; i++){
                                 
                if( strcmp(nome_editar_categoria, Gcadastro_categoria[i].nome )==0){
                                     
                   printf("informe o novo nome da categoria:");
                   scanf("%s", &Gcadastro_categoria[i].nome ); 
                                 
                }
                         
            }   
	   
	   break;
	   
	   case 2:
	        printf("\t\t informe o codigo da categoria:\n");
            scanf("%d", &codigo_editar_categoria);
              for(i=0; i<quantidade_categoria; i++){
                             
                if(codigo_editar_categoria== Gcadastro_categoria[i].codigo){
                                
                   printf("\t\t informe o novo codigo da categoria:\n");
                   scanf("%d", &Gcadastro_categoria[i].codigo);
                             
                 }          
		
	          }
	   break;
	      
	   case 3:
	      printf("\t\t Sair");
	   
	   break;
	       
	   default:
	   
	   printf("\t\t Opcao invalida");
	           
              
	}
 
}

// FUNÇÃO EDITAR GAMES //

 void editar_games(void)
{
  
   char nome_games_editar[20];
   char nome_categoria_editar[20];
   float preco_editar_games;
   
   printf("\t\t **********Edcao de Games****************\n\n");
   
   printf("\t\t DIGITE 1 PARA EDITAR NOME\n");
   printf("\t\t DIGITE 2 PARA EDITAR CATEGORIA\n");
   printf("\t\t DIGITE 3 PARA EDITAR GAMES\n");
   printf("\t\t DIGITE 4 PARA SAIR\n\t\t ");
   scanf("\t\t %d", &op);
   switch(op){
   	
   	case 1:
   		   printf("\t\t Informe o nome:\n\t\t ");
   		   scanf("%s", &nome_games_editar);
   	       for(i=0; i<quantidade_games; i++){
   	       	   
   	       	   if(strcmp(nome_games_editar, Ccadastro_games[i].nome)==0){
   	       	   	       
   	       	   	       printf("\t\t Informe o novo nome do games:\n\t\t ");
   	       	   	       scanf("\t\t %s", &Ccadastro_games[i].nome);
   	       	   	
   	       	         }
   	       	 
   	          } 
	   	break;
   	case 2:
   		   printf("\t\t Informe a categoria:\n\t\t ");
   		   scanf("%s", &nome_categoria_editar);
   		   for(i=0; i<quantidade_games; i++){
   		   	   
   		   	   if (strcmp(nome_categoria_editar, Ccadastro_games[i].categoria)==0){
   		   	          
   		   	          printf("\t\t Informe o novo nome da categoria:\n\t\t ");
   		   	          scanf("\t\t %s", &Ccadastro_games[i].categoria);
   		   	
					   
					 }
   		   	    
   		   	     
   		      }          
   		break;
   	case 3:
	   
	      printf("\t\t Informe o preco do games:\n\t\t ");
	   	  scanf("%f", &preco_editar_games);
	   	  for(i=0; i<quantidade_games; i++){
	   		
	   		  if( preco_editar_games == Ccadastro_games[i].preco){
	   		      
	   		       printf("\t\t Informe o novo preco do games:\n\t\t");
	   		       scanf("%f", &Ccadastro_games[i].preco);
				   
				 }
	   		
	   	     
	   	     }
   	
   	    break;
	case 4:
	   	 system("\t\t exit");
	   	 
			break;
	
	default:
	     printf("\t\t Opcao invalida");	 
	   	
   }
   
}
 
 // FUNÇÃO FUNCIONARIO EXISTE //
 
 int funcionario_existe(char nome[30]){
 	
 	int i;
 	 for(i=0; i<quantidade_funcionario; i++){
 		
 		if(strcmp(nome, cadastro_funcionario[i].nome)==0)
 		return 1;
 	  }
 	return 0;
 	
 }
 
 
  
// FUNÇÃO VERIFICA SE O CLIENTE EXISTE //
  
int cliente_existe(char nome[30]){
	
	int i;
	
	for(i=0; i<quantidade_cliente; i++){
		
		if(strcmp(nome, Lcadastro_cliente[i].nome)==0)
		return 1;
		
	}
	return 0;
	
	
}

// FUNÇÃO VERIFICA SE O GAMES EXISTE //

int games_existe(char nome[30]){
   
   	
   for(i=0; i<quantidade_games; i++){
   	
   	if(strcmp(nome,Ccadastro_games[i].nome)==0)
   	return 1;
   }	
	return 0;
	
}  
 
// FUNÇÃO RELIZAR VENDA //

int realizar_venda(){
	
	int i;
	
  	 
   for(i=0; i<quantidade_venda; i++){
   
  	    printf("\t\t Informe seu nome:");
  	    scanf("%s", &nome_funcionario);
  	
  	    if(funcionario_existe(nome_funcionario)==1){
  	    	
  	       strcpy(cadastro_funcionario[i].nome, nome_funcionario);	
  	    	
  	      }
  	           else{
  	           	
                    printf("\t\t Funcionario não encontrado!\n");  	           	
  	           	    break;
  	           	    return;
  	             }
  	    printf("\t\t Informe o nome do cliente:");
  	    scanf("%s", &nome_cliente);
  	
  	   if(cliente_existe(nome_cliente)==1){
  	   
		   strcpy(Lcadastro_cliente[i].nome, nome_cliente);
		 
		
	     }  
		 
  	         else{
  	             printf("\t\t Cliente nao encontado, Favor tente novamente\n!");
		         printf("\t\t Sem sucesso. Venda não pode ser efetuada\n\n");
		         return;	
  	           }
  	     fflush(stdin);
	     printf("\t\t informe o nome do games:");
		 scanf("%s", &nome_games);
		 if(games_existe(nome_games)==1){
		  
		   strcpy(Ccadastro_games[i].nome, nome_games);	
  	     
		 }
		    else{
		 	    printf("\t\t games não econtrado!\n\n");
		 	    printf("\t\t venda não realizada\n\n");
		 	    break;
			    return;
		    }
		printf("\t\t Informe a quantidade de games:");
		scanf("%d", &quantidade_games);
	
		printf("Informe o valor do games:");
		scanf("%f", &valor_games);
		if(valor_games==Ccadastro_games[i].preco){
		  	
		  total_pagamento=quantidade_games*Ccadastro_games[i].preco;
	
		}
		else{
			printf("\t\t Valor incorreto\n");
			printf("\t\t venda não pode ser efetuada\n\n");
			return;
			break;
			
		}		 
	    fflush(stdin);
	    printf("\t\t Venda efetuada com sucesso!\n\n");
	    
		printf("\t\t Deseja realizar uma nova venda: [S/N]?\n\t\t ");
  	    scanf("%s", &opcao);
          
		  if(opcao=='n')
          break;
   }
   quantidade_venda++;
   
  return;
}


// FUNÇÃO GERAR RELATÓRIO //

int gerar_relatorio()
{
	int i;
	char data[10];
	
	printf("\t\t Digite a data do dia atual para gerar o relatorio:");
	gets(data);
    

// ENTRAR COM A DATA DO DIA ATUAL PARA GERAR RELATORIO //
	 	 

	if(strcmp(data,__DATE__ )==0){
		
	  for(i=0; i<quantidade_funcionario; i++){
	  	printf("\n\n");
	  	printf("\t\t **********Dados funcionarios************\n\n");
        
        printf("\t\t Codigo  do Funcionario he:%d\n", cadastro_funcionario[i].codigo); 	
		printf("\t\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
		printf("\t\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		printf("\t\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		printf("\t\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		printf("\t\t Telefone do Funcionario he:%d\n", cadastro_funcionario[i].telefone);
         
      }
    
	   
	    for(i=0; i<quantidade_cliente; i++){
   	      printf("\n\n");
   	      printf("\t\t *********Dados clientes********* \n\n");
   	      
   	      printf("\t\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
          printf("\t\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
          printf("\t\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
          printf("\t\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
          printf("\t\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
          printf("\t\t O Telefone do Cliente he:%d\n", Lcadastro_cliente[i].telefone);
       
        }	
	    
	    for(i=0; i<quantidade_categoria; i++){
	      printf("\n\n");
	      printf("\t\t *********Dados categoria*********\n\n");
	      
	 	  printf("\t\t Codigo  da categoria:%d\n", Gcadastro_categoria[i].codigo); 	
		  printf("\t\t Nome do games he:%s\n", Gcadastro_categoria[i].nome ); 
		  printf("\t\t Codigo dos games he:%d\n", Gcadastro_categoria[i].codigo); 
		 
	    }
	    
	     for(i=0; i<quantidade_games; i++){
 		  printf("\n\n");
 		  printf("\t\t *******Dados dos games********\n\n");
 		  
 	   	  printf("\t\t Codigo  dos games:%d\n", Ccadastro_games[i].codigo); 	
		  printf("\t\t Nome dos games he:%s\n", Ccadastro_games[i].nome ); 
		  printf("\t\t Categoria dos games he:%s\n", Ccadastro_games[i].categoria); 
		  printf("\t\t Preco dos games he:R$:%.2f\n\n", Ccadastro_games[i].preco); 
		
 	    }
	     for(i=0; i<quantidade_venda; i++){
	     
	      printf("\n\n");
		  printf("\t\t ********Dados das compras*********\n\n");
   
          printf("\t\t Funcinário: %s\n", nome_funcionario);
          printf("\t\t cliente: %s\n", nome_cliente);
          printf("\t\t games: %s\n", nome_games);
          printf("\t\t Quantidade: %d\n", quantidade_games);
          printf("\t\t Preco %.2f\n\n", valor_games);
          printf("\t\t Total pagamento he: %.2f\n\n", total_pagamento);
	   	
	     }
		
		
		
	  printf("\t\t Deseja imprimir no bloco de notas:");
	  scanf("%d", &opcao);
		
	  if(opcao=='s'){
		
		
		
	    for(i=0; i<quantidade_funcionario; i++){
         
          FILE *arquivo= fopen("Relatório sistema.txt", "a");
          
          fprintf(arquivo, "\t\t *******Dados dos funcionarios**********\n\n");
          
          fprintf(arquivo, "\t\t Codigo  do Funcionario he:%d\n", cadastro_funcionario[i].codigo); 	
		  fprintf(arquivo, "\t\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
		  fprintf(arquivo, "\t\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		  fprintf(arquivo, "\t\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		  fprintf(arquivo, "\t\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		  fprintf(arquivo, "\t\t Telefone do Funcionario he:%d\n\n", cadastro_funcionario[i].telefone);
          fclose(arquivo);
        }
	   
	    for(i=0; i<quantidade_cliente; i++){
	    	
   	      FILE *arquivo= fopen("Relatório sistema.txt", "a");
   	      
   	      fprintf(arquivo, "\t\t *******Dados dos clientes**********\n\n");
   	      
   	      fprintf(arquivo, "\t\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
          fprintf(arquivo, "\t\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
          fprintf(arquivo, "\t\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
          fprintf(arquivo, "\t\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
          fprintf(arquivo, "\t\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
          fprintf(arquivo, "\t\t O Telefone do Cliente he:%d\n\n", Lcadastro_cliente[i].telefone);
          fclose(arquivo);
        }	
	    
	    for(i=0; i<quantidade_categoria; i++){
	      
		  FILE *arquivo= fopen("Relatório sistema.txt", "a");
	      
	      fprintf(arquivo, "\t\t *******Dados da categoria**********\n\n");
	      
	 	  fprintf(arquivo, "\t\t Codigo  da categoria:%d\n", Gcadastro_categoria[i].codigo); 	
		  fprintf(arquivo, "\t\t Nome da categoria he:%s\n", Gcadastro_categoria[i].nome ); 
		  fprintf(arquivo, "\t\t Codigo da categoria he:%d\n", Gcadastro_categoria[i].codigo); 
	      fclose(arquivo);
	    }
	    
	    for(i=0; i<quantidade_games; i++){
 		   
		   FILE *arquivo= fopen("Relatório sistema.txt", "a");
 		  
		   fprintf(arquivo, "\t\t *******Dados dos games**********\n\n");
 		  
 	   	  fprintf(arquivo, "\t\t Codigo  dos games:%d\n", Ccadastro_games[i].codigo); 	
		  fprintf(arquivo, "\t\t Nome do games he:%s\n", Ccadastro_games[i].nome ); 
		  fprintf(arquivo, "\t\t categoria do games he:%s\n", Ccadastro_games[i].categoria);
		  fprintf(arquivo, "\t\t Preco do games he:R$:%.2f\n\n", Ccadastro_games[i].preco); 
		  fclose(arquivo);
 	    }
	    
	     for(i=0; i<quantidade_venda; i++){
           
		   FILE *arquivo= fopen("Relatório sistema.txt", "a");
 		     
           fprintf(arquivo, "\t\t *******Dados da compra**********\n\n");
   
           fprintf(arquivo, "\t\t Funcinário: %s\n", nome_funcionario);
           fprintf(arquivo, "\t\t cliente: %s\n", nome_cliente);
           fprintf(arquivo, "\t\t games: %s\n", nome_games);
           fprintf(arquivo, "\t\t Quantidade: %d\n", quantidade_games);
           fprintf(arquivo, "\t\t Preco %.2f\n\n", valor_games);
           fprintf(arquivo, "\t\t Total pagamento he: %.2f\n\n", total_pagamento);		 	
           fclose(arquivo);
		 }
		 
         
	  }
	  else{
	  	printf("\t\t Data invalida impossivel gerar relatorio\n");
	  	
	  	
	  } 
      
    }
    

}




