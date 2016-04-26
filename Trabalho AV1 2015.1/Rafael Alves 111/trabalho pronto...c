#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

  // DECLARAÇÃO DE PARAMETROS  	    
  void cadastar_funcionario(void);
  void cadastro_cliente(void);
  void cadastro_fornecedor(void);
  void cadastro_produto(void);
  
  void listar_todos(void);
  void pesquisar(void);
  void editar(void);
  void excluir(void);
  
  void listar_todos_funcionarios(void);
  void listar_todos_clientes(void);
  void listar_todos_fornecedores(void);
  void listar_todos_produtos(void);
  
  void pesquisar_funcionario(void); 
  void pesquisar_cliente(void);
  void pesquisar_fornecedor(void);
  void pesquisar_produto(void);
  
  void editar_funcionario(void);
  void editar_cliente(void);
  void editar_fornecedor(void);
  void editar_produto(void);
  
  int realizar_venda();
  
  int funcionario_existe(char nome[30]);
  int cliente_existe(char nome[30]);
  int produto_existe(char nome[30]);
  
  int gerar_relatorio();
  
  // DECLARAÇÃO DE VARIAVIS GLAOBAIS
   
  int i;
  char n[1];
  int op;
  char opcao;
  int quantidade_funcionario=0;
  int quantidade_cliente=0;
  int quantidade_fornecedor=0;
  int quantidade_produto=0;
  int quantidade_venda=0;
  int quantidade_relatorio=0;
  
  char nome_funcionario[30], nome_cleinte[30], nome_produto[30] ;
  float total_pagamento, valor_produto;
  
  // DECLARÇÃO DE STRUCTS
  
    struct funcionario{
        char nome[30];
       	int matricula;
		int cpf;
		int  rg;
        char endereco[20];
        int telefone;
        };    
    
    struct cliente{
    	int codigo;
        char nome[30];
        int  rg;
        int cpf;
        char endereco[30];
        int telefone;
       };
       
    struct fornecedor{
       	int codigo;
		char nome[30];
       	int  cnpj;
       	char endereco[20];
       	int telefone;
        char  email[30];
	   };
	
	struct produto{
        int codigo;
		char nome[20];
        char fornecedor[10];
        float preco;
		};
    
	struct venda{
		   
	   char nome_cliente[30];
	   char produto[10];
		 
	};	 
	   

struct funcionario cadastro_funcionario[100];
struct cliente Lcadastro_cliente[100];
struct fornecedor Gcadastro_fornecedor[100];	
struct produto Ccadastro_produto[100];
struct venda produto[100];
	    
int main(int argc, char *argv[]){
   system("color 1A"); 
   
	int senha, adm;
    char log[10];
   

// TELA DE LOGIN

system("cls");             
printf("\n\n\n");
printf("\t***************************************************\n");	
printf("\t              Floricultura do Vale                 \n");
printf("\t***************************************************\n");
printf("\t**            ######   #       #                 **\n");
printf("\t**            #        #       #                 **\n");
printf("\t**            ######    #     #                  **\n");
printf("\t**            #          #   #                   **\n");
printf("\t**            #           # #                    **\n");
printf("\t**            #            #                     **\n");
printf("\t**                                               **\n");
printf("\t***************************************************\n");
printf("\t                      Acesso                       \n");
printf("\t***************************************************\n");


   do{	
   
     printf("\tUSUARIO: ");
     gets(log);
     fflush(stdin);
     printf(" \tSENHA: ");
     scanf("%d", &senha);
     fflush(stdin);
     if(log != "adm" && senha != 1234)
     printf(" loguin ou senha incorreta\n");
   }
   while(strcmp(log, "adm") || senha!=1234);
   system("cls");
      printf("\n\n");
	  printf("\t Data :%s\n\n",__DATE__); 
      printf("\n\n\t\t\t FLORICULTURA DO VALE\n\n");
     
	 do{
    	
	   printf("\t DIGITE 1 PARA CADASTRA FUNCIONARIO\n");
       printf("\t DIGITE 2 PARA CADASTRA CLIENTE\n"    );
       printf("\t DIGITE 3 PARA CADASTRA FORNECEDOR\n" );
	   printf("\t DIGITE 4 PARA CADASTRA PRODUTO\n"    );	
	   printf("\t DIGITE 5 PARA LISTAR TODOS\n"        );
	   printf("\t DIGITE 6 PARA PESQUISAR \n"          );
	   printf("\t DIGITE 7 PARA EDITAR\n"              );
	   printf("\t DIGITE 8 PARA REALIZAR VENDA\n"      );
	   printf("\t DIGITE 9 PARA GERAR RELATORIO\n"     );
	   printf("\t DIGITE 10 PARA SAIR DO SISTEMA\n "   );
	   scanf(" %d", &op);
       getchar();
       system("cls");
	   switch(op){
       	
       	case 1:
       	   	 cadastar_funcionario();
       		
			   break;
       	case 2:
		    cadastro_cliente();	
       	   
			  break;
       	   
       	case 3:
		   cadastro_fornecedor();
		   
			break;
			
		case 4:
	        cadastro_produto();
	     
		  break;	 	
	    case 5:
	    	
	       listar_todos();
 
	      break;
		case 6:
			
		   pesquisar();
        
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
			
			printf(" Opcao Invalida tente novamente!\n");
				   
	   }
       
	
	
     }while(op != 10);
	 
	 system("pause>>null");
   
    return 0;	
  
}
// FUNÇÃO CADASTRO DE FUNCIONARIO

