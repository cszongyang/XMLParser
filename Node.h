#ifndef NODE_H
#define NODE_H

#include<string>
#include<vector>
using namespace std;

class node{
public:
	unsigned int index;		//index to node from tree
	string nodeText;		//name or value of node
	unsigned int depth;		//current depth of the node/indent level
	unsigned int nodeType;		//Type of node: 0 = tag name, 1 = tag parameter 2 = tag parameter value, 3 = value
	int parent;  //index to parent node. If -1, then its a root node
	vector<unsigned int> children;	//list of indices of children
	string superName;	//for tags with a subname
	string subName;	

	node(unsigned int index, string nodeText,unsigned int depth, unsigned int nodeType,int parent);
	node(unsigned int index, string nodeText,unsigned int depth, unsigned int nodeType,int parent, string superName, string subName);
	void addLink(unsigned int newLink);
};











#endif