#include <stdio.h>
#include <string.h>

char graph[200][200];
char group[200];

int main() {
	int i, j, instancia, guests, friends, friend1, friend2;
	int flagFinish;

	instancia = 1;

	while(scanf("%d", &guests) != EOF) {
		if(instancia != 1) {
			printf("\n");
		}

		scanf("%d", &friends);

		memset(graph, 0, sizeof(char) * 200 * 200);
		memset(group, 0, sizeof(char) * 200);

		for(i = 0; i < friends; i++) {
			scanf("%d %d", &friend1, &friend2);
			graph[friend1][friend2] = 1;
			graph[friend2][friend1] = 1;
		}

		flagFinish = 0;
		for(i = 1; i <= guests; i++) {
			if(group[i] == 0) {
				group[i] = 1;
			}
			for(j = i + 1; j <= guests; j++) {
				if(graph[i][j] == 1) {
					if(group[j] == 0) {
						group[j] = (group[i] % 2) + 1;
					}
					else {
						if(group[j] == group[i]) {
							flagFinish = -1;
							break;
						}
					}
				}
			}
			if(flagFinish != 0) {
				break;
			}
		}

		if(flagFinish != 0) {
			printf("Instancia %d \nnao\n", instancia);
		}
		else {
			printf("Instancia %d \nsim\n", instancia);
		}

		instancia++;
	}

	return 0;
}