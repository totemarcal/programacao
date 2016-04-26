
/*Um programa para gerenciar o aluguel de jogos numa locadora Os jogos sao separados por tipo;
xBOX, PLAY, pC).
pOSSUI 100GAMES
AO DAR SAIDA O PROGRAMA DEVE ARMAZENAR O CPF DO CLIENTE , O COD DO GAME, DATAS E HORA DA SAIDA.
fAZER UMA EXTRUTURA STRUCT PARA DATA E outra PARA HORARIO.
COD DAS PLATAFORMAS:
    1 xbox,2playstation,3Pc.*/
 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>s
#include <string.h>
#include<assert.h>


struct cadastro2
{
       char Nome[30];
       int cpfCliente;
       int codc;
}; typedef cliente;
 
 struct data
 {
        int dia;
        int mes;
        int ano;
 };  typedef data;

struct cadastro1
{
       char nPlataforma[30];
       int codgame;
       int codcliente;
       int datasaida;
}; typedef game;
      
void add_game();
void cadastra_game();
void cadastra_cliente();
void add_data()
void aluga_game();
void devolucao();
int pesquisa_n_plataforma(int nplataforma);
void pesquisar_game(int parametro);
void pesquisar_cliente();
void pesquisar_elemento_game(char nplataforma[6]);
int pesquisar_elemento_cliente(int cpfCliente);  

