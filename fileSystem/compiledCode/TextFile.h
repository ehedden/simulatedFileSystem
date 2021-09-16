/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	TextFile class declaration
*/
#pragma once
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	TextFile(std::string s);
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
private:
	std::vector<char> contents;
	std::string name;
};