#include <stdio.h>
#include <math.h>

#define MAXSIZE 1001

typedef struct ponto {
	int x, y;
} Ponto;

Ponto pontos[MAXSIZE];

void lePontos(int n) {
	int i;

	for(i = 0; i < n; i++) {
		scanf("%d %d", &pontos[i].x, &pontos[i].y);
	}
}

double calculaDistancias(int n) {
	int i, j;
	double d, minD;

	minD = hypot((double)pontos[0].x - (double)pontos[1].x, (double)pontos[0].y - (double)pontos[1].y);

	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			d = hypot((double)pontos[i].x - (double)pontos[j].x, (double)pontos[i].y - (double)pontos[j].y);
			if(d < minD) {
				minD = d;
			}
		}
	}

	return minD;
}

int main() {
	int n;
	double dist;
	
	scanf("%d", &n);
	lePontos(n);
	dist = calculaDistancias(n);
	printf("%.3f", dist);

	return 0;
}