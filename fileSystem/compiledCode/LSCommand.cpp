/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	LSCommand class implementation - definitions for constructor, execute, and displayInfo methods
*/
#include"LSCommand.h"
#include<iostream>
#include<iomanip>
#include "MetadataDisplayVisitor.h"
LSCommand::LSCommand(AbstractFileSystem* fs) : files(fs) {} 

int LSCommand::execute(std::string userInput) {
	enum filesPerLine { filesPerLine = 2};
	std::set<std::string> names = files->getFileNames();
	int newLine = 1;
	if (userInput == "") {	
		for (std::string fileName : names) {
			std::cout << std::setw(20) << ' ' << fileName;

			if (newLine == filesPerLine) {
				std::cout << std::endl;
				newLine = 1;
			}
			else {
				newLine++;
			}
		}	
		std::cout << std::endl;
		return commandSuccess;
	}
	else if(userInput == "-m"){
		for(std::string fileName : names) {
			AbstractFile * thisFile = files->openFile(fileName);
			MetadataDisplayVisitor* metaVs = new MetadataDisplayVisitor();
			thisFile->accept(metaVs);
			files->closeFile(thisFile);
		}
		return commandSuccess;
	}
	else {
		return commandFailure;
	}
}


void LSCommand::displayInfo() {
	std::cout << "Use \"ls\" to print out the files in a file system.  Use \"ls -m\" to print out the meta data for all the files" << std::endl;
}