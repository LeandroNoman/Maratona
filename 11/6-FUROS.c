#include <stdio.h>
#include <math.h>

#define MAXSIZE 1000

typedef struct ponto {
	int x, y;
} Ponto;

Ponto furos[MAXSIZE];
double distancias[MAXSIZE];

void leFuros(int n) {
	int i;

	for(i = 0; i < n; i++) {
		scanf("%d %d", &furos[i].x, &furos[i].y);
	}
}

double distPontos(int p1, int p2) {
	double x, y;

	x = (furos[p1].x - furos[p2].x) * (furos[p1].x - furos[p2].x);
	y = (furos[p1].y - furos[p2].y) * (furos[p1].y - furos[p2].y);
	
	return sqrt(x + y);
}

double calculaDistancias(int n) {
	int i, j;
	double d, maxD, maxaoD;

	for(i = 0; i < n; i++) {
		maxD = .0;
		for(j = 0; j < n; j++) {
			d = distPontos(i, j);
			if(d > maxD) {
				maxD = d;
			}
		}
		distancias[i] = maxD;
		if(i == 0) {
			maxaoD = maxD;
		}
		else if(maxD < maxaoD) {
			maxaoD = maxD;
		}
	}

	return maxaoD;
}

int main() {
	int n, teste;
	double dist;
	
	scanf("%d", &n);
	teste = 1;

	while(n > 0) {
		leFuros(n);
		dist = calculaDistancias(n);
		printf("Teste %d\n", teste);
		printf("%d\n\n", (int)((dist + 2.5) * 2));
		teste++;
		scanf("%d", &n);
	}

	return 0;
}