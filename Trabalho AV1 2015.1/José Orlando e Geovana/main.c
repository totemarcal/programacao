#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 2

struct endereco
{
    char rua [50];
    int num;
    int cep;
    char bairro[50];
    char cidade[50];
    char estado[50];
} typedef endereco;

struct produto
{
    char merc [50];
    int codigo;
    float valor;
    char data[50];
    float quant;
} typedef produto;

struct cadastro
{
    int cod;
    char nome[50];
    char cpf[11];
    int idade;
    endereco end;
    produto prod;
    char sexo[2];
    char email[50];
    char tel[15];
} typedef cadastro;

struct cadastro cliente [MAX];
int prim;

janela_login()
{
    int c, l;
    textcolor(11);
    textbackground(3);
    gotoxy(26,3);
    printf ("PROGRAMA DE CADASTRO DE CLIENTES");
    textbackground(3);
    textcolor(15);
    textcolor(15);
        gotoxy (40,13);
        printf ("USUARIO");
        textcolor(15);
        gotoxy (41,19);
        printf ("SENHA");
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 1);
        printf("%c", 205);
        gotoxy(c, 4);
        printf("%c", 205);
    }
    gotoxy(2,1);
    printf("%c" ,201);
    gotoxy(79,1);
    printf("%c", 187);
    gotoxy(79,4);
    printf("%c", 188);
    gotoxy(2,4);
    printf("%c", 200);

    for(l = 2; l <= 3; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 29);
        printf("%c", 205);
    }
    gotoxy(2,5);
    printf("%c", 201);
    gotoxy(79,5);
    printf("%c", 187);
    gotoxy(2,8);
    printf("%c", 204);
    gotoxy(79,8);
    printf("%c", 185);
     for(l = 9; l <= 28; l++)
    {
        gotoxy(2, l);
        printf("%c", 186);
        gotoxy(79, l);
        printf("%c", 186);
    }
        for(l = 6; l <= 7; l++)
    {
        gotoxy(2,l);
        printf("%c", 186);
        gotoxy(79,l);
        printf("%c", 186);
    }
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 5);
        printf("%c", 205);
        gotoxy(c, 8);
        printf("%c", 205);

    }
    for (c = 29; c <= 52; c++)
    {
        gotoxy(c + 2, 11);
        printf("%c", 205);
        gotoxy(c + 2, 25);
        printf("%c", 205);
    }
    for(l = 12; l <= 25; l++)
    {
        gotoxy(30, l);
        printf("%c", 186);
        gotoxy(55, l);
        printf("%c", 186);
    }
    gotoxy(30,11);
    printf("%c", 201);
    gotoxy(55,11);
    printf("%c", 187);
    gotoxy(55,25);
    printf("%c", 188);
    gotoxy(30,25);
    printf("%c", 200);
     // USUARIO
    for (c = 34; c <= 47; c++)
    {
        gotoxy(c + 2, 14);
        printf("%c", 205);
        gotoxy(c + 2, 17);
        printf("%c", 205);
    }
    for(l = 15; l <= 16; l++)
    {
        gotoxy(35, l);
        printf("%c", 186);
        gotoxy(50, l);
        printf("%c", 186);
    }
    gotoxy(35,14);
    printf("%c", 201);
    gotoxy(50,14);
    printf("%c", 187);
    gotoxy(50,17);
    printf("%c", 188);
    gotoxy(35,17);
    printf("%c", 200);
    // SENHA
    for (c = 34; c <= 47; c++)
    {
        gotoxy(c + 2, 20);
        printf("%c", 205);
        gotoxy(c + 2, 23);
        printf("%c", 205);
    }
    for(l = 21; l <= 23; l++)
    {
        gotoxy(35, l);
        printf("%c", 186);
        gotoxy(50, l);
        printf("%c", 186);
    }
    gotoxy(35,20);
    printf("%c", 201);
    gotoxy(50,20);
    printf("%c", 187);
    gotoxy(50,23);
    printf("%c", 188);
    gotoxy(35,23);
    printf("%c", 200);


    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 30);
        printf("%c", 205);
        gotoxy(c, 33);
        printf("%c", 205);
    }
    for(l = 31; l <= 32; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }
    gotoxy(79,29);
    printf("%c", 188);
    gotoxy(2,29);
    printf("%c", 200);

    gotoxy(2,30);
    printf("%c" ,201);
    gotoxy(79,30);
    printf("%c", 187);
    gotoxy(79,33);
    printf("%c", 188);
    gotoxy(2,33);
    printf("%c", 200);
}
void janela_alterar()
{
    system("color 3F");
    int c, l;

    textcolor(11);
    textbackground(3);
    gotoxy(26,3);
    printf ("PROGRAMA DE CADASTRO DE CLIENTES");

    textcolor(15);
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 1);
        printf("%c", 205);
        gotoxy(c, 4);
        printf("%c", 205);
    }
    gotoxy(2,1);
    printf("%c" ,201);
    gotoxy(79,1);
    printf("%c", 187);
    gotoxy(79,4);
    printf("%c", 188);
    gotoxy(2,4);
    printf("%c", 200);

    for(l = 2; l <= 3; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }

    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 29);
        printf("%c", 205);
    }
    gotoxy(2,5);
    printf("%c", 201);
    gotoxy(79,5);
    printf("%c", 187);
    gotoxy(2,8);
    printf("%c", 204);
    gotoxy(79,8);
    printf("%c", 185);

     for(l = 9; l <= 28; l++)
    {
        gotoxy(2, l);
        printf("%c", 186);
        gotoxy(79, l);
        printf("%c", 186);
    }

    for(l = 6; l <= 7; l++)
    {
        gotoxy(2,l);
        printf("%c", 186);
        gotoxy(79,l);
        printf("%c", 186);
    }
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 5);
        printf("%c", 205);
        gotoxy(c, 8);
        printf("%c", 205);

    }

    for(l = 9; l <= 28; l++)
    {
        gotoxy(40, l);
        printf("%c", 186);
    }
    gotoxy(40,8);
    printf ("%c",203);
    gotoxy(40,29);
    printf ("%c",202);

    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 30);
        printf("%c", 205);
        gotoxy(c, 33);
        printf("%c", 205);
    }
    for(l = 31; l <= 32; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }
    gotoxy(79,29);
    printf("%c", 188);
    gotoxy(2,29);
    printf("%c", 200);

    gotoxy(2,30);
    printf("%c" ,201);
    gotoxy(79,30);
    printf("%c", 187);
    gotoxy(79,33);
    printf("%c", 188);
    gotoxy(2,33);
    printf("%c", 200);
}
janela_menuprinc()
{
    int c, l;
    textcolor(11);
    textbackground(3);
    gotoxy(26,3);
    printf ("PROGRAMA DE CADASTRO DE CLIENTES");
    textbackground(3);
    textcolor(15);
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 1);
        printf("%c", 205);
        gotoxy(c, 4);
        printf("%c", 205);
    }
    gotoxy(2,1);
    printf("%c" ,201);
    gotoxy(79,1);
    printf("%c", 187);
    gotoxy(79,4);
    printf("%c", 188);
    gotoxy(2,4);
    printf("%c", 200);

    for(l = 2; l <= 3; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }

    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 29);
        printf("%c", 205);
    }
    gotoxy(2,5);
    printf("%c", 201);
    gotoxy(79,5);
    printf("%c", 187);
    gotoxy(2,8);
    printf("%c", 204);
    gotoxy(79,8);
    printf("%c", 185);

    for(l = 9; l <= 28; l++)
    {
        gotoxy(2, l);
        printf("%c", 186);
        gotoxy(79, l);
        printf("%c", 186);
    }

    for(l = 6; l <= 7; l++)
    {
        gotoxy(2,l);
        printf("%c", 186);
        gotoxy(79,l);
        printf("%c", 186);
    }
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 5);
        printf("%c", 205);
        gotoxy(c, 8);
        printf("%c", 205);

    }
        for (c = 29; c <= 52; c++)
    {
        gotoxy(c + 2, 11);
        printf("%c", 205);
        gotoxy(c + 2, 26);
        printf("%c", 205);
    }
    for(l = 12; l <= 26; l++)
    {
        gotoxy(30, l);
        printf("%c", 186);
        gotoxy(55, l);
        printf("%c", 186);
    }
    gotoxy(30,11);
    printf("%c", 201);
    gotoxy(55,11);
    printf("%c", 187);
    gotoxy(55,26);
    printf("%c", 188);
    gotoxy(30,26);
    printf("%c", 200);

   for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 30);
        printf("%c", 205);
        gotoxy(c, 33);
        printf("%c", 205);
    }
    for(l = 31; l <= 32; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }
    gotoxy(79,29);
    printf("%c", 188);
    gotoxy(2,29);
    printf("%c", 200);

    gotoxy(2,30);
    printf("%c" ,201);
    gotoxy(79,30);
    printf("%c", 187);
    gotoxy(79,33);
    printf("%c", 188);
    gotoxy(2,33);
    printf("%c", 200);
}
void janela()
{

    int c, l;

    textcolor(11);
    textbackground(3);
    gotoxy(26,3);
    printf ("PROGRAMA DE CADASTRO DE CLIENTES");

    textcolor(15);
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 1);
        printf("%c", 205);
        gotoxy(c, 4);
        printf("%c", 205);
    }
    gotoxy(2,1);
    printf("%c" ,201);
    gotoxy(79,1);
    printf("%c", 187);
    gotoxy(79,4);
    printf("%c", 188);
    gotoxy(2,4);
    printf("%c", 200);

    for(l = 2; l <= 3; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 29);
        printf("%c", 205);
    }
    gotoxy(2,5);
    printf("%c", 201);
    gotoxy(79,5);
    printf("%c", 187);
    gotoxy(2,8);
    printf("%c", 204);
    gotoxy(79,8);
    printf("%c", 185);

      for(l = 9; l <= 28; l++)
    {
        gotoxy(2, l);
        printf("%c", 186);
        gotoxy(79, l);
        printf("%c", 186);
    }

    for(l = 6; l <= 7; l++)
    {
        gotoxy(2,l);
        printf("%c", 186);
        gotoxy(79,l);
        printf("%c", 186);
    }
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 5);
        printf("%c", 205);
        gotoxy(c, 8);
        printf("%c", 205);

    }
       for (c = 2; c <= 74; c++)
    {
        gotoxy(c + 2, 9);
        printf("%c", 205);
        gotoxy(c + 2, 28);
        printf("%c", 205);
    }
    for(l = 10; l <= 27; l++)
    {
        gotoxy(4, l);
        printf("%c", 186);
        gotoxy(77, l);
        printf("%c", 186);
    }
    gotoxy(4,9);
    printf("%c", 201);
    gotoxy(77,9);
    printf("%c", 187);
    gotoxy(77,28);
    printf("%c", 188);
    gotoxy(4,28);
    printf("%c", 200);
    for(c = 3; c <= 78; c++)
    {
        gotoxy(c, 30);
        printf("%c", 205);
        gotoxy(c, 33);
        printf("%c", 205);
    }
    for(l = 31; l <= 32; l++)
    {
        gotoxy(79, l);
        printf("%c", 186);
        gotoxy(2, l);
        printf("%c", 186);
    }
    gotoxy(79,29);
    printf("%c", 188);
    gotoxy(2,29);
    printf("%c", 200);

    gotoxy(2,30);
    printf("%c" ,201);
    gotoxy(79,30);
    printf("%c", 187);
    gotoxy(79,33);
    printf("%c", 188);
    gotoxy(2,33);
    printf("%c", 200);
}
janela_opcao()
{
    int c,l;

    textcolor(15);
    for(l = 30; l <= 33; l++)
    {
        gotoxy(13, l);
        printf("%c", 186);
        gotoxy(27, l);
        printf("%c", 186);
        gotoxy(39, l);
        printf("%c", 186);
        gotoxy(51, l);
        printf("%c", 186);
        gotoxy(65, l);
        printf("%c", 186);
        gotoxy(75, l);
        printf("%c", 186);

        gotoxy(13,30);
        printf("%c", 203);
        gotoxy(27,30);
        printf("%c", 203);
        gotoxy(39, 30);
        printf("%c", 203);
        gotoxy(51, 30);
        printf("%c", 203);
        gotoxy(65, 30);
        printf("%c", 203);
        gotoxy(75, 30);
        printf("%c", 203);

        gotoxy(13,33);
        printf("%c", 202);
        gotoxy(27,33);
        printf("%c", 202);
        gotoxy(39, 33);
        printf("%c", 202);
        gotoxy(51, 33);
        printf("%c", 202);
        gotoxy(65, 33);
        printf("%c", 202);
        gotoxy(75, 33);
        printf("%c", 202);
    }
}
void login()
{
    char senha[10];
    char usuario[10];
    int i,a=1,b=1;

    janela_login();

    for(i=0; i<3; i++)
    {
        textcolor(15);
        gotoxy(23,7);
        printf ("BEM VINDO AO NOSSO SISTEMA DE CADASTROS");
        textcolor(14);
        gotoxy(19,32);
        printf ("DIGITE USUARIO E SENHA PARA ACESSAR O SISTEMA");

        textcolor(14);
        gotoxy (41,16);
        gets(usuario);

        textcolor(14);
        gotoxy (42,22);
        gets(senha);

        a=strcmp(usuario,"admin");
        b=strcmp(senha,"123");
        fflush(stdin);
        if (a==0 && b==0)
        {

            system("cls");
            menu_principal();
            break;
        }
        else
            system("cls");
        janela_login();
        textcolor(14);
        gotoxy(20,32);
        printf ("SENHA OU USUARIO INCORRETO,TENTE NOVAMENTE !!!");
        login();
    }
    getche();
}

