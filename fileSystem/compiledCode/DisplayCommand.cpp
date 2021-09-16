/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	DisplayCommand class implementation - definitions for constructor, fileExists, execute, and displayInfo methods
*/
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs) : afs(afs) {}

bool DisplayCommand::fileExists(std::string file) { //helper method
	set<string> setOfFiles = afs->getFileNames();
	set<string>::iterator it = setOfFiles.find(file);
	if (it == setOfFiles.end()) {
		return false;
	}
	return true;
}


int DisplayCommand::execute(std::string userArgs){					
	string file, extension; 
	istringstream ss(userArgs);
	if (userArgs.find(' ') != string::npos) {						//userArgs contains a space (contains -d), assume good formating
		if (ss >> file && ss >> extension && fileExists(file)) {
			if (extension == "-d") {
				AbstractFile* thisFile = afs->openFile(file);
				vector<char> file = thisFile->read();
				for (char c : file) {
					cout << c;
				}
				cout << endl;
				afs->closeFile(thisFile);
				return commandSuccess;
			}
			else {
				cout << "No such extension found." << endl;
				return commandFailure;
			}
		}
		else {
			return commandFailure;
		}
	}
	else {															//userArgs does not contain a space (no extension), assume good formating
		if (ss >> file && fileExists(file)) {
			AbstractFile* thisFile = afs->openFile(file);
			BasicDisplayVisitor* bdv = new BasicDisplayVisitor;
			thisFile->accept(bdv);
			afs->closeFile(thisFile);
			return commandSuccess;
		}
		else {
			cout << "File not found." << endl;
			return commandFailure;
		}
	}
}


 void DisplayCommand::displayInfo(){
	 cout << "Used to display a file, can be invoked with the command: ds <filename> [-d]" << endl;
 }


