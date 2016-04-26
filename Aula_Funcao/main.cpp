#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int calcular_media();
void verificar_media(int media_global);

int main(int argc, char** argv) {
	int media;
	media = calcular_media();
	verificar_media(media);
	
	return 0;
}

int calcular_media()
{
	int i, num, total=0, media;
	for(i=0;i<10;i++){
		
		total = total + num;
	}
	media = total / 10;
	return media;	
}

void verificar_media(int media_global){
	if(media_global >= 7){
		printf("BOM!");
	}else if(media_global) < 7 && media_global) >= 5 ){
		printf("REGULAR!");
	}else{
		printf("RUIM!");
	}	
}
