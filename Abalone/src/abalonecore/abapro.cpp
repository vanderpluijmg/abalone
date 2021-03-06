#include "abapro.h"

bool AbaPro::checkCommandSyntaxValidity(const std::string& command)
{
    if( (1<=(command[1]-'0') && (command[1]-'0')<=9))
        if('A'<=command[0] && command[0]<='I')
            return true;
    return false;
}

void AbaPro::commandTok(std::string& move,  std::vector<std::string>& response)
{
    if (move.size()<=6)
    {
        for (int i = 0; i<(int)move.size();i++)
            if (i==2 || i==5)
                move.insert(i, " ");
    }
    size_t start, end = 0;
    std::string space =" ";
    while (end < move.size())
    {
        start = end;
        while (start < move.size() && (space.find(move[start]) != std::string::npos))
        {
            start++;
        }
        end = start;
        while (end < move.size() && (space.find(move[end]) == std::string::npos))
        {
            end++;
        }
        if (end-start != 0)
        {
            response.push_back(std::string(move, start, end-start));
        }
    }
}

MoveUtils AbaPro::getCommand(std::string move)
{
    MoveUtils mvUtils;
    std::vector<std::string> command;
    AbaPro::commandTok(move, command);
    if (checkPositionsInCommand(command))
    {
        if (command.size()==2){
            Position pos = getPosition(command[0]);
            Direction dir = getDirection(pos, getPosition(command[1]));
            AbaPro::addPosAndDirToUtils(mvUtils,pos,dir);

        } else {
            Position pos1 = getPosition(command[0]);
            Position pos2 = getPosition(command[1]);
            Direction dir = getDirection(pos1, getPosition(command[2]));
            AbaPro::add2PosAndDirToUtils(mvUtils,pos1,pos2,dir);
        }
        return mvUtils;
    }
    else mvUtils.dir=Direction(0,0);
    return mvUtils;
}

bool AbaPro::checkPositionsInCommand(const std::vector<std::string> &command)
{
    bool check = true;
    for (auto& x : command){
        check = checkCommandSyntaxValidity(x);
        if(!check) return check;
    }
    return check;
}

void AbaPro::addPosAndDirToUtils (MoveUtils& a, Position p,Direction dir)
{
    a.pos1.setPosition(p);
    a.dir.setDirection(dir);
}

void AbaPro::add2PosAndDirToUtils (MoveUtils& a, Position p1, Position p2,Direction dir)
{
    a.pos1.setPosition(p1);
    a.pos2.setPosition(p2);
    a.dir.setDirection(dir);
}

Position AbaPro::getPosition(const std::string& command)
{
    if(checkCommandSyntaxValidity(command)){
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
    }
    throw "erreur with translating user given position into a valid position";
}

Direction AbaPro::getDirection(Position init, Position final)
{
    Direction end = Direction((final.getX()-init.getX()),(final.getY()-init.getY()));
    if(end.getDeltaX()==0 && end.getDeltaY()==0){
        return NONE;
    }
    return end;
}

std::string AbaPro::posToAbaString(point<int> pos){
    std::string posStr = "";
    char row = pos.second;
    int col = pos.first + 1;
    switch (row){
    case 0: {posStr+="I";posStr+=std::to_string(col);return posStr;};
    case 1: {posStr+="H";posStr+=std::to_string(col);return posStr;};
    case 2: {posStr+="G";posStr+=std::to_string(col);return posStr;};
    case 3: {posStr+="F";posStr+=std::to_string(col);return posStr;};
    case 4: {posStr+="E";posStr+=std::to_string(col);return posStr;};
    case 5: {posStr+="D";posStr+=std::to_string(col);return posStr;};
    case 6: {posStr+="C";posStr+=std::to_string(col);return posStr;};
    case 7: {posStr+="B";posStr+=std::to_string(col);return posStr;};
    case 8: {posStr+="A";posStr+=std::to_string(col);return posStr;};
    }
    return "";
}

