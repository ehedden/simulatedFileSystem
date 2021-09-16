/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	GrepCommand class implementation - definitions for constructor, execute, and displayInfo methods
*/
#include"GrepCommand.h"
#include <sstream>

GrepCommand::GrepCommand(AbstractFileSystem* afs) : files(afs) {}

//execute will search for the first string in userInput before a space
int GrepCommand::execute(std::string userInput) {
	
	std::istringstream iss(userInput);
	std::string stringToSearchFor;
	
	if (iss >> stringToSearchFor) {
		std::set<std::string> fileNames = files->getFileNames();
		
		for (std::string fileName : fileNames) {
			AbstractFile* thisFile = files->openFile(fileName);
			BasicGrepVisitor* bgv = new BasicGrepVisitor(stringToSearchFor);
			thisFile->accept(bgv);
			files->closeFile(thisFile);
		}
		return commandSuccess;
	}
	return commandFailure;
}


void GrepCommand::displayInfo() {
	std::cout << "Searches text files for inputted string, can be invoked with the command: grep <string_to_search_for>" << std::endl;
}

