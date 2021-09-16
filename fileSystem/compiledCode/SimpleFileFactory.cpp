/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	SimpleFileFactory class implementation - definition for createFile method
*/
#include"SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFileSystem.h"

AbstractFile* SimpleFileFactory::createFile(std::string fileName) {
	
	if (fileName.find(".txt") != std::string::npos) { //so it's a text file
		return new TextFile(fileName);
	}
	if (fileName.find(".img") != std::string::npos) { //so it's an image file
		return new ImageFile(fileName);
	}
	return 0;
}






/*  Previously in SimpleFileSystem.cpp
int SimpleFileSystem::createFile(std::string fileName) {
	if (fileName.find(".txt") != std::string::npos) { //so it's a text file
		return addFile(fileName, new TextFile(fileName));
	}
	if (fileName.find(".img") != std::string::npos) { //so it's an image file
		return addFile(fileName, new ImageFile(fileName));
	}
	return fileSystemErrorList::fileSystemFailure;
}
*/