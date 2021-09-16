/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	SimpleFileFactory class declaration
*/
#pragma once
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(std::string fileName) override;
};
