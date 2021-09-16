/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	CommandPrompt class implementation - definitions for constructor, setFileSystem, setFileFactory, addCommand,
	listCommands, prompt, and run methods
*/
#include "CommandPrompt.h"
#include<string>
#include <sstream>
using namespace std;

CommandPrompt::CommandPrompt() : fileSystem(nullptr), fileFactory(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* afs){
	fileSystem = afs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* aff){
	fileFactory = aff;
}

int CommandPrompt::addCommand(std::string myString, AbstractCommand* ac){
	map<std::string, AbstractCommand*>::iterator it;
	it = objects.find(myString);

	if (it == objects.end()) { //so the element is not already in the map 
		objects.insert({ myString, ac });
		return errorsForCommandPrompt::successForCommandPrompt;
	}
	else {
		return errorsForCommandPrompt::addCommandError;
	}
}

void CommandPrompt::listCommands() {
	for (auto it = objects.cbegin(); it != objects.cend(); ++it) {
		std::cout << it->first << endl;
    }
	
}

std::string CommandPrompt::prompt() {
		cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
		cout << "$  ";
		string helper;
		getline(cin, helper); 
		return helper;
}

int CommandPrompt::run() {
	while (true) {
		string userInput = prompt();
		if (userInput == "q") {
			return errorsForCommandPrompt::userQuit;
		}
		else if (userInput == "help") {
			listCommands();
		}
		else {
			bool isOneWord = true;
			for (int i = 0; i < userInput.size(); i++) {
				if (userInput[i] == ' ') {
					isOneWord = false;
				}
			}

			if (isOneWord) {
				map<std::string, AbstractCommand*>::iterator it;
				it = objects.find(userInput);
				if (it != objects.end()) { //so the command was found
					if (it->second->execute("") != success) { //error in execution
						cout << "User command returns an error" << endl;
					}
				}
				else { //so the command was not found
					cout << "User command was not found" << endl;
				}
			} 
			else { //input longer than one word


				std::istringstream iss(userInput);
				std::string helpString; //really the first string
				std::string commandString;
				std::string remainingString;
				if (iss >> helpString && helpString == "help") {
					if (iss >> commandString && objects.find(commandString) != objects.end()) {	//can find commandString in map AND help 
						objects.find(commandString)->second->displayInfo();
					}
					else {
						cout << "Command does not exist." << endl;		//cannot find command string in map			
					}

				}
				else if (objects.find(helpString) != objects.end()) { //fist word not help and the first word is a command
					getline(iss, remainingString);
					remainingString = remainingString.substr(1);
					map<std::string, AbstractCommand*>::iterator it = objects.find(helpString); //possibly doesn't find command string
					int res = it->second->execute(remainingString);
					if (res != success) { //error
						cout << "User command returns an error" << endl;
					}
				}
				else { //first word is garbage - neither help nor a command
					cout << "Command does not exist" << endl;
				}

			}
		}
	}
}
