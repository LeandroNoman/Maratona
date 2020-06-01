#include <stdio.h>
#include <stdlib.h>

int verificaigual(float x[] , float y[]){
    if(x[0]==x[1] && y[0]==y[1]){
        return 0;
    }
    if(x[0]==x[2] && y[0]==y[2]){
        return 0;
    }
    if(x[1]==x[2] && y[1]==y[2]){
        return 0;
    }

    return 1;
}

int verifica(float a,float b,float  c,float d,float e,float f){
    float dist1 = (a - c)*(a - c) + (b - d)*(b - d);
    float dist2 = (c - e)*(c - e) + (d - f)*(d - f);
    float dist3 = (a - e)*(a - e) + (b - f)*(b - f);
    float u , y;

    u = dist1;
    y = dist2 + dist3;
    ////////////////////printf("1 %f - %f\n" ,u,y);
    if(u==y)
    {
        return 0;
    }
    u = dist2;
    y =  dist1 + dist3;

    if(u==y)
    {
        return 0;
    }
    u = dist3;
    y = dist2 + dist1;
    //printf(" 3%f - %f \n" ,u,y);
    if(u==y)
    {
        return 0;
    }

    return 1;
}

int main(){

    float a, b,  c, d, e, f;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    scanf("%f", &e);
    scanf("%f", &f);

    if(verifica(a,b,c,d,e,f)==0){
        printf("RIGHT\n");
        return 0;
    }
int i = 0;
    float x[3];
    float y[3];
    x[0] = a;
    y[0] = b;
    x[1] = c;
    y[1] = d;
    x[2] = e;
    y[2] = f;

    for(i = 0 ; i < 3 ; i ++){

        x[i] -= 1;
        if(verifica(x[0],y[0],x[1],y[1],x[2],y[2])==0 && verificaigual(x,y)){

            printf("ALMOST\n");

            return 0 ;
        }

        x[i] += 1;
        x[i] += 1;
        if(verifica(x[0],y[0],x[1],y[1],x[2],y[2])==0 && verificaigual(x,y) ){
            printf("ALMOST\n");
            return 0;
        }
        x[i] -=1;
        y[i] += 1;

        if(verifica(x[0],y[0],x[1],y[1],x[2],y[2])==0 && verificaigual(x,y)){
            printf("ALMOST\n");
            return 0 ;
        }
        y[i] -=1;
        y[i] -= 1;

        if(verifica(x[0],y[0],x[1],y[1],x[2],y[2])==0 && verificaigual(x,y)){
            printf("ALMOST\n");
            return 0;
        }
        y[i] +=1;

    }

    printf("NEITHER\n");


}
