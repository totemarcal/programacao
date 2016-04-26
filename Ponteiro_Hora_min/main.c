#include <stdio.h>
#include <stdlib.h>

/*
Um ponteiro pode ser usado para dizer a uma função onde ela deve depositar 
o resultado de seus cálculos. Escreva uma função hm que converta minutos 
em horas-e-minutos. A função recebe um inteiro mnts e os endereços de 
duas variáveis inteiras, digamos h e m, e atribui valores a essas 
variáveis de modo que m seja menor que 60 
e que 60*h + m seja igual a mnts.   
Escreva também uma função main que use a função hm.
*/

void hm(int mnts, int * h, int * m);

int main(int argc, char *argv[]) {
	int totalMinutos, minuto, hora;
	printf("Digite o total de minutos");
	scanf("%i", &totalMinutos);
	hm(totalMinutos, &hora, &minuto );
	printf("\nHoras %i \nMinutos %i ", hora, minuto);
	return 0;
}

void hm(int mnts, int * h, int * m)
{
	*h = mnts/60;
	*m = mnts%60;
}
