#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int vet[5], i, j,aux;
	for(i=0; i<5; i++){
		printf("Digite Numero: ");
		scanf("%i", &vet[i]);
	}
	for(i=0; i<5; i++){
		printf("%i \t ", vet[i]);
	}
	printf("\n\n");
	for(i=0; i<4; i++){
		for(j=i+1; j<5; j++){
			if(vet[i] > vet[j]){
				aux= vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
	for(i=0; i<5; i++){
		printf("%i \t ", vet[i]);
	}	
	return 0;
}
