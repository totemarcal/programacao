#include <stdio.h>
#include <stdlib.h>



struct Funcionario
{
       int matricula;
       char nome[100];
       char cpf[11];
};

void inseri_func(struct Funcionario f[10]);

typedef struct Funcionario Func;

int main(int argc, char *argv[])
{
    Func f1[10];   
    int i;
    inseri_func(f1);
    
     
  system("PAUSE");	
  return 0;
}

void inseri_func(Func f[10])
{
     int i;
     
    for(i=0;i<10;i++)
    {
       printf("Digite os dados do funcionario");
       scanf("%d", &f[i].matricula);
    }
  
    for(i=0;i<10;i++)
    {
       printf("Funcionario %d eh: %d \n", i, f[i].matricula);
    } 
}

