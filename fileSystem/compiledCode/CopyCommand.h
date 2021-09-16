/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	CopyCommand class declaration
*/
#pragma once
#include"AbstractCommand.h"
#include"SimpleFileSystem.h"

class CopyCommand : public AbstractCommand {
public:	
	CopyCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
	bool fileExists(std::string); //helper
private:
	AbstractFileSystem* afs;
};
