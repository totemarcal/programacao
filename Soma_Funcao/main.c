#include <stdio.h>
#include <stdlib.h>
int SOMA(float a, int b);  // Prot�tipo da fun��o SOMA
main()
{
    int s,b;
    float a;
    a=15.2;
    b=16; 
    s=SOMA(a,b); // fun��o retorna valor ao final da execu��o 
    printf("A soma de %f com %i eh %i \n", a,b,s);
    system("pause");
}
int SOMA(float a, int b)  // Defini��o da fun��o SOMA 
{
   int result;     // a declara��o de vari�veis � igual ao que 
                   // se faz na fun��o main 
   result = a+b;
   return result;
}

