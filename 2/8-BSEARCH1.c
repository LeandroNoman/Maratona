#include <stdio.h>

int bsearch(int *elements, int numOfElements, int query) {
	int oldLow, oldHigh, index, newIndex;

	oldLow = 0;
	oldHigh = numOfElements - 1;

	while(oldHigh - oldLow > 1) {
		index = (oldHigh + oldLow) / 2;
		if(elements[index] == query) {
			oldHigh = index;
		}
		else if(elements[index] < query) {
			oldLow = index;
		}
		else {
			oldHigh = index;
		}
	}

	if(elements[oldLow] == query) {
		return oldLow;
	}
	if(elements[index] == query) {
		return index;
	}	
	if(elements[oldHigh] == query) {
		return oldHigh;
	}

	return -1;
}

int main() {

	int i, numOfElements, numOfQueries, query;
	int elements[100000];

	scanf("%d", &numOfElements);
	scanf("%d", &numOfQueries);

	for(i = 0; i < numOfElements; i++) {
		scanf("%d", &elements[i]);
	}

	for(i = 0; i < numOfQueries; i++) {
		scanf("%d", &query);
		printf("%d\n", bsearch(elements, numOfElements, query));
	}
	
	return 0;
}