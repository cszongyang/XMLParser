#include "XMLTree.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

XMLTree::XMLTree(){
	currentPosition = 0;
}

/* addNode
 * Adds a node to the tree
 *
 * @param nodeText - text of the node
 * @param nodeType - type of the node
 * @param parent - index to parent of the node. If -1, node is added to root list
 * @return - index to node just added
 */
unsigned int XMLTree::addNode(string nodeText, unsigned int nodeType, int parent){
	if(parent == -1){
		node newNode(currentPosition,nodeText,0,nodeType,-1);
		NodeList.push_back(newNode);
		RootList.push_back(currentPosition);
		currentPosition++;
	}
	else{
		node newNode(currentPosition,nodeText,NodeList[parent].depth+1,nodeType,parent);
		NodeList.push_back(newNode);
		NodeList[parent].children.push_back(currentPosition);
		currentPosition++;
	}
	return currentPosition-1;
}
unsigned int XMLTree::addNode(string nodeText, unsigned int nodeType, int parent,string SuperName,string subName){
	if(parent == -1){
		node newNode(currentPosition,nodeText,0,nodeType,-1,SuperName,subName);
		NodeList.push_back(newNode);
		RootList.push_back(currentPosition);
		currentPosition++;
	}
	else{
		node newNode(currentPosition,nodeText,NodeList[parent].depth+1,nodeType,parent,SuperName,subName);
		NodeList.push_back(newNode);
		NodeList[parent].children.push_back(currentPosition);
		currentPosition++;
	}
	return currentPosition-1;
}




/* printNode
 * prints all the information at the index to the console
 *
 *@param index - index to Node
 */
void XMLTree::printNode(unsigned int index){
	if(index > NodeList.size())
		cout<<"printNode Error::Index is out of bounds!"<<endl;
	else{
		cout<<"Node: "<<NodeList[index].nodeText<<endl;
		cout<<"Index = "<<NodeList[index].index<<endl;
		cout<<"Depth = "<<NodeList[index].depth<<endl;
		cout<<"Node Type = ";
		
		switch(NodeList[index].nodeType){
			case 0:
				cout<<"tag name"<<endl;
				break;
			case 1:
				cout<<"tag parameter"<<endl;
				break;
			case 2:
				cout<<"tag parameter value"<<endl;
				break;
			case 3:
				cout<<"value"<<endl;
				break;
			default:
				cout<<"Unknown"<<endl;
				break;
		}

		cout<<"Parent = "<<NodeList[index].parent<<endl;
		cout<<"Children = ";
		if(NodeList[index].children.size() != 0){
			for(unsigned int ii = 0; ii < NodeList[index].children.size()-1; ii++)
				cout<<NodeList[index].children[ii]<<", ";
			cout<<NodeList[index].children.back();
		}
		cout<<endl;
		cout<<"SuperName = "<<NodeList[index].superName<<endl;
		cout<<"SubName = "<<NodeList[index].subName<<endl;
		cout<<endl;
	}
}
// @param filePath - outputs to filePath
void XMLTree::printNode(unsigned int index, string filePath){
	if(index > NodeList.size())
		cout<<"printNode Error::Index is out of bounds!"<<endl;
	else{
		ofstream outFile;
		outFile.open(filePath, fstream::app);
		if(!outFile.good())
			cout<<"printNode Error::Cannot open "<<filePath<<endl;
		outFile<<"Node: "<<NodeList[index].nodeText<<endl;
		outFile<<"Index = "<<NodeList[index].index<<endl;
		outFile<<"Depth = "<<NodeList[index].depth<<endl;
		outFile<<"Node Type = ";
		
		switch(NodeList[index].nodeType){
			case 0:
				outFile<<"tag name"<<endl;
				break;
			case 1:
				outFile<<"tag parameter"<<endl;
				break;
			case 2:
				outFile<<"tag parameter value"<<endl;
				break;
			case 3:
				outFile<<"value"<<endl;
				break;
			default:
				outFile<<"Unknown"<<endl;
				break;
		}

		outFile<<"Parent = "<<NodeList[index].parent<<endl;
		outFile<<"Children = ";
		if(NodeList[index].children.size() != 0){
			for(unsigned int ii = 0; ii < NodeList[index].children.size()-1; ii++)
				outFile<<NodeList[index].children[ii]<<", ";
			outFile<<NodeList[index].children.back();
		}
		cout<<endl;
		outFile<<"SuperName = "<<NodeList[index].superName<<endl;
		outFile<<"SubName = "<<NodeList[index].subName<<endl<<endl;
		outFile.close();
	}
}




/* printTree
 * prints the whole tree
 *
 *@param filePath - prints tree to filePath
 */
void XMLTree::printTree(){
	for(unsigned int ii = 0; ii < RootList.size(); ii++){
		vector<unsigned int> PrintSpool;
		PrintSpool.push_back(RootList[ii]);
		while(PrintSpool.size() != 0){
			unsigned int index = PrintSpool.back();
			PrintSpool.pop_back();
			printNode(index);
			for(unsigned int jj = 0; jj < NodeList[index].children.size(); jj++)
				PrintSpool.push_back(NodeList[index].children[jj]);
		}
	}
}
void XMLTree::printTree(string filePath){
	for(unsigned int ii = 0; ii < RootList.size(); ii++){
		vector<unsigned int> PrintSpool;
		PrintSpool.push_back(RootList[ii]);
		while(PrintSpool.size() != 0){
			unsigned int index = PrintSpool.back();
			PrintSpool.pop_back();
			printNode(index,filePath);
			for(unsigned int jj = 0; jj < NodeList[index].children.size(); jj++)
				PrintSpool.push_back(NodeList[index].children[jj]);
		}
	}
}















