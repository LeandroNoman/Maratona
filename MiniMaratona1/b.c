#include <stdio.h>
#include <stdlib.h>


void bfs(int **matriz ,int s, int *alcanca, int tamanho)
{
    int i;
    
    if(alcanca[s] == 1){
        return;
    }
    else{
        alcanca[s] = 1;
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
    int teste;
    int n,m,i,x,y,z,j;
    int **matriz;
    int *alcanca;

    alcanca = (int *) calloc (2001, sizeof(int));
    matriz = (int **) calloc (2001, sizeof(int *));

    for ( i = 0; i < 2001; i++ ) {
        matriz[i] = (int*) calloc (2001, sizeof(int));
    }

    scanf("%d %d",&n,&m);

    while(n>0){
        for(i = 0;i < n+1; i++){
            for(j = 0;j < n+1; j++){
                matriz[i][j] = 0;
            }
        }
    	for(i = 0;i < m; i++){
    		scanf("%d %d %d",&x,&y,&z);
            if(z == 2){
    		  matriz[x][y]=1;
    		  matriz[y][x]=1;
            }
            else{
              matriz[x][y]=1;
            }
    	}
        
        for(i = 1;i < n+1; i++){
            teste = 1;
            for(j = 0;j < n+1; j++){
                alcanca[j] = 0;
            }
            bfs(matriz,i,alcanca,n+1);
            for(j = 1;j < n+1; j++){
                
                if(alcanca[j] == 0){
                    teste = 0;
                    break;
                }
            }
            if(teste == 0){
                break;
            }
        }
        if(teste == 0){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
        scanf("%d %d",&n,&m);
    }

    return 0;
}