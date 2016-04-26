#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int calcular_media();
void verificar_media(int media_global);

int main(int argc, char** argv) {
	int media_turma1, media_turma2, media_turma3;
	media_turma1 = calcular_media();
	verificar_media(media_turma1);
	media_turma2 = calcular_media();
	verificar_media(media_turma2);
	media_turma3 = calcular_media();
	verificar_media(media_turma3);
	return 0;
}

int calcular_media()
{
	int i, num, total=0, media;
	for(i=0;i<10;i++){
		printf("Digite um numero");
		scanf("%i", &num);
		total = total + num;
	}
	media = total / 10;
	return media;	
}

void verificar_media(int media_global){
	printf("Media Final: %i", media_global);
	if(media_global >= 7){
		printf("\nBOM!");
	}else if(media_global < 7 && media_global >= 5 ){
		printf("\nREGULAR!");
	}else{
		printf("\nRUIM!");
	}	
}