void cadastar_funcionario(void)

 {  
		   
       for(i=quantidade_funcionario; i<100; i ++){
     	printf("Informe o Nome do Funcionario:\n "); 
        scanf("%s", &cadastro_funcionario[i].nome);
		printf("Informe o CPF do Funcionario:\n "); 
        scanf("%d", &cadastro_funcionario[i].cpf);
		printf("informe o RG do Funcionario:\n "); 
        scanf("%d", &cadastro_funcionario[i].rg);
		printf(" nforme o Endereco do Funcionario:\n "); 
        scanf("%s", &cadastro_funcionario[i].endereco);
		printf("Informe o Telefone do Funcionario:\n ");
		scanf("%d", &cadastro_funcionario[i].telefone);	
        
		cadastro_funcionario[i].matricula=i;
        fflush(stdin);
        
        quantidade_funcionario++;
        
       	printf("\t\t Deseja cadastrar um novo funcionario: [S/N]?\n\t\t ");
        scanf("%s", &opcao);
        if(opcao== 'n')
        break;
        
        } 
	   
 }


// FUNÇÃO CADASTRO DE CLEINTE//
 
void cadastro_cliente(void)
{
   
      for(i=quantidade_cliente; i<100; i++){
      	fflush(stdin);
        printf("Informe o Nome do Cliente:\n\t\t ");
        scanf("%s", &Lcadastro_cliente[i].nome);
        printf("Informe o CPF do Cliente:\n\t\t ");
        scanf("%d", &Lcadastro_cliente[i].cpf);
        printf("Informe o RG do Cliente:\n\t\t ");
        scanf("%d", &Lcadastro_cliente[i].rg);
        printf("Informe o Endereco do Cliente:\n\t\t ");
        scanf("%s", &Lcadastro_cliente[i].endereco);
        printf("Informe o Telefone do Cliente:\n\t\t ");
        scanf("%d", &Lcadastro_cliente[i].telefone);
        Lcadastro_cliente[i].codigo=i;
        fflush(stdin);
        
        quantidade_cliente++;
        
  	    printf(" Deseja cadastrar uma nova empresa: [S/N]?\n\t\t ");
        scanf("%s", &opcao);
        if(opcao== 'n')
        break;
      }
      	
      
      
}

// FUNÇÃO CADASTRO FORNECEDOR 

void cadastro_fornecedor(void)
{
		
	for(i=quantidade_fornecedor; i<100; i++){
	    printf("\t Informe o Nome da Empresa:\n\t\t ");
		scanf("%s", &Gcadastro_fornecedor[i].nome);
	    printf("\t Informe o CNPJ da Empresa:\n\t\t ");
		scanf("%d", &Gcadastro_fornecedor[i].cnpj);
	    printf("\t Informe o Endereco da Empresa:\n\t\t ");
		scanf("%s", &Gcadastro_fornecedor[i].endereco);
	    printf("\t Informe o Telefone da Empresa:\n\t\t ");
		scanf("%d",  &Gcadastro_fornecedor[i].telefone);
	    printf("\t Informe o email da Empresa:\n\t\t ");
		scanf("%s", &Gcadastro_fornecedor[i].email);
		Gcadastro_fornecedor[i].codigo=i;
        fflush(stdin);
    
        quantidade_fornecedor++;
        
  	    printf("\t Deseja cadastar um novo forncedor: [S/N]?\n\t\t ");
  	    scanf("%s", &opcao);
  	    
        if(opcao== 'n')
        break;
      }
     
     
      
	
}

// FUNÇÃO CADASTRO  PRODUTO

void cadastro_produto(void)
{
		
	for(i=quantidade_produto; i<100; i++){
		printf("\t Informe o Nome do Produto\n\t\t ");
		scanf("%s", &Ccadastro_produto[i].nome);	
		printf("\t Informe o Fornecedor do Produto\n\t\t ");
		scanf("%s", &Ccadastro_produto[i].fornecedor);
		printf("\t Informe o Preco do Produto\n\t\t ");
		scanf("%f", &Ccadastro_produto[i].preco);
		Ccadastro_produto[i].codigo=i;
        fflush(stdin);
        
  	    quantidade_produto++;
  	    
		printf("\t Deseja cadastar um novo produto: [S/N]?\n\t\t ");
  	    scanf("%s", &opcao);
        if(opcao== 'n')
        break;
      }
      		 
	
}

//fUNÇAO LISTAR TODOS

void listar_todos(void)
{
			
	do{
	
      printf("DIGITE 1 PARA LISTAR OS FUNCIONARIOS\n");
      printf("DIGITE 2 PARA LISTAR OS CLIENTES\n");
	  printf("DIGITE 3 PARA LISTAR OS FORNECEDORES\n");
	  printf("DIGITE 4 PARA LISTAR OS PRODUTOS\n");	
	  printf("DIGITE 5 PARA SAIR\t\n\t\t ");
	  scanf("%d", &op);
	  switch(op){
		
		case 1:
		    
		    listar_todos_funcionarios();
		    
		    
			break;
			
		case 2:
		
		  listar_todos_clientes();
		  
		    break;
	    			
		case 3:
		
		 listar_todos_fornecedores();
		
			break;
			
		case 4:
		   
	    	listar_todos_produtos();
	    	
		   break;
		   
		case 5:
			
		   system("exit");
		   
		   break; 
			
		default:
		    
		    printf("Opcao Invalida!\n");
		
		  
	  }
	
	
    }while(op != 5);
}

