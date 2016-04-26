#include <stdio.h>
#include <stdlib.h>

#define NOME "= Deposito de bebida Maroto =\n\n"


// Estruturas e variaveis Globais...
struct struct_bar{
    char produto[20];
    float preco;
    int q_estoque;
        }typedef bar;

struct venbar{
    int v_quant[10], resul, itens_vend ;
    float resul2;

        }vendar;

    int q_produto;
    char proc_prod[20];

//Funcoes...

void func_consul(bar menu [2]);
void pesquisar_prod (bar menu[2], char produto[20]);
void vender_prod (bar menu[2], char produto[20]);


int main(){
system("color 0c");
//variaveis...
    char usuario[10], seguir, produto2[20],opcao;
    int senha2,opcao1, opcao2, i;
    bar menu [50];

// Atribuicao de valores

    senha2 == 123;
    seguir = 's';

//menu...
    do{
    printf ("%s",NOME);
    printf("Entre com o login e senha");
    printf ("\n[Login]: ");
            gets(usuario);
    printf("\n[Senha]: ");
            scanf("%i", &senha2);
        fflush(stdin);
            system("cls");

   }while (strcmp (usuario,"admin") || senha2 != 123);
    system("cls");

//Menu e funcao dos menus dentro do switch
 do{
    printf ("%s", NOME);

	printf ("\nOpcoes");
	printf ("\n (1)- Cadastrar produtos");
	printf ("\n (2)- Consultar todos produtos");
	printf ("\n (3)- Pesquisar produtos");
	printf ("\n (4)- Alterar produtos");
	printf ("\n (5)- Vender produtos");
	printf ("\n (6)- sair");

	printf ("\n\n Digite um numero para escolher uma opcao");
	printf ("\n Opcao: ");
	scanf ("%i", &opcao1);
	fflush (stdin);
    system("cls");

// switch
	switch (opcao1){

	case 1:
        printf ("%s", NOME);

	    for (i=q_produto;i<100;i++){
        printf("\nNome do Produto: ");
            scanf("%s", &menu[i].produto);
        printf("Valor do produto: ");
            scanf("%f", &menu[i].preco);
        printf("Quantidade em estoque: ");
            scanf("%i",&menu[i].q_estoque);

        printf("Deseja cadastrar mais produtos: ");
            scanf("%s", &seguir);
            if (seguir == 'n'){
                break;
            }
	    }
	    q_produto = i + 1;
        system("cls");
        break;

    case 2:
         func_consul(menu);
        break;
    case 3:
        printf ("%s", NOME);
        printf("\n\nDigite nome do produto para pesquisar: ");
        gets(proc_prod);
        pesquisar_prod (menu, proc_prod);
        fflush(stdin);
        system("cls");
        break;
    case 4:

        printf ("%s", NOME);
        printf("Alterar produto: ");
        gets(produto2);


        for(i=0;i<q_produto; i++){
        if (!strcmp(produto2,menu[i].produto)){

        printf("Digite o novo produto\n\n");
        printf("Nome do Produto: ");
        scanf("%s", &menu[i].produto);
        printf("Valor do produto: ");
        scanf("%f", &menu[i].preco);
        printf("Quantidade em estoque: ");
        scanf("%i",&menu[i].q_estoque);
        break;
        system("cls");
            }
        } system("cls");
        break;

        case 5:
            vender_prod (menu, proc_prod);
        break;

        case 6:
            	printf ("%s", NOME);
            	printf("\nVoce saiu do Programa...\n\n");

           			break;

            break;
	}

 }while (opcao2 != 9);
    return 0;
}
void func_consul(bar menu[2]){
    int i;
    char opcao;
    opcao = 's';

        printf ("%s", NOME);
        for (i=0;i<q_produto;i++){
            printf("\nNome do Produto: %s \n",menu[i].produto);
            printf("Valor do Produto: %.2f \n",menu[i].preco);
            printf("Quantidade em estoque: %i \n",menu[i].q_estoque);
    }
        printf("\n\nDigite 'S' para retornar\na tela do menu: ");
            scanf("%s", &opcao);
        if (opcao = 's'){
            system("cls");
        }
}
void pesquisar_prod (bar menu[2], char produto[20]){
int i;
char opcao;
fflush(stdin);
    for(i=0;i<3;i++){
        if (!strcmp(menu[i].produto, produto)){

            printf("\nNome do Produto: %s \n",menu[i].produto);
            printf("Valor do Produto: %.2f \n",menu[i].preco);
            printf("Quantidade em estoque: %i \n",menu[i].q_estoque);
        }
    }

   printf("\n\nDigite [S] para retornar\na tela do menu: ");
            scanf("%s", &opcao);
        if (opcao = 's'){
            system("cls");
        }
}

void vender_prod(bar menu[2], char produto[20]){
int i,j, quantidade [30], venda_q[20], contador = 0;
float preco [30];
char opcao, opcao2;

opcao = 'n';
opcao2 = 'n';

do{

        fflush(stdin);
        printf ("%s", NOME);
        printf("\n\nDigite nome do produto para pesquisar: ");
        gets(proc_prod);
        vendar.resul = 0;
        fflush(stdin);


for(i=contador;i<30;i++){

    if (!strcmp(menu[i].produto, produto)){
       do{
            printf("\nNome do Produto: %s \n",menu[i].produto);
            printf("Valor do Produto: %.2f \n",menu[i].preco);
            printf("Quantidade em estoque: %i",menu[i].q_estoque);

            printf("\nDigite quantos itens deseja vender: ");
            scanf("%i",&vendar.v_quant[i]);

        venda_q[i] = i + 1;
        contador ==0;
            if (vendar.v_quant[i] <= menu[i].q_estoque){

                vendar.resul2 = vendar.v_quant[i] * menu[i].preco;
                vendar.resul = menu[i].q_estoque - vendar.v_quant[i];
                menu[i].q_estoque = vendar.resul;
                vendar.itens_vend = menu[i].q_estoque;
                quantidade [i] = vendar.v_quant[i];
                preco [i] = vendar.resul2;


     }
            else{
                printf("Estoque Vazio ou Insuficiente");
            }
        }while(vendar.v_quant[i] == 0);

    }

}
    printf("\nAdicionar mais produtos ao carrinho: S ou N? ");
      scanf("%s", &opcao);
      fflush(stdin);
      system("cls");

}while (opcao != 'n');


do{
printf ("%s\n", NOME);

    for(i=0; i<venda_q[i]; i++){

            if(vendar.v_quant[i] != 0 && quantidade[i] >0 && preco[i] > 0){
        printf("voce comprou %i %s Valor unidade %.2f TOTAL: %.2f \n",quantidade[i], menu[i].produto,menu[i].preco, preco [i]);
        fflush(stdin);
    }

}
printf("\n\nDigite [S] para retornar\na tela do menu: ");
            scanf("%s", &opcao2);
            fflush(stdin);
            system("cls");
            break;
   }while (opcao2 == 'n');

}
