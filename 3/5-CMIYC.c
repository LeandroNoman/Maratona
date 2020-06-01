#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{

    int T;
    long long int N;

    scanf("%d",&T);

    T = T-1;

    for(T; T>=0; T--)
    {
        scanf("%lli",&N);
	
	(N%3) ? printf("0\n") : printf("%lli\n",N/3);
    
    }

    return 0;
}
