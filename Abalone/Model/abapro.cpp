#include "abapro.h"
#include "direction.h"
#include "cstring"
#include <cctype>
#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <stdlib.h>
#include <cctype>


void AbaPro::split(const std::string& move, const std::string& space, std::vector<std::string>& response){
    size_t start, end = 0;
    while (end < move.size()) {
        start = end;
        while (start < move.size() && (space.find(move[start]) != std::string::npos)) {
            start++;
        }
        end = start;
        while (end < move.size() && (space.find(move[end]) == std::string::npos)) {
            end++;
        }
        if (end-start != 0) {
            response.push_back(std::string(move, start, end-start));
        }
    }
}

moveUtils AbaPro::getCommand(std::string move)
{
    moveUtils mv;
    if (move.size()<=6){
        std::vector<std::string> command;
        for (int i = 0; i<(int)move.size();i++)
            if (i==2 || i==5)
                move.insert(i, " ");
        AbaPro::split(move, " ", command);
        if (command.size()==2){
            AbaPro::addPositionUtils(mv,getPosition(command[0]));
            mv.dir = getDirection(mv.pos1, getPosition(command[1]));
        } else {
             AbaPro::addPositionUtils(mv,getPosition(command[0]));
             AbaPro::addPositionUtils(mv,getPosition(command[1]));
             mv.dir = getDirection(mv.pos1, getPosition(command[2]));
        }
        return mv;
    }
    else {throw "Sorry you move is not valid";}
}

Position AbaPro::getPosition(const std::string command){
    char row = command[0];
    int col = (command[1] - '0') - 1;
    switch (row){
    case 'I': return Position(col--,0);
    case 'H': return Position(col--,1);
    case 'G': return Position(col--,2);
    case 'F': return Position(col--,3);
    case 'E': return Position(col--,4);
    case 'D': return Position(col--,5);
    case 'C': return Position(col--,6);
    case 'B': return Position(col--,7);
    case 'A': return Position(col--,8);
    }
    return Position();
}

void AbaPro::addPositionUtils(moveUtils& a, Position p){
    if (a.pos1.getX()==-5&&a.pos1.getY()==-5)
            Position::setPosition(a.pos1,p);
    else
            Position::setPosition(a.pos2,p);

}
//Does not work
Direction AbaPro::getDirection(Position init, Position final){
    return Direction((init.getX()-final.getX()),(init.getY()-final.getY()));
}




