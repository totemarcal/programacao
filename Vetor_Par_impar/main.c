#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, num, vet_impar[5], vet_par[5], i_par=0, i_impar=0;
	
	for(i=0;i<10;i++)
	{
		printf("Informe numero %i:", i+1);
		scanf("%i", &num);
		if(num % 2 == 0){
			if(i_par < 5){
				vet_par[i_par] = num;
				i_par++;
			}else
			{
				printf("Vetor PAR cheio!");
			}
		}else
		{	
			if(i_impar < 5){
				vet_impar[i_impar] = num;
				i_impar++;
			}else
			{
				printf("Vetor IMPAR cheio!");
			}
		}
	}
	
	for(i=0;i<i_par;i++)
	{
		printf("\nVetor Par %i:", vet_par[i]);
	}
	for(i=0;i<i_impar;i++)
	{
		printf("\nVetor Impar %i:", vet_impar[i]);
	}
	
	return 0;
}
