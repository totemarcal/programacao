#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int i;
   float total_peso_a=0, total_peso_b=0, total_peso_c=0;
   int qtd_peso_a=0, qtd_peso_b=0, qtd_peso_c=0;
   float peso;
   int idade;
   
   for(i=0;i<6;i++)
   {
      printf("\n Informe o peso e idade da pessoa %d", i+1);
      scanf("%f%d", &peso,&idade);
      if(idade>0 && idade<=10){
         total_peso_a += peso;
         qtd_peso_a++;
      }else if(idade>10 && idade<=40){
         total_peso_b += peso;
         qtd_peso_b++;
      }else if(idade>40 && idade<=100){
         total_peso_c += peso;
         qtd_peso_c++;
      }
   }
   printf("A média da faixa de 0 a 10: %.2f \n", total_peso_a/qtd_peso_a);
   printf("A média da faixa de 10 a 40: %.2f \n", total_peso_b/qtd_peso_b);
   printf("A média da faixa de 40 a 100: %.2f \n", total_peso_c/qtd_peso_c);
  
  system("PAUSE");	
  return 0;
}
