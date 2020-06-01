#include <stdio.h>
#include <string.h>

#define MAXSIZE 10001

char in[MAXSIZE];

int multOnze(int m) {
	int aux, sum1, sum2, dif;

	sum1 = sum2 = 0;
	aux = m;
	while(aux > 0) {
		sum1 += aux % 10;
		aux /= 100;
	}

	m /= 10;
	while(m > 0) {
		sum2 += m % 10;
		m /= 100;
	}

	if(sum1 == sum2) {
		return 1;
	}
	else {
		if(sum1 > sum2) {
			dif = sum1 - sum2;
		}
		else {
			dif = sum2 - sum1;
		}
		if(dif < 11) {
			return 0;
		}
		return multOnze(dif);
	}
}

int multiploOnze() {
	int i, len, sum1, sum2, dif;

	len = strlen(in);

	sum1 = sum2 = 0;
	for(i = 0; i < len; i += 2) {
		sum1 += (in[i] - '0');
	}
	for(i = 1; i < len; i += 2) {
		sum2 += (in[i] - '0');
	}

	if(sum1 == sum2) {
		return 1;
	}
	else {
		if(sum1 > sum2) {
			dif = sum1 - sum2;
		}
		else {
			dif = sum2 - sum1;
		}
		if(dif < 11) {
			return 0;
		}
		return multOnze(dif);
	}
}

void prepareString() {
	int len;

	len = strlen(in);

	while(in[len - 1] == '\n') {
		in[len - 1] = '\0';
		len--;
	}
}

int main() {

	while(fgets(in, sizeof(char) * MAXSIZE, stdin) != NULL) {
		if(in[0] == '0' && (in[1] < '0' || in[1] > '9')) {
			break;
		}
		prepareString();
		if(multiploOnze() == 1) {
			printf("%s is a multiple of 11.\n", in);
		}
		else {
			printf("%s is not a multiple of 11.\n", in);
		}
	}

	return 0;
}