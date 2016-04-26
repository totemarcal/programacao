#include<stdlib.h>
#include<stdio.h>
#include <conio.h>
#include <string.h>
#include<assert.h>

struct Cadastroc
{
    char placa[6];
    int ano;
    char modelo[15];
    char chassi[15];
    int cod;
    int status;
} typedef carro;

struct Cadastroc2
{
    char nome [30];
    int cpf;
    char data[10];
    char tel[15];
    int cod;
    int carro;
} typedef cliente;

void add_carros();
void cadastra_carro();
void cadastra_cliente();
void aluga_carro();
void devolucao();
int pesquisa_cod_carro(int codCarro);
void pesquisar_carro(int parametro);
void pesquisar_cliente();
void pesquisar_elemento_carro(char placa[6]);
int pesquisar_elemento_cliente(int cpfCliente);

int qtd_carro=0;
int qtd_cliente=0;
carro cadastrodecarro[100];
cliente cadastrodecliente[100];

int qtd_al=0;

main()
{
	system("color 9f");
	char login[10],seguir;
    int senha,op1=0,op2=0,op3=0,op4=0,op5=0,op6=0;
    int esc = 0;
    int i=0;
    int cod,cod2;
    char p_placa[6];
    int p_cliente;

    add_carros();
    do
    {

        printf("Digite seu login ");
        scanf("%s", & login);
        printf("Digite seu senha ");
        scanf("%d", & senha);
        if(strcmp(login,"admin") && senha != 123);
        {
            printf("\t\tlogin ou senha invalido\n");
            fflush(stdin);
            system("cls");
        
			
            
        }
    }
    


    while(strcmp(login,"admin" ) && senha != 123);
    printf ("\t\tBem vindo ao RJ Taxi\n                Sua referencia no mercado\n\n");
    system("cls");
    do
    {
        int op;
        printf("1 cadastro\n2 consulta\n3 consulta todos \n4 alteracao\n5 Aluguel\n6 Devolucao\n7 Total de carros alugados\n8 Sair\n");
        scanf("%d", & esc);
        fflush(stdin);

        system("cls");
        switch (esc)
        {
        case 1:
            printf ("\t\tVoce escolheu Cadastro.\n1 - Cadastro de carro\n2 - Cadastro  de cliente\n");
            printf("Outro - voltar ao menu principal\n");
            scanf("%d", & op);

            system("cls");
            if(op == 1) cadastra_carro();
            if(op == 2) cadastra_cliente();
            else break;
            break;

        case 2:
            fflush(stdin);
            printf("1 Consulta um  carro\n2 consulta um   cliente\n3 voltar ao menu principal\n");
            scanf("%d", & op);
            fflush(stdin);
            if(op== 1)
            {
                printf("Digite a placa a ser pesquisada: ");
                gets(p_placa);
                pesquisar_elemento_carro(p_placa);
                fflush(stdin);
                break;
            }

            if(op==2)
            {

                printf("Digite a CPF do cliente a ser pesquisada: ");
                scanf("%i", &p_cliente);
                pesquisar_elemento_cliente(p_cliente);
                fflush(stdin);
                break;
            }

            if(op==3)
            {

                fflush(stdin);
                break;
            }
            break;

            fflush(stdin);

        case 3:
            fflush(stdin);

            fflush(stdin);
            printf("1 Consulta todos os carro\n");
            printf("2 Consulta todos  os cliente\n");
            printf("3 voltar ao menu principal\n");
            scanf("%d", & esc);
            if(esc== 1)
            {
                pesquisar_carro(2);
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
            printf("1 alteracao de carro\n");
            printf("2 alteracao  de cliente\n");
            printf("3 voltar ao menu principal\n");
            scanf("%d", & op4);

            if(op4 == 1)
            {
                fflush(stdin);
                printf("1 Para alteracao a placa\n  ");
                printf("2 Para alteracao o ano\n  ");
                printf("3 Para alteracao o modelo\n  ");
                printf("4 Para alteracao o chassi\n\n  ");
                printf("5 voltar ao menu principal\n\n  ");
                scanf("%d", & op5);


                if (op5==1)
                {

                    printf("Digite o codigo do carro");
                    scanf("%d", &cod);
                    for(i=0; i<qtd_carro; i++)
                    {

                        if(cod == cadastrodecarro[i].cod)
                        {
                            printf("Digite a nova placa:");
                            scanf("%s", &cadastrodecarro[i].placa);
                        }
                    }
                    fflush(stdin);

                }


                if (op5==2)
                {

                    printf("Digite o codigo do carro");
                    scanf("%d", &cod);
                    for(i=0; i<qtd_carro; i++)
                    {

                        if(cod == cadastrodecarro[i].cod)
                        {
                            printf("Digite a nova ano:");
                            scanf("%d", &cadastrodecarro[i].ano);
                        }
                    }
                    fflush(stdin);

                }


                if (op5==3)
                {

                    fflush(stdin);
                    printf("Digite o codigo do carro");
                    scanf("%d", &cod);
                    for(i=0; i<qtd_carro; i++)
                    {

                        if(cod == cadastrodecarro[i].cod)
                        {
                            printf("Digite a nova modelo:");
                            scanf("%s", &cadastrodecarro[i].modelo);
                        }
                    }
                    fflush(stdin);


                }

                if (op5==4)
                {

                    fflush(stdin);
                    printf("Digite o codigo do carro");
                    scanf("%d", &cod);
                    for(i=0; i<qtd_carro; i++)
                    {

                        if(cod == cadastrodecarro[i].cod)
                        {
                            printf("Digite a nova chassi:");
                            scanf("%s", &cadastrodecarro[i].chassi);
                        }
                    }
                    fflush(stdin);

                }

                if (op5==5)
                {

                    break;
                }
                break;

            }

            if(op4 == 2)
            {
                fflush(stdin);
                printf("1 Para alteracao a nome\n  ");
                printf("2 Para alteracao o cpf\n  ");
                printf("3 Para alteracao o o ano de nascimento\n  ");
                printf("4 Para alteracao o tel\n\n  ");
                printf("5 voltar ao menu principal\n\n  ");
                scanf("%d", & op6);

                if (op6==1)
                {
                    fflush(stdin);

                    printf("Digite o codigo do cliente");
                    scanf("%d", &cod2);
                    for(i=0; i<qtd_cliente; i++)
                    {

                        if(cod == cadastrodecliente[i].cod)
                        {
                            printf("Digite a nova nome:");
                            scanf("%s", &cadastrodecliente[i].nome);
                        }
                    }
                    fflush(stdin);

                    break;
                }


                if (op6==2)
                {
                    fflush(stdin);

                    printf("Digite o codigo do cliente");
                    scanf("%d", &cod2);
                    for(i=0; i<qtd_cliente; i++)
                    {

                        if(cod == cadastrodecliente[i].cod)
                        {
                            printf("Digite a nova cpf:");
                            scanf("%s", &cadastrodecliente[i].cpf);
                        }
                    }
                    fflush(stdin);

                    break;
                }


                if (op6==3)
                {
                    fflush(stdin);

                    printf("Digite o codigo do cliente");
                    scanf("%d", &cod2);
                    for(i=0; i<qtd_cliente; i++)
                    {

                        if(cod == cadastrodecliente[i].cod)
                        {
                            printf("Digite a nova ano de nascimento:");
                            scanf("%s", &cadastrodecliente[i].data);
                        }
                    }
                    fflush(stdin);

                    break;
                }


                if (op6==4)
                {
                    fflush(stdin);

                    printf("Digite o codigo do cliente");
                    scanf("%d", &cod2);
                    for(i=0; i<qtd_cliente; i++)
                    {

                        if(cod == cadastrodecliente[i].cod)
                        {
                            printf("Digite a nova tel:");
                            scanf("%s", &cadastrodecliente[i].tel);
                        }
                    }
                    fflush(stdin);

                    break;
                }



                if (op6==5)
                {
                    break;
                }



                break;

            }
            break;
        case 5:
            aluga_carro();
            break;
        case 6:
            devolucao();
            break;

        case 7:
            system("cls");
            	printf("Total de carros alugados %i\n", qtd_al);
            	system("pause");
            break;
        case 8:
            break;
        default:
            printf("Opcao Invalida");
        }
        op = 0;
    }
    while(esc != 8);



    system("pause>>null");
}


void add_carros()
{
    strcpy(cadastrodecarro[0].placa, "14A32B");
    cadastrodecarro[0].ano = 2013;
    strcpy(cadastrodecarro[0].modelo, "Cobalt");
    strcpy(cadastrodecarro[0].chassi, "CDAfH");
    cadastrodecarro[0].cod = qtd_carro++;
    cadastrodecarro[0].status = 0;

    strcpy(cadastrodecarro[1].placa, "218AS1");
    cadastrodecarro[1].ano = 2013;
    strcpy(cadastrodecarro[1].modelo, "Cruze");
    strcpy(cadastrodecarro[1].chassi, "YUASH");
    cadastrodecarro[1].cod = qtd_carro++;
    cadastrodecarro[1].status = 0;

    strcpy(cadastrodecliente[0].nome, "Alghuts Tra");
    cadastrodecliente[0].cpf = 11;
    strcpy(cadastrodecliente[0].data, "21-09-11");
    strcpy(cadastrodecliente[0].tel, "7326493");
    cadastrodecliente[0].cod = qtd_cliente++;
    cadastrodecliente[0].carro = -1;

    strcpy(cadastrodecliente[1].nome, "Eifesuas Drei");
    cadastrodecliente[1].cpf = 22;
    strcpy(cadastrodecliente[1].data, "21-06-12");
    strcpy(cadastrodecliente[1].tel, "7554321");
    cadastrodecliente[1].cod = qtd_cliente++;
    cadastrodecliente[1].carro = -1;
}
void cadastra_carro()
{
    int i;
    char esc;
    for(i = qtd_carro; i<100; i++)
    {

        printf("Digite o placa do carro ");
        scanf("%s", & cadastrodecarro[i].placa);
        fflush(stdin);

        printf("Digite o ano do carro ");
        scanf("%d", & cadastrodecarro[i].ano);
        fflush(stdin);
        printf("Digite o modelo do carro ");
        scanf("%s", & cadastrodecarro[i].modelo);
        fflush(stdin);
        printf("Digite o chassi do carro ");
        scanf("%s", & cadastrodecarro[i].chassi);
        fflush(stdin);
        cadastrodecarro[i].cod = qtd_carro++;
        cadastrodecarro[i].status = 0;
        fflush(stdin);

        printf("\nO Cod e %d\nA placa e %s\nO ano e %d",cadastrodecarro[i].cod,cadastrodecarro[i].placa,cadastrodecarro[i].ano);
        printf("\nO modelo e %s\nO chassis e %s\n",cadastrodecarro[i].modelo,cadastrodecarro[i].chassi);

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
        scanf("%s", &cadastrodecliente[i].nome);
        fflush(stdin);
        printf("Digite o CPF do cliente ");
        scanf("%i", &cadastrodecliente[i].cpf);
        fflush(stdin);
        printf("Digite o ano de nascimento do cliente ");
        scanf("%s", &cadastrodecliente[i].data);
        fflush(stdin);
        printf("Digite o Telefone  do cliente ");
        scanf("%s", &cadastrodecliente[i].tel);
        fflush(stdin);
        cadastrodecliente[i].cod = qtd_cliente++;
        cadastrodecliente[i].carro = -1;
        printf("\nO cod e %d \nO nome e %s \n" ,cadastrodecliente[i].cod, cadastrodecliente[i].nome);
        printf("O CPF e %i \nO o ano de nascimento e %s\nO telefone e %s\n\n",cadastrodecliente[i].cpf,cadastrodecliente[i].data,cadastrodecliente[i].tel);
        printf("Deja cadastrar novamente [s]-Sim [n]-Nao ?");
        scanf("%c", &esc);
        if(esc == 'n')
        {
            break;
        }
    }
}

void aluga_carro()
{
    int cpfCliente, codCarro, pesq, i;
    char esc;
    printf("Digite o cpf do cliente\n");
    scanf("%i", &cpfCliente);
    for(i=0; i< qtd_cliente; i++)
    {
        if(cadastrodecliente[i].cpf == cpfCliente)
        {
            if(cadastrodecliente[i].carro >= 0)
            {
                printf("O cliente ja possui um carro alugado!n");
                return 0;
            }
            else
            {
                int pesquisa;
                pesquisar_carro(1);
                printf("Digite o codigo do carro");
                scanf("%i", &codCarro);
                pesquisa = pesquisa_cod_carro(codCarro);
                if(pesquisa == 1)
                {
                    printf("Confirma Aluguel?\n");
                    fflush(stdin);
                    scanf("%c", &esc);
                    if(esc == 's')
                    {
                        cadastrodecarro[codCarro].status = 1;
                        cadastrodecliente[i].carro = codCarro;
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
                    printf("O veiculo ja esta alugado\n");
                    return 0;

                }
                else
                {
                    printf("O veiculo n existe!\n");
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
        printf("Deseja devover o carro?\n");
        fflush(stdin);
        scanf("%c", &esc);
        if(esc == 's')
        {
            int i;
            int temp = cadastrodecliente[pesq].carro;
            cadastrodecliente[pesq].carro = -1;
            cadastrodecarro[temp].status = 0;
            printf("Devolvido!\n");
        }
        else
        {
            printf("Cancelado\n");
        }
    }
}

int pesquisa_cod_carro(int codCarro)
{
    int i;
    for(i=0; i<qtd_carro; i++)
    {
        if(codCarro == cadastrodecarro[i].cod)
        {
            if(cadastrodecarro[i].status == 0)
            {
                printf("\no cod e %d",codCarro);
                printf("\nA placa e %s",cadastrodecarro[i].placa);
                printf("\nO ano e %d",cadastrodecarro[i].ano);
                printf("\nO modelo e %s",cadastrodecarro[i].modelo);
                printf("\nO chassis e %s\n\n",cadastrodecarro[i].chassi);
                return 1;//Carro econtrado e disponivel
            }
            else
            {
                return 2;//O carro ja esta alugado
            }
        }
    }
    return -1;//Carro n encontrado
}
void pesquisar_carro(int parametro)
{
    /* Parametros: 1 Mostra dados iportantes de todos os carros
                   2 Mostra todas as informações de todos os carros
    */
    int i;
    if(parametro == 1)
    {
        for(i=0; i<qtd_carro; i++)
        {
            printf("COD: %i - %s - %s %i\n", cadastrodecarro[i].cod, cadastrodecarro[i].placa, cadastrodecarro[i].modelo, cadastrodecarro[i].ano);
        }
    }
    if(parametro == 2)
    {
        for(i=0; i<qtd_carro; i++)
        {
            printf("\no cod e %d",cadastrodecarro[i].cod);
            printf("\nA placa e %s",cadastrodecarro[i].placa);
            printf("\nO ano e %d",cadastrodecarro[i].ano);
            printf("\nO modelo e %s",cadastrodecarro[i].modelo);
            printf("\nO chassis e %s\n\n",cadastrodecarro[i].chassi);
        }
    }
}

void pesquisar_cliente()
{
    int i;
    for(i=0; i<qtd_cliente; i++)
    {
        printf("\nO cod e %d",cadastrodecliente[i].cod);
        printf("\nO nome e %s",cadastrodecliente[i].nome);
        printf("\nO CPF e %i ",cadastrodecliente[i].cpf);
        printf("\nO o ano de nascimento e %s",cadastrodecliente[i].data);
        printf("\nO telefone e %s\n\n",cadastrodecliente[i].tel);
    }
}

void pesquisar_elemento_carro(char placa[6])
{
    int i;

    for(i=0; i<qtd_carro; i++)
    {
        printf("%i \n\n", strcmp(cadastrodecarro[i].placa, placa));
        if(!strcmp(cadastrodecarro[i].placa, placa))
        {

            printf("\no cod e %d",cadastrodecarro[i].cod);
            printf("\nA placa e %s",cadastrodecarro[i].placa);
            printf("\nO ano e %d",cadastrodecarro[i].ano);
            printf("\nO modelo e %s",cadastrodecarro[i].modelo);
            printf("\nO chassis e %s\n\n",cadastrodecarro[i].chassi);
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

            printf("\nO cod e %d",cadastrodecliente[i].cod);
            printf("\nO nome e %s",cadastrodecliente[i].nome);
            printf("\nO CPF e %i ",cadastrodecliente[i].cpf);
            printf("\nO o ano de nascimento e %s",cadastrodecliente[i].data);
            printf("\nO telefone e %s\n",cadastrodecliente[i].tel);
            if(cadastrodecliente[i].carro == -1)
            {
                printf("Nao possui carro alugado\n\n");
                return -1;
            }
            else
            {
                printf("Esta em posse do carro de codigo %i\n\n", cadastrodecliente[i].carro);
                return i;
            }
        }
    }
    printf("Nao Existe!");
    return -1;
}
