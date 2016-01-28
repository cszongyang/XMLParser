#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "XMLTree.h"
#include "Node.h"
#include <string>
#include <vector>

class XMLParser{
private:
	vector<XMLTree> trees;
	vector<string> XMLFiles;





public:
	XMLParser();

	unsigned int addPath(string newPath);





};













#endif