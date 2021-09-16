/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	AbstractFileSystem class declaration and enum for file system error list
*/
#pragma once
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <string>
#include <set>

enum fileSystemErrorList { fileSystemSuccess, fileSystemFailure, fileSystemNotSupported, fileExists, nullpointer, fileNotOpen, fileDoesNotExist, fileOpen };

class AbstractFileSystem {
public:
	virtual int addFile(std::string filename, AbstractFile* abs) = 0;
	virtual int deleteFile(std::string fileName) = 0;
	virtual AbstractFile* openFile(std::string fileName) = 0;
	virtual int closeFile(AbstractFile* abs) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};

