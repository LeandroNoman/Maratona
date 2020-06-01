#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define MAXCARACTERES 100

char entrada[MAXCARACTERES];

void resolveProblema(int tamEntrada) {
	int i;
	uint64_t custo;

	custo = 0;
	for(i = 0; i < tamEntrada; i++) {
		if(entrada[i] == '\0') {
			break;
		}

		if(entrada[i] == 'b') {
			custo += (uint64_t)1 << (tamEntrada - i - 1);
		}
	}

	printf("%llu", custo);
} 

int main() {
	int numInstancia;

	numInstancia = 1;
	while(scanf("%s", &entrada) != EOF) {

		printf("Palavra %d\n", numInstancia);
		resolveProblema(strlen(entrada));
		printf("\n\n");
		numInstancia++;

	}

	return 0;
}