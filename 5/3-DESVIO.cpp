#include <cstdio>
#include <cstring>
#include <list>

#define MAXCIDADES 256
#define INF 0xFFFFFFFF

int pais[MAXCIDADES][MAXCIDADES];
unsigned int distancias[MAXCIDADES];
char visitados[MAXCIDADES];
std::list<int> aSerVisitados(MAXCIDADES);

void atualizaVizinho(int cidade, int numCidades) {
	int i;

	for(i = 0; i < numCidades; i++) {
		if(pais[cidade][i] >= 0) {
			if(visitados[i] != 0) {
				continue;
			}
			else {
				if(distancias[i] > distancias[cidade] + pais[cidade][i]) {
					if(distancias[i] == INF) {
						aSerVisitados.push_back(i);
					}
					distancias[i] = distancias[cidade] + pais[cidade][i];
				}
			}
		}
	}
}

int main() {
	int i, numCidades, numEstradas, numCidadesRota, cidadeConserto;
	int cidade1, cidade2, pedagio, distanciaTotal, cidadeMenorDistancia;
	std::list<int>::iterator listIterator, listIteratorErase;

	scanf("%d %d %d %d", &numCidades, &numEstradas, &numCidadesRota, &cidadeConserto);
	while(numCidades != 0 || numEstradas != 0 || numCidades != 0 || cidadeConserto != 0) {
		memset(pais, -1, sizeof(int) * MAXCIDADES * MAXCIDADES);
		memset(distancias, INF, sizeof(int) * MAXCIDADES);
		memset(visitados, 0, sizeof(char) * MAXCIDADES);
		for(i = 0; i < numEstradas; i++) {
			scanf("%d %d %d", &cidade1, &cidade2, &pedagio);
			pais[cidade1][cidade2] = pedagio;
			pais[cidade2][cidade1] = pedagio;
		}

		numCidadesRota--;
		distanciaTotal = 0;
		distancias[numCidadesRota] = 0;
		visitados[numCidadesRota] = 1;
		aSerVisitados.clear();
		for(i = numCidadesRota - 1; i >= 0; i--) {
			distanciaTotal += pais[i][i+1];
			distancias[i] = distanciaTotal;
			visitados[i] = 1;
		}
		for(i = numCidadesRota; i >= 0; i--) {
			atualizaVizinho(i, numCidades);
		}

		while(distancias[cidadeConserto] == INF || !aSerVisitados.empty()) {
			listIterator = aSerVisitados.begin();
			listIteratorErase = listIterator;
			cidadeMenorDistancia = *listIterator;
			//Pega o menor a ser visitado e atualiza seus vizinhos
			for(listIterator++; listIterator != aSerVisitados.end(); listIterator++) {
				if(distancias[*listIterator] < distancias[cidadeMenorDistancia]) {
					cidadeMenorDistancia = *listIterator;
					listIteratorErase = listIterator;
				}
			}
			//Marca e retira o que foi visitado da lista
			visitados[cidadeMenorDistancia] = 1;
			atualizaVizinho(cidadeMenorDistancia, numCidades);
			aSerVisitados.erase(listIteratorErase);
		}

		printf("%d\n", distancias[cidadeConserto]);

		scanf("%d %d %d %d", &numCidades, &numEstradas, &numCidadesRota, &cidadeConserto);
	}

	return 0;
}