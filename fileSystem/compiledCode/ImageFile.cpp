/*
(Lab 5) Ethan Hedden ethan.hedden@wustl.edu, Jacob Freund j.freund@wustl.edu, Lily Goldberg lilygoldberg@wustl.edu
	ImageFile class implementation - definitions for constructor, getSize, getName, write, append, read,
	accept, and clone methods
*/
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
class AbstractFileVisitor;
#include <cmath>

ImageFile::ImageFile(std::string fileName) : name(fileName), size(0) {}

unsigned int ImageFile::getSize() {
	return static_cast<unsigned int>(contents.size());
}

std::string ImageFile::getName() {
	return name;
}

int ImageFile::write(std::vector<char> pixels) {
	size = pixels[pixels.size() - 1] - 48;
	std::vector<char>::iterator it = pixels.begin();
	if (pixels.size() - 1 != size * size) { //size mismatch
		std::cout << "size error" << std::endl;
		return errorList::failure;
	}
	while (it != pixels.end()-1) {
		if(!(*it == ' ' || *it == 'X')){
			contents.clear();
			size = 0;
			return errorList::failure; //error
		}
		contents.push_back(*it);	
		it++;
	}
	return errorList::success;
}

int ImageFile::append(std::vector<char> vec) {
	return errorList::notSupported;
}

std::vector<char> ImageFile::read() {
	return contents;
}


void ImageFile::accept(AbstractFileVisitor* vis) {
	if (vis) {
		vis->visit_ImageFile(this);
	}
}

AbstractFile* ImageFile::clone(std::string newName) {
	ImageFile* newCopy = new ImageFile(newName+".img");
	newCopy->write(contents);
	return newCopy;
}
