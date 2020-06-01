#include<iostream>
#include<stdio.h>

int main(){
        long jeitos[30001] = {0};
        int moedas[] = {1,5,10,25,50};
        int n;
        jeitos[0] = 1;

        for(int i = 0 ; i < 5 ; i++){
            for(int j = moedas[i] ; j  <= 30000 ; j++ ){
                jeitos[j] += jeitos[j - moedas[i]];
            }
        }
        while(scanf("%d" , &n) == 1){
            if(jeitos[n] == 1){
                printf("There is only %ld way to produce %d cents change.\n" , jeitos[n] , n );

            }else{
                printf("There are %ld ways to produce %d cents change.\n" , jeitos[n] , n);
            }
        }
}
