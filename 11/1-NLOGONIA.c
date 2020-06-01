#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int n,i,P[2],P1x,P1y,aux;
  scanf("%d",&n);
  while(n>0){
    aux = n;
    P[0]=0;
    P[1]=0;
/*
Se x′<x e  y′<y, então SS está ao Sudoeste de PP
Se x′<x e y′>y, então SS está ao Noroeste de PP
Se x′>x e y′<y, então SS está ao Sudeste de PP
Se x′>x e y′>y, então SS está ao Nordeste de PP
Senão SS está na divisa de P
*/
    scanf("%d %d",&P[0],&P[1]);
    for(i=0;i<aux;i++){
	     scanf("%d %d",&P1x,&P1y);
       if (P1x<P[0] && P1y<P[1]) {
         printf("SO\n");
       }
       else if (P1x<P[0] && P1y>P[1]) {
         printf("NO\n");
       }
       else if (P1x>P[0] && P1y<P[1]) {
         printf("SE\n");
       }
       else if (P1x>P[0] && P1y>P[1]) {
         printf("NE\n");
       }
       else{
         printf("divisa\n");
       }
     }
    scanf("%d",&n);
  }
  return 0;
}
