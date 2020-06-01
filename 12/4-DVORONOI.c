#include <stdio.h>

int main() {
	int t, det;
	int p1[3], p2[3], p3[3], p4[3];
	int matrix[3][3];

	scanf("%d", &t);

	while(t > 0) {
		scanf("%d %d %d", &p1[0], &p1[1], &p1[2]);
		scanf("%d %d %d", &p2[0], &p2[1], &p2[2]);
		scanf("%d %d %d", &p3[0], &p3[1], &p3[2]);
		scanf("%d %d %d", &p4[0], &p4[1], &p4[2]);

		matrix[0][0] = p1[0] - p4[0];
		matrix[0][1] = p2[0] - p4[0];
		matrix[0][2] = p3[0] - p4[0];
		matrix[1][0] = p1[1] - p4[1];
		matrix[1][1] = p2[1] - p4[1];
		matrix[1][2] = p3[1] - p4[1];
		matrix[2][0] = p1[2] - p4[2];
		matrix[2][1] = p2[2] - p4[2];
		matrix[2][2] = p3[2] - p4[2];

		det = 0;
		det += (matrix[0][0] * matrix[1][1] * matrix[2][2]);
		det += (matrix[0][1] * matrix[1][2] * matrix[2][0]);
		det += (matrix[0][2] * matrix[1][0] * matrix[2][1]);
		det -= (matrix[0][0] * matrix[1][2] * matrix[2][1]);
		det -= (matrix[0][1] * matrix[1][0] * matrix[2][2]);
		det -= (matrix[0][2] * matrix[1][1] * matrix[2][0]);

		det = abs(det);

		printf("%.6f\n", (double)det/6.0);

		t--;
	}

	return 0;
}