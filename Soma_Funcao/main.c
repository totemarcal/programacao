#include <stdio.h>
#include <stdlib.h>
int SOMA(float a, int b);  // Protótipo da função SOMA
main()
{
    int s,b;
    float a;
    a=15.2;
    b=16; 
    s=SOMA(a,b); // função retorna valor ao final da execução 
    printf("A soma de %f com %i eh %i \n", a,b,s);
    system("pause");
}
int SOMA(float a, int b)  // Definição da função SOMA 
{
   int result;     // a declaração de variáveis é igual ao que 
                   // se faz na função main 
   result = a+b;
   return result;
}

