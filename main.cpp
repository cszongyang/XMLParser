#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Node.h"
#include "XMLTree.h"


using namespace std;

XMLTree myTree;

int main(){
	cout<<"Starting operations."<<endl<<endl;
	time_t startTime = time(NULL);

	
	unsigned int myNode = myTree.addNode("meep",1,-1);
	unsigned int mySecondNode = myTree.addNode("Boop", 2, myNode, "beep", "bloopbloop");
	myTree.addNode("loop",1,mySecondNode);
	myTree.addNode("sloop",1,mySecondNode);
	myTree.addNode("feep",0,myNode);

	myTree.printTree();
	myTree.printTree("C:\\Users\\The Happy Ultralisk\\Desktop\\treetest.txt");

	cout<<"All operations completed. Took "<<time(NULL) - startTime<<"s."<<endl;
	cin.ignore();
	cin.get();
	return 0;
}