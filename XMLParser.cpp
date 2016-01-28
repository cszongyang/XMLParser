#include "XMLParser.h"

using namespace std;


XMLParser::XMLParser(){


}

/* addPath
 * adds a XML file path to the register
 *
 *@param newPath - new path to add
 */
unsigned int XMLParser::addPath(string newPath){
	XMLFiles.push_back(newPath);
	return XMLFiles.size() - 1;
}
