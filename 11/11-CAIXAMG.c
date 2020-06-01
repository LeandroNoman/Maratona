#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  double a,b,aux,aux2,delta,x1,x2,total1,total2;
  scanf("%lf %lf",&a,&b);
  while(a>0 && b>0){
    //calcular x
    //f′(x)=12x^2−4x(a+b)+ab
    aux = 0;
    aux = a*b;
    aux2 = 0;
    aux2 = 4*(a+b);
    delta = 0;
    delta = aux2*aux2 - 48*aux;
    delta = sqrt(delta);
    x1 = (aux2 + delta)/24;
    x2 = (aux2 - delta)/24;
    //4x^3−2x^2(a+b)+x(ab)
    total1 = 4*x1*x1*x1 - 2*x1*x1*(a+b) + x1*aux;
    total2 = 4*x2*x2*x2 - 2*x2*x2*(a+b) + x2*aux;

    //printf("%lf %lf\n",x1,x2 );
    //printf("%lf %lf\n",aux,aux2 );

    if(total1>total2){
        printf("%.4lf %.4lf\n",x1,total1 );
    }
    else{
        printf("%.4lf %.4lf\n",x2,total2 );
    }
    //sqrt(5.0);
    scanf("%lf %lf",&a,&b);
  }
  return 0;
}
