/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	BasicDisplayVisitor class implementation - definitions for visit_TextFile and visit_ImageFile
*/

#include "BasicDisplayVisitor.h"
#include "math.h"
using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* myFile) {
	vector<char> helper = myFile->read();
	for (char myChar : helper) {
		std::cout << myChar;
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* myFile) {
	int arraySize = myFile->getSize();
	std::vector<char> file = myFile->read();
	for (int i = 0; i < arraySize; i++) {
		if ((i % static_cast<int>(sqrt(arraySize)) == 0 && (i != 0))) {
			std::cout << std::endl;
		}
		std::cout << file[i];
	}
	std::cout << endl;
}