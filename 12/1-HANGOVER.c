#include <stdio.h>
#include <stdlib.h>

int main ( int argc , char  *argv[] ) {
	double a,i,aux;
	scanf("%lf" , &a);
	while(a > 0){
    aux = 0;
    i = 2;
		while(aux<=a){
			aux += 1/i;
      i++;
		}
		printf("%d card(s)\n",((int) i) - 2);
		scanf("%lf",&a);
	}
	return 0;
}
