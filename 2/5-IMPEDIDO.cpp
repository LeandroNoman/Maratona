#include <iostream>
#include <algorithm>

int main() {

	int i, numOfAttack, numOfDef;
	int attackers[100], defenders[100];
	bool impedido;

	std::cin >> numOfAttack;
	std::cin >> numOfDef;
	while(numOfAttack > 0 || numOfDef > 0) {
		impedido = false;
		
		for(i = 0; i < numOfAttack; i++) {
			std::cin >> attackers[i];
		}
		for(i = 0; i < numOfDef; i++) {
			std::cin >> defenders[i];
		}

		if(numOfAttack == 0) {
			impedido = false;
			std::cin >> numOfAttack;
			std::cin >> numOfDef;
			std::cout << 'N' << std::endl;
			continue;
		}
		else if(numOfDef < 2) {
			impedido = true;
			std::cin >> numOfAttack;
			std::cin >> numOfDef;
			std::cout << 'Y' << std::endl;
			continue;
		}

		std::sort(defenders, defenders+numOfDef);

		for(i = 0; i < numOfAttack; i++) {
			if(attackers[i] < defenders[1]) {
				impedido = true;
				break;
			}
		}

		if(impedido) {
			std::cout << 'Y' << std::endl;
		}
		else {
			std::cout << 'N' << std::endl;			
		}

		std::cin >> numOfAttack;
		std::cin >> numOfDef;
	}
	
	return 0;
}