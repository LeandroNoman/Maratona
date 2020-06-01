#include <stdio.h>

int numPrimes(int n) {
  int i, ret, oldi;
	i = 3;
  oldi = -1;
  ret = 0;
  while(n % 2 == 0) {
    ret = 1;
    n /= 2;
  }
	while(n > 1) {
		if(n % i == 0) {
			if(i != oldi) {
				oldi = i;
				ret++;
			}
			n /= i;
		}
		else {
			i+=2;
		}
	}

	return ret;
}

int main() {
	int n;

	scanf("%d", &n);

	while(n > 0) {
		printf("%d : %d\n", n, numPrimes(n));
		scanf("%d", &n);
	}

	return 0;
}