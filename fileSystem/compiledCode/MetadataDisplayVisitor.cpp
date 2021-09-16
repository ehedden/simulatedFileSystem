/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	MetadataDisplayVisitor class implementation - definitions for visit_TextFile and visit_ImageFile methods
*/
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* myFile) {
	cout << std::setw(20) << (*myFile).getName() << " text " << (*myFile).getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile * myFile){
	cout << setw(30) << (*myFile).getName() << " image " << (*myFile).getSize() << endl;
}