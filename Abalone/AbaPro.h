/**
 * Project Untitled
 */


#ifndef _ABAPRO_H
#define _ABAPRO_H
#include "direction.h"
#include "position.h"
#include <vector>
#include <map>
#include <string>
using namespace std;
class AbaPro {
public: 
    
/**
 * Parses String to get single command to execute move.
 */
vector<string> getCommand();
    
/**
 * @param source
 */
Direction getDirection(vector<string> source);
    
/**
 * @param moves
 */
void moveBall( map<vector<Position>, Direction> moves);
};

#endif //_ABAPRO_H
