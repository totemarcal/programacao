#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int vet[15];
  float vet_result[15];
  int i, maior_elemento;
  maior_elemento=0;
  for(i=0;i<15;i++)
  {
     printf("\n Informe o valor do elemento %d ", i+1);
     scanf("%d", &vet[i]);
  }
  for(i=0;i<15;i++)
  {
     printf("\n Elemento %d he %d", i+1, vet[i]);
  }
  for(i=0;i<15;i++)
  {
     if(vet[i]>maior_elemento)
        maior_elemento = vet[i];
  }
  printf("\n Maior elemento he %d \n", maior_elemento);  
  for(i=0;i<15;i++)
  {
     vet_result[i] = (float)vet[i]/maior_elemento;
  }
  for(i=0;i<15;i++)
  {
     printf("\n Elemento Result %d he %.2f", i+1, vet_result[i]);
  }  
  
  
    
  system("PAUSE");	
  return 0;
}
