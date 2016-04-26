#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUANTIDADE 5


typedef struct cliente{
	 char nome_do_cliente [100];
	 char numero_do_telefone [20];
	 char endereco [100];
     char complemento [50];
	float total_gasto;
}cliente;

typedef struct pizza {

     int codigo_da_pizza;
     char nome_da_pizza [50];
     float valor_da_pizza;

}pizza;

typedef struct pedido{

     int numero_do_pedido;
     char numero_do_telefone [20];
     int codigo_da_pizza;
     int codigo_do_motoqueiro;
     int situacao_do_pedido;
}pedido;


main()
{
    int senha;
    char usuario[20];
    
    	

    do {


printf("\t\tdigite usuario\n\n");
   gets(usuario);


printf("\t\tdigite a senha\n\n");
    scanf("%i",& senha);
fflush(stdin);


}while (senha != 123 || strcmp(usuario,"admin"));

void cadastra (int * vet);



setlocale(LC_ALL, "portuguese");
  // COMEÇO DAS VARIÁVEIS DE SAIDAS DAS FUNÇÕES E DOS PROTÓTIPOS DAS FUNÇÕES.//
  pizza total_gasto (pizza total[]);

  pedido situacao_pizza(pizza situacaopizza [] );

  int funcao_codigo_motoqueiro( int motoqueiro);

  pizza saida_valor_total[QUANTIDADE];

  pedido saida_estado_pizza [QUANTIDADE];

  int saida_codigomotoqueiro;
  // FIM DAS VARIÁVEIS DE SAIDAS DAS FUNÇÕES E DOS PROTÓTIPOS DAS FUNÇÕES.//

  cliente Clientes [QUANTIDADE]; // Declarei a variavel " Clientes" que contem os campos :nome,telefone, endereco e complemento da estrutura de 5 clientes.//
  pizza Pizzas [QUANTIDADE]; // Declarei a variavel "Pizzas" que contem os campos: condigo, nome e valor da pizza da estrutura com 5 *pizzas.//
  pedido Pedidos [QUANTIDADE]; // Declarei a variavel "Pedidos" que contem os campos: pedido, telefone, pizza, codigo do motoqueiro e situação do pedido.//
  int contador,opcao=0, opcao2=0,opcao3=0, cont_id_telefone=0, qtd_cadastro = 0, qtd_cadastrada_cli=0;
  int qtd_cadastrada_pizzas=0, qtd_cadastrada_pedidos=0, condigo_moto=0;
  int numClientes=0, numPizzas=0,i,Clientes_pizzas_cadastrados=0,contecliente=1,conte_situacao_do_pedido=0;
  char pesquisar [15],conte_situacao1[1], conte_situacao2 [1], codigo_do_motoqueiro;


while(opcao!=8){

 system("cls"); //limpar a tela
 printf("\n");
 printf("\t\t\t\tPIZZAS____&____MASSAS\n\n");
 printf("________________________________________________________________________________\n");

 printf("\t\t\t\tMENU.\n\n");
 printf("\tESCOLHA UMA OPCAO DESEJADA:\n\n");
 printf("________________________________________________________________________________\n");
 printf("\t* 1-CLIENTES           * 2-PIZZAS              * 3-PEDIDOS\n\n ");
 printf("\t* 4-PESQUISAR CLIENTES * 5-SITUAÇAO DO PEDIDO  * 6-DESPACHO DA PIZZA\n\n");
 printf("\t* 7-VALOR TOTAL DAS PIZZAS POR CLIENTE         * 8-SAIR\n");
printf("_______________________________________________________________________________\n");

fflush(stdin);
scanf("%d",&opcao);

 	switch (opcao){

 	case 1:

        	while(opcao2!=3){

        	 system("cls"); //limpar a tela
        	 printf("\n\n");

         	printf("1- Cadastrar clientes. 2- listar clientes. 3- Sair\n\n");
         	fflush(stdin);
 			scanf("%d",&opcao2);

		 	switch (opcao2){

 			case 1:
                printf("\t\t\t\tCADASTRAR CLIENTES\n\n");
                if(qtd_cadastrada_cli==QUANTIDADE){
                   printf("\t\tQUANTIDADE MAXIMA DE CLIENTES JA CADASTRADA\n\n");
                   system("pause");
                   break;
               }
                printf("Digite a Quantidade de Clientes a cadastrar\n\n");
                scanf("%d",&qtd_cadastro);

                for(i=0;i<qtd_cadastro;i++){
                 printf("\t\tCLIENTE %d\n\n",contecliente);
                 contecliente++;
				printf("\t Digite o nome do cliente :\n");
				fflush(stdin);
 				gets(Clientes[qtd_cadastrada_cli].nome_do_cliente);

 				printf("\tDigite o numero de telefone:\n\n");
 				gets(Clientes[qtd_cadastrada_cli].numero_do_telefone);
 	            fflush(stdin);
 				printf("\t Digite o endereco :\n\n");
 				gets(Clientes[qtd_cadastrada_cli].endereco);

 				printf("\t Digite o complemento :\n\n");
 				gets(Clientes[qtd_cadastrada_cli].complemento);
 				fflush(stdin);
 				qtd_cadastrada_cli++;

 				system("pause");
 				Clientes_pizzas_cadastrados++;
                }

		 	break;

 			case 2:

 				 if(qtd_cadastrada_cli<1){

                     printf("\t\tCLIENTES NÃO CADASTRADOS.CADASTRE-OS!\n\n");
                     system("pause");
                     break;
                     }

 			     for(i=0;i<qtd_cadastrada_cli;i++){
 					printf("\t\t Nome do cliente: %s\n\n",Clientes[i].nome_do_cliente);

 					printf("\t\t Numero do telefone: %s\n\n",Clientes[i].numero_do_telefone);

 					printf("\t\tEndereco: %s\n\n",Clientes[i].endereco);

 					printf("\t\tComplemento: %s\n\n",Clientes[i].complemento);

 					printf("\n");



                   }
                   system("pause");
                   break;
		 		case 3:
		 		printf(" \t\tVOCE SAIU DO CAMPO CADASTRAR CLIENTES\n\n");

 				system("pause");
 				break;
		 }

 	}
 break;
 case 2:
 	 printf("\t\t\t\tCADASTRAR PIZZAS\n\n");


       if(qtd_cadastrada_pizzas==QUANTIDADE){
       printf("\t\tQUANTIDADE MAXIMA DE CLIENTES JA CADASTRADA\n\n");
       system("pause");
       break;
       }
       printf("\t\tDIGITE A QUANTIDADE DE PIZZAS A CADASTRAR\n\n");
       scanf("%d",&qtd_cadastrada_pizzas);

    for(i=0;i<qtd_cadastrada_pizzas;i++){
    printf("\t\t DIGITE O CODIGO DA PIZZA\n\n");
    scanf("%d",&Pizzas[qtd_cadastrada_pizzas].codigo_da_pizza);
    fflush(stdin);
    printf("\t\t DIGITE O NOME DA PIZZA\n\n");
    gets(Pizzas[qtd_cadastrada_pizzas].nome_da_pizza);
    fflush(stdin);
    printf("\t\tDIGITE O VALOR DA PIZZA \n\n");
    scanf("%f",&Pizzas[qtd_cadastrada_pizzas].valor_da_pizza);
   Clientes_pizzas_cadastrados++;
   saida_valor_total[i]=  total_gasto(Pizzas);

 saida_valor_total[i]=  total_gasto(Pizzas);
}
break;

 case 3:

    if(Clientes_pizzas_cadastrados<1){

    printf("\tCADASTRE OS CLIENTES E AS PIZZAS PRIMEIRO, DEPOIS CADASTRE OS PEDIDOS.\n\n");
    system("pause");
    break;
        }

   printf("\t\t\t\tCADASTRAR PEDIDOS\n\n");

   if(qtd_cadastrada_pizzas==QUANTIDADE){
   printf("\t\tQUANTIDADE MAXIMA DE CLIENTES JA CADASTRADA\n\n");
   system("pause");
   break;
       }
   printf("\t\tDIGITE A QUANTIDADE DE PEDIDOS A CADASTRAR\n\n");
   scanf("%d",&qtd_cadastrada_pedidos);
   for(i=0;i<qtd_cadastrada_pedidos;i++){
   printf("\t\t DIGITE O NUMERO DO PEDIDO\n\n");
   scanf("%d",&Pedidos[qtd_cadastrada_pedidos].numero_do_pedido );
   fflush(stdin);
   printf("\t\tDIGITE O NUMERO DO TELEFONE \n\n");
   gets(Pedidos[qtd_cadastrada_pedidos].numero_do_telefone);
   fflush(stdin);
   printf("\t\tENTRE COM O CODIGO DA PIZZA\n\n");
   scanf("%d",&Pedidos[qtd_cadastrada_pedidos].codigo_da_pizza);
   fflush(stdin);

   Pedidos[qtd_cadastrada_pedidos].codigo_do_motoqueiro=0;
   fflush(stdin);
   Pedidos[qtd_cadastrada_pedidos].situacao_do_pedido=1;

  conte_situacao_do_pedido++;
}


break;

  case 4:


                printf("\t\t1- PESQUISAR CLIENTE.-2 SAIR.\n\n");
                scanf("%d",&opcao3);
                system("cls");
       switch(opcao3){


                 case 1:

                     printf("\t\t DIGITE O NUMERO DO TELEFONE DESEJADO\n\n");
                     fflush (stdin);
                     gets(pesquisar);

                    for(i=0;i<QUANTIDADE;i++){
                    if(strcmp(pesquisar,Clientes[i].numero_do_telefone) == 0){


                    printf("\t\tNOME DO CLIENTE    : %s\n\n",Clientes[i].nome_do_cliente);

 					printf("\t\tNUMERO DO TELEFONE : %s\n\n",Clientes[i].numero_do_telefone);

 					printf("\t\tENDERECO           : %s\n\n",Clientes[i].endereco);

 					printf("\t\tCOMPLEMENTO        : %s\n\n",Clientes[i].complemento);
 					cont_id_telefone++;

                    cont_id_telefone ++;
                    }
                   }
                    if(cont_id_telefone <1){
                    printf("\t\tNUMERO INVALIDO. DIGITE NOVAMENTE\n\n");
                    system("pause");
                    break;
                      }

                   system("pause");
                   break;

               case 2:
                  printf("\t\t VOCE SAIU DO CAMPO PESQUISAR.\n\n");
                  break;
                      }



     case 5 :
            printf("\t\tVOCÊ ESTÁ SITUACAO DO PEDIDO\n\n");
          if(conte_situacao_do_pedido==1){
             codigo_do_motoqueiro=0;
            printf("\t\tEM PREPARO\n\n");
          }
          break;
     case 6:

          printf("\t\tDESPACHO DA PIZZA \n\n");

          	printf("\t\tDIGITE PARA QUAL SITUAÇÃO DESEJA MUDAR O PEDIDDO\n\n");
            gets(conte_situacao1);



            printf("\t\tPARA QUAL PEDIDO DESEJA MUDAR A SITUACAO\n\n");
             gets(conte_situacao2);

          /* for(i=0;i<QUANTIDADE;i++){

           if(strcmp(conte_situacao1, Pedidos[i].situacao_do_pedido)==0)


           //Pedidos[i].situacao_do_pedido=conte_situacao1;

           printf("\t\tPEDIDO ALTERADO COM SUCESSO!\n\n");

            }

	//Essa linha acima está dando erro//
	*/
	case 7:
		for(i=0;i<qtd_cadastrada_pizzas;i++){

		  printf("\t\tO GASTO POR CADA CLIENTE E:%f \n\n",saida_valor_total[qtd_cadastrada_pizzas].valor_da_pizza);
		  system("pause");
}
break;

    case 8:
   printf("\t\tVOCE SAIU DO PROGRAMA.\n");
   break;

}
}
 	 system("pause");

}

pizza total_gasto (pizza total[QUANTIDADE]){

    int i;
   pizza T;

	 for(i=0;i<QUANTIDADE;i++){

	  T.valor_da_pizza=total[i].valor_da_pizza;



	  return T;
          }
		}

  pedido situacao_pizza(pizza situacaopizza []){



         }

  int funcao_codigo_motoqueiro( int motoqueiro){


        }







