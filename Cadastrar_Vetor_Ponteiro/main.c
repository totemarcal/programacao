#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
      float *f;
      int i;
      f = vet;
      printf("contador/valor/valor/endereco/endereco");
      for(i = 0 ; i <= 4 ; i++){
            printf("\ni = %d",i);
            printf("   vet[%d] = %.1f",i, vet[i]);
            printf("   *(f + %d) = %.1f",i, *(f+i));
            printf("   &vet[%d] = %X",i, &vet[i]);
            printf("   (f + %d) = %X",i, f+i);
      }

	return 0;
}