int qtd_game=0;
int qtd_cliente=0;
int qtd_al=0;
game cadastrodegame[100];
cliente cadastrodecliente[100];     
     
     int main(){
         
     
    char login[10];
    int senha,opção1=0,opção2=0,opção3=0,opção4=0,opção5=0,opção6=0;
    int esc = 0;
    int i=0;
    int cod,cod2;
    char pesquisa_game[6];
    int pesquisa_cliente;
    
    add_games();
    do
    {
        printf("Digite seu login ");
        scanf(\n"%s", & login);
        printf("Digite seu senha ");
        scanf("%d", & senha);
        if(strcmp(login,"Olá") && senha != 123)
        {
            printf ("\n\nlogin ou senha invalida\n");
            fflush(stdin);
        }
    } 
  while(strcmp(login,"Olá" ) && senha == 123);
    printf ("\n\nBem vindo\n");
    system("cls");
    do
    {
    printf("\n1 Cadastro\n");
    printf("\n2 Consulta\n");
    printf("\n3 Consulta todos\n");
    printf("\n4 Alteração\n");
    printf("\n5 Alugado\n");
    printf("\n6 Devolução\n");
    printf("\n7 Total de games alugados\n");
    printf("\n8 Sair\n");
     scanf("%d", & esc);
     fflush(stdin);

        system("cls");
        switch (esc)
        {
        case 1:
            printf ("\t\tVoce escolheu Cadastro.\n1 - Cadastro de game\n2 - Cadastro  de cliente\n3 cadastra data");
            printf("Outro - voltar ao menu principal\n");
            scanf("%d", &opção);
            
            
            system("cls");
            if(opção == 1) cadastra_games();
            if(opção == 2) cadastra_cliente();
            if(opção == 3) cadastra_data()
            else break;
            break;
        case 2:
	            fflush(stdin);
	            printf("1 Consulta um game\n 2 Consulta um cliente\n3 Consulta data \n4 Voltar menu principal\n");
	            scanf("%d", &opção);
	            
            if(&opção== 1)
            {
	            fflush(stdin);
	             printf("Digite a plataforma a ser pesquisada:\n");
	             gets(pesquisa_game);
	             pesquisar_elemento_game(nplataforma);
	             fflush(stdin);
	             break;
            }

             if(opção==2)
            {

                printf("Digite a CPF do cliente a ser pesquisada: ");
                scanf("%i", &pesquisa_cliente);
                pesquisar_elemento_cliente(CPFcliente);
                fflush(stdin);
                break;
            }
               if(opção==3)
            {

                fflush(stdin);
                break;
            }
            break;

            fflush(stdin);
        case 3:
        	
              fflush(stdin);

            fflush(stdin);
            printf("1 Consulta todos os games\n");
            printf("2 Consulta todos  os cliente\n");
            printf("3 voltar ao menu principal\n");
            scanf("%d", & esc);
            if(esc== 1)
            {
                pesquisar_games(2);
            }

            if(esc==2)
            {
                pesquisar_cliente();
            }
            if(esc==3)
            {
                break;
            }

            break;
         
 case 4:

            fflush(stdin);
            printf("1 alteracao de game\n");
            printf("2 alteracao  de cliente\n");
            printf("3 voltar ao menu principal\n");
            scanf("%d", &opção4);

            if(opção4 == 1)
            {
                fflush(stdin);
                printf("1 Para alteracao a nplataforma\n  ");
                printf("2 Para alteracao o codcliente\n  ");
                printf("3 Para alteracao o datasaida\n  ");
				printf("4 Para alteracao o codgame\n");
                printf("5 voltar ao menu principal\n\n  ");
                scanf("%d", &opção5);



                   if (opção5==1)
                   {

                    printf("Digite o codigo do game");
                    scanf("%d", &codgame);
                    for(i=0; i<qtd_game; i++)
                    {

                        if(codgame == cadastrodegame[i].codgame)
                        {
                            printf("Digite a plataforma:");
                            scanf("%c", &cadastrodegame[i].nplataforma);
                        }
                    }
                    fflush(stdin);

                }


                    if (opção5==2)
                  {

                    printf("Digite o codigo do game");
                    scanf("%d", &codgame);
                    for(i=0; i<qtd_carro; i++)
                    {

                        if(codgame == cadastrodegame[i].codgame)
                        {
                            printf("Digite o codigo do cliente:");
                            scanf("%d", &cadastrodegame[i].codcliente);
                        }
                    }
                    fflush(stdin);

                }


                   if (opção5==3)
                {

                    fflush(stdin);
                    printf("Digite o codigo do game");
                    scanf("%d", &codgame);
                    for(i=0; i<qtd_game; i++)
                    {

                        if(codgame == cadastrodegame[i].codgame)
                        {
                            printf("Digite a data de saida:");
                            scanf("%d", &cadastrodegame[i].datasaida);
                        }
                    }
                    fflush(stdin);


                }

                 if (opção5==4)
                {

                    fflush(stdin);
                    printf("Digite o codigo do game");
                    scanf("%d", &codgame);
                    for(i=0; i<qtd_game; i++)
                    {

                        if(codgame == cadastrodegame[i].codgame)
                        {
                            printf("Digite cod do game:");
                            scanf("%d", &cadastrodegame[i].codgame);
                        }
                    }
                    fflush(stdin);


                  if (opção5==5)
                {

                    break;
                }
                break;

            }
    
          if(opção4 == 2)//alteração da cadastro 2 cliente
            {
                fflush(stdin);
                printf("1 Para alteracao a nome\n  ");
                printf("2 Para alteracao o cpf\n  ");
                printf("3 Para alteracao o codigo de cliente\n\n ");
                printf("4 voltar ao menu principal\n\n  ");
                scanf("%d", & opção4);
                
                 
                if (opção4==1)//altera o nome do cliente
                {
                    fflush(stdin);

                    printf("Digite o codigo do cliente");
                    scanf("%d", &codc);
                    for(i=0; i<qtd_cliente; i++)
                    {

                        if(codc == cadastrodecliente[i].codc)
                        {
                            printf("Digite o nome do Cliente:");
                            scanf("%c", &cadastrodecliente[i].nome);
                        }
                    }
                    fflush(stdin);

                    break;
                }
                   if (opção4==2)//altere o cpfCliente
                {
                    fflush(stdin);

                    printf("Digite o codigo do cliente");
                    scanf("%d", &codc);
                    for(i=0; i<qtd_cliente; i++)
                    {

                        if(codc == cadastrodecliente[i].codc)
                        {
                            printf("Digite  cpfCliente :");
                            scanf("%d", &cadastrodecliente[i].cpfCliente);
                        }
                    }
                    fflush(stdin);

                    break;
                }
                if (opção4==3)            //altera o codigo do cliente
                {
                    fflush(stdin);

                    printf("Digite o codigo do cliente");
                    scanf("%d", &codc);
                    for(i=0; i<qtd_cliente; i++)
                    {

                        if(codc == cadastrodecliente[i].codc)
                        {
                            printf("Digite codigo do cliente:");
                            scanf("%d", &cadastrodecliente[i].codc);
                        }
                    }
                    fflush(stdin);

                    break;
                }
                
                if (opção4==4)
                {
                    break;
                }



                 break;

             }
             break;
case 5:
            aluga_game();
            break;
case 6:
            devolucao();
            break;

case 7:
            system("cls");
            	printf("Total de games alugados %i\n", qtd_al);
            	system("pause");
            break;
case 8:
            break;
        default:
            printf("Opcao Invalida");
        }
        opção = 0;
    }
    while(esc != 8);



    system("pause>>null");
   
    void add_games()
{
    strcpy(cadastrodegame[0].nplataforma, "playstation";
    cadastrodegame[0].datasaida = 101015;
    strcpy(cadastrodegame[0].codcliente, "02");
    cadastrodegame[0].cod = qtd_game++;
    cadastrodegame[0].status = 0;
    
    strcpy(cadastrodegame[0].nplataforma, "Xbox";
    cadastrodegame[0].datasaida = 100814;
    strcpy(cadastrodegame[0].codcliente, "05");
    cadastrodegame[0].cod = qtd_game++;
    cadastrodegame[0].status = 0;
    
}

    strcpy(cadastrodecliente[0].nome, "Maria Brito");
    cadastrodecliente[0].cpf = 11;
    strcpy(cadastrodecliente[0].data, "02-09-15");
    cadastrodecliente[0].codcliente = qtd_cliente++;
    cadastrodecliente[0].game = -1;

    strcpy(cadastrodecliente[1].nome, "Cassio ");
    cadastrodecliente[1].cpf = 22;
    strcpy(cadastrodecliente[1].data, "21-06-12");
    cadastrodecliente[1].codcliente = qtd_cliente++;
    cadastrodecliente[1].game = -1;
    
    void cadastra_game()
{
    int i;
    char esc;
    for(i = qtd_game; i<100; i++)
    {

        printf("Digite o cod do game ");
        scanf("%d", & cadastrodegame[i].codgame);
        fflush(stdin);

        printf("Digite a paltaforma do game ");
        scanf("%c", & cadastrodegame[i].nplataforma);
        fflush(stdin);
        printf("Digite o cod do cliente ");
        scanf("%d", & cadastrodegame[i].codcliente);
        fflush(stdin);
        printf("Digite a data de saida ");
        scanf("%d", & cadastrodegame[i].datasaida);
        fflush(stdin);
        cadastrodegame[i].codgame = qtd_carro++;
        cadastrodegame[i].status = 0;
        fflush(stdin);

        printf("\nO Cod game e %d\nA plataforma %c",cadastrodegame[i].codgame,cadastrodegame[i].nplataforma);
        printf("\n codigo do cliente %d \ne data de saida %d",cadastrodegame[i]cadcliente,cadastrodegame[i].datasaida);

        printf("Deja cadastrar novamente [s]-Sim [n]-Nao ?");
        scanf("%c", &esc);
        fflush(stdin);
        if(esc == 'n')
        {
            break;
        }
    }
}

void cadastra_cliente()
{
    int i;
    char esc;
    for(i=qtd_cliente; i<100; i++)
    {


        printf("Digite o nome do cliente ");
        scanf("%c", &cadastrodecliente[i].Nome);
        fflush(stdin);
        printf("Digite o CPF do cliente ");
        scanf("%i", &cadastrodecliente[i].cpfCliente);
        fflush(stdin);
        printf("Digite o codigo do cliente ");
        scanf("%i", &cadastrodecliente[i].codc);
        fflush(stdin);
        fflush(stdin);
        cadastrodecliente[i].codc = qtd_cliente++;
        cadastrodecliente[i].cliente = -1;
        printf("\nO Nome e %c \nO CPF %d \n O codigo Cliente %d" ,cadastrodecliente[i].Nome, cadastrodecliente[i].cpfCliente,cadastrocliente[i].codc);
        printf("Deja cadastrar novamente [s]-Sim [n]-Nao ?");
        scanf("%c", &esc);
        if(esc == 'n')
        {
            break;
        }
    }
}void aluga_game()
{
    int cpfCliente, codgame, pesq, i;
    char esc;
    printf("Digite o cpf do cliente\n");
    scanf("%i", &cpfCliente);
    for(i=0; i< qtd_cliente; i++)
    {
        if(cadastrodecliente[i].cpf == cpfCliente)
        {
            if(cadastrodecliente[i].game >= 0)
            {
                printf("O cliente ja possui um game alugado!n");
                return 0;
            }
            else
            {
                int pesquisa;
                pesquisar_game(1);
                printf("Digite o codigo do game");
                scanf("%i", &codgame);
                pesquisa = pesquisa_cod_game(codgame);
                if(pesquisa == 1)
                {
                    printf("Confirma Aluguel?\n");
                    fflush(stdin);
                    scanf("%c", &esc);
                    if(esc == 's')
                    {
                        cadastrodegame[codgame].status = 1;
                        cadastrodecliente[i].game = codgame;
                        printf("Alugado");
                        qtd_al++;
                        return 1;
                    }
                    else
                    {
                        printf("Cancelado\n");
                        return 0;
                    }
                }
                else if(pesquisa == 2)
                {
                    printf("O game ja esta alugado\n");
                    return 0;

                }
                else
                {
                    printf("O game n existe!\n");
                    return 0;
                }
            }
        }
    }
    printf("Cliente n existe!\n");
}
void devolucao()
{
    int cpfCliente, pesq, i;
    char esc;
    printf("Digite o cpf do cliente\n");
    scanf("%i", &cpfCliente);
    pesq = pesquisar_elemento_cliente(cpfCliente);
    if(pesq >= 0)
    {
        //pesquisar_cliente(codCliente);
        printf("Deseja devolver o game?\n");
        fflush(stdin);
        scanf("%c", &esc);
        if(esc == 's')
        {
            int i;
            int temp = cadastrodecliente[pesq].game;
            cadastrodecliente[pesq].game = -1;
            cadastrodecarro[temp].status = 0;
            printf("Devolvido!\n");
        }
        else
        {
            printf("Cancelado\n");
        }
    }
}

int pesquisa_cod_game(int codgame)
{
    int i;
    for(i=0; i<qtd_game; i++)
    {
        if(codgame == cadastrodegame[i].codgame)
        {
            if(cadastrodegame[i].status == 0)
            {
                printf("\no cod e %d",codgame);
                printf("\nA plataforma e %s",cadastrodegame[i].nplataforma);
                printf("\nO cod cliente e %d",cadastrodegame[i].codcliente);
                printf("\nA data de saida e %s",cadastrodegame[i].datasaida);
                return 1;//se  disponivel
            }
            else
            {
                return 2;//O game ja esta alugado
            }
        }
    }
    return -1;//game n encontrado
    
}
    
    void pesquisar_game(int parametro)
{
    /* Parametros: 1 Mostra dados iportantes de todos os games
                   2 Mostra infomacoes de games
    */
    int i;
    if(parametro == 1)
    {
        for(i=0; i<qtd_games; i++)
        {
            printf("COD: %i - %s - %i %i\n", cadastrodegame[i].codgame, cadastrodegame[i].nplataforma, cadastrodegame[i].codcliente, cadastrodegame[i].datasaida);
        }
    }
    if(parametro == 2)
    {
        for(i=0; i<qtd_games; i++)
        {
            printf("\no cod e %d",cadastrodegame[i].codgame);
            printf("\nA nplataforma e %c",cadastrodegame[i].nplataforma);
            printf("\nO cod cliente e %d",cadastrodegame[i].codcliente);
            printf("\nA data de saida e %s",cadastrodegame[i].datasaida);
          
        }
    }
}

    void pesquisar_cliente()
{
    int i;
    for(i=0; i<qtd_cliente; i++)
    {
        printf("\nO cod  e %d",cadastrodecliente[i].codc);
        printf("\nO nome e %s",cadastrodecliente[i].nome);
        printf("\nO CPF e %i ",cadastrodecliente[i].cpfCliente);
    }
}

 void pesquisar_elemento_game(char[nplataforma])
{
    int i;

    for(i=0; i<qtd_game; i++)
    {
        printf("%i \n\n", strcmp(cadastrodegame[i].nplataforma,plataforma));
        if(!strcmp(cadastrodegame[i].nplataforma,plataforma))
        {

            printf("\no cod e %d",cadastrodegame[i].codgame);
            printf("\nA plataforma e %s",cadastrodegame[i].nplataforma);
            printf("\nO cod cliente e %d",cadastrodegame[i].codcliente);
            printf("\nA data e %s",cadastrodegame[i].datasaida);
            
        }

    }
}

int pesquisar_elemento_cliente(int cpfCliente)
{
    int i;
    for(i=0; i<qtd_cliente; i++)
    {
        if(cadastrodecliente[i].cpf == cpfCliente)
        {

            printf("\nO cod e %d",cadastrodecliente[i].codc);
            printf("\nO nome e %s",cadastrodecliente[i].nome);
            printf("\nO CPF e %i ",cadastrodecliente[i].cpfCliente);
            
            if(cadastrodecliente[i].game == -1)
            {
                printf("Nao possui game alugado\n\n");
                return -1;
            }
            else
            {
                printf("Esta em posse do game de codigo %i\n\n", cadastrodecliente[i].game);
                return i;
            }
        }
    }
    printf("Nao Existe!");
    return -1;
}
    

