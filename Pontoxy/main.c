#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//estrutura que representa um ponto com os valores de x e y
struct ponto2d{
	float x;
	float y;
};
//proptotipo da funcao que eh utilizada para cadastrar pontos
//recebe com parametro a referencia de um ponto
void informa_ponto(struct ponto2d *p);

int main(int argc, char *argv[]) {
	//criação de dois pontos para calcular a distancia entre eles
	//conforme struct ponto2d, cada ponto possui as coordenadas x e y
	struct ponto2d ponto_inicial, ponto_final;
	//armazena a distancia dos pontos
	float distancia;
	//invoca a funcao para cadastrar o ponto inicial
	informa_ponto(&ponto_inicial);
	//invoca a funcao para cadastrar o ponto final
	informa_ponto(&ponto_final);
	//calcula a distancia (x1-x2)²+(y1-y2)²
	distancia = pow(ponto_final.x - ponto_inicial.x,2)+pow(ponto_final.y - ponto_inicial.y,2);
	printf("A distancia eh: %.2f", distancia);
	return 0;
}

void informa_ponto(struct ponto2d *p)
{	
	
	printf("Informe o valor de X");
	//armazeno o valor de x para a referencia passada em *p
	scanf("%f", &p->x);
	//armazeno o valor de y para a referencia passada em *p
	printf("Informe o valor de Y");
	scanf("%f", &p->y);
}










