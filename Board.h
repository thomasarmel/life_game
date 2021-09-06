#ifndef LIFE_GAME_BOARD_H
#define LIFE_GAME_BOARD_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Board
{
public:
    Board(size_t boardSize=100);
    virtual void fillWithRandom();
    void toNext();
    const void *rawData();

private:
    const unsigned short numberOfCellNeighbours(short x, short y);

    size_t m_boardSize;
    std::vector<unsigned char> m_board;
};

#endif //LIFE_GAME_BOARD_H
