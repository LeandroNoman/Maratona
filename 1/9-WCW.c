#include <stdio.h>

#define MAXTAM 100001

int vetor[MAXTAM];
int posicoes[MAXTAM];

int selectionSort(int tamSequencia) {
	int i, j, aux, numDaPos, numTrocas;

	numTrocas = 0;
	for(i = 0; i < tamSequencia; i++) {
		if(posicoes[i + 1] != i) {
			aux = vetor[i];
			vetor[i] = vetor[posicoes[i + 1]];
			vetor[posicoes[i + 1]] = aux;

			numDaPos = aux;
			aux = posicoes[i + 1];
			posicoes[i + 1] = i;
			posicoes[numDaPos] = aux;

			numTrocas++;
		}
	}

	return numTrocas;
}

int main() {
	int i, j, numInstancias, tamSequencia;
	
	scanf("%d", &numInstancias);
	
	for(i = 0; i < numInstancias; i++) {
		scanf("%d", &tamSequencia);

		for(j = 0; j < tamSequencia; j++) {
			scanf("%d", &vetor[j]);
			posicoes[vetor[j]] = j;
		}

		printf("%d\n", selectionSort(tamSequencia));
	}

	return 0;
}