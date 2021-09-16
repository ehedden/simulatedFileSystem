/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	MacroCommand class implementation - definitions for constructor, setParseStrategy, addCommand, 
	execute, and displayInfo methods
*/
#include "MacroCommand.h"
#include <vector>
#include "RenameParsingStrategy.h"
#include "CopyCommand.h"
#include "RemoveCommand.h"

using namespace std;
enum errorMacroCommand { notEnoughCommands = 2 };

MacroCommand::MacroCommand(AbstractFileSystem * files) : afs(files), myParsing(nullptr) {}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* myParse) {
	myParsing = myParse;
}

void  MacroCommand::addCommand(AbstractCommand* comm) {
	myCommand.push_back(comm);
}

int MacroCommand::execute(std::string myString) {
	vector<string> parsedString = myParsing->parse(myString);
	if (parsedString.size() != myCommand.size()) {
		return notEnoughCommands;
	}

	int i = 0;
	vector<AbstractCommand*>::iterator it = myCommand.begin();
	while (it != myCommand.end()) {
		if ((*it)->execute(parsedString.at(i)) != success) {
			return failure;
		}
		it++;
		i++;
	}
	
	return success;
}


void MacroCommand::displayInfo() {
	cout << "For composite commands, will be used for renaming. Executes the commands it is composed of in order" << endl;
}

