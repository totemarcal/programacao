#include <stdio.h>
#include <stdlib.h>
// Escreva um programa que calcule a média
// de três numeros

void exibir_medias(float l_media[3]);
void cadastrar_medias(float l_media[3]);

int main(int argc, char *argv[]) 
{
	
	float lista_media[3];
	cadastrar_medias(lista_media);
	exibir_medias(lista_media);	
	return 0;
}

void cadastrar_medias(float l_media[3])
{
	int n1, n2, n3, i;
	float media;
	
	for(i=0;i<3;i++)
	{
		printf("\nDigite 3 numeros \n");
		scanf("%i%i%i", &n1, &n2, &n3);
		media = (float)(n1+n2+n3)/3;
		printf("A media eh: %.2f \n", media);
		if(media >= 7){
			printf("\nAprovado!");
		}else if(media > 3 && media <7){
			printf("\nFinal!");
		}else{
			printf("\nReprovado!");
		}
		l_media[i] = media;
	}
}

void exibir_medias(float l_media[3])
{
	int i;
	float media;
	
	for(i=0;i<3;i++)
	{
		printf("\nMedia %i : %.2f",i,l_media[i]);
	}

}




