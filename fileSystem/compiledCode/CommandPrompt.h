/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	CommandPrompt class declaration and enum for command prompt success
*/

#pragma once
#include"AbstractCommand.h"
#include"AbstractFileSystem.h"
#include"AbstractFileFactory.h"
#include<map>

enum errorsForCommandPrompt { successForCommandPrompt = 0, addCommandError = 1, userQuit = 2, runError = 3 };

class CommandPrompt {
public:
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();
private:
	std::map<std::string, AbstractCommand*> objects;
	AbstractFileSystem * fileSystem;
	AbstractFileFactory* fileFactory;
};