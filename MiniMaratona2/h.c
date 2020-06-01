#include <stdio.h>
#include <math.h>

double tempo(double d, int v) {
	return d / (double)v;
}

int main() {
	int d, vf, vg;
	double distance;

	while(scanf("%d %d %d", &d, &vf, &vg) != EOF) {
		distance = hypot(12.0, (double)d);
		if(tempo(distance, vg) <= tempo(12.0, vf)) {
			printf("S\n");
		}
		else {
			printf("N\n");
		}
	}
	return 0;
}