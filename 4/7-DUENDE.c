#include <stdio.h>
#include <string.h>

#define DISTANCIAMAXIMA 100

char caverna[10][10];
char distancias[10][10];

struct Salao {
	int linha, coluna;
};

struct Salao pilhaSaloes[100];
int indicePilha;

void atualizaPosicao(int linha, int coluna, int distanciaVisinho) {
	if(caverna[linha][coluna] != 0 && caverna[linha][coluna] != 1) {
		return;
	}
	if(distancias[linha][coluna] > distanciaVisinho) {
		distancias[linha][coluna] = distanciaVisinho + 1;
		indicePilha++;
		pilhaSaloes[indicePilha].linha = linha;
		pilhaSaloes[indicePilha].coluna = coluna;
	}
}

int main() {
	int i, j, numLinhas, numColunas;
	int duendeL, duendeC, linhaAtual, colunaAtual, distanciaAtual;

	scanf("%d %d", &numLinhas, &numColunas);
	
	for(i = 0; i < numLinhas; i++) {
		for(j = 0; j < numColunas; j++) {
			scanf("%d", &caverna[i][j]);
			if(caverna[i][j] == 3) {
				duendeL = i;
				duendeC = j;
			}
			distancias[i][j] = DISTANCIAMAXIMA;
		}
	}

	distancias[duendeL][duendeC] = 0;

	indicePilha = 0;

	pilhaSaloes[indicePilha].linha = duendeL;
	pilhaSaloes[indicePilha].coluna = duendeC;

	//Enquanto houver elementos na pilha
	while(indicePilha >= 0) {
		linhaAtual = pilhaSaloes[indicePilha].linha;
		colunaAtual = pilhaSaloes[indicePilha].coluna;
		distanciaAtual = distancias[linhaAtual][colunaAtual];
		indicePilha--;
		//Verifica se pode ir para cima
		if(linhaAtual > 0) {
			atualizaPosicao(linhaAtual - 1, colunaAtual, distanciaAtual);
		}
		//Verifica se pode ir para a direita
		if(colunaAtual < numColunas - 1) {
			atualizaPosicao(linhaAtual, colunaAtual + 1, distanciaAtual);
		}
		//Verifica se pode ir para baixo
		if(linhaAtual < numLinhas - 1) {
			atualizaPosicao(linhaAtual + 1, colunaAtual, distanciaAtual);
		}
		//Verifica se pode ir para a esquerda
		if(colunaAtual > 0) {
			atualizaPosicao(linhaAtual, colunaAtual - 1, distanciaAtual);
		}
	}

	distanciaAtual = DISTANCIAMAXIMA;

	for(i = 0; i < numLinhas; i++) {
		for(j = 0; j < numColunas; j++) {
			if(caverna[i][j] == 0) {
				if(distancias[i][j] < distanciaAtual) {
					distanciaAtual = distancias[i][j];
				}
			}
		}
	}

	printf("%d\n", distanciaAtual);

	return 0;
}