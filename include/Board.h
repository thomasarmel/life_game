#ifndef LIFE_GAME_BOARD_H
#define LIFE_GAME_BOARD_H

#include <iosfwd>
#include <vector>
#include "ObservableBoard.h"

class Board : public ObservableBoard
{
public:
    Board(size_t boardSize=100);
    virtual void fillWithRandom();
    virtual void reset();
    void toNext();
    const void *rawData();
    size_t getBoardSize() const;
    void pauseSimulation(bool pause=true);
    bool isSimulationPaused() const;

protected:
    virtual void calculateNext();
    const unsigned short numberOfCellNeighbours(short x, short y, short stopAt=8);

    size_t m_boardSize;
    std::vector<unsigned char> m_board, m_tmpBoard;
    bool m_simulationIsPAused = false;
};

#endif //LIFE_GAME_BOARD_H
