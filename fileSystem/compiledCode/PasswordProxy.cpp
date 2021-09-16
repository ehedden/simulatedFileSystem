/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	PasswordProxy class implementation - definitions for constructor, destructor, passwordPrompt, isPassword,
	read, write, append, getSize, getName, accept, and clone methods 
*/
#include "PasswordProxy.h"

using namespace std; 

enum errorListPP {writeError = 1, appendError = 2};

PasswordProxy::PasswordProxy(AbstractFile* file, std::string name) : mainSubject(file), password(name) {}

PasswordProxy::~PasswordProxy() {
	delete mainSubject;
}

std::string PasswordProxy::passwordPrompt() {
	string password;
	cout << "Enter your password:   ";
	cin >> password;
	return password;
}

bool PasswordProxy::isPassword(std::string possiblePassword) {
	if (possiblePassword == password) {
		return true;
	}
	return false;
}

std::vector<char> PasswordProxy::read() {
	if(isPassword(passwordPrompt())){
		return mainSubject->read();
	}
	else{
		vector<char>empty;
		return empty;
	}
}

int PasswordProxy::write(std::vector<char> file) {
	if (isPassword(passwordPrompt())) {
		return mainSubject->write(file);
	}
	else {
		return errorListPP::writeError;
	}
}

int PasswordProxy::append(std::vector<char> file) {
	if (isPassword(passwordPrompt())) {
		return mainSubject->append(file);
	}
	else {
		return errorListPP::appendError;
	}
}

unsigned int PasswordProxy::getSize() {
	return mainSubject->getSize();
}

std::string PasswordProxy::getName() {
	return mainSubject->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* vs) {
	if (isPassword(passwordPrompt())) {
		mainSubject->accept(vs);
	}
}

AbstractFile* PasswordProxy::clone(std::string newName) {
	PasswordProxy* newCopy = new PasswordProxy(mainSubject->clone(newName), password);
	return newCopy;
}