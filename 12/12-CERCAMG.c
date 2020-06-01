#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXTREES 1001

typedef struct Point {
	int x, y;
} Point;

Point trees[MAXTREES];
Point *hull[MAXTREES];

int comparePoints(const void *p1, const void *p2) {
	Point *po1 = (Point*)p1;
	Point *po2 = (Point*)p2;

	if(po1->x < po2->x) {
		return -1;
	}
	else if(po1->x > po2->x) {
		return 1;
	}
	else {
		if(po1->y < po2->y) {
			return -1;
		}
		return 1;
	}
}

int ccw(Point* p1, Point* p2, Point* p3) {
	return (p2->x - p1->x)*(p3->y - p1->y) - (p2->y - p1->y)*(p3->x - p1->x);
}

int convexHull(int npoints) {
	int i, t, k = 0;

	for (i = 0; i < npoints; ++i) {
		while (k >= 2 && ccw(hull[k-2], hull[k-1], &trees[i]) <= 0) {
			k--;
		}
		hull[k] = &trees[i];
		k++;
	}

	for (i = npoints-2, t = k+1; i >= 0; --i) {
		while (k >= t && ccw(hull[k-2], hull[k-1], &trees[i]) <= 0) {
			k--;
		}
		hull[k] = &trees[i];
		k++;
	}

	return k;
}

double pointDistance(Point *p1, Point *p2) {
	double x, y;

	x = pow((double)p1->x - (double)p2->x, 2);
	y = pow((double)p1->y - (double)p2->y, 2);
	
	return sqrt(x + y);
}

double totalDistance(int hullSize) {
	int i;
	double distance;

	distance = 0.0;

	for(i = 0; i < hullSize - 1; i++) {
		distance += pointDistance(hull[i], hull[i + 1]);
	}

	return distance;
}

int main() {
	int i, a, d, hSize;

	while(scanf("%d %d", &a, &d) != EOF) {
		for(i = 0; i < a; i++) {
			scanf("%d %d", &trees[i].x, &trees[i].y);
		}
		qsort(trees, a, sizeof(Point), comparePoints);

		hSize = convexHull(a);
		printf("%.2f\n", totalDistance(hSize));
	}

	return 0;
}