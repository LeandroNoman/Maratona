#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( int argc , char  *argv[] ) {
	int L,C,R1,R2,R,x;
	scanf("%d %d %d %d\n",&L,&C,&R1,&R2);
	while(L > 0){
		R = R1+R2;
		x =	sqrt(((C-R)*(C-R))+((L-R)*(L-R)));
		R1 += R1;
		R2 += R2;
		if(x>=R && C>=R1 && C>=R2 && L>=R1 && L>=R2)
			printf("S\n");
		else
			printf("N\n");
    scanf("%d %d %d %d\n",&L,&C,&R1,&R2);
	}
	return 0;
}
