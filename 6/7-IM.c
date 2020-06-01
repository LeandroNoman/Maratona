#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100000

struct GraphNode {
	int planetID;
	int fluxo;
	struct GraphNode* nextPlanet;
};

struct Vertice {
	int indice;
	int vizinho;
};

struct GraphNode map[MAXSIZE];
int tamanhoAtualMapa;
struct Vertice pilha[MAXSIZE];

void graphAddNode(int i, int j) {
	struct GraphNode* gn;

	gn = &map[i];
	while(gn->nextPlanet != NULL) {
		gn = gn->nextPlanet;
	}

	gn->nextPlanet = (struct GraphNode*) malloc(sizeof(struct GraphNode));
	gn->nextPlanet->planetID = j;
	gn->fluxo = 0;
	gn->nextPlanet->nextPlanet = NULL;
}

void deleteNode(struct GraphNode* gn) {
	if(gn == NULL) {
		return;
	}
	deleteNode(gn->nextPlanet);
	free(gn);
}

void deleteMap() {
	int i;

	for(i = 0; i < tamanhoAtualMapa; i++) {
		deleteNode(map[i].nextPlanet);
		map[i].nextPlanet = NULL;
	}
}

int fluxoMaximo(int numPlanetas) {
	int achouCaminho, fluxoTotal, indicePilha;
	char visitados[MAXSIZE];

	memset(visitados, 0, (numPlanetas * 2) + 1);
	achouCaminho = 1;
	fluxoTotal = 0;
	indicePilha = 0;

	pilha[0].indice = 0;
	pilha[0].vizinho = map[0].nextPlanet;
	visitados[0] = 1;

	while(achouCaminho) {
		achouCaminho = 0;

		//Procura um caminho de 0 a 3 ou 4
		while(indicePilha >= 0) {
			//Empilha o proximo vizinho e continua
			if(pilha[indicePilha].vizinho != NULL) {
				indicePilha++;
				pilha[indicePilha].indice = pilha[indicePilha - 1].vizinho->planetID;
				pilha[indicePilha].vizinho = map[pilha[indicePilha].indice].nextPlanet;
				pilha[indicePilha - 1].vizinho = pilha[indicePilha - 1].vizinho->nextPlanet;
			}
		}
	}

	return fluxoTotal;
}

void intergalacticMap() {
	int i, numPlanetas, numConexoes, planeta1, planeta2, planetaSwitch;

	scanf("%d %d", &numPlanetas, &numConexoes);
	tamanhoAtualMapa = numPlanetas * 2 + 1;
	memset(map, 0, sizeof(struct GraphNode) * tamanhoAtualMapa);

	//Cria as conexoes dos vertices duplicados
	for(i = 1; i < numPlanetas + 1; i++) {
		printf("Caminho criado entre %d e %d\n", (i << 1) - 1, i << 1);
		graphAddNode((i << 1) - 1, i << 1);
	}

	for(i = 0; i < numConexoes; i++) {
		scanf("%d %d", &planeta1, &planeta2);
		//Todos os planetas foram duplicados
		if(planeta2 < planeta1) {
			planetaSwitch = planeta2;
			planeta2 = planeta1;
			planeta1 = planetaSwitch;
		}
		printf("Caminho criado entre %d e %d\n", planeta1 << 1, (planeta2 << 1) - 1);
		printf("Caminho criado entre %d e %d\n", (planeta1 << 1) - 1, planeta2 << 1);
		graphAddNode(planeta1 << 1, (planeta2 << 1) - 1);
		graphAddNode((planeta1 << 1) - 1, planeta2 << 1);
	}
	//Adiociona um vertice do source(0) aos planetas 1 e 3
	graphAddNode(0, 1);
	graphAddNode(0, 5);
	//Se o fluxo maximo de 0 ao 3 for 2, existe caminho, se nao, nao existe caminho
	if(fluxoMaximo(numPlanetas) >= 2) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main() {
	int i, numCasos;

	scanf("%d", &numCasos);
	for(i = 0; i < numCasos; i++) {
		if(i > 0) {
			deleteMap();
		}
		intergalacticMap();
	}

	return 0;
}