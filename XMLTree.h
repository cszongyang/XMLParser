#ifndef XMLTREE_H
#define XMLTREE_H

#include "Node.h"


class XMLTree{
private:
	
	vector<unsigned int> RootList;
	unsigned int currentPosition;


public:
	vector<node> NodeList;

	XMLTree();
	unsigned int addNode(string nodeText, unsigned int nodeType, int parent);
	unsigned int addNode(string nodeText, unsigned int nodeType, int parent,string SuperName,string subName);

	void printNode(unsigned int index);
	void printNode(unsigned int index, string filePath);

	void printTree();
	void printTree(string filePath);






};






#endif