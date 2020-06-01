#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXSIZE 10001

char graph[MAXSIZE][MAXSIZE];
char jaVisitados[MAXSIZE];
int visitados1[MAXSIZE];
int numVisitados1;
int visitados2[MAXSIZE];
int numVisitados2;

int *bfs(int n) {
	int i, j, numVisitados, proximoSize;
	int *visitados = visitados1;
	int *proximosVisitados = visitados2;
	int finish;

	numVisitados = numVisitados1;
	finish = 0;
	
	while(finish == 0) {
		proximoSize = 0;
		finish = 1;

		for(i = 0; i < numVisitados; i++) {
			for(j = 0; j <= n; j++) {
				if(graph[visitados[i]][j] == 1 && jaVisitados[j] == 0) {
					finish = 0;
					proximosVisitados[proximoSize] = j;
					proximoSize++;
					jaVisitados[j] = 1;
				}
			}
		}

		if(finish == 1) {
			break;
		}

		numVisitados = proximoSize;
		if(visitados == visitados1) {
			visitados = visitados2;
			proximosVisitados = visitados1;
			numVisitados2 = proximoSize;
		}
		else {
			visitados = visitados1;
			proximosVisitados = visitados2;
			numVisitados1 = proximoSize;
		}
	}

	return visitados;
}

int main() {
	int i, n, k, m, a, b;
	int *visitados;

	scanf("%d %d %d", &n, &k, &m);
	
	while(n != 0) {
		memset(graph, 0, sizeof(char) * MAXSIZE * MAXSIZE);
		memset(jaVisitados, 0, sizeof(char) * MAXSIZE);
		numVisitados1 = k;

		for(i = 0; i < k; i++) {
			scanf("%d", &visitados1[i]);
			jaVisitados[visitados1[i]] = 1;
		}

		for(i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			graph[a][b] = 1;
			graph[b][a] = 1;
		}

		visitados = bfs(n);

		if(visitados == visitados1) {
			n = numVisitados1;
		}
		else {
			n = numVisitados2;
		}

		std::sort(visitados, visitados + n);

		for(i = 0; i < n - 1; i++) {
			printf("%d ", visitados[i]);
		}
		printf("%d\n", visitados[i]);

		scanf("%d %d %d", &n, &k, &m);
	}

	return 0;
}