/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	BasicGrepVisitor class declaration
*/
#pragma once

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicGrepVisitor : public AbstractFileVisitor {
public:
	BasicGrepVisitor(std::string); 
	void visit_TextFile(TextFile*) override;
	void visit_ImageFile(ImageFile*) override;
private:
	std::string stringToSearchFor;
};