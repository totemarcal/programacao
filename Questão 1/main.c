#include <stdio.h>
#include <stdlib.h>
struct s_conta{
       int n_conta;
       int saldo;
};
typedef struct s_conta conta;

struct s_cliente{
       int cod_cliente;
       conta lista_contas[3];
       char possui_conta;
       char nome_cliente[];
};
typedef struct s_cliente cliente;

int verifica_Codigo(int cod, cliente lista[3], int limite);
int Imprime_Conta(conta lista[3], int cod_cliente);

int main(int argc, char *argv[])
{
    int i, j, pode_cadastrar, cod_cliente;
    char opcao, cont_cliente, cont_conta;
    cliente lista_cliente[3];
    for(i=0;i<3;i++)
    {
        printf("Digite o codigo cliente: ");
        scanf("%d", &cod_cliente);
        fflush(stdin);
        pode_cadastrar = verifica_Codigo(cod_cliente, lista_cliente, i);
        if(pode_cadastrar != -1)
        {
           printf("Codigo existente! \nNome do Cliente: %s", lista_cliente[pode_cadastrar].nome_cliente);
           i--;
        }else
        {
           printf("Digite o nome do cliente: ");
           scanf("%s", &lista_cliente[i].nome_cliente);
           fflush(stdin);
           lista_cliente[i].cod_cliente = cod_cliente;
        }
        printf("\nDeseja cadastrar conta [s]Sim [n]Nao?");
        fflush(stdin);
        scanf("%c", &opcao);
        if(opcao == 's')
        {
           lista_cliente[i].possui_conta = 's';
           for(j=0;j<3;j++){
              printf("Informe o número da conta: ");
              scanf("%d", &lista_cliente[i].lista_contas[j].n_conta);
              printf("Informe o saldo: ");
              scanf("%d", &lista_cliente[i].lista_contas[j].saldo);
           }
        }
    }
    for(i=0;i<3;i++)
    {
       if(lista_cliente[i].possui_conta == 's')
          Imprime_Conta(lista_cliente[i].lista_contas, lista_cliente[i].cod_cliente);
    }
    system("PAUSE");	
    return 0;
}

int verifica_Codigo(int cod, cliente lista[3], int limite)
{
    int i;
    printf("%d", limite);
    for(i=0;i<limite;i++)
    {
        if(lista[i].cod_cliente == cod)
           return i;
    }
    return -1;
}

int Imprime_Conta(conta lista[3], int cod_cliente)
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("Codigo Cliente: %d \n", cod_cliente);
        printf("Conta: %d \n", lista[i].n_conta);
    }
}
