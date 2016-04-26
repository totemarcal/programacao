#include <stdio.h>
#include <stdlib.h>
void mm(int v[10], int *max, int *min);

int main(int argc, char *argv[])
{
    int vet[10];
    int i, maximo, minimo;
    
    for(i=0; i<10; i++){
        printf("\nDigite o elemento %d: ", i);
        scanf("%d", &vet[i]);
    }
    
    mm(vet, &maximo, &minimo);
    
    printf("\nMaximo: %d", maximo);
    printf("\nMinimo: %d\n", minimo);
    
  system("PAUSE");	
  return 0;
}

void mm(int v[10], int *max, int *min)
{
     int i;
     *min = v[0];
     *max = v[0];
     
     for(i=0; i<10; i++)
     {
         if(v[i] < *min)   
            *min = v[i];
         if(v[i] > *max)
            *max = v[i];
     }
     
}
