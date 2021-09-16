/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	SimpleFileSystem class implementation - definitions for addFile, openFile, closeFile, deleteFile, and getFileNames
*/
#include"SimpleFileSystem.h"


int SimpleFileSystem::addFile(std::string filename, AbstractFile* abs) {
	std::map<std::string, AbstractFile*>::iterator it = files.find(filename);
	if(it != files.end()){
		return fileSystemErrorList::fileExists;
	}
	if(abs == nullptr){
		return fileSystemErrorList::nullpointer;		
	}

	files.insert({ filename, abs });
	return fileSystemErrorList::fileSystemSuccess;


}


AbstractFile* SimpleFileSystem::openFile(std::string fileName) {
	std::map<std::string, AbstractFile*>::iterator it = files.find(fileName);
	if(it == files.end()){
		return nullptr;
	}
	std::set<AbstractFile*>::iterator itSet = openFiles.find(files[fileName]);
	if (itSet != openFiles.end()) {  //it is open already
		return nullptr;
	}
	openFiles.insert(files[fileName]);
	return files[fileName];
}

int SimpleFileSystem::closeFile(AbstractFile* abs) {
	std::set<AbstractFile*>::iterator it = openFiles.find(abs);
	if(it != openFiles.end()) { //it is open already
		openFiles.erase(abs);
		return fileSystemErrorList::fileSystemSuccess;
	}
	return fileSystemErrorList::fileNotOpen;
}

int SimpleFileSystem::deleteFile(std::string fileName) {
	std::map<std::string, AbstractFile*>::iterator it = files.find(fileName);
	if(it != files.end()) { //the file exists
		std::set<AbstractFile*>::iterator itSet = openFiles.find(files[fileName]);
		if (itSet == openFiles.end()) {  //not open already
			delete files[fileName];
			files.erase(fileName);
			return fileSystemErrorList::fileSystemSuccess;
		}
		return fileSystemErrorList::fileOpen;
	}
	//so the file does not exist
	return fileSystemErrorList::fileDoesNotExist;

}

std::set<std::string> SimpleFileSystem::getFileNames() {
	std::set<std::string> names;
	for (const auto& file : files) {
		names.insert(file.first);
	}
	return names;
}
