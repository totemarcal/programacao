#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct struct_casa{
                int num, cod;
                char end[50];
                unsigned int cep;
                char rent;
                char cpf_inq[11];
                float aluguel;
        }typedef casa;
        
struct struct_cliente{               
                char nome[50];
                char cpf[11];
                int cod_casa;
        }typedef cliente;
       
void clientes();
void casas();
char consulta1();
char consulta2();
void menu();
void alt1();
void alt2();
casa tab_casas[50];
cliente tab_cliente[50];
char user[10]="admin";
int pass=123, qtd_cliente=0, qtd_casas=0;

int main(){
	char usuario[10];
	int senha;
		system("color 3F");
		do{
			system("cls");
			fflush(stdin);
   			printf ("                    SLK CORRETORES\n\n");
			printf("               Entre com Login e Senha.\n\n\n\n");
			printf("\t\tLOGIN:");
			gets(usuario);		
			printf("\t\tPASSWORD:");
			scanf("%i", &senha);
		}while(strcmp(usuario, user) || senha!= pass);
		menu();
	
	system("PAUSE");
	return 0;
}

void menu(){
	 int opcao, i;
	 	system("cls");
        printf ("   SLK CORRETORES\n\n");
        printf ("    ***MENU***\n\n");
        printf("1.Cadastro de Cliente\n");
        printf("2.Cadastro de Casas\n");
        printf("3.Consulta de Clientes\n");
        printf("4.Consulta de Casas\n");
        printf("5.Alteracao de Cadastro de Clientes\n");
        printf("6.Alteracao de Cadastro de Casas\n");
        printf("7.Sair\n\n");
        printf("Escolha uma opcao (1,2,3,4,5,6 ou 7):");
        scanf("%i", &opcao);
        switch(opcao){
            case 1: system("cls");
					clientes();
            		break;
            case 2: system("cls");
					casas();
                    break;
            case 3: system("cls");
					consulta1();
                    break;
            case 4: system("cls");
					consulta2();
					break;
            case 5: system("cls");
            		printf("                    LOGOFF EFETUADO.\n\n");
					alt1();
					break;
			case 6: system("cls");
					alt2();
					break;
			case 7: system("cls");
					main();
					break;
    	}
    	if(opcao != 1 || 2 || 3 || 4 ||5|| 6 || 7 ){
    		menu();
    	}
}

void clientes(){
	int i;
	char prox, check; 
        fflush(stdin);				
        system("cls");
        for(i=qtd_cliente;i<50;i++){
            printf("\n--------------------------------------------\n");
            printf("Insira Nome: ");
            gets(tab_cliente[i].nome);
            fflush(stdin);
            printf("Digite o CPF: ");
            gets(tab_cliente[i].cpf);
            printf("Atualmente inquilino de alguma casa ? [s]-SIM e [n]-NAO: ");
            scanf("%s", &check);
            if(check == 's'){
            	printf("Digite o codigo da casa: ");
            	scanf("%i", &tab_cliente[i].cod_casa);
			}
            qtd_cliente++;;
            do{
            	printf("Deseja cadastrar mais clientes ? [s]-SIM e [n]-NAO: ");
            	scanf("%s", &prox);
            	fflush(stdin);
            	system("cls");
                if(prox == 'n'){
                	system("cls");
                	menu();
           		}else if(prox == 's'){          			
           			system("cls");
           			clientes();
           		}else{
           			printf("Digito incorreto.\n");           	
          		}
      		}while(prox != 'n' || 's');
        }
}

void casas(){
        int i;
        char prox, inq;
                system("cls");        
                for(i=qtd_casas;i<50;i++){
                	printf("\n--------------------------------------------\n");      
                    printf("Digite o Endereco: ");
                    fflush(stdin);
                    gets(tab_casas[i].end);
                    printf("Digite o Numero: ");
                    scanf("%i", &tab_casas[i].num);
                    fflush(stdin);
                    printf("Digite o CEP: ");
                    scanf("%i", &tab_casas[i].cep);
                    printf("Valor de Aluguel: ");
                    scanf("%f", &tab_casas[i].aluguel);
                    fflush(stdin);
                	printf("Casa disponivel ? [s]-SIM e [n]-NAO: ");
                    scanf("%s", &tab_casas[i].rent); 
                    fflush(stdin);
 	   				if(tab_casas[i].rent == 'n'){
 	   					fflush(stdin);
						printf("Digite o CPF do atual inquilino: ");
						scanf("%s", &tab_casas[i].cpf_inq);
						fflush(stdin);
					}
					tab_casas[i].cod = i+1;
 	   				qtd_casas++;
 	   				do{
						printf("Deseja cadastrar mais casas ? [s]-SIM e [n]-NAO: ");
        				scanf("%s", &prox);
        				fflush(stdin);
        				system("cls");
        				if(prox == 'n'){
        					system("cls");
            				menu();
            			}else if(prox == 's'){
            				system("cls");
           					casas();
        				}else{
           					printf("Digito incorreto.\n");           	
        				}
    				}while(prox != 'n' || 's');
            	}
}

