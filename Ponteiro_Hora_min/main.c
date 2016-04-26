#include <stdio.h>
#include <stdlib.h>

/*
Um ponteiro pode ser usado para dizer a uma fun��o onde ela deve depositar 
o resultado de seus c�lculos. Escreva uma fun��o hm que converta minutos 
em horas-e-minutos. A fun��o recebe um inteiro mnts e os endere�os de 
duas vari�veis inteiras, digamos h e m, e atribui valores a essas 
vari�veis de modo que m seja menor que 60 
e que 60*h + m seja igual a mnts.   
Escreva tamb�m uma fun��o main que use a fun��o hm.
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
