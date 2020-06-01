#include <stdio.h>

int resolve() {
	int c, last, first, tauto;

	c = getc(stdin);
	if(c == '*') {
		return -1;
	}
	if(c > 96) {
		c -= ('a' - 'A');
	}
	first = c;
	last = c;
	tauto = 1;

	while(c != '\n' && c != EOF) {
		if(last == ' ') {
			if(c > 96) {
				c -= 'a' - 'A';
			}
			if(c != first) {
				tauto = 0;
			}
		}
		last = c;
		c = getc(stdin);
	}

	return tauto;
}

int main() {
	int t;

	t = resolve();
	while(t != -1) {
		if(t == 0) {
			printf("N\n");
		}
		else {
			printf("Y\n");
		}
		t = resolve();
	}
	return 0;
}