#include <stdio.h>
#include <string.h>

#define GRAPHSIZE 100

struct Pilha {
	int cidade, pedagios, visinho;
};

char graph[GRAPHSIZE][GRAPHSIZE];
char cidadesAlcancadas[GRAPHSIZE];
int pedagiosCidade[GRAPHSIZE];
struct Pilha pilha[GRAPHSIZE];
int indicePilha; 

void imprimeCidadesAlcancadas(int numCidades) {
	int i;

	for(i = 0; i <= numCidades; i++) {
		if(cidadesAlcancadas[i] == 1) {
			printf("%d ", i);
		}
	}
}

int main() {
	int i, numCidades, numEstradas, cidadeInicial, maxPedagios;
	int cidade1, cidade2, flagContinue, testeNum;

	scanf("%d %d %d %d", &numCidades, &numEstradas, &cidadeInicial, &maxPedagios);
	testeNum = 1;
	while(numCidades > 0) {

		memset(graph, 0, sizeof(char) * GRAPHSIZE * GRAPHSIZE);
		memset(cidadesAlcancadas, 0, sizeof(char) * GRAPHSIZE);
		memset(pedagiosCidade, 0, sizeof(int) * GRAPHSIZE);
		indicePilha = 0;

		for(i = 0; i < numEstradas; i++) {
			scanf("%d %d", &cidade1, &cidade2);
			graph[cidade1][cidade2] = 1;
			graph[cidade2][cidade1] = 1;
		}

		//Coloca na pilha a cidade inicial
		pilha[indicePilha].cidade = cidadeInicial;
		pilha[indicePilha].pedagios = maxPedagios;
		pilha[indicePilha].visinho = -1;
		pedagiosCidade[cidadeInicial] = maxPedagios;

		//Verifica todos os elementos presentes na pilha
		while(indicePilha >= 0) {
			flagContinue = 0;
			//Se nao houverem mais pedagios, retira o elemento da pilha e continua
			if(pilha[indicePilha].pedagios <= 0) {
				indicePilha--;
				continue;
			}
			//Passa por todos os visinhos do primeiro elemento da pilha
			for(i = pilha[indicePilha].visinho; i <= numCidades; i++) {
				if(graph[pilha[indicePilha].cidade][i] == 1) {
					//Empilha a proxima cidade e continua o loop a partir dela
					if(cidadesAlcancadas[i] == 1 && pedagiosCidade[i] > pilha[indicePilha].pedagios - 1) {
						continue;
					}
					pedagiosCidade[i] = pilha[indicePilha].pedagios - 1;
					cidadesAlcancadas[i] = 1;
					pilha[indicePilha].visinho = i + 1;
					indicePilha++;
					pilha[indicePilha].cidade = i;
					pilha[indicePilha].visinho = -1;
					pilha[indicePilha].pedagios = pilha[indicePilha - 1].pedagios - 1;
					flagContinue = 1;
					break;
				}
			}
			if(flagContinue == 1) {
				continue;
			}
			//Quando acabar os visinhos, retira o elemento da pilha
			indicePilha--;
		}

		cidadesAlcancadas[cidadeInicial] = 0;

		if(testeNum > 1) {
			printf("\n\n");
		}
		printf("Teste %d\n", testeNum);
		testeNum++;
		imprimeCidadesAlcancadas(numCidades);
		scanf("%d %d %d %d", &numCidades, &numEstradas, &cidadeInicial, &maxPedagios);

	}

	return 0;
}