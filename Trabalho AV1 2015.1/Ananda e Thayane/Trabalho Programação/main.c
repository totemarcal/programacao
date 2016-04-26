#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

   //============TELAS DO SISTEMA====================
   //LOGIN
      int login();

  //CARREGAMENTO DO SISTEMA
      int loading (void);

  //LOGOTIPO DA CASA DE SHOWS
      int logotipoEntar();
      int logotipoFinal();

  //OPCOES
      int menuOpcao();
 
  //TELA DE BLOQUEIO
      int bloqueio();


 //==============PROTOTIPOS DO PROGRAMA=======================
 
    //CADASTRAR FUNCIONARIO
      int cadastrarFuncionario();
      int imprimirFuncionario();

   //CADASTRAR QUARTO
      int cadastrarQuarto();
      int imprimirQuarto();
      
    //RESERVAR E LIBERAR
      int reservarQuarto();
      int libererQuarto();
      int listarReservados();  
      int reservarPorIndice();
      int liberarPorIndice();      
      int imprimirQuartoReservado();
      int cadastroClientesReservado();
      int imprimirCadastroClienteReservado();
      
 //==================STRUCT======================
  typedef struct{
        
        char matricula[50];
        char funcao[50];
        char nome[50];
        char cpf [50];
        char rg[50];
                                   
        }funcionario;
        
        funcionario cadastro[50];
