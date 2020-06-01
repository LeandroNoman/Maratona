#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int n,i;
    int f1,f2,aux;

    scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d",&f1,&f2);
		aux = 0;
		while(f2 != 0){
			aux = f1 % f2;
			f1 = f2;
			f2 = aux;
		}
		printf("%d\n", f1);
	}

    return 0;
}