/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	AbstractCommand class declaration and enum for command success
*/

#pragma once
#include<string>

enum CommandSuccessValues { commandSuccess, commandFailure };

class AbstractCommand {
public:	
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
};