//--------------------------------------------------       
  struct acesso{
        
        char login[50];
        char senha[50]; 
        
    } acesso;  
 //--------------------------------------------------       
  typedef struct{
         char ap[100];
         char andar[10];
         char reservado;
         char nome[50];
         char cpf[50];
         char data[50];
         char hora[50];
         }motel; 
        
        motel quarto[200];    
 //--------------------------------------------------- 
  typedef struct{
         char nome[100];
         char cpf[15];
         char data[15];
         char hora[15];
       
         }reservados;
         
    reservados cliente[1000] ;
        
 int IndiceAtual = 0;
 int NovoIndice = 0;
 //===================PROTOTIPOS DAS FUNÇÕES=========================        
     void Menucadastrar();
     void excluir();
     void Menupesquisar();
     void reservado();
     void liberarado();
     void sair();
  
  
 //===================================================================
 
 int main(){
          //logotipoEntar();
         // system("cls");
         // loading ( );
          system ("cls");
          system ("color 2F"); 
        //  login(login);
          menuOpcao();
          
         }   
   
     //================================================================
    //                          FUNÇÕES
   //================================================================== 
   
   //===================CADASTRAR E IMPRIMIR FUNCIONARIO===============
   
   int cadastrarFuncionario(funcionario *c ){
          
                   system("cls");
                   printf("DIGITE A MATRICULA:\n");
                   gets(c->matricula);
                   fflush(stdin);   
                   printf("DIGITE A FUNCAO: \n");                         
                   gets(c->funcao);
                   fflush(stdin);                 
                   printf("DIGITE O NOME: \n");
                   gets(c->nome); 
                   fflush(stdin);                        
                   printf("DIGITE O CPF: \n");
                   gets(c->cpf); 
                   fflush(stdin);                        
                   printf("DIGITE O RG: \n");                                                 
                   gets(c->rg);                         
                   fflush(stdin);     
                   printf("\nCADASTRO REALIZADO COM SUCESSO!!!\n\n");
                   
                   IndiceAtual++;
                   
                }
                
     int imprimirFuncionario(funcionario *c){
           
           int x;
                                         
                   system("cls");
                   for(x=0; x<IndiceAtual; x++){
                   printf("\n=========================================\n");
                   printf("MATRICULA: %s\n", c->matricula);
                   printf("FUNCAO: %s\n",c->funcao);
                   printf("NOME: %s\n",c->nome);
                   printf("CPF: %s\n",c->cpf);
                   printf("RG: %s",c->rg);
                   printf("\n=========================================\n");
                   
                   c++;
                   
           }
           
        }
   //======================TELA DE BLOQUEIO============================
  
    int bloqueio(){
        
      printf("\n\n\t\t\tSECAO BLOQUEADA!\n\n");
      system("pause");
       login();
        }
   
   
   //===========================SAIR===================================
   
      void sair(){
           system("cls");
           logotipoFinal();
           printf("\t\tOBRIGADO POR UTILIZAR O NOSSO SISTEMA!!!\n\n");
           printf("\t\tPrecione ENTER para SAIR\n");
           getchar();
           exit(1);
           }
    //==================================================================
   //                   CADASTRAR QUARTO
   //==================================================================
    
   //CADASTRAR QUARTO
    
       int cadastrarQuarto(motel *m){
                         
           system("cls");
           printf("\n\nATENCAO.: AO CADASTRAR, O NUMERO DO PRIMEIRO QUARTO TEM QUE SER ZERO \n\n\n");
           printf("DIGITE O NUMERO DO APARTAMENTO: \n");                         
           gets(m->ap);     
           printf("DIGITE ANDAR: \n");
           gets(m->andar);
           fflush(stdin);
           m->reservado = 'N'; 
           printf("\nCADASTRO REALIZADO COM SUCESSO\n\n");                          
           getchar(); 
         
           NovoIndice++;
    
              } 
    
       int imprimirQuarto(motel *m){
           
           int x;
           
           system("cls");
           for(x=0; x<NovoIndice; x++){
           printf("\n=========================================\n");
           printf("QUARTO: %s\n\n", m->ap);
           printf("ANDAR: %s\n\n",m->andar);
           printf("RESERVADO: %c\n\n", m->reservado);
           printf("\n=========================================\n");
          
             m++;  
            }
           }
           
     int imprimirQuartoReservado(motel *m){
          
          int x;
          
           system("cls"); 
           for(x=0; x<NovoIndice; x++){
           printf("\n=========================================\n");                         
           printf("QUARTO: %s\n\n", m->ap);
           printf("ANDAR: %s\n\n",m->andar);
           printf("RESERVADO: %c\n\n", m->reservado);
           printf("\n=========================================\n");
            
            m++;
          }
         }
      
      int imprimirCadastroClienteReservado(motel *m){
           
           int x;
           system("cls");
           for(x=0; x<IndiceAtual; x++){
           printf("\n=========================================\n");
           printf("CLIENTE: %s\n", m->nome);
           printf("CPF: %s\n", m->cpf);
           printf("DATA: %s\n", m->data);
           printf("HORA: %s\n\n", m->hora);
           printf("\n=========================================\n");
           
            m++;
            }
           }
      
    //==================================================================
   //                   FUNÇÃ0 RESERVAR E LIBERAR
   //==================================================================
   
    int reservarQuarto(motel *m){
    if(m->reservado == 'N'){
        m->reservado = 'S';
      
        return 1;
    } else {
        return 0;   
       }    
    }
    
    int libererQuarto(motel *m){
    if(m->reservado == 'S'){
        m->reservado = 'N';
        return 1;
    } else {
        return 0;   
    }    
}

    int listarReservados(motel *m){
    int x;
    for(x=0; x < NovoIndice; x++){
        if(m->reservado == 'S')
            imprimirQuartoReservado(m);
        m++;
      
      }
    }
   
     int reservarPorIndice(){
       int i;
       if(NovoIndice > 0){
        do{
            printf("DIGITE O NUMERO DO QUARTO: ");
            scanf("%d", &i);
        }while(i < 0 || i > NovoIndice);
      
        if(reservarQuarto(&quarto[i]) == 1){
                                                                                                    
            printf("\nQUARTO RESERVADO COM SUCESSO!\n");
              
        }else {
            printf("\nNAO FOI POSSIVEL RESERVAR ESTE QUARTO!\n");
        }
     }else{
        printf("\nNAO EXISTE QUARTOS!\n");
    }
    system("pause");
  }
    int liberarPorIndice(){
    int i;
    if(NovoIndice > 0){
        do{
            printf("DIGITE O NUMERO DO QUARTO: ");
            scanf("%d", &i);
        }while(i < 0 || i > NovoIndice);
        if(libererQuarto(&quarto[i]) == 1){
            printf("\nQUARTO LIBERADO COM SUCESSO!\n");
        }else {
            printf("\nNAO FOI POSSIVEL DEVOLVER ESTE QUARTO!\n");
        }
     }else{
        printf("\nNAO EXISTE QUARTOS!\n");
     }
      system("pause");
    }
    
    int cadastroClientesReservado(motel *m){
        
        printf("DIGITE O NOME DO CLIENTE: \n");
        scanf("%s",&m->nome);
        printf("DIGITE O CPF: \n");
        scanf("%s",&m->cpf);
        printf("DIGITE A DATA: \n");
        scanf("%s",&m->data);
        printf("DIGITE A HORA: \n");
        scanf("%s",&m->hora);
       
        }
    
   //====================================================================
  //     MENUS, TELAS DE ABERTURA, LOGIN E CARREGAMENTO
 //=======================================================================   
         
    void Menucadastrar(){
         
         int op,i;
         
              
                do {
                    system("cls");
                    printf("\t\tCADASTRO\n\n");
                    printf("\t1 - CADASTRAR FUNCIONARIO\n\n"); 
                    printf("\t2 - CADASTRAR QUARTO\n\n");
                    printf("\t3 - VOLTAR AO MENU\n\n");
                    printf("ESCOLHA SUA OPCAO: ");
                    scanf("%d",&op);
                    getchar();
                  
                }while (op < 1 && op > 3);
                  
                  
                  
                   switch(op){ 
                   case 1:
                      cadastrarFuncionario(&cadastro[IndiceAtual]);
                      getchar();
                      Menucadastrar();
                      break;
                      
                   case 2: 
                      cadastrarQuarto(&quarto[NovoIndice]);
                      getchar();
                      Menucadastrar();
                      break;  
                   case 3:
                     menuOpcao();
                     break;
                   default :
                    printf("\t\tOPCAO INVALIDADE");
                    getchar();
                    break;       
                      }
                    }
                    
  //========================================================================
                               
    void Menupesquisar(){
         int i;
         int op;
        
       
                    do{
                    system("cls");
                    printf("\t\tCONSULTAR\n\n");
                    printf("\t1 - CONSULTAR FUNCIONARIO\n\n"); 
                    printf("\t2 - CONSULTAR QUARTO\n\n");
                    printf("\t3 - CONSULTAR QUARTOS RESERVADOS\n\n");
                    printf("\t4 - VOLTAR AO MENU\n\n");
                    printf("ESCOLHA SUA OPCAO: ");
                    scanf("%d",&op);
                    getchar();
                   
                    } while (op<1 && op>4 );
                    
                    switch(op){
                    case 1:
                       imprimirFuncionario(cadastro);
                       getchar();
                       Menupesquisar();
                       break; 
                         
                    case 2:
                       system("cls");
                       imprimirQuarto(quarto);
                       getchar();
                       Menupesquisar();
                        break; 
                    case 3:
                        system("cls");
                        listarReservados(quarto);
                        
                        getchar();
                       Menupesquisar();
                        break;
                    case 4:
                      menuOpcao();
                      break;  
                      
                    default :
                      printf("\n\n\t\tOPCAO INVALIDA");
                      getchar();
                      break; 
                             
                    } 
                    system("pause");
                   }
 //=====================================================================
      //TELA DE LOGIN 
      
        int login(){
            
             int a = 1, b = 1, c = 1;
             int i,j;
             
        system("cls");
        system("color 1F");                       
        printf("************************\n");
        printf("USUARIO = admin/ADMIN  *\n");
        printf("************************\n");
        printf("SENHA =  12345         *\n");
        printf("************************\n\n") ;
          
       
                           
        printf("USUARIO: ");
        gets(acesso.login);
        printf("SENHA: ");
        gets(acesso.senha);
                          
              a=strcmp(acesso.login,"admin");
              b=strcmp(acesso.login,"ADMIN"); 
              c=strcmp(acesso.senha,"12345");
              
              
              if(a == 0 && c == 0 || b == 0 && c == 0){
                   system("cls");
                   menuOpcao();
                   
                   }else{
                    system("cls");
                    printf("\n\nSENHA INCORRERA! - TENTE NOVAMENTE\n\n");
                    getchar();
                    system("cls");
                    return login();
                 
                 }     
              
               }
 //======================================================================
    //LOGOTIPO DE ENTRADA DO MOTEL
    int logotipoEntar(){ 
      
              fflush(stdin);
              system("cls");
              system ("color 4F");
              printf("\t\t*******************************************\n\n");
              printf("\t\t*          BEM VINDO AO SISTEMA           *\n\n");
              printf("\t\t*                 MOTEL                   *\n\n");
              printf("\t\t*           HOUSE OF PLEASURES            *\n\n");
              printf("\t\t*******************************************\n\n");
              printf("\t\tpresione ENTER para entrar no SISTEMA");
              getchar();
              
                            
             } 
 //======================================================================
    //LOGOTIPO DE SAIDA DO MOTEL
    int logotipoFinal(){ 
      
              fflush(stdin);
              system("cls");
              system ("color 4F");
              printf("\t\t*******************************************\n\n");
              printf("\t\t*          SAINDO DO SISTEMA              *\n\n");
              printf("\t\t*                 MOTEL                   *\n\n");
              printf("\t\t*           HOUSE OF PLEASURES            *\n\n");
              printf("\t\t*******************************************\n\n");
            
             }        
                                                       
