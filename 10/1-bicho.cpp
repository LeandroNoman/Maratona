#include <iostream>
#include <stdio.h>
using namespace std;

void imprime (double t){
    printf("%.2lf\n" , t);
}

int main(){

    int  b , c;
    double a;
    bool achou = false;

    do{
        scanf("%lf %d %d" , &a , &b , &c );
        if(a==0 and b == 0 and c == 0)
            break;

        if( b % 10000 == c % 10000 )
        {
            imprime(a * 3000);

        }
        else if(b % 1000 == c % 1000 ){
            imprime(a * 500);
        }
        else if(b % 100 == c % 100 ){
             imprime(a * 50);
        }
        else{
            int aux;
            achou = false;
            for(int i = 1 ; i <=93; i+=4){
                if( ( b%100 >= i && b%100 <= i+3) &&  ( c%100 >= i && c%100 <= i+3) ){
                     imprime(a*16);
                    achou = true;
                    break;
                }
            }
            if( (b%100 == 0 and c%100 >= 97) || (b%100 >= 97 and c%100 >= 97) || (b%100 >= 97  and c%100 == 0) ) {
                imprime(a*16);
                achou = true;
            }
            if(!achou){
                imprime(0);
            }
        }
    }while(1);


    return 0;
}
