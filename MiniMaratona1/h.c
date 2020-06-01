#include <stdio.h>
#include <string.h>

#define MAXSIZE 20

typedef struct domino {
	int l, r;
} Domino;

Domino pieces[MAXSIZE];
char used[MAXSIZE];

void swap(Domino* d) {
	int aux;

	aux = d->l;
	d->l = d->r;
	d->r = aux;
}

int solve(int n, int m, Domino* first, Domino* last) {
	int i;

	if(n == 0) {
		if(first->r == last->l) {
			return 1;
		}
	}

	for(i = 0; i < m; i++) {
		if(used[i] == 1) {
			continue;
		}
		if(pieces[i].l == first->r) {
			used[i] = 1;
			if(solve(n - 1, m, &pieces[i], last) == 1) {
				return 1;
			}
			used[i] = 0;
		}
		else if(pieces[i].r == first->r) {
			swap(&pieces[i]);
			used[i] = 1;
			if(solve(n - 1, m, &pieces[i], last) == 1) {
				return 1;
			}
			used[i] = 0;
		}
	}

	return 0;
}

int main() {
	int i, n, m;
	Domino first, last;

	scanf("%d", &n);

	while(n > 0) {
		memset(used, 0, sizeof(char) * MAXSIZE);
		scanf("%d", &m);
		scanf("%d %d", &first.l, &first.r);
		scanf("%d %d", &last.l, &last.r);

		for(i = 0; i < m; i++) {
			scanf("%d %d", &pieces[i].l, &pieces[i].r);
		}

		if(solve(n, m, &first, &last) == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		scanf("%d", &n);
	}

	return 0;
}