//==================================================================      
     //MENU     
      int menuOpcao(){
          int opcao;

          do {
                    
       system("cls"); 
       system ("color 2F");             
       printf("\t\t*********************************************\n");
       printf("\t\t*                  MENU                     *\n\n"); 
       printf("\t\t*********************************************\n");
       printf("\t\t*         1 - CADASTRAR                     *\n\n"); 
       printf("\t\t*         2 - CONSULTAR                     *\n\n");
       printf("\t\t*         3 - RESERVAR QUARTO               *\n\n");
       printf("\t\t*         4 - LIBERAR QUARTO                *\n\n");
       printf("\t\t*         5 - BLOQUEAR TELA                 *\n\n");
       printf("\t\t*         6 - SAIR                          *\n");      
       printf("\t\t*********************************************\n");
       printf("\t\t*********************************************\n");
       printf("ESCOLHA SUA OPCAO: ");
       scanf("%d",&opcao);
       system("cls");
           
            switch(opcao){
                case 1://CADASTRO
                    system("cls");
                    Menucadastrar();
                    getchar();
                    break;
                    
                case 2://PESQUISA
                    system("cls");
                    Menupesquisar();
                    getchar();
                    break;
                    
                case 3://RESERVAR QUARTO
                    system("cls");
                    reservarPorIndice() ;
                    getchar();
                    break;
                    
                case 4://LIBERAR QUARTO
                    system("cls");
                    liberarPorIndice();
                    getchar();
                    break;
              //  case 5://EXCLUIR
                    system("cls");
                 //   excluir();
                 //   getchar();
                 //   break;
                                     
                case 5://TELA DE BLOQUEIO
                    getchar(); 
                    bloqueio();
                    getchar();
                    break;
                    
                case 6://SAIR
                    getchar(); 
                    sair();
                    getchar();
                    break; 
                    
               default :
                    printf("\t\tOPCAO INVALIDADE");
                    getchar();
                    break;                     
                    }   
                    getchar();
                    menuOpcao();         
               }
           while (opcao!=7);

                   }                           
                 //  }  
//=======================================================================
  //LOADING
  int loading (void)
{
   int i, j;

   system ("cls");

   printf ("\n\nAGUARDE CARREGANDO OS DADOS..................................: \n\n");

   for (i = 0; i <=50; i++)
   {
      printf ("  %d%%\r", i);
      fflush (stdout);

      for (j = 0; j < i; j++)
      {
         if (!j) // Da espaco na barra pra nao enconstar na borda da tela
           printf ("  ");

         printf ("%c", 220);
         Sleep(3);
      }
   }

   printf ("\n\n\tFinalizando......");
   Sleep (3000);
   system ("cls");
   printf ("\n\n\tCARREGADO!!.........\n\n\n");
   system ("pause");

   return 0;
}     





























