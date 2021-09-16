/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	DisplayCommand class declaration
*/
#pragma once
#include "AbstractCommand.h"
#include"AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
private:
	AbstractFileSystem* afs;
	bool fileExists(std::string); //just a helper method for execute
};
