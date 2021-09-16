/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	LSCommand class declaration
*/
#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"

class LSCommand : public AbstractCommand {
public:	
	LSCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* files;
};