#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

using namespace std;

 struct animal{
 	
 	char nome[20];
 	int idade;
 	double peso;
 } typedef animal;
 
 struct servico{
 	int data;
 	int tipo;
 	struct animal animal;
 }typedef servico;
 
 struct compra{
 	int tipo;
 	
 };
 
 
 
 animal vetgoblanimais[100];
 servico vetgoblalservico[100];
 compra vetglobalcompra[100];
 
 
 int    vindiceglobal, vindiceglobalservico,vindiceglobalcompra;
 


  
   int geramenu(){
   	 printf("\n\n MENU:\n\n");
   	 printf("1- Adicionando Novo Animal\n\n");
   	 printf("2- Servico\n\n");
   	 printf("3- Listar Todos os Servico \n\n");
   	 printf("4- Listar Todos os Animais\n\n");
   	 printf("5- Pesquisar Por Nome\n\n"); //ou funcão para lista os servicos solicitados:
   	 printf("6-  Edita Animal\n\n");
   	 printf("7- Efetuando Compra\n\n");
	 printf("8- Sair\n\n");
   	 printf("\n\nDigite a Apcao Escolhida:");
   	 int vopcao;                                           
   	 scanf("%d",&vopcao);
   	 return vopcao;   	
   }

void Adicionaranimal(){    //adicionando animal
	
	 if (vindiceglobal <100 ){
		
		printf("\n\nAdicionando Um Novo Animal A Loja :\n\n ");
		animal vanimalbuffer;
		printf (" Digite A  Nome  Do Animal: ");
		fflush(stdin);
		gets (vanimalbuffer.nome);
		printf("  Digite A Idade  Do Animal: ");
		scanf("%d", & vanimalbuffer.idade);
		printf (" Informe O Peso  Do Animal: ");
		scanf("%lf",& vanimalbuffer.peso);
		vetgoblanimais[vindiceglobal] = vanimalbuffer;
		vindiceglobal++;
		printf("\n\n Animal Adicionado Com Sucesso.\n\n");
		
	  } else {
		    printf("\n\n Limite de Animais Ultrapassado... \n\n");
	}	
}

void cad_servico( animal animal){
	if(vindiceglobalservico < 100){
		vetgoblalservico[vindiceglobalservico].animal = animal;
		printf (" Digite a Data do Serviço: \n\n");
		fflush(stdin);
		scanf("%i",&vetgoblalservico[vindiceglobalservico].data);
		printf (" Digite (1) Tosa, (2) Banho: ");
		fflush(stdin);
		scanf ("%i", &vetgoblalservico[vindiceglobalservico].tipo);
	 	printf("\n\n Servico Adicionado Com Sucesso.\n\n");
	 	fflush(stdin);
	}else{
		printf ("Servico não Cadastraddo!...\n\n");
		
	  }
	
}

void lista_servico(){
	printf("listando todos  os servicos\n\n");
	int i;
		for (i=0; i<vindiceglobal; i++){
			printf(" %i]Data :%d | Tipo : %d",i,vetgoblalservico[i].data,vetgoblalservico[i].tipo);
			printf(" |Nome do Animal: %s", vetgoblalservico[i].animal.nome);
	    }puts("\n\n");
		fflush(stdin);
}

	


void  listartodosanimais(){    //listando todos animas
	
	printf("\n\n Listando Todos Animais cadastrados\n\n");
	int i;
	for (i=0; i<vindiceglobal; i++){
			printf("%d] Nome : %s | Idade : %d | Peso kg : %lf\n",i,vetgoblanimais[i].nome,vetgoblanimais[i].idade,vetgoblanimais[i].peso);
			
	} puts("\n\n");	
		fflush(stdin);
}


  animal pesquisarpornome (){   //pesquisar os animas por nome
	
	printf ("\n\n Pesquisar Por Nome:\n\n");
	char vexpressaobusca[20];
    printf (" Digite A Expressao De Busca Pro Nome: \n\n");
    fflush(stdin);
    gets(vexpressaobusca);
	int i;
	for (i=0; i<vindiceglobal; i++){
		
		if(strcasecmp (vexpressaobusca,vetgoblanimais[i].nome)==0){
			
		 	printf("%d] Nome : %s | Idade : %d | Peso kg : %lf\n",i,vetgoblanimais[i].nome,vetgoblanimais[i].idade,vetgoblanimais[i].peso);
		 	return vetgoblanimais[i];
		}else{
			fflush(stdin);
			printf("Animal Nao Cadastraddo!...\n\n");
		}	
		fflush(stdin);
    }puts("\n\n");	
}

	  
void editar_animal(){   //pesquisar os animas por nome
	
	printf ("\n\n Pesquisar Por Nome:\n\n");
	char vexpressaobusca[20];
    printf (" Digite A Expressao De Busca Pro Nome: \n\n");
    fflush(stdin);
    gets(vexpressaobusca);
	int i;
	for (i=0; i<vindiceglobal; i++){
		
		if(strcasecmp (vexpressaobusca,vetgoblanimais[i].nome)==0){
			
		 	printf("%d] Nome : %s | Idade : %d | Peso kg : %lf\n",i,vetgoblanimais[i].nome,vetgoblanimais[i].idade,vetgoblanimais[i].peso);
			printf("\n\nAlterando Animal:\n\n ");
			printf (" Digite o nome  Do Animal: ");
			fflush(stdin);
			gets (vetgoblanimais[i].nome);
			printf("  Digite A Idade  Do Animal: ");
			scanf("%d", & vetgoblanimais[i].idade);
			printf ("Informe O Peso  Do Animal: ");
			scanf("%lf",& vetgoblanimais[i].peso);
			printf("\n\n Animal Alterado Com Sucesso.\n\n");
			 	
		}else{
			
			printf("Animal Nao Cadastraddo!...\n\n");
		}	
    }puts("\n\n");	
}


void  Compra (){
	

	
	 if (vindiceglobalcompra  <100 ){
		compra vcomprabuffer;
		printf("\n\n Efetuando Compra na Loja:  Produtos A disposicao :\n\n ");
	    printf ("Digite:\n\n (1)Osso Nó 1Kg ,\n\n(2)Adesivo Eu Amo meu Golden,\n\n(3)Poltrona Suite Dubai Pet Alumínio e Fibra Sintética:\n");
	    fflush(stdin);
	    scanf("%d",& vcomprabuffer.tipo);
		printf("\n\n Compra Adicionado Com Sucesso.\n\n");
	 	fflush(stdin);
		  } else { 
		    printf("\n\n Compra  Não  Solicitada ... \n\n");
	}	
}
	


int main(int argc, char** argv) {   
	
	 vindiceglobal =0;
	int vopcao;
	int senha, admin;
    char log[10];
    
system("color 5");
system("cls");             
printf("\n\n\n");
printf("\t\t ###############################################\n");	
printf("\t\t ##                  L VPETS LTDA             ##\n");
printf("\t\t ##               Banho,Venda e Tosa          ##\n ");
printf("\t\t    ........._.._..._..---.                        \n");
printf("\t\t    .......-....;-...........                      \n");
printf("\t\t    ...../....../............|                     \n");
printf("\t\t    ....|......|......._=....|                     \n");
printf("\t\t    ....;..._.-'|__.-')......          OlA!!!      \n"); 
printf("\t\t    .....`--'....../.../....;         UM GRANDE    \n");
printf("\t\t    ............../.../;.../ _,       BEIJAO NO    \n");
printf("\t\t    .............-.;.-=-./-""-.-`       CORACAO!   \n");
printf("\t\t    ...........|.....|.....|....|                  \n");
printf("\t\t    ..........|......|......|...|                  \n");
printf("\t\t    ..........|___|___|.....|...                   \n");
printf("\t\t    ...........|.0.| |.0.|...../                   \n");
printf("\t\t    .........--.-""-.`--'.....'                    \n");
printf("\t\t    .......(#...)..........,...|                   \n");
printf("\t\t    .......('--'..........||`...|                  \n");
printf("\t\t    ........|..........,..'........|               \n");
printf("\t\t    .........`-._....'.|..........| |              \n");
printf("\t\t    ..............""`...|..........\\              \n");
printf("\t\t ##                     LOGIN                   ## \n");
printf("\t\t ################################################# \n");

   do{	
     printf("\t\t USUARIO: ");
     gets(log);
     fflush(stdin);
     printf("\t\t SENHA: ");
     scanf("%d", &senha);
     fflush(stdin);
     if(log != "admin" && senha != 1234)
     printf("\t\t loguin ou senha incorreta\n");
   }
   while(strcmp(log, "admin") || senha!=1234);
   system("cls"); 

	
	  while(true){
	  	
	  	   system("cls");
	  	   vopcao = geramenu();
	  	   
			 switch (vopcao){
	  	   	   
	  	   	    case 1:
	  	   	    	Adicionaranimal();
	  	   	    	
	  	   	    	system("pause");
	  	   	    	break;
	  	   	    	
	  	   	    	
	  	   	    case 2:
	  	   	    	animal a;
				    a = pesquisarpornome();
	  	   	        cad_servico(a);              
	  	   	    	system("pause");
	  	   	    	break;                              
	  	   	    
	  	   	    case 3:
	  	   	    	 lista_servico();
	  	   	    	 	system("pause");
	  	   	    	break; 
	  	   	    	
				case 4:
				     listartodosanimais();
				    system("pause");
				   break;
				
				case  5:
				    pesquisarpornome ();
				    system("pause"); 
				    break;
				
				 
				case 6:
				  editar_animal();
					system("pause");
					break;
					
				case 7:
				  	Compra ();
					system("pause");
					break;
					
				case  8:
					 exit (0);
				  break;
				  default :
				  
				  printf("\n\nOpcao Invalida.\nTente Novamente.\n\n");
				  system("pause");
				    break;
			 
	  }
	    

}	
system("pause");    
	return 0;
}
