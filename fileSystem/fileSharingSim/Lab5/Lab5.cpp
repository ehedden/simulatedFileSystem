// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode\LSCommand.h"
#include "../../SharedCode\RemoveCommand.h"
#include "../../SharedCode\CatCommand.h"
#include "../../SharedCode\DisplayCommand.h"
#include "../../SharedCode\CopyCommand.h"
#include "../../SharedCode\MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include"../../SharedCode/BasicGrepVisitor.h"
#include"../../SharedCode/GrepCommand.h"
using namespace std;

int main()
{
	//for the last bullet point in #8 on renaming  (make sure to delete commands after added to avoid memory leaks)
	//won't all these objects be deleted when main returns?
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	MacroCommand* mc = new MacroCommand(sfs);
	RenameParsingStrategy* rps = new RenameParsingStrategy;
	AbstractCommand* cpc = new CopyCommand(sfs);
	AbstractCommand* rmc = new RemoveCommand(sfs);
	AbstractCommand* lsc = new LSCommand(sfs);
	AbstractCommand* cat = new CatCommand(sfs);
	AbstractCommand* tch = new TouchCommand(sfs, sff);
	AbstractCommand* dsp = new DisplayCommand(sfs);
	AbstractCommand* grep = new GrepCommand(sfs);
	
	CommandPrompt* cmp = new CommandPrompt();
	cmp->setFileFactory(sff);
	cmp->setFileSystem(sfs);

	cmp->addCommand("rn",mc);
	mc->addCommand(cpc);
	mc->addCommand(rmc);
	mc->setParseStrategy(rps);
	
	cmp->addCommand("ls", lsc);
	cmp->addCommand("cp", cpc);
	cmp->addCommand("rm", rmc);
	cmp->addCommand("cat", cat);
	cmp->addCommand("touch", tch);
	cmp->addCommand("ds", dsp);	
	cmp->addCommand("grep", grep);
	cmp->run();
	cout << "End Program." << endl;
	return 0;
	

}


