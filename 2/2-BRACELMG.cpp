#include <iostream>
#include <string>

bool verifyBracelet(const std::string& bracelet, const std::string& sequence, int start) {

	int i;

	for(i = 0; i < sequence.size(); i++) {
		if(sequence[i] != bracelet[(i + start) % bracelet.size()]) {
			break;
		}
	}
	if(i == sequence.size()) {
		return true;
	}
	for(i = 0; i < sequence.size(); i++) {
		if(sequence[i] != bracelet[(start - i) % bracelet.size()]) {
			break;
		}
	}
	if(i == sequence.size()) {
		return true;
	}

	return false;
}

int main() {

	int i, index, numOfWords;
	bool sequencyFound;
	std::string sequence = "", bracelet = "";

	std::cin >> numOfWords;

	for(i = 0; i < numOfWords; i++) {
		std::cin >> sequence;
		std::cin >> bracelet;
		index = 0;
		sequencyFound = false;
		for(std::string::const_iterator it = bracelet.begin(); it != bracelet.end(); it++, index++) {
			if(*it != sequence[0]) {
				continue;
			}
			else {
				if(verifyBracelet(bracelet, sequence, index)) {
					sequencyFound = true;
					std::cout << "S" << std::endl;
					break;
				}
			}
		}
		if(!sequencyFound) {
			std::cout << "N" << std::endl;
		}
	}

	return 0;
}