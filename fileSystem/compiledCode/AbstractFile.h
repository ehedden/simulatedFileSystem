/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	AbstractFile class declaration and enum for error list
*/
#pragma once
#include <vector>
#include <string>
#include <iostream>

class AbstractFileVisitor;

enum errorList {success, failure, notSupported};

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual ~AbstractFile() = default;
	virtual AbstractFile* clone(std::string) = 0;
};