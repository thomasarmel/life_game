#ifndef LIFE_GAME_BOARD_H
#define LIFE_GAME_BOARD_H

#include <iosfwd>
#include <vector>
#include <future>
#include "ObservableBoard.h"

class Board : public ObservableBoard
{
public:
    Board();
    Board(size_t boardSize);
    void setSize(size_t boardSize);
    virtual void fillWithRandom();
    virtual void reset();
    void toNext();
    void operator()();
    const void *rawData();
    size_t getBoardSize() const;
    void pauseSimulation(bool pause=true);
    bool isSimulationPaused() const;
    Board & operator=(Board &other);

protected:
    virtual void calculateNext();
    const unsigned short numberOfCellNeighbours(short x, short y, short stopAt=8);

    size_t m_boardSize;
    std::vector<unsigned char> m_board, m_tmpBoard;
    std::vector<std::future<void>> m_nextCalculatorFuturesList;
    bool m_simulationIsPAused = false;
};

#endif //LIFE_GAME_BOARD_H
