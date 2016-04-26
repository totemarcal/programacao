#include <stdio.h>
#include <stdlib.h>

void mm(int *v, int n, int *min, int *max);

int main(int argc, char *argv[])
{
  int i, n, *vet, minimo, maximo;
  
  printf("Digite o tamanho do veto");
  scanf("%d", &n);
  vet = malloc(n * (sizeof(int)));
  for(i=0; i<n; i++)
  {
      printf("Digite o elemento %d do vetor", i);
      scanf("%d", &vet[i]);           
  }
  
  for(i=0; i<n; i++)
  {
      printf("%d ", vet[i]);
  }
  mm(vet,n,&minimo,&maximo);
  
  printf("Maximo: %d,  Minimo: %d ", maximo, minimo);
  
  system("PAUSE");	
  return 0;
}


void mm(int *v, int n, int *min, int *max)
{
     int i;
     *min = v[0];
     *max = v[0];
     for(i=1; i<n; i++)
     {
         if(v[i]>*max)
            *max=v[i];
         if(v[i]<*min)
            *min=v[i];
     }
     
}
