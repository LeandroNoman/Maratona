#include <iostream>

int main() {
	int i, numPacks, totalCandy, candyPerPacket, candyMoved;
	int candies[20000];

	std::ios_base::sync_with_stdio(false);
	std::cin >> numPacks;
	
	while(numPacks > -1) {
		totalCandy = 0;
		for(i = 0; i < numPacks; i++) {
			std::cin >> candies[i];
			totalCandy += candies[i];
		}

		if(totalCandy % numPacks != 0) {
			std::cout << -1 << '\n';
		}
		else {
			candyMoved = 0;
			candyPerPacket = totalCandy / numPacks;

			for(i = 0; i < numPacks; i++) {
				if(candies[i] > candyPerPacket) {
					candyMoved += candies[i] - candyPerPacket;
				}
			}

			std::cout << candyMoved << '\n';
		}

		std::cin >> numPacks;
	}

	return 0;
}