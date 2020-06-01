#include <stdio.h>

int main() {
	int numVaretas, compVareta, varetas;
	int i, totalPares;

	scanf("%d", &numVaretas);
	while(numVaretas > 0) {
		totalPares = 0;

		for(i = 0; i < numVaretas; i++) {
			scanf("%d %d", &compVareta, &varetas);
			totalPares += (varetas / 2);
		}

		totalPares /= 2;

		printf("%d\n", totalPares);
		scanf("%d", &numVaretas);
	}

	return 0;
}