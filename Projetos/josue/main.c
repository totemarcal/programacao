#include <stdio.h>
#include <stdlib.h>
/* 
1- Defnir estrutura(Struct)
2- Criar a função de inserir
3- Criar o Menu
4- Criar a funcção de imprimir os elemento
5- Criar função de excluir */


struct lista {
       int info;
       struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa (void)
{
       return NULL;
}

Lista* insere (Lista* l, int i)
{
       Lista* novo = (Lista*) malloc(sizeof(Lista));
       novo->info = i;
       novo->prox = l;
       return novo;
}

void imprime (Lista* l)
{
       Lista* p; /* variável auxiliar para percorrer a lista */
       for (p = l; p != NULL; p = p->prox)
           printf("info = %d \n", p->info);
}

int main (void)
{
       Lista* l; /* declara uma lista não inicializada */
       l = inicializa(); /* inicializa lista como vazia */
       l = insere(l, 23); /* insere na lista o elemento 23 */
       l = insere(l, 45); /* insere na lista o elemento 45 */
       imprime (l);
       system("Pause");
       return 0;
}



     
     
