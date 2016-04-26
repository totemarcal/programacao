#include <stdio.h>
#include <stdlib.h>

int * cadastrar_vetor(int *v);
void exibir_vetor(int *v);

int main(int argc, char *argv[])
{
    
    int *v;
    
    v = malloc( 10 * sizeof (int));
            
    exibir_vetor(cadastrar_vetor(v));
    printf("Endereço %u", v);
    
  system("PAUSE");	
  return 0;
}

int * cadastrar_vetor(int *v)
{
    int i;
    for (i = 0; i < 10; ++i)  
        scanf( "%d", &v[i]);
    return v;
  }

void exibir_vetor(int *v)
{
     int i;
     for (i = 0; i < 10; ++i)  
        printf("\n %d", v[i]);             
}
