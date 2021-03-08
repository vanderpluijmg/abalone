/**
 * Project Untitled
 */


#ifndef _PLAYER_H
#define _PLAYER_H
#include "ball.h"
#include <string>
#include "list"
using namespace std;
class Player {
public: 
    
List<Ball> getBalls();
    
int getCurBalls();
    
/**
 * @param value
 */
int setCurBalls(int value);
    
/**
 * Pseudo constructeur pour player.
 * @param color
 * @param name
 */
Player initPlayer(bool color, string name);
    
/**
 * @param position
 * @param direction
 */
Position move(Position position, Directions direction);
    
/**
 * @param position
 */
boolean validatePos(Position position);
    
/**
 * @param position
 * @param direction
 */
boolean validateMove(Position position, Directions direction);
private: 
    List<Ball> balls;
    Integer curBalls;
    String  name;
};

#endif //_PLAYER_H
