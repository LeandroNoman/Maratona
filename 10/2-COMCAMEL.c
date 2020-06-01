#include <stdio.h>

#define MAXSIZE 100

unsigned long long val[MAXSIZE];
char op[MAXSIZE];
int ops;

void leEntrada() {
	int i;
	char c;
	int index;

	index = 0;
	ops = 0;
	while(1) {
		scanf("%d", &i);
		if(scanf("%c", &c) == EOF) {
			val[index] = i;
			return;
		}
		val[index] = i;
		if(c != '+' && c != '*') {
			return;
		}
		op[index] = c;
		ops++;
		index++;
	}
}

void printEntrada() {
	int i;

	for(i = 0; i < ops; i++) {
		printf("%d ", val[i]);
		printf("%c ", op[i]);
	}

	printf("%d\n", val[i]);
}

unsigned long long getMax() {
	int i, index;
	unsigned long long res;
	unsigned long long v[MAXSIZE];

	v[0] = val[0];
	index = 0;

	for(i = 0; i < ops; i++) {
		if(op[i] == '+') {
			v[index] += val[i + 1];	
		}
		else {
			index++;
			v[index] = val[i + 1];
		}
	}

	res = 1;
	for(i = 0; i <= index; i++) {
		res *= v[i];
	}

	return res;
}

unsigned long long getMin() {
	int i, index;
	unsigned long long res;
	unsigned long long v[MAXSIZE];

	v[0] = val[0];
	index = 0;

	for(i = 0; i < ops; i++) {
		if(op[i] == '*') {
			v[index] *= val[i + 1];	
		}
		else {
			index++;
			v[index] = val[i + 1];
		}
	}

	res = 0;
	for(i = 0; i <= index; i++) {
		res += v[i];
	}

	return res;
}


int main() {
	int n;
	unsigned long long max, min;

	scanf("%d", &n);
	while(n > 0) {
		leEntrada();
		max = getMax();
		min = getMin();
		printf("The maximum and minimum are %llu and %llu.\n", max, min);
		n--;
	}
	return 0;
}