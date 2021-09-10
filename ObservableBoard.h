#ifndef LIFE_GAME_OBSERVABLEBOARD_H
#define LIFE_GAME_OBSERVABLEBOARD_H

#include "BoardObserver.h"

class BoardObserver;

class ObservableBoard
{
public:
    void addObserver(BoardObserver *observer);
    void updateAllObservers();
protected:
    std::vector<BoardObserver*> m_observers;
};


#endif //LIFE_GAME_OBSERVABLEBOARD_H
