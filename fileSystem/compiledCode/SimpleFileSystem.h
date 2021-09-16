/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	SimpleFileSystem class declaration
*/
#pragma once
#include"AbstractFileSystem.h"
#include<map>
#include<set>
#include<string>

class SimpleFileSystem : public AbstractFileSystem {
public:
	int addFile(std::string filename, AbstractFile* abs) override;
	int deleteFile(std::string fileName) override;
	AbstractFile* openFile(std::string fileName) override;
	int closeFile(AbstractFile* abs) override;
	std::set<std::string> getFileNames() override;
private:
	std::map<std::string, AbstractFile*> files;
	std::set <AbstractFile*> openFiles;
};