// FUNÇÃO LISTAR  TODOS OS FUNCIONARIOS

void listar_todos_funcionarios(void)

{
	 int i;
	 
	 for(i=0; i<quantidade_funcionario; i++){
        
        printf("\t Matricula  do Funcionario he:%d\n", cadastro_funcionario[i].matricula); 	
		printf("\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
		printf("\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		printf("\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		printf("\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		printf("\t Telefone do Funcionario he:%d\n\n", cadastro_funcionario[i].telefone);
        
      }
}

// LISTAR TODOS CLIENTES

 void listar_todos_clientes(void)
{
   
   int i;
   
   for(i=0; i<quantidade_cliente; i++){
   	
   	    printf("\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
        printf("\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
        printf("\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
        printf("\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
        printf("\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
        printf("\t O Telefone do Cliente he:%d\n\n", Lcadastro_cliente[i].telefone);
       
   }	
	
	
}	
	

// LISTAR TODOS FORNECEDORES 

void listar_todos_fornecedores(void)
{
	int i;
	
	for(i=0; i<quantidade_fornecedor; i++){
	 
	 	printf("\t Codigo  do Fornecedor:%d\n", Gcadastro_fornecedor[i].codigo); 	
		printf("\t Nome da empresa he:%s\n", Gcadastro_fornecedor[i].nome ); 
		printf("\t CNPJ da empresa he:%d\n", Gcadastro_fornecedor[i].cnpj); 
		printf("\t Endereco da empresa he:%s\n", Gcadastro_fornecedor[i].endereco); 
		printf("\t Telefone do empresa he:%d\n", Gcadastro_fornecedor[i].telefone); 
		printf("\t Email da empresa he:%s\n\n", Gcadastro_fornecedor[i].email);
	 
	}
	
}	

// LISTAR TODOS PRODUTOS 

 void listar_todos_produtos(void){
 	
 	 int i;
 	 for(i=0; i<quantidade_produto; i++){
 		
 	   	printf("\t Codigo  do produto:%d\n", Ccadastro_produto[i].codigo); 	
		printf("\t Nome do produto he:%s\n", Ccadastro_produto[i].nome ); 
		printf("\t Fabricante do produto he:%s\n", Ccadastro_produto[i].fornecedor); 
		printf("\t Preco do produto he:R$:%.2f\n\n", Ccadastro_produto[i].preco); 
		
 	  }
 	
 }
 

//FUNÇÃO PESQUISAR TODOS 

void pesquisar(void)

{
  
  do{
  
    printf("\t DIGITE 1 PARA PESQUISAR  FUNCIONARIO\n");
    printf("\t DIGITE 2 PARA PESQUISAR  CLIENTE\n");
	printf("\t DIGITE 3 PARA PESQUISAR  FORNECEDOR\n");
	printf("\t DIGITE 4 PARA PESQUISAR  PRODUTO\n");	
	printf("\t DIGITE 5 PARA SAIR\t\n\t\t ");
	scanf("%d", &op);
    switch(op){
  	   
		 case 1:
		     
		     pesquisar_funcionario();
			 
			 break;
		 case 2:
		 	 
		 	 pesquisar_cliente();
		 	 
		 	 break;
		  case 3:
		     
		      pesquisar_fornecedor();
		     
			 break; 
		 case 4:
		 	 
		 	 pesquisar_produto();
		 	 
		 	 break;
		case 5:
		     system("exit");
			 
			 break;
		default:
		 
		   printf("opcao invalida\n");
		 	
    }
  }while(op != 5);
}

//PESQUISAR FUNCIONARIO
 
void pesquisar_funcionario(void) 
{ 
     int cpf_pesquisa;
     int i;
	 
	 printf("\t Informe o CPF do Funcionario:\n");
	 scanf("\t %d", &cpf_pesquisa);     
     fflush(stdin);
	 for(i=0; i<quantidade_funcionario; i++)     
     { 
         if(cadastro_funcionario[i].cpf==cpf_pesquisa){
         	
         	printf("\t Codigo  do Funcionario he:%d\n", cadastro_funcionario[i].matricula); 	
	  	    printf("\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
	 	    printf("\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		    printf("\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		    printf("\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		    printf("\t Telefone do Funcionario he:%d\n\n", cadastro_funcionario[i].telefone);
        
           }
          else if(cadastro_funcionario[i].cpf!=cpf_pesquisa){
         	
         	printf("\t Funcionario nao encontrado!\n\n");
	    
          }
         	           
        
	 } 
	   	
}

// PESQUISAR CLEINTE	

void pesquisar_cliente(void)

{
	
	 int i;
     int cpf_cliente;
     
   printf("\t Informe o CPF do cliente:\n");
   scanf("%d", &cpf_cliente);
   for(i=0; i<quantidade_cliente; i++){
   	    if(Lcadastro_cliente[i].cpf==cpf_cliente){
   	         printf("\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
             printf("\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
             printf("\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
             printf("\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
             printf("\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
             printf("\t O Telefone do Cliente he:%d\n\n", Lcadastro_cliente[i].telefone);
             
   	       }    
   	      else{
   	      	  
   	           printf("\t Cliente nao encontrado!\n\n");	
   	         }
   }	
	
}

//PESQUISAR  FORNECEDOR	
void pesquisar_fornecedor(void)
{
	int i;
	int cnpj_fornecedor;
	
	printf("\t Informe o CNPJ do forecedor\n");
	scanf("%d", &cnpj_fornecedor);
	for(i=0; i<quantidade_fornecedor; i++){
	    
        if(Gcadastro_fornecedor[i].cnpj==cnpj_fornecedor){
	      printf("\t Codigo  do Fornecedor:%d\n", Gcadastro_fornecedor[i].codigo); 	
		  printf("\t Nome da empresa he:%s\n", Gcadastro_fornecedor[i].nome ); 
		  printf("\t CNPJ da empresa he:%d\n", Gcadastro_fornecedor[i].cnpj); 
		  printf("\t Endereco da empresa he:%s\n", Gcadastro_fornecedor[i].endereco); 
		  printf("\t Telefone do empresa he:%d\n", Gcadastro_fornecedor[i].telefone); 
		  printf("\t Email da empresa he:%s\n\n", Gcadastro_fornecedor[i].email);
	 
		
		}
	 	else{
	 		
	 	  printf("\t Fornecedor nao encontrado\n\n");
	 		
	 	}
	 	
	}
	
}


//PESQUISAR PRODUTO
void pesquisar_produto(void)
{
   
   int i;
   char nome_produto[20];
     
     
      printf("\t Informe o nome do produto:\n");
      scanf("\t %s", &nome_produto);
	  fflush(stdin);	
 	  for(i=0; i<quantidade_produto; i++){
 		  
 	       printf("%i \n\n", strcmp(Ccadastro_produto[i].nome, nome_produto));
           if(!strcmp(Ccadastro_produto[i].nome, nome_produto)){
           
 	   	     printf("\t Codigo  do produto:%d\n", Ccadastro_produto[i].codigo); 	
		     printf("\t Nome do produto he:%s\n", Ccadastro_produto[i].nome ); 
		     printf("\t Fabricante do produto he:%s\n", Ccadastro_produto[i].fornecedor); 
		     printf("\t Preco do produto he:R$:%.2f\n\n", Ccadastro_produto[i].preco); 
			
 		   }
 	      else{
 	    	
 	    	printf("\t Produto nao encontrado\n\n");
 	    	
 	     }
	   
	  }
	
}


//FUNÇÃO EDITAR

void editar(void)

{   
    int codigo_funcionario;
    int codigo_cliente;
	int codigo_fornecedor;
	int codigo_produto;
  do{
  
	printf("\t DIGITE 1 PARA EDITAR FUNCIONARIO\n");
    printf("\t DIGITE 2 PARA EDITAR CLEINTE\n");
	printf("\t DIGITE 3 PARA EDITAR FORNECEDOR\n");
	printf("\t DIGITE 4 PARA EDITAR PRODUTO\n");	
	printf("\t DIGITE 5 PARA SAIR\n");
	scanf("%d", &op);
	
     switch(op){
  	   
		 case 1:
		    editar_funcionario();
				
			 break;
		 case 2:
		 	editar_cliente();
		  
		     break;
		  case 3:
		     editar_fornecedor();
		      
			 break;
			 
		  case 4:
		 	  editar_produto();
		 	 
			  break;
		 case 5:
		     printf("\t saindo..\n");
			 
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
	
	printf("\t ***************Editar Funcionario****************\n\n");
	
	printf("\t DIGITE 1 PARA EDITAR O NOME DO FUNCIONARIO\n");
	printf("\t DIGITE 2 PARA EDITAR O CPF DO FUNCIONARIO\n");
	printf("\t DIGITE 3 PARA EDITAR O RG DO FUNCIONARIO\n");
	printf("\t DIGITE 4 PARA EDITAR O ENDERECO DO FUNCIONARIO\n");
    printf("\t DIGITE 5 PARA EDITAR O TELEFONE DO FUNCIONARIO\n");
    printf("\t DIGITE 6 PARA SAIR");
    scanf("\t %d", &op);
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
	   	    printf("\tInforme o RG:\n");
	   	    scanf("%d", &rg_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		      if(rg_editar_funcionario==cadastro_funcionario[i].rg){
		      	printf("Informe o novo RG do funcionario:\n");
		      	scanf("%d", &cadastro_funcionario[i].rg);
		      }
		
	        }
	   break;
	   
	   case 4:
	   	    printf("\tInforme o endereco:\n");
	   	    scanf("%s", &endereco_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		       if(strcmp(endereco_editar_funcionario, cadastro_funcionario[i].endereco)==0){
		       	 printf("Informe o novo endereco do funcionario:\n");
		       	 scanf("%s", &cadastro_funcionario[i].endereco);
		       	
		       }
		
	        }
	   break;
	   
	   case 5:
	   	     printf("\tInforme o telefone:\n");
	   	     scanf("%d", &telefone_editar_funcionario);
	        for(i=0; i<quantidade_funcionario; i++){
		        if(telefone_editar_funcionario== cadastro_funcionario[i].telefone){
		        	printf("Informe o novo telefone do funcionario:\n");
		        	scanf("%d", &cadastro_funcionario[i].telefone);
		        	
		        }
		
	        }
	   break;
	   
	   case 6:
	   	   printf("\t Saindo\n");
	   	
	   	break;
	   
	   default:
	   
	   printf("\t Opcao invalida");
	           
              
	}
	  
}

// FUNÇÃO EDITAR CLEINTE 
void editar_cliente(void)
{ 
    char nome_editar_cliente[30];
	int cpf_editar_cliente;
	int rg_editar_cliente;
	char endereco_editar_cliente[30];
	int telefone_editar_cliente;
	
	printf("\t ***********Editar Cliente**************:\n\n");
	
	printf("\t DIGITE 1 PARA EDITAR O NOME DO CLEINTE\n");
	printf("\t DIGITE 2 PARA EDITAR O CPF DO CLEINTE\n");
	printf("\t DIGITE 3 PARA EDITAR O RG DO CLEINTE\n");
	printf("\t DIGITE 4 PARA EDITAR O ENDERECO DO CLEINTE\n");
	printf("\t DIGITE 5 PARA EDITAR O TELEFONE DO FORNECEDOR\n");
	printf("\t DIGITE 6 PARA SAIR\n");
	scanf("%d", &op);
	
	 switch(op){
       
	   case 1:
	       printf("\tInforme o nome:\n");
	       scanf("%s", &nome_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(strcmp(nome_editar_cliente, Lcadastro_cliente[i].nome)==0){
	       		printf("\tInforme o novo nome do cleinte:\n");
	       		scanf("%s", &Lcadastro_cliente[i].nome);
	       		
	       		
	       	}
	       	
	       }
	   break;
	   
	   case 2:
	       printf("\tInforme o CPF");
	       scanf("%d", &cpf_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(cpf_editar_cliente==Lcadastro_cliente[i].cpf){
	       		
	       		printf("\tInforme o novo CPF do cleinte:\n");
	       		scanf("%d", &Lcadastro_cliente[i].cpf);
	       	}
	       	
	       }
	   break;
	       
	   case 3:
	       printf("\tInforem o RG:\n");
	       scanf("%d", &rg_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(rg_editar_cliente==Lcadastro_cliente[i].rg){
	       		printf("\tInforme o novo RG do clliente:\n");
	       		scanf("%d", &Lcadastro_cliente[i].rg);
	       		
	       	}
	       	
	       }
	   break;
	   
	   case 4:
	      printf("\tInforme o endereco:\n");
	      scanf("%s", &endereco_editar_cliente);
	      for(i=0; i<quantidade_cliente; i++){
	       	if(strcmp(endereco_editar_cliente, Lcadastro_cliente[i].endereco)==0){
	       		printf("\tInforme o novo endereco do cleinte:\n");
	       		scanf("%s", &Lcadastro_cliente[i].endereco);
	       		
	       	}
	       	
	      }
	   break;
	   
	   case 5:
	        printf("\tInforme o telefone:\n");
	        scanf("%d", &telefone_editar_cliente);
	       for(i=0; i<quantidade_cliente; i++){
	       	if(telefone_editar_cliente==Lcadastro_cliente[i].telefone){
	       	     printf("\tInforme o novo telefone do cliente:\n");
	       	     scanf("%d", &Lcadastro_cliente[i].telefone);
			   }
	       	 
	       }
	   break;
	   
	   case 6:
	   	   printf("\t Saindo");
	   	break;
	   default:
	   
	   printf("\t Opcao invalida" );
	           
              
	}
		
}

// FUNÇÃO EDITAR FORNECEDOR 
 void editar_fornecedor(void)
{   
    char nome_editar_fornecedor[30];
    int cnpj_editar_fornecedor;
	char endereco_editar_fornecedor[30];
	int telefone_editar_fornecedor;
	char email_editar_fornecedor[30];
	
	printf("\t *************Editar Fornecedor**********\n\n");
	
	printf("\t DIGITE 1 PARA EDITAR O NOME DO FORNECEDOR\n");
	printf("\t DIGITE 2 PARA EDITAR O CNPJ DO FORNECEDOR\n");
	printf("\t DIGITE 3 PARA EDITAR O ENDERECO DO FORNECEDOR\n");
	printf("\t DIGITE 4 PARA EDITAR O TELEFONE DO FORNECEDOR\n");
    printf("\t DIGITE 5 PARA EDITAR O E-MAIL DO FORNECEDOR\n");
    printf("\t DIGITE 6 PARA SAIR\n\t\t ");
    scanf("%d", &op);
    switch(op){
       
	   case 1:
	       printf("\t informe o nome:");
           scanf("%s", &nome_editar_fornecedor);
            for(i=0; i<quantidade_fornecedor; i++){
                                 
                if( strcmp(nome_editar_fornecedor, Gcadastro_fornecedor[i].nome )==0){
                                     
                   printf("\tinforme o novo nome do fornecedor:");
                   scanf("%s", &Gcadastro_fornecedor[i].nome ); 
                                 
                }
                         
            }   
	   
	   break;
	   
	   case 2:
	        printf("\t informe o CNPJ do fornecedor:\n");
            scanf("%d", &cnpj_editar_fornecedor);
              for(i=0; i<quantidade_fornecedor; i++){
                             
                if(cnpj_editar_fornecedor== Gcadastro_fornecedor[i].cnpj){
                                
                   printf("\t informe o novo CNPJ do fornecedor:\n");
                   scanf("%d", &Gcadastro_fornecedor[i].cnpj);
                             
                 }          
		
	          }
	   break;
	      
	   case 3:
	     printf("\t informe o endereco:\n");
         scanf("%s", &endereco_editar_fornecedor);
           for(i=0; i<quantidade_fornecedor; i++){
                                 
             if( strcmp(endereco_editar_fornecedor, Gcadastro_fornecedor[i].endereco )==0){
                                     
                printf("/tinforme o novo endereco do fornecedor:\n");
                scanf("%s", &Gcadastro_fornecedor[i].endereco ); 
                                 
             }
                         
           }
	   break;
	    
	   case 4:
	      printf("\t informe o telefone:\n");
			      scanf("%d", &telefone_editar_fornecedor);
                  for(i=0; i<quantidade_fornecedor; i++){
                  	if(telefone_editar_fornecedor== Gcadastro_fornecedor[i].telefone){
                  	
                  	    printf("\t informe o novo telefone do fornecedor:\n");
                  	    scanf("%d", &Gcadastro_fornecedor[i].telefone);
                  	
					  
					  }
                  	 
                  }
	   break;
	     case 5:
	     	
		     printf("\t Informe o E-mail:\n");
	         scanf("%s", &email_editar_fornecedor);
	           	for(i=0; i<quantidade_fornecedor; i++){
	           		
	           		if(strcmp(email_editar_fornecedor,Gcadastro_fornecedor[i].email)==0){
	           			
	           		     printf("\t Informem o novo E-mail do fornecedor:\n");
						 scanf("%s", &Gcadastro_fornecedor[i].email);	
	           		   }
	           		
	               }
	            break;
	   case 6:
	      printf("\t Sair");
	   
	   break;
	       
	   default:
	   
	   printf("\t Opcao invalida");
	           
              
	}
 
}

// FUNÇÃO EDITAR PRODUTO 
 void editar_produto(void)
{
  
   char nome_produto_editar[20];
   char nome_fabricante_editar[20];
   float preco_editar_produto;
   
   printf("\t **********Edcao de Produto****************\n\n");
   
   printf("\t DIGITE 1 PARA EDITAR NOME\n");
   printf("\t DIGITE 2 PARA EDITAR FABRICANTE\n");
   printf("\t DIGITE 3 PARA EDITAR PRECO\n");
   printf("\t DIGITE 4 PARA SAIR\n\t\t ");
   scanf("%d", &op);
   switch(op){
   	
   	case 1:
   		   printf("\t Informe o nome:\n\t\t ");
   		   scanf("%s", &nome_produto_editar);
   	       for(i=0; i<quantidade_produto; i++){
   	       	   
   	       	   if(strcmp(nome_produto_editar, Ccadastro_produto[i].nome)==0){
   	       	   	       
   	       	   	       printf("\t Informe o novo nome no produto:\n\t\t ");
   	       	   	       scanf(" %s", &Ccadastro_produto[i].nome);
   	       	   	
   	       	         }
   	       	 
   	          } 
	   	break;
   	case 2:
   		   printf("\t Informe o fabricante:\n\t\t ");
   		   scanf("%s", &nome_fabricante_editar);
   		   for(i=0; i<quantidade_produto; i++){
   		   	   
   		   	   if (strcmp(nome_fabricante_editar, Ccadastro_produto[i].fornecedor)==0){
   		   	          
   		   	          printf("\t Informe o novo nome de fabricante:\n\t\t ");
   		   	          scanf("\t %s", &Ccadastro_produto[i].fornecedor);
   		   	
					   
					 }
   		   	    
   		   	     
   		      }          
   		break;
   	case 3:
	   
	      printf("\t Informe o preco do produto:\n\t\t ");
	   	  scanf("%f", &preco_editar_produto);
	   	  for(i=0; i<quantidade_produto; i++){
	   		
	   		  if( preco_editar_produto == Ccadastro_produto[i].preco){
	   		      
	   		       printf("\t Informe o novo preco do produto:\n\t\t");
	   		       scanf("%f", &Ccadastro_produto[i].preco);
				   
				 }
	   		
	   	     
	   	     }
   	
   	    break;
	case 4:
	   	 system("\t exit");
	   	 
			break;
	
	default:
	     printf("\t Opcao invalida");	 
	   	
   }
   
}
 
 // FUNÇÃO VERIFICA FUNCIONÁRIO EXISTE
 
 int funcionario_existe(char nome[30]){
 	
 	int i;
 	 for(i=0; i<quantidade_funcionario; i++){
 		
 		if(strcmp(nome, cadastro_funcionario[i].nome)==0)
 		return 1;
 	  }
 	return 0;
 	
 }
 
 
  
// FUNÇÃO VERIFICA SE O CLEINTE EXIST
  
int cliente_existe(char nome[30]){
	
	int i;
	
	for(i=0; i<quantidade_cliente; i++){
		
		if(strcmp(nome, Lcadastro_cliente[i].nome)==0)
		return 1;
		
	}
	return 0;
	
	
}

// FUNÇÃO PRODUTO EXISTE

int produto_existe(char nome[30]){
   
   	
   for(i=0; i<quantidade_produto; i++){
   	
   	if(strcmp(nome,Ccadastro_produto[i].nome)==0)
   	return 1;
   }	
	return 0;
	
}  

// FUNÇÃO RELIZAR VENDA

int realizar_venda(){
	
	int i;
	
  	 
   for(i=0; i<quantidade_venda; i++){
   
  	    printf("\t Informe seu nome:");
  	    scanf("%s", &nome_funcionario);
  	
  	    if(funcionario_existe(nome_funcionario)==1){
  	    	
  	       strcpy(cadastro_funcionario[i].nome, nome_funcionario);	
  	    	
  	      }
  	           else{
  	           	
                    printf("\t Funcionario não encontrado!\n");  	           	
  	           	    break;
  	           	    return;
  	             }
  	    printf("\t Informe o nome do cleinte:");
  	    scanf("%s", &nome_cleinte);
  	
  	   if(cliente_existe(nome_cleinte)==1){
  	   
		   strcpy(Lcadastro_cliente[i].nome, nome_cleinte);
		 
		
	     }  
		 
  	         else{
  	             printf("\t Cliente nao encontado, Favor tente novamente\n!");
		         printf("\t venda não pode ser efetuada\n\n");
		         return;	
  	           }
  	     fflush(stdin);
	     printf("\t informe o nome do produto:");
		 scanf("%s", &nome_produto);
		 if(produto_existe(nome_produto)==1){
		  
		   strcpy(Ccadastro_produto[i].nome, nome_produto);	
  	     
		 }
		    else{
		 	    printf("\t produto não econtrado!\n\n");
		 	    printf("\t venda não pode ser efetuada\n\n");
		 	    break;
			    return;
		    }
		printf("\t Informe a quantidade de produtos:");
		scanf("%d", &quantidade_produto);
	
		printf("\tInforme o valor do produto:");
		scanf("%f", &valor_produto);
		if(valor_produto==Ccadastro_produto[i].preco){
		  	
		  total_pagamento=quantidade_produto*Ccadastro_produto[i].preco;
	
		}
		else{
			printf("\t Valor incorreto\n");
			printf("\t venda não pode ser efetuada\n\n");
			return;
			break;
			
		}		 
	    fflush(stdin);
	    printf("\t Venda efetuada com sucesso!\n\n");
	    
		printf("\t Deseja realizar uma nova venda: [S/N]?\n\t\t ");
  	    scanf("%s", &opcao);
          
		  if(opcao=='n')
          break;
   }
   quantidade_venda++;
   
  return;
}

// FUNÇÃO GERAR RELATÓRIO

int gerar_relatorio()
{
	int i;
	char data[10];
	
	printf("\t Digite a data do dia atual para gerar o relatorio:");
	gets(data);
    
   // GERA O RELATORIO ENTRAR COM A DATA DO DIA ATUAL
	 	 

	if(strcmp(data,__DATE__ )==0){
		
	  for(i=0; i<quantidade_funcionario; i++){
	  	printf("\n\n");
	  	printf("Dados fornecedores\n\n");
        
        printf("\t Matricula  do Funcionario he:%d\n", cadastro_funcionario[i].matricula); 	
		printf("\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
		printf("\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		printf("\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		printf("\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		printf("\t Telefone do Funcionario he:%d\n", cadastro_funcionario[i].telefone);
        
      }
    
	   
	    for(i=0; i<quantidade_cliente; i++){
   	      printf("\n\n");
   	      printf("Dados clientes\n\n");
   	      
   	      printf("\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
          printf("\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
          printf("\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
          printf("\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
          printf("\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
          printf("\t O Telefone do Cliente he:%d\n", Lcadastro_cliente[i].telefone);
       
        }	
	    
	    for(i=0; i<quantidade_fornecedor; i++){
	      printf("\n\n");
	      printf("Dados fornecedores\n\n");
	      
	 	  printf("\t Codigo  do Fornecedor:%d\n", Gcadastro_fornecedor[i].codigo); 	
		  printf("\t Nome da empresa he:%s\n", Gcadastro_fornecedor[i].nome ); 
		  printf("\t CNPJ da empresa he:%d\n", Gcadastro_fornecedor[i].cnpj); 
		  printf("\t Endereco da empresa he:%s\n", Gcadastro_fornecedor[i].endereco); 
		  printf("\t Telefone do empresa he:%d\n", Gcadastro_fornecedor[i].telefone); 
		  printf("\t Email da empresa he:%s\n\n", Gcadastro_fornecedor[i].email);
	 
	    }
	    
	     for(i=0; i<quantidade_produto; i++){
 		  printf("\n\n");
 		  printf("Dados dos produtos\n\n");
 		  
 	   	  printf("\t Codigo  do produto:%d\n", Ccadastro_produto[i].codigo); 	
		  printf("\t Nome do produto he:%s\n", Ccadastro_produto[i].nome ); 
		  printf("\t Fabricante do produto he:%s\n", Ccadastro_produto[i].fornecedor); 
		  printf("\t Preco do produto he:R$:%.2f\n\n", Ccadastro_produto[i].preco); 
		
 	    }
	     for(i=0; i<quantidade_venda; i++){
	     
	      printf("\n\n");
		  printf("Dados das compras\n\n");
   
          printf("\t Funcinário: %s\n", nome_funcionario);
          printf("\t cleinte: %s\n", nome_cleinte);
          printf("\t produto: %s\n", nome_produto);
          printf("\t Quantidade: %d\n", quantidade_produto);
          printf("\t Preco %.2f\n\n", valor_produto);
          printf("\t Total pagamento he: %.2f\n\n", total_pagamento);
	   	
	     }
		
		
		
	  printf("\t Deseja imprimir no bloco de notas:");
	  scanf("%d", &opcao);
		
	  if(opcao=='s'){
		
		
		
	    for(i=0; i<quantidade_funcionario; i++){
         
          FILE *arquivo= fopen("Relatório sistema.txt", "a");
          
          fprintf(arquivo, "Dados dos funcionarios\n\n");
          
          fprintf(arquivo, "\t Matricula  do Funcionario he:%d\n", cadastro_funcionario[i].matricula); 	
		  fprintf(arquivo, "\t Nome do Funcionario he:%s\n", cadastro_funcionario[i].nome ); 
		  fprintf(arquivo, "\t CPF do Funcionario he:%d\n", cadastro_funcionario[i].cpf); 
		  fprintf(arquivo, "\t RG do Funcionario he:%d\n", cadastro_funcionario[i].rg); 
		  fprintf(arquivo, "\t Endereco do Funcionario he:%s\n", cadastro_funcionario[i].endereco); 
		  fprintf(arquivo, "\t Telefone do Funcionario he:%d\n\n", cadastro_funcionario[i].telefone);
          fclose(arquivo);
        }
	   
	    for(i=0; i<quantidade_cliente; i++){
	    	
   	      FILE *arquivo= fopen("Relatório sistema.txt", "a");
   	      
   	      fprintf(arquivo, "Dados dos clientes\n\n");
   	      
   	      fprintf(arquivo, "\t O codigo cliente he:%d\n", Lcadastro_cliente[i].codigo);
          fprintf(arquivo, "\t O nome do cliente he:%s\n", Lcadastro_cliente[i].nome);
          fprintf(arquivo, "\t O CPF do Cliente he:%d\n", Lcadastro_cliente[i].cpf);
          fprintf(arquivo, "\t O RG do Cliente he:%d\n", Lcadastro_cliente[i].rg);
          fprintf(arquivo, "\t O Endereco do Cliente he:%s\n", Lcadastro_cliente[i].endereco);
          fprintf(arquivo, "\t O Telefone do Cliente he:%d\n\n", Lcadastro_cliente[i].telefone);
          fclose(arquivo);
        }	
	    
	    for(i=0; i<quantidade_fornecedor; i++){
	      
		  FILE *arquivo= fopen("Relatório sistema.txt", "a");
	      
	      fprintf(arquivo, "Dados dos fornecedores\n\n");
	      
	 	  fprintf(arquivo, "\t Codigo  do Fornecedor:%d\n", Gcadastro_fornecedor[i].codigo); 	
		  fprintf(arquivo, "\t Nome da empresa he:%s\n", Gcadastro_fornecedor[i].nome ); 
		  fprintf(arquivo, "\t CNPJ da empresa he:%d\n", Gcadastro_fornecedor[i].cnpj); 
		  fprintf(arquivo, "\t Endereco da empresa he:%s\n", Gcadastro_fornecedor[i].endereco); 
		  fprintf(arquivo, "\t Telefone do empresa he:%d\n", Gcadastro_fornecedor[i].telefone); 
		  fprintf(arquivo, "\t Email da empresa he:%s\n\n", Gcadastro_fornecedor[i].email);
	      fclose(arquivo);
	    }
	    
	    for(i=0; i<quantidade_produto; i++){
 		   
		   FILE *arquivo= fopen("Relatório sistema.txt", "a");
 		  
		   fprintf(arquivo, "Dados dos produtos\n\n");
 		  
 	   	  fprintf(arquivo, "\t Codigo  do produto:%d\n", Ccadastro_produto[i].codigo); 	
		  fprintf(arquivo, "\t Nome do produto he:%s\n", Ccadastro_produto[i].nome ); 
		  fprintf(arquivo, "\t Fabricante do produto he:%s\n", Ccadastro_produto[i].fornecedor); 
		  fprintf(arquivo, "\t Preco do produto he:R$:%.2f\n\n", Ccadastro_produto[i].preco); 
		  fclose(arquivo);
 	    }
	    
	     for(i=0; i<quantidade_venda; i++){
           
		   FILE *arquivo= fopen("Relatório sistema.txt", "a");
 		     
           fprintf(arquivo, "Dados de compra\n\n");
   
           fprintf(arquivo, "\t Funcinário: %s\n", nome_funcionario);
           fprintf(arquivo, "\t cleinte: %s\n", nome_cleinte);
           fprintf(arquivo, "\t produto: %s\n", nome_produto);
           fprintf(arquivo, "\t Quantidade: %d\n", quantidade_produto);
           fprintf(arquivo, "\t Preco %.2f\n\n", valor_produto);
           fprintf(arquivo, "\t Total pagamento he: %.2f\n\n", total_pagamento);		 	
           fclose(arquivo);
		 }
		 
         
	  }
	  else{
	  	printf("\t Data invalida impossivel gerar relatorio\n");
	  	
	  	
	  } 
      
    }
    

}




