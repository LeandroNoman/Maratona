#include <iostream>
#include <algorithm>
#include <vector>

int main() {

	int i, milkOutput, numOfCows;

	std::cin >> numOfCows;
	std::vector<int> milkArray(numOfCows);

	for(i = 0; i < numOfCows; i++) {
		std::cin >> milkArray[i];
	}

	std::sort(milkArray.begin(), milkArray.end());

	std::cout << milkArray[numOfCows / 2] << std::endl;

	return 0;
}