/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	TouchCommand class implementation - definitions for constructor, displayInfo, and execute methods
*/
#include "TouchCommand.h"
#include "PasswordProxy.h"
#include<sstream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff) : absFileSystem(fs), absFileFactory(ff) {}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <filename> [-p]" << endl;
}

int TouchCommand::execute(string userInput) {
	
	bool isOneWord = true;
	for (int i = 0; i < userInput.size(); i++) {
		if (userInput[i] == ' ') {
			isOneWord = false;
		}
	}

	if (isOneWord) { //not a password protected file
		AbstractFile* myFile = (*absFileFactory).createFile(userInput);
		if (myFile != nullptr) { //so the file was created successfully
			if (absFileSystem->addFile(userInput, myFile) == success) {
				return commandSuccess;
			}
			else {
				return executeErrorFileAddition;
			}
		}
		else {
			return executeErrorFileCreation;
		}

		return commandFailure;
	}
	
	istringstream iss(userInput);
	string fileName;
	string passwordOption;

	if (iss >> fileName && iss >> passwordOption && passwordOption == "-p") {
		
		std::cout << "What is the password?" << endl;
		std::string password;
		std::cin >> password;
		
		AbstractFile* myFile = (*absFileFactory).createFile(fileName);
		PasswordProxy* fileProxy = new PasswordProxy(myFile, password); 

		if (myFile != nullptr) { //so the file was created successfully
			if (absFileSystem->addFile(fileName, fileProxy) == success) {
				return commandSuccess;
			}
			else {
				return executeErrorFileAddition;
			}
		}
		else {
			return executeErrorFileCreation;
		}

		return commandFailure;
	}
	return commandFailure;

}