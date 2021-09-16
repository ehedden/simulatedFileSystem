/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	TouchCommand class declaration
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

enum touchCommandErrors { executeErrorFileCreation = 1, executeErrorFileAddition };
class TouchCommand : public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual int execute(std::string) override;
	virtual void displayInfo() override;
private:
	AbstractFileSystem * absFileSystem;
	AbstractFileFactory* absFileFactory;
};