char consulta1(){
     int i=0, comp;
	 char cpf_busca[20], prox;
     	system("cls");
     	fflush(stdin);
     	printf("    CONSULTA DE CLIENTES\n\n");
     	printf("Digite CPF: ");
     	scanf("%s", &cpf_busca);
	 	for(i=0;i<50;i++){
    		comp = (strcmp(cpf_busca,tab_cliente[i].cpf));
		 	if(comp == 0){
     			fflush(stdin);
    			printf("\n--------------------------------------------\n"); 
    			printf("    Cliente Cadastrado\n");
            	printf("Nome do Cliente: %s\n", tab_cliente[i].nome);
            	printf("Numero do CPF: %s\n", tab_cliente[i].cpf);
         		if(tab_cliente[i].cod_casa > 0){
         			printf("Inquilino da Casa Codigo: %i\n", tab_cliente[i].cod_casa);
        		}
				printf("\n--------------------------------------------\n");
				break;      
			}else if(i==50){
			printf("Cliente nao encontrado.\n");		
			}
     	}
		do{
	 		printf("Deseja realizar mais alguma consulta ? [s]-SIM e [n]-NAO: ");
        	scanf("%s", &prox);
        	fflush(stdin);
        	system("cls");
        	if(prox == 'n'){
        	    menu();
            	system("cls");
    		}else if(prox == 's'){
           		consulta1();
        	}else{
           		printf("Digito incorreto.\n");           	
        	}
    	}while(prox != 'n' || 's');
    return cpf_busca[20];
}

char consulta2(){
	int i, cod;
	char esc1, prox;
		system("cls");
		printf("Deseja realizar busca por todas casas cadastradas,\nsomente as disponiveis, ou por codigo ? \n \n[t]-TODAS , [d]-DISPONIVEIS e [c]-CODIGO :");
		scanf("%s", &esc1);
		fflush(stdin);
		if(esc1 == 't'){
			system("cls");
			for(i=0;i<qtd_casas;i++){
				printf("\n--------------------------------------------\n"); 
    			printf("    CODIGO: %i\n", tab_casas[i].cod);
       			printf("Endereco: %s\n", tab_casas[i].end);
       			printf("Numero: %i\n", tab_casas[i].num);
       			fflush(stdin);
        		printf("CEP: %i\n", tab_casas[i].cep);
				printf("Valor do Aluguel: %.2f reais.\n", tab_casas[i].aluguel); 
        		if(tab_casas[i].rent == 'n'){
        			printf("CPF do atual inquilino: %s\n", tab_casas[i].cpf_inq);
				}else if(tab_casas[i].rent == 's'){
					printf("Atualmente Disponivel.\n"); 
					printf("\n--------------------------------------------\n");
				}
			}
		}else if(esc1 == 'd'){
			for(i=0;i<qtd_casas;i++){
				if(tab_casas[i].rent == 's'){
					printf("\n--------------------------------------------\n"); 
    				printf("    CODIGO: %i\n", tab_casas[i].cod);
       				printf("Endereco: %s\n", tab_casas[i].end);
       				printf("Numero: %i\n", tab_casas[i].num);
       				fflush(stdin);
        			printf("CEP: %s\n", tab_casas[i].cep);
					printf("Atualmente Disponivel.\n");
					printf("Valor do Aluguel: %.2f reais.\n", tab_casas[i].aluguel);
					printf("\n--------------------------------------------\n"); 	
				}else if(i==50){
					printf("Nenhuma casa disponivel no momento.\n");
				}
			}
		}else if(esc1 == 'c'){
			system("cls");
			printf("Digite Codigo da Casa: ");
			scanf("%i", &cod);
			for(i=0;i<qtd_casas;i++){
				if(cod == tab_casas[i].cod){
					printf("\n--------------------------------------------\n"); 
    				printf("    CODIGO: %i\n", tab_casas[i].cod);
       				printf("Endereco: %s\n", tab_casas[i].end);
       				printf("Numero: %i\n", tab_casas[i].num);
       				fflush(stdin);
        			printf("CEP: %s\n", tab_casas[i].cep);
					printf("Valor do Aluguel: %.2f reais.\n", tab_casas[i].aluguel); 
        			if(tab_casas[i].rent == 'n'){
       		 			printf("CPF do atual inquilino: %s\n", tab_casas[i].cpf_inq);
					}else if(tab_casas[i].rent == 's'){
						printf("Atualmente Disponivel.\n"); 
						printf("\n--------------------------------------------\n");
					}
				}
			}
		}	
		do{
	 		printf("Deseja realizar mais alguma consulta ? [s]-SIM e [n]-NAO: ");
        	scanf("%s", &prox);
        	fflush(stdin);
        	system("cls");
        	if(prox == 'n'){
        	    menu();
        	    system("cls");
    		}else if(prox == 's'){
        	   	consulta2();
        	}else{
        	   	printf("Digito incorreto.\n");           	
        	}
    	}while(prox != 'n' || 's');
}

