/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	GrepCommand class declaration
*/
#pragma once
#include"AbstractCommand.h"
#include"AbstractFileSystem.h"
#include"BasicGrepVisitor.h"

class GrepCommand : public AbstractCommand {
public:
	GrepCommand(AbstractFileSystem*);
	int execute(std::string) override;
	void displayInfo() override;
private:
	AbstractFileSystem* files;
};