void cadastrar()
{
    int opcao;
    float total;
    cliente[prim].cod = prim+1;
    system("cls");
    janela_alterar();
    gotoxy(22,7);
    printf ("VOCE ESTA CADASTRANDO CLIENTE NUMERO: %d",cliente[prim].cod);
    fflush(stdin);

    if(prim < MAX)
    {
        textcolor(15);
    gotoxy (13,9);
    printf ("DADOS DO CLIENTE");

    textcolor(15);
    gotoxy (52,9);
    printf ("DADOS DA COMPRA");
        textcolor(14);
        gotoxy (5,11);
        printf("NOME: ");
        textcolor(15);
        gets(cliente[prim].nome);
        fflush(stdin);
        gotoxy (5,12);
        textcolor(14);
        printf("CPF: ");
        textcolor(15);
        gets(cliente[prim].cpf);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,13);
        printf("IDADE: ");
        textcolor(15);
        scanf("%d", &cliente[prim].idade);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,14);
        printf ("SEXO(F/M): ");
        textcolor(15);
        gets(cliente[prim].sexo);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,15);
        printf("TELEFONE: ");
        textcolor(15);
        gets(cliente[prim].tel);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,16);
        printf("EMAIL: ");
        textcolor(15);
        gets(cliente[prim].email);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,17);
        printf("RUA: ");
        textcolor(15);
        gets(cliente[prim].end.rua);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,18);
        printf("NUMERO: ");
        textcolor(15);
        scanf("%d",&cliente[prim].end.num);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,19);
        printf("CEP: ");
        textcolor(15);
        scanf("%d",&cliente[prim].end.cep);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,20);
        printf("BAIRRO: ");
        textcolor(15);
        scanf("%s",&cliente[prim].end.bairro);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,21);
        printf("CIDADE: ");
        textcolor(15);
        gets(cliente[prim].end.cidade);
        fflush(stdin);
        textcolor(14);
        gotoxy (5,22);
        printf("ESTADO: ");
        textcolor(15);
        gets(cliente[prim].end.estado);
        fflush(stdin);
        textcolor(14);
        gotoxy (42,11);
        printf ("PRODUTO: ");
        textcolor(15);
        gets(cliente[prim].prod.merc);
        fflush(stdin);
        textcolor(14);
        gotoxy (42,12);
        printf ("COD.PRODUTO: ");
        textcolor(15);
        scanf("%d",&cliente[prim].prod.codigo);
        fflush(stdin);
        textcolor(14);
        gotoxy (42,13);
        printf ("QUANTIDADE: ");
        textcolor(15);
        scanf("%f",&cliente[prim].prod.quant);
        fflush(stdin);
        textcolor(14);
        gotoxy (42,14);
        printf ("VALOR UNITARIO:R$ ");
        textcolor(15);
        scanf("%f",&cliente[prim].prod.valor);
        fflush(stdin);
         textcolor(14);
        gotoxy (42,15);
        printf ("DATA:");
        textcolor(15);
        gets(cliente[prim].prod.data);

       total = cliente[prim].prod.valor*cliente[prim].prod.quant;

        textcolor(14);
        gotoxy (42,17);
        printf("TOTAL DA COMPRA: R$%.2f",total);


        prim = prim + 1;
        fflush(stdin);

        textcolor(11);
        gotoxy(26,27);
        printf ("CADASTRO REALIZADO COM SUCESSO");
    }
    else
    {
        system("cls");
        gotoxy(28,25);
        printf(" NAO HA ESPACO NO SISTEMA!");
    }
}
void excluir()
{
    int opcao;
    janela();
    gotoxy(27,7);
    printf("EXCLUIR REGISTRO DO SISTEMA");

    if(prim == 0)
    {
        gotoxy(28,18);
        printf("NAO HA DADOS PARA EXCLUIR!");
    }
    else
    {    system("cls");
        pesquisar();
        textcolor(14);
        gotoxy(24,32);
        printf ("DESEJA EXCLUIR CADASTRO ? 1-SIM / 2-NAO: ");
        textcolor(15);
        scanf ("%d",&opcao);
        do {
           switch (opcao){
       case 1:
           system("cls");
           janela();
           gotoxy(27,7);
           printf("EXCLUIR REGISTRO DO SISTEMA");
           gotoxy(28,18);
           printf(" DADOS EXCLUIDO COM SUCESSO!");
           prim  = prim - 1;
           menu_opcao();
       case 2:
           system("cls");
           menu_principal();
        break;
       default:
        printf ("OPCAO INVALIDA !");
        break;
           }

        } while (opcao!=2);

    }
}

