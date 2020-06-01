#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int n,m,i,j,k,x,y,z,maior=0;
    int total = -1,i1 = 0,i2 = 0,i3 = 0;


    scanf("%d %d",&n,&m);

    if(m == 0){
    	printf("1 2 3\n");
    	return 0;
    }

	int matriz[101][101] = { 0 };

	for(i = 0;i < m; i++){
		scanf("%d %d %d",&x,&y,&z);
		matriz[x][y]=z;
		matriz[y][x]=z;
	}

	for(i=1;i<n+1;i++){
        for(j=i+1;j<n+1;j++){
        	for (k = j+1; k < n+1; k++){
                maior = 0;
        		maior = matriz[i][j] + matriz[i][k] + matriz[j][k];
        		if(maior > total){
        			total = maior;
        			i1=i;
        			i2=j;
        			i3=k;
        		}
        	}
        }    

	}
	printf("%d %d %d\n",i1,i2,i3 );

    return 0;
}