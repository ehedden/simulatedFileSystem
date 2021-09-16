/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
    RemoveCommand class implementation - definitions for constructor, execute, and displayInfo methods
*/
#include"RemoveCommand.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* afs) : files(afs) {}

int RemoveCommand::execute(std::string fileName) {
    return files->deleteFile(fileName);
}

void RemoveCommand::displayInfo() {
    std::cout << "rm removes a file from the file system, and can be invoked with the command: rm <filename>" << std::endl;
}