void relatorio()
{
    int i;
    float total;
    float quant;
    float valor;
    gotoxy(25,7);
    printf("RELATORIO DE CLIENTES CADSTRADOS");
    janela_alterar();
    gotoxy (13,9);
    printf ("DADOS DO CLIENTE");

    textcolor(15);
    gotoxy (52,9);
    printf ("DADOS DA COMPRA");
    for(i = 0; i < prim; i++)
    {

        textcolor(15);
        fflush(stdin);
        gotoxy (6,10);
        printf("ARQUIVO %d\n",(i+1));
        fflush(stdin);
        gotoxy (6,11);
        printf("CODIGO: %d\n",cliente[i].cod);
        fflush(stdin);
        gotoxy (6,12);
        printf("NOME: %s\n",cliente[i].nome);

        textcolor(14);
        gotoxy (42,10);
        printf ("PRODUTO %s",cliente[i].prod.merc);
        quant=cliente[i].prod.quant;
        textcolor(14);
        gotoxy (42,11);
        printf ("QUANTIDADE: %.2f",quant);
        valor = cliente[i].prod.valor;
        textcolor(14);
        gotoxy (42,12);
        printf ("VALOR PRODUTO: R$%.2f",valor);
        total = cliente[i].prod.valor*cliente[i].prod.quant;
        textcolor(14);
        gotoxy (42,13);
        printf("TOTAL DA COMPRA: R$%.2f",total);

         textcolor(10);
        gotoxy(26,28);
        printf(" LISTANDO CLIENTES CADASTRADOS");

    }
    if(prim == 0){
    gotoxy(28,18);
    printf("DADOS NAO ENCONTRADO NO SISTEMA");
    }
}

