#include <stdio.h>
#include <stdlib.h>

void hm(int t_min, int *h, int *m);

int main(int argc, char *argv[])
{
    int total_minutos, horas, minutos;
    
    printf("Informe o total de minutos: ");
    scanf("%d", &total_minutos);
    
    hm(total_minutos, &horas, &minutos);
    
    printf("\n Horas: %d \n", horas);
    printf("Minutos: %d\n", minutos);
    
  system("PAUSE");	
  return 0;
}

void hm(int t_min, int *h, int *m)
{
     *h = t_min/60;
     *m = t_min%60;
}
