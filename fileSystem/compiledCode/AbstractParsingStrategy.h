/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	AbstractParsingStrategy class declaration
*/

#pragma once
#include<string>
#include<vector>

class AbstractParsingStrategy {
public:	
	virtual std::vector<std::string> parse(std::string) = 0;
};