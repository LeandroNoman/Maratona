#include <stdio.h>
#include <string.h>

#define MAXSIZE 100000

char musica[MAXSIZE];
char plagio[MAXSIZE];
int prefix[MAXSIZE];

enum {A = 0, B = 2, C = 3, D = 5, E = 7, F = 8, G = 10};

int leNota() {
	char nota, alt;
	int ret = 0;

	nota = fgetc(stdin);
	while(nota == ' ' || nota == '\n') {
		nota = fgetc(stdin);
	}

	alt = fgetc(stdin);

	switch(nota) {
		case 'A':
			ret = A;
			break;
		case 'B':
			ret = B;
			break;
		case 'C':
			ret = C;
			break;
		case 'D':
			ret = D;
			break;
		case 'E':
			ret = E;
			break;
		case 'F':
			ret = F;
			break;
		case 'G':
			ret = G;
			break;
	}

	if(alt == '#') {
		ret++;
	}
	else if(alt == 'b') {
		ret--;
	}

	if(ret < 0) {
		ret = 11;
	}

	return ret;
}

void calcPrefix(int t) {
	int i, j;

	i = 0;
	j = prefix[0] = -1;
	while (i < t) {
		while (j > -1 && plagio[i] != plagio[j]) {
			j = prefix[j];
		}
		i++;
		j++;
		if (plagio[i] == plagio[j]) {
			prefix[i] = prefix[j];
		}
		else {
			prefix[i] = j;
		}
	}
}

int kmp(int m, int t) {
	int i, j;

	i = j = 0;
	while (j < m) {
		while (i > -1 && plagio[i] != musica[j]) {
    		i = prefix[i];
    	}

    	i++;
    	j++;
    	if (i >= t) {
    		return 1;
    	}
	}

	return 0;
}

int main() {
	int m, t, i, nota1, nota2;

	scanf("%d %d", &m, &t);
	while(m > 0) {
		m--;
		t--;

		nota1 = leNota();
		for(i = 0; i < m; i++) {
			nota2 = leNota();
			musica[i] = nota2 - nota1;
			if(musica[i] < 0) {
				musica[i] += 12;
			}
			nota1 = nota2;
		}

		nota1 = leNota();
		for(i = 0; i < t; i++) {
			nota2 = leNota();
			plagio[i] = nota2 - nota1;
			if(plagio[i] < 0) {
				plagio[i] += 12;
			}
			nota1 = nota2;
		}

		calcPrefix(t);
		if(kmp(m, t) == 1) {
			printf("S\n");
		}
		else {
			printf("N\n");
		}

		scanf("%d %d", &m, &t);
	}

	return 0;
}