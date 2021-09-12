#ifndef LIFE_GAME_BOARDOBSERVER_H
#define LIFE_GAME_BOARDOBSERVER_H

#include "ObservableBoard.h"

class ObservableBoard;

class BoardObserver
{
public:
    virtual void update(ObservableBoard *observable) = 0;
};


#endif //LIFE_GAME_BOARDOBSERVER_H
