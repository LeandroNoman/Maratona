#include <stdio.h>

#define CIMA -1
#define DIREITA 1
#define BAIXO 1
#define ESQUERDA -1

struct Pista {
	int x, y, passos;
};

int map[100][100] = {0};
struct Pista pistas[100];

int numPossibilidades = 0;
int pistasVerificadas = 0;
int ultimoX, ultimoY;

void anda(int x, int y, int horizontal, int vertical, int passos) {
	int passosH, novoX, novoY;

	for(passosH = 0; passosH <= passos; passosH++) {
		novoY = passosH*horizontal + y;
		novoX = (passos - passosH)*vertical + x;
		if(novoX >= 0 && novoX < 100 && novoY >= 0 && novoY < 100) {
			if(map[novoX][novoY] == pistasVerificadas) {
				map[novoX][novoY]++;
				numPossibilidades++;
				ultimoX = novoX;
				ultimoY = novoY;
			}
		}
	}

}

int main() {
	int i, dimensaoMapa, numPistas;

	scanf("%d", &dimensaoMapa);
	scanf("%d", &numPistas);

	for(i = 0; i < numPistas; i++) {
		scanf("%d", &pistas[i].x);
		scanf("%d", &pistas[i].y);
		scanf("%d", &pistas[i].passos);
	}

	for(i = 0; i < numPistas; i++) {
		numPossibilidades = 0;
		pistasVerificadas = i;
		anda(pistas[i].x, pistas[i].y, DIREITA, CIMA, pistas[i].passos);
		anda(pistas[i].x, pistas[i].y, DIREITA, BAIXO, pistas[i].passos);
		anda(pistas[i].x, pistas[i].y, ESQUERDA, CIMA, pistas[i].passos);
		anda(pistas[i].x, pistas[i].y, ESQUERDA, BAIXO, pistas[i].passos);
		if(numPossibilidades == 1) {
			break;
		}
	}

	if(numPossibilidades == 1) {
		printf("%d %d\n", ultimoX, ultimoY);
	}
	else {
		printf("-1 -1\n");
	}

	return 0;
}