void alterar()
{
    int i,dado,cont=0;

    janela_alterar();
    gotoxy(25,7);
    printf(" ALTERACAO DE DADOS CADASTRADOS");

    for(i=0; i<prim; i++)
    {
        textcolor(15);
        gotoxy(19,32);
        printf("PARA ALTERAR CADASTRO DIGITE CODIGO DO CLIENTE: ");
        textcolor(14);
        scanf("%d",&dado);
        if(dado == cliente[i].cod)
        {
            janela_alterar();
            fflush(stdin);
            textcolor(15);
            gotoxy(15,9);
            printf("DADOS ATUAIS");
            textcolor(14);
            gotoxy(6,11);
            printf("ARQUIVO %d",(i+1));
            fflush(stdin);
            gotoxy(6,12);
            printf("CODIGO: %d",cliente[i].cod);
            fflush(stdin);
            gotoxy(6,13);
            printf("NOME: %s",cliente[i].nome);
            fflush(stdin);
            gotoxy(6,14);
            printf("CPF: %s",cliente[i].cpf);
            fflush(stdin);
            gotoxy(6,15);
            printf("IDADE: %d",cliente[i].idade);
            fflush(stdin);
            gotoxy(6,16);
            printf("SEXO: %s",cliente[i].sexo);
            fflush(stdin);
            gotoxy(6,17);
            printf("TELEFONE: %s\n",cliente[i].tel);
            fflush(stdin);
            gotoxy(6,18);
            printf("EMAIL: %s",cliente[i].email);
            fflush(stdin);
            gotoxy(6,19);
            printf("RUA:%s",cliente[i].end.rua);
            gotoxy(6,20);
            printf("NUMERO: %d",cliente[i].end.num);
            gotoxy(6,21);
            printf("CEP: %d",cliente[i].end.cep);
            gotoxy(6,22);
            printf("BAIRRO: %s",cliente[i].end.bairro);
            gotoxy(6,23);
            printf("CIDADE: %s",cliente[i].end.cidade);
            gotoxy(6,24);
            printf("ESTADO: %s",cliente[i].end.estado);

            fflush(stdin);
            textcolor(15);
            gotoxy(49,9);
            printf("ATUALIZACAO DE DADOS");
            gotoxy(42,11);
            printf("ARQUIVO %d",(i+1));
            fflush(stdin);
            textcolor(15);
            gotoxy(42,12);
            printf("CLIENTE: %d",cliente[i].cod);
            textcolor(14);
            gotoxy (42,13);
            printf("NOME: ");
            textcolor(15);
            gets(cliente[i].nome);
            fflush(stdin);
            gotoxy (42,14);
            textcolor(14);
            printf("CPF: ");
            textcolor(15);
            gets(cliente[i].cpf);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,15);
            printf("IDADE: ");
            textcolor(15);
            scanf("%d", &cliente[i].idade);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,16);
            printf ("SEXO (F/M):");
            textcolor(15);
            gets(cliente[i].sexo);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,17);
            printf("TELEFONE: ");
            textcolor(15);
            gets(cliente[i].tel);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,18);
            printf("EMAIL: ");
            textcolor(15);
            gets(cliente[i].email);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,19);
            printf("RUA: ");
            textcolor(15);
            gets(cliente[i].end.rua);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,20);
            printf("NUMERO: ");
            textcolor(15);
            scanf("%d",&cliente[i].end.num);
            textcolor(14);
            gotoxy (42,21);
            printf("CEP: ");
            textcolor(15);
            scanf("%d",&cliente[i].end.cep);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,22);
            printf("BAIRRO: ");
            textcolor(15);
            scanf("%s",&cliente[i].end.bairro);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,23);
            printf("CIDADE: ");
            textcolor(15);
            gets(cliente[i].end.cidade);
            fflush(stdin);
            textcolor(14);
            gotoxy (42,24);
            printf("ESTADO: ");
            textcolor(15);
            gets(cliente[i].end.estado);
            fflush(stdin);
            textcolor(10);
            gotoxy(44,26);
            printf(" DADOS ALTERADOS COM SUCESSO!");
            cont = cont + 1;
        }
    }
    if (cont==0)
    {   system("cls");
        janela_alterar();
        textcolor(15);
        gotoxy(7,18);
        printf("DADOS NAO ENCONTRADO NO SISTEMA");
        textcolor(15);
        gotoxy(50,18);
        printf("ALTERACAO INVALIDA !");
    }
}
void pesquisar()
{
    int i,dado,cont = 0;
    janela();
    gotoxy(29,7);
    printf ("PESQUISAR CLIENTE CADASTRADO");
    textcolor(14);
    gotoxy(30,32);
    printf(" PESQUISA POR CODIGO: ");
    textcolor(15);
    scanf("%d",&dado);
    for(i = 0; i < prim; i++)
    {
        if(dado == cliente[i].cod)
        {   system("cls");
            gotoxy(29,7);
            printf ("PESQUISAR CLIENTE CADASTRADO");
            janela();
            textcolor(14);
            gotoxy(6,10);
            printf("ARQUIVO %d\n",(i+1));
            fflush(stdin);
            textcolor(14);
            gotoxy(6,11);
            printf("CODIGO: %d\n",cliente[i].cod);
            fflush(stdin);
            textcolor(14);
            gotoxy(6,12);
            printf("NOME: %s\n",cliente[i].nome);
            fflush(stdin);
            textcolor(14);
            gotoxy(6,13);
            printf("CPF: %s\n",cliente[i].cpf);
            fflush(stdin);
            textcolor(14);
            gotoxy(6,14);
            printf("IDADE: %d\n",cliente[i].idade);
            fflush(stdin);
            textcolor(14);
            gotoxy(6,15);
            printf("SEXO: %s\n",cliente[i].sexo);
            fflush(stdin);
            textcolor(14);
            gotoxy(6,16);
            printf("TELEFONE: %s\n",cliente[i].tel);
            fflush(stdin);
            textcolor(14);
            gotoxy(6,17);
            printf("EMAIL: %s\n",cliente[i].email);
            fflush(stdin);
            textcolor(14);
            gotoxy(6,18);
            printf("RUA:%s\n",cliente[i].end.rua);
            textcolor(14);
            gotoxy(6,19);
            printf("NUMERO: %d\n",cliente[i].end.num);
            textcolor(14);
            gotoxy(6,20);
            printf("CEP: %d\n",cliente[i].end.cep);
            textcolor(14);
            gotoxy(6,21);
            printf("BAIRRO: %s\n",cliente[i].end.bairro);
            textcolor(14);
            gotoxy(6,22);
            printf("CIDADE: %s\n",cliente[i].end.cidade);
            textcolor(14);
            gotoxy(6,23);
            printf("ESTADO: %s\n",cliente[i].end.estado);
            cont = cont + 1;
           textcolor(10);
           gotoxy(29,27);
           printf("CLIENTE ENCONTRADO NO SISTEMA");
        }
    }
    if(cont == 0)
    {   system("cls");
        janela();
        gotoxy(29,7);
        printf ("PESQUISAR CLIENTE CADASTRADO");
        textcolor(15);
        gotoxy(28,18);
        printf("DADOS NAO ENCONTRADO NO SISTEMA");
    }
}
void sobre()
{
    janela();
    gotoxy(29,7);
    printf ("SOBRE O PROGRAMA (TRABALHO)");
    textcolor(11);
    gotoxy(26,10);
    printf ("SISTEMA DE CADASTROS DE CLIENTES");
    textcolor(14);
    gotoxy(15,12);
    printf ("Criado pelos alunos Jose Orlando (Diouzeh) e Geovana");
    textcolor(15);
    gotoxy(16,14);
    printf ("Trabalho de Programacao I - Prof. Aristoteles Macal");
    gotoxy(25,18);
    printf ("CURSO : SISTEMAS DE INFORMACAO");
    gotoxy(25,20);
    printf ("FACULDADE DOM PEDRO II");
    gotoxy(25,22);
    printf ("SEMESTRE - 2015.1");
    textcolor(14);
    gotoxy(10,25);
    printf ("Este programa trata-se de uma versao BETA que se destina apenas");
    gotoxy(13,26);
    printf ("ao uso em processo avaliativo da materia de Programacao I");
    menu_opcao();
}

