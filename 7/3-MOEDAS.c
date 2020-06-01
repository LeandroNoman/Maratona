#include <stdio.h>
#include <string.h>

#define MAXMOEDAS 200
#define MAXPRECO 60000

int moedas[MAXMOEDAS];
int troco[MAXPRECO];
int pilha1[MAXPRECO];
int pilha2[MAXPRECO];
int indicePilha1, indicePilha2;

int main() {
	int i, j, precoMercadoria, numMoedas, valorTotal, flagTerminou;

	scanf("%d", &precoMercadoria);
	scanf("%d", &numMoedas);
	
	while(precoMercadoria != 0) {
		memset(troco, -1, sizeof(int) * MAXPRECO);
		for(i = 0; i < numMoedas; i++) {
			scanf("%d", &moedas[i]);
		}

		//Nas pilhas ficam os valores totais conseguidos com as moedas
		indicePilha1 = 0;
		pilha1[indicePilha1] = 0;
		indicePilha1++;
		troco[0] = 0;

		flagTerminou = 0;

		while(!flagTerminou) {

			indicePilha2 = 0;
			for(i = 0; i < indicePilha1; i++) {
				for(j = 0; j < numMoedas; j++) {
					valorTotal = pilha1[i] + moedas[j];
					if(valorTotal <= precoMercadoria &&
					   troco[valorTotal] == -1) {

						troco[valorTotal] = troco[pilha1[i]] + 1;
						//Empilha o valor novo
						pilha2[indicePilha2] = valorTotal;
						indicePilha2++;

					}
				}
			}

			//Verifica se a pilha esta vazia ou se o valor da mercadoria ja foi computado
			if(troco[precoMercadoria] != -1) {
				flagTerminou = 1;
				printf("%d\n", troco[precoMercadoria]);
				break;
			}
			else if(indicePilha2 == 0) {
				flagTerminou = 1;
				printf("Impossivel\n");
				break;
			}

			//Continua para a proxima pilha
			indicePilha1 = 0;
			for(i = 0; i < indicePilha2; i++) {
				for(j = 0; j < numMoedas; j++) {
					valorTotal = pilha2[i] + moedas[j];
					if(valorTotal <= precoMercadoria &&
					   troco[valorTotal] == -1) {

						troco[valorTotal] = troco[pilha2[i]] + 1;
						//Empilha o valor novo
						pilha1[indicePilha1] = valorTotal;
						indicePilha1++;

					}
				}
			}

			//Verifica se a pilha esta vazia ou se o valor da mercadoria ja foi computado
			if(troco[precoMercadoria] != -1) {
				flagTerminou = 1;
				printf("%d\n", troco[precoMercadoria]);
				break;
			}
			else if(indicePilha1 == 0) {
				flagTerminou = 1;
				printf("Impossivel\n");
				break;
			}

		}

		scanf("%d", &precoMercadoria);
		if(precoMercadoria == 0) {
			break;
		}
		scanf("%d", &numMoedas);
	}

	return 0;
}