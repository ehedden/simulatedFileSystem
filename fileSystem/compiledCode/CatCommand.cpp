/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	CatCommand class implementation - definitions for constructor, fileExists, printContents, stringToVector
	execute, and displayInfo
*/
#include "CatCommand.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include<sstream>

enum catCommandErrors {catCommandFileNotFound = 1, catCommandWrongExtension = 2};

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* theFile) : afs(theFile) {}

bool CatCommand::fileExists(std::string file) { //helper method
	set<string> setOfFiles = afs->getFileNames();
	set<string>::iterator it = setOfFiles.find(file);
	if (it == setOfFiles.end()) {
		return false;
	}
	return true;
}

void printContents(vector<char> myVector) { //helper method
	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector.at(i);
	}
	cout << endl;
}

vector<char> stringToVector(string myString) {
	vector<char> result;
	for (int i = 0; i < myString.size(); i++) {
		result.push_back(myString.at(i));
	}
	return result;
}

int CatCommand::execute(std::string decision) {
	string file, extension;
	string userInputBuffer, userInput;
	if (decision.find(' ') == std::string::npos) { //so it one word long
		file = decision;
		extension = "";
	}
	else {
		file = decision.substr(0, decision.find(' '));
		extension = decision.substr(decision.find(' '));
	}
	
	if (!(fileExists(file))) {
		cout << "file not in file system" << endl;
		return catCommandFileNotFound;
	}

	if (extension == "") {
		AbstractFile* filePtr = afs->openFile(file);
		afs->closeFile(filePtr);
		cout << "Enter data you would like to write to the file.  Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
		getline(cin, userInputBuffer);
		while (userInputBuffer != ":wq" && userInputBuffer != ":q") {
			userInput += (userInputBuffer);
			getline(cin, userInputBuffer);
			if (userInputBuffer != ":wq" && userInputBuffer != ":q") {
				userInput += '\n';
			}
		}
		if (userInputBuffer == ":wq") {
			if (filePtr->write(stringToVector(userInput)) != success) {
				return failure;
			}
			return success;
		}
		else if (userInputBuffer == ":q") {
			return success;
		}

	}
	else if (extension.find("-a") != std::string::npos){ //so the it is "-a" or " -a" 
		AbstractFile* filePtr = afs->openFile(file);
		afs->closeFile(filePtr);
		cout << "Enter data you would like to write to the file.  Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
		printContents(filePtr->read());
		getline(cin, userInputBuffer);
		while (userInputBuffer != ":wq" && userInputBuffer != ":q") {
			userInput += (userInputBuffer);
			getline(cin, userInputBuffer);
			cout << userInputBuffer;
			if (userInputBuffer != ":wq" && userInputBuffer != ":q") {
				userInput += '\n';
			}
		}
		if (userInputBuffer == ":wq") {
			if (filePtr->append(stringToVector(userInput)) != success) {
				return failure;
			}
			return success;
		}
		else if (userInputBuffer == ":q") {
			return success;
		}
	}
	return catCommandWrongExtension;
}

void CatCommand::displayInfo() {
	cout << "For appending to a file, can be invoked with the command: cat <filename> [-a]" << endl;
	
}