void menu_principal()
{
    int opcao;
    janela();
    janela_menuprinc();

    do
    {
        janela();
        textcolor(14);
        gotoxy(26,7);
        printf ("ESCOLHA UMA OPCAO PARA CONTINUAR");
        textcolor(15);
        gotoxy(34,13);
        printf("1) CADASTRAR");
        gotoxy(34,15);
        printf("2) REMOVER");
        gotoxy(34,17);
        printf("3) RELATORIO");
        gotoxy(34,19);
        printf("4) PESQUISAR");
        gotoxy(34,21);
        printf("5) ALTERAR");
        gotoxy(34,23);
        printf("6) SOBRE O PROGRAMA");
        gotoxy(34,25);
        printf("7) SAIR");
        textcolor(14);
        gotoxy(33,32);
        printf("DIGITE OPCAO: ");
        textcolor(15);
        scanf("%d%*c",&opcao);
        printf("\n");

        switch(opcao)
        {
        case 1:
            system("cls");
            cadastrar();
            menu_opcao();
            break;
        case 2:
            system("cls");
            excluir();
            menu_opcao();
            break;
        case 3:
            system("cls");
            relatorio();
            menu_opcao();
            break;
        case 4:
            system("cls");
            pesquisar();
            menu_opcao();
            break;
        case 5:
            system("cls");
            alterar();
            menu_opcao();
            break;
        case 6:
            system("cls");
            sobre();
            menu_opcao();
            break;
        case 7:
            system("cls");
            janela();
            textcolor(14);
             gotoxy (34,15);
            printf ("SAINDO DO SISTEMA ...");
            textcolor(15);
            gotoxy(30,18);
            printf ("PRESSIONE ENTER PARA SAIR");
            exit(0);
            break;
        default:
            textcolor(14);
            gotoxy(7,18);
            printf(" ( OPCAO INVALIDA! )");
            gotoxy(60,17);
            printf("PARA INICIAR");
            gotoxy(62,18);
            printf("O SISTEMA");
            gotoxy(60,19);
            printf("ESCOLHA OPCAO");
            gotoxy(63,20);
            printf("VALIDA");
            break;
        }
    }while (opcao!= '7');
}


void menu_opcao()
{
    int opcao;
    janela_opcao();

    textcolor(14);
    gotoxy(4,32);
    printf("1-INICIO");
    gotoxy(15,32);
    printf("2-CADASTRAR");
    gotoxy(29,32);
    printf("3-EXCLUIR");
    gotoxy(41,32);
    printf("4-ALTERAR");
    gotoxy(53,32);
    printf("5-PESQUISAR");
    gotoxy(67,32);
    printf("6-SAIR: ");
    textcolor(15);
    gotoxy(77,32);
    scanf ("%d",&opcao);
    do
    {

        switch(opcao)
        {
        case 1:
            system("cls");
            menu_principal();

            break;
        case 2:
            system("cls");
            cadastrar();
            menu_opcao();
            break;
        case 3:
            system("cls");
            excluir();
            menu_opcao();
            break;
        case 4:
            system("cls");
             alterar();
            menu_opcao();

            break;
        case 5:
            system("cls");
            pesquisar();
            menu_opcao();

            break;
        case 6:
             system("cls");
            gotoxy (34,15);
            textcolor(14);
            printf ("SAINDO DO SISTEMA ...");
            textcolor(15);
            printf ("\t\t\t\t\t\t\t\PRESSIONE ENTER PARA SAIR");
            gotoxy(32,32);
            exit(0);
            break;
        }
    }
    while (opcao!='7');
}
int main()
{
    fflush(stdin);
    system("color 3F");
    login();
    menu_principal();
    system("pause");
    return 0;
}