void alt1(){
	char cpf[11], prox, check;
	int i;
		printf("    ALTERACAO DE CLIENTES\n\n");
		printf("Digite CPF do cliente desejado:");
		scanf("%s", &cpf);
		for(i=0;i<qtd_cliente;i++){
			if(strcmp(cpf,tab_cliente[i].cpf)==0){
				printf("\n--------------------------------------------\n");
            	printf("Insira Nome: ");
            	fflush(stdin);
            	gets(tab_cliente[i].nome);
            	fflush(stdin);
            	printf("Digite o CPF: ");
            	gets(tab_cliente[i].cpf);
            	printf("Atualmente inquilino de alguma casa ? [s]-SIM e [n]-NAO: ");
            	scanf("%s", &check);
            	if(check == 's'){
            		printf("Digite o codigo da casa: ");
            		scanf("%i", &tab_cliente[i].cod_casa);
				}
			}else{
				printf("Cliente nao encontrado.\n\n");
			}
		}
		do{
	 		printf("Deseja realizar mais alguma alteracao ? [s]-SIM e [n]-NAO: ");
        	scanf("%s", &prox);
        	fflush(stdin);
        	system("cls");
        	if(prox == 'n'){
            	menu();
            	system("cls");
    		}else if(prox == 's'){
           		alt1();
        	}else{
           		printf("Digito incorreto.\n");           	
        	}	
    	}while(prox != 'n' || 's');
}

void alt2(){
	char prox;
	int cod,i;
		printf("    ALTERACAO DE CASAS\n\n");
		printf("Digite COD da casa:");
		scanf("%i", &cod);
		for(i=0;i<qtd_casas;i++){
			if(cod==tab_casas[i].cod){
				printf("\n--------------------------------------------\n");      
                printf("Digite o Endereco: ");
                fflush(stdin);
                gets(tab_casas[i].end);
                printf("Digite o Numero: ");
                scanf("%i", &tab_casas[i].num);
                fflush(stdin);
                printf("Digite o CEP: ");
                scanf("%i", &tab_casas[i].cep);
                printf("Valor de Aluguel: ");
                scanf("%f", &tab_casas[i].aluguel);
                fflush(stdin);
                printf("Casa disponivel ? [s]-SIM e [n]-NAO: ");
                scanf("%s", &tab_casas[i].rent); 
                fflush(stdin);
 	   			if(tab_casas[i].rent == 'n'){
 	   				fflush(stdin);
					printf("Digite o CPF do atual inquilino: ");
					scanf("%s", &tab_casas[i].cpf_inq);
					fflush(stdin);
				}
			}else{
				printf("Casa nao encontrada.\n\n");
			}
		}
		do{
	 		printf("Deseja realizar mais alguma alteracao ? [s]-SIM e [n]-NAO: ");
        	scanf("%s", &prox);
        	fflush(stdin);
        	system("cls");
        	if(prox == 'n'){
            	menu();
            	system("cls");
    		}else if(prox == 's'){
           		alt2();
        	}else{
           		printf("Digito incorreto.\n");           	
        	}	
    	}while(prox != 'n' || 's');
}
