/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	RenameParsingStrategy class implementation - definition for parse method
*/
#include"RenameParsingStrategy.h"
#include<vector>
#include<string>
#include<sstream>
using namespace std;


std::vector<std::string> RenameParsingStrategy::parse(std::string unsequenceCommands) {
	string existingFile, newNameNoExtensions;
	vector<std::string> parsed;
	if (unsequenceCommands.find(' ') != std::string::npos) { //so it one word long
		existingFile = unsequenceCommands.substr(0, unsequenceCommands.find(' '));
		newNameNoExtensions = unsequenceCommands.substr(unsequenceCommands.find(' ')+1);
	}
	else {
		return parsed;
	}

	parsed.push_back(existingFile + " " + newNameNoExtensions);
	parsed.push_back(existingFile);
	return parsed;
	
}