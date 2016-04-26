#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i=5, p=&i;
	
	printf("%u  %d  %d  %d  %d  %d", p, *p+2, **&p, 3**p, **&p+4);

	
	
	return 0;
}



