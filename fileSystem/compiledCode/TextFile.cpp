/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	TextFile class implementation - definitions for constructor, read, write, append, getSize, getName,
	accept, and clone methods
*/
#include "TextFile.h"
#include "AbstractFileVisitor.h"
using namespace std;

TextFile::TextFile(string s) : name(s), contents() {};

vector<char> TextFile::read() {
	return contents;
}

int TextFile::write(std::vector<char> c) {
	contents = c;
	return 0;
}

int TextFile::append(std::vector<char> c) {
	std::vector<char>::iterator it = c.begin();
	while(it != c.end()) {
		contents.push_back(*it);
		++it;
	}
	return 0;
} 
 
unsigned int TextFile::getSize() {
	return static_cast<unsigned int>(contents.size());
}
 
std::string TextFile::getName() {
	return name;
}

void TextFile::accept(AbstractFileVisitor* sv) {
	if (sv) { (*sv).visit_TextFile(this); }
}

AbstractFile* TextFile::clone(std::string newName) {
	TextFile* newCopy = new TextFile(newName+".txt");
	newCopy->write(contents);
	return newCopy;
}