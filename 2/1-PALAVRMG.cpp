#include <iostream>
#include <string>

void verificaPalavraOrdenada(const std::string& palavra) {

	int letraAnterior = -1000;
	int letraAtual;

	for(std::string::const_iterator it = palavra.begin(); it != palavra.end(); it++) {
		letraAtual = std::tolower(*it);
		if(letraAtual <= letraAnterior) {
			std::cout << palavra << ": N" << std::endl;
			return;
		}
		letraAnterior = letraAtual;
	}

	std::cout << palavra << ": O" << std::endl;

}

int main() {

	int i, numOfWords;
	std::string word = "";

	std::cin >> numOfWords;

	for(i = 0; i < numOfWords; i++) {
		std::cin >> word;
		verificaPalavraOrdenada(word);
	}

	return 0;
}