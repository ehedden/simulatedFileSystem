/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	BasicGrepVisitor class implementation - definitions for constructor, visit_TextFile, and visit_ImageFile
*/
#include"BasicGrepVisitor.h"

BasicGrepVisitor::BasicGrepVisitor(std::string s) : stringToSearchFor(s) {}

void BasicGrepVisitor::visit_TextFile(TextFile* textFile) {
	//search the text file for the stringToSearchFor and print the name of the file if it is found
	std::vector<char> contents = textFile->read();
	std::string contentsString(contents.begin(), contents.end());
	std::size_t found = contentsString.find(stringToSearchFor);
	if (found != std::string::npos) {
		std::cout << textFile->getName() << std::endl;
	}
}

void BasicGrepVisitor::visit_ImageFile(ImageFile* imageFile) {} //do nothing