/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	ImageFile class declaration
*/
#pragma once
#include"AbstractFile.h"

class ImageFile : public AbstractFile {
public:
	ImageFile(std::string);
	unsigned int getSize() override;
	std::string getName() override; 
	int write(std::vector<char>) override;
	int append(std::vector<char>) override;
	std::vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string);
private:
	std::string name;
	std::vector<char> contents;
	char size;
};