#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int n,aux= 0,i,j;
    int candidatos[100] = {0};
    int maior = 0;
    scanf("%d",&n);
    while(n>0){
    	maior = 0;
    	for(i=0;i<n;i++){
    		candidatos[i]=0;
    	}
    	for(j=0;j<n;j++){
	    	for(i = 0; i < n; i++) {
				scanf("%d",&aux);
				if(aux == 1){
					candidatos[i]++;
					if(candidatos[i]>maior){
						maior = candidatos[i];
					}
				}
				aux = 0;
			}
		}

		printf("%d\n", maior);

		scanf("%d",&n);
    }
    return 0;
}