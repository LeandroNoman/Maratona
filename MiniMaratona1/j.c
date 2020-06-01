#include <stdio.h>
#include <stdlib.h>

int numDependencias;

void bfs(int **matriz ,int s, int *alcanca, int tamanho)
{
    int i;
    
    if(alcanca[s] == 1){
        return;
    }
    else{
        alcanca[s] = 1;
        numDependencias++;
        for(i = 1; i < tamanho; i++){
            if (matriz[s][i] == 1 && alcanca[i] == 0)
            {
                bfs(matriz,i,alcanca,tamanho);
            }
        }
    }
}


int main(int argc, char *argv[])
{
    int n,t,i,x,j;
    int **matriz;
    int *alcanca;
    int maxDependencias, maxTarefa;

    alcanca = (int *) calloc (2001, sizeof(int));
    matriz = (int **) calloc (2001, sizeof(int *));

    for ( i = 0; i < 2001; i++ ) {
        matriz[i] = (int*) calloc (2001, sizeof(int));
    }

    scanf("%d",&n);

    while(n>0){
        for(i = 0;i < n+1; i++){
            for(j = 0;j < n+1; j++){
                matriz[i][j] = 0;
            }
        }
    	for(i = 0;i < n; i++){
            scanf("%d", &t);
            for(j = 0; j < t; j++) {
        		scanf("%d",&x);
                matriz[i+1][x] = 1;
            }
    	}


        maxDependencias = 0;
        maxTarefa = 0;
        
        for(i = 1;i < n+1; i++){
            for(j = 0;j < n+1; j++){
                alcanca[j] = 0;
            }
            numDependencias = 0;
            bfs(matriz,i,alcanca,n+1);
            for(j = 1;j < n+1; j++){
                if(numDependencias > maxDependencias) {
                    maxDependencias = numDependencias;
                    maxTarefa = i;
                }
            }
        }

        printf("%d\n", maxTarefa);
        scanf("%d",&n);
    }

    return 0;
}