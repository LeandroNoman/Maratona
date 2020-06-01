#include <iostream>
#include <string>
#include <algorithm>

struct Student {
	int problemsSolved;
	std::string name;
};

bool higherName(Student s1, Student s2) {
	int size;
	bool higherName;

	if(s1.name.size() < s2.name.size()) {
		size = s1.name.size();
		higherName = false;
	}
	else {
		size = s2.name.size();
		higherName = true;
	}

	for(int i = 0; i < size; i++) {
		if(s1.name[i] == s2.name[i]) {
			continue;
		}
		if(s1.name[i] > s2.name[i]) {
			return true;
		}
		else {
			return false;
		}
	}

	return higherName;
}

bool studentComparison(Student s1, Student s2) {
	if(s1.problemsSolved < s2.problemsSolved) {
		return true;
	}
	else if(s1.problemsSolved > s2.problemsSolved) {
		return false;
	}
	else {
		return higherName(s1, s2);
	}
}

int main() {

	int i, numOfStudents, currentInstance;
	Student students[100];

	currentInstance = 1;
	while(std::cin >> numOfStudents) {
		
		for(i = 0; i < numOfStudents; i++) {
			std::cin >> students[i].name;
			std::cin >> students[i].problemsSolved;
		}

		std::sort(students, students + numOfStudents, studentComparison);

		std::cout << "Instancia " << currentInstance << std::endl;
		std::cout << students[0].name << std::endl << std::endl;

		currentInstance++;
	}
	
	return 0;
}