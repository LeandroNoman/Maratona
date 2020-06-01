#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    long long n,total;

    scanf("%lld",&n);
    while(n>-1){
        total = 0;
        total = ((n*n) + n)/2 + 1;
        printf("%lld\n",total );
        scanf("%lld",&n);
    }

    return 0;
}