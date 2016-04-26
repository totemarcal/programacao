#include <stdio.h>
#include <stdlib.h>


struct aluno{
       int id;
       char nome[10];
       };
       
struct aluno aluno_dpii[2];

int main(int argc, char *argv[])
{
  int i;
  for(i=0;i<3;i++){
    printf("Digite id e nome \n");	

    scanf("%[^\n]s", aluno_dpii[i].nome);
    setbuf(stdin, NULL);
  }
    for(i=0;i<3;i++){
              printf("nome: %s \n", aluno_dpii[i].nome);	
    }
  system("PAUSE");
  return 0;
}
