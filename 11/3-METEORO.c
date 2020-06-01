#include <stdio.h>

typedef struct Ponto {
	int x, y;
} Ponto;

int dentro(Ponto *se, Ponto *id, Ponto *meteorito) {
	if (meteorito->x >= se->x &&
		meteorito->y <= se->y &&
		meteorito->x <= id->x &&
		meteorito->y >= id->y)
	{
		return 1;
	}
	return 0;
}

int main() {
	int teste, n, mCount, i;
	Ponto se, id, meteorito;

	teste = 1;
	scanf("%d %d %d %d", &se.x, &se.y, &id.x, &id.y);

	while(se.x != 0 || se.y != 0 || id.x != 0 || id.y != 0)
	{
		mCount = 0;
		scanf("%d", &n);

		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &meteorito.x, &meteorito.y);
			if(dentro(&se, &id, &meteorito) == 1) {
				mCount++;
			}
		}

		printf("Teste %d\n%d\n\n", teste, mCount);
		teste++;
		scanf("%d %d %d %d", &se.x, &se.y, &id.x, &id.y);
	}

	return 0;
}