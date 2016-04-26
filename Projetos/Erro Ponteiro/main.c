#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anagrama(char palavra[20], int pos)
{
   if(pos == strlen(palavra)){
       return 1;
   }
   else{
       if(palavra[pos] == palavra[strlen(palavra)-1-pos])
       {
           anagrama(palavra,pos-1);
       }else{
           return 0;  
       }
   }          
}

int main(int argc, char *argv[])
{
    char nome[20];
    printf("Digita a palavra \n");
    gets(nome);
    
    if(anagrama(nome, 0))
       printf("HE ANAGRAMA");
    else 
       printf("NAO HE ANAGRAMA");
       
    system("PAUSE");	
    return 0;
}
