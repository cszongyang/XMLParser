#include "Node.h"
#include <string>
#include <vector>

using namespace std;

node::node(unsigned int index, string nodeText,unsigned int depth, unsigned int nodeType,int parent){
	this->index = index;
	this->nodeText = nodeText;
	this->depth = depth;
	this->nodeType = nodeType;
	this->parent = parent;
	superName = "";
	subName = "";

}

node::node(unsigned int index, string nodeText,unsigned int depth, unsigned int nodeType,int parent, string superName, string subName){
	this->index = index;
	this->nodeText = nodeText;
	this->depth = depth;
	this->nodeType = nodeType;
	this->parent = parent;
	this->superName = superName;
	this->subName = subName;

}

void node::addLink(unsigned int newLink){
	children.push_back(newLink);
}