/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	CopyCommand class implementation - definitions for constructor, fileExists, execute, and displayInfo
*/
#include"CopyCommand.h"
#include <string>
#include <iostream>

using namespace std;
enum CopyCommandErrors { notEnoughCommandLines = 1, fileDoesNotExists = 2};

CopyCommand::CopyCommand(AbstractFileSystem* files) : afs(files) {} 

bool CopyCommand::fileExists(std::string file) { //helper method
	set<string> setOfFiles = afs->getFileNames();
	set<string>::iterator it = setOfFiles.find(file);
	if (it == setOfFiles.end()) {
		return false;
	}
	return true;
}



//use prototype pattern because objects should be in charge of creating their own copies (especially if I
// can't get private member variables)
int CopyCommand::execute(std::string command) {
	string fileToCopy, newFileName;
	if (command.find(' ') == std::string::npos) { //so it one word long
		cout << "Invalid command line arguments" << endl;
		return notEnoughCommandLines;
	}
	else {
		fileToCopy = command.substr(0, command.find(' '));
		newFileName = command.substr(command.find(' ')+1);
	}

	if (!(fileExists(fileToCopy))) {
		return fileDoesNotExist;
	}
	AbstractFile* filePtr = afs->openFile(fileToCopy);
	afs->closeFile(filePtr);

	AbstractFile* newFile = filePtr->clone(newFileName);
	if (afs->addFile(newFile->getName(), newFile) == success) {
		return success;
	}
	delete newFile;
	return failure;
}

void CopyCommand::displayInfo() {
	cout << "To copy files, can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>" << endl;
}