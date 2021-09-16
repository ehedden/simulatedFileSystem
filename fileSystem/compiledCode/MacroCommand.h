/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	MacroCommand class declaration
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem *);
	int execute(std::string) override;
	void displayInfo() override;
	void setParseStrategy(AbstractParsingStrategy *);
	void addCommand(AbstractCommand*);
private:
	std::vector<AbstractCommand*> myCommand;
	AbstractParsingStrategy* myParsing;
	AbstractFileSystem * afs;
};