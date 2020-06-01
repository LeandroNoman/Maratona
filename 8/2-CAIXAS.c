#include <stdio.h>
#include <string.h>

#define MAXCAIXAS 1010

int numPilhas;
int tamPilha[MAXCAIXAS];
int pilhas[MAXCAIXAS][MAXCAIXAS];
int pilhasEsquerda[MAXCAIXAS][MAXCAIXAS];
int pilhasDireita[MAXCAIXAS][MAXCAIXAS];

int min(int a, int b) {
	if(a  < b) {
		return a;
	}
	else {
		return b;
	}
}

void desempilhaEsquerda() {
	int i, j;

	//printf("Borda da esquerda: ");
	//Desempilha primeiro as beradas
	for(i = 0; i < tamPilha[0]; i++) {
		pilhasEsquerda[0][i] = tamPilha[0] - i;
		//printf("%d ", pilhasEsquerda[0][i]);
	}
	//printf("\nBorda da direita: ");
	for(i = 0; i < tamPilha[numPilhas - 1]; i++) {
		pilhasEsquerda[numPilhas - 1][i] = tamPilha[numPilhas - 1] - i;
		//printf("%d ", pilhasEsquerda[numPilhas - 1][i]);
	}
	//printf("\n");
	//Desempilha as pilhas de dentro
	for(i = 1; i < numPilhas - 1; i++) {
		for(j = tamPilha[i] - 1; j >= 0; j--) {
			//Se tem vizinho livre eh so desempilhar as de cima e ela mesma
			if(pilhas[i - 1][j] == 0 || pilhas[i + 1][j] == 0) {
				pilhasEsquerda[i][j] = tamPilha[i] - j;
			}
			//Se nao tem vizinho livre, eh so desempilhar os do lado e as de cima e ela mesma
			else {
				pilhasEsquerda[i][j] = (tamPilha[i] - j) + pilhasEsquerda[i - 1][j];
			}
			//printf("%d ", pilhasEsquerda[i][j]);
		}
		//printf("\n");
	}
}

void desempilhaDireita() {
	int i, j;

	//printf("Borda da esquerda: ");
	//Desempilha primeiro as beradas
	for(i = 0; i < tamPilha[0]; i++) {
		pilhasDireita[0][i] = tamPilha[0] - i;
		//printf("%d ", pilhasDireita[0][i]);
	}
	//printf("\nBorda da direita: ");
	for(i = 0; i < tamPilha[numPilhas - 1]; i++) {
		pilhasDireita[numPilhas - 1][i] = tamPilha[numPilhas - 1] - i;
		//printf("%d ", pilhasDireita[numPilhas - 1][i]);
	}
	//printf("\n");
	//Desempilha as pilhas de dentro
	for(i = numPilhas - 2; i > 0; i--) {
		for(j = tamPilha[i] - 1; j >= 0; j--) {
			//Se tem vizinho livre eh so desempilhar as de cima e ela mesma
			if(pilhas[i - 1][j] == 0 || pilhas[i + 1][j] == 0) {
				pilhasDireita[i][j] = tamPilha[i] - j;
			}
			//Se nao tem vizinho livre, eh so desempilhar os do lado e as de cima e ela mesma
			else {
				pilhasDireita[i][j] = (tamPilha[i] - j) + pilhasDireita[i + 1][j];
			}
			//printf("%d ", pilhasDireita[i][j]);
		}
		//printf("\n");
	}
}

int main() {
	int i, j, numCaixas, numCaixasNaPilha, caixaLida, pilhaCaixa1, alturaCaixa1;

	scanf("%d %d", &numCaixas, &numPilhas);
	//Loop dos casos de teste
	while(numCaixas > 0) {
		pilhaCaixa1 = alturaCaixa1 = 0;
		memset(tamPilha, 0, sizeof(int) * MAXCAIXAS);
		memset(pilhas, 0, sizeof(int) * MAXCAIXAS * MAXCAIXAS);
		memset(pilhasEsquerda, 0, sizeof(int) * MAXCAIXAS * MAXCAIXAS);
		memset(pilhasDireita, 0, sizeof(int) * MAXCAIXAS * MAXCAIXAS);
		//Loop de leitura das pilhas
		for(i = 0; i < numPilhas; i++) {
			scanf("%d", &numCaixasNaPilha);
			tamPilha[i] = numCaixasNaPilha;
			//Loop de leitura das caixas das pilhas
			for(j = 0; j < numCaixasNaPilha; j++) {
				scanf("%d", &caixaLida);
				if(caixaLida == 1) {
					pilhaCaixa1 = i;
					alturaCaixa1 = j;
				}
				pilhas[i][j] = 1;
			}
		}

		desempilhaEsquerda();
		desempilhaDireita();

		printf("%d\n", min(pilhasEsquerda[pilhaCaixa1][alturaCaixa1], pilhasDireita[pilhaCaixa1][alturaCaixa1]) - 1);

		scanf("%d %d", &numCaixas, &numPilhas);
	}
	return 0;
}