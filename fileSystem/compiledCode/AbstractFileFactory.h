/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	AbstractFileFactory class declaration
*/
#pragma once
#include "AbstractFile.h"
#include <string>

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string) = 0;
};