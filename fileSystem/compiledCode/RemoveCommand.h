/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	RemoveCommand class declaration
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
public:	
	RemoveCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* files;
};
