#include <iostream>
#include <random>
#include <chrono>
#include "Board.h"

using namespace std;

Board::Board(size_t boardSize) : m_boardSize(boardSize)
{
    m_board.resize(m_boardSize*m_boardSize);
}

void Board::fillWithRandom()
{
    random_device rd;
    mt19937::result_type seed = rd() ^ ((mt19937::result_type) chrono::duration_cast<std::chrono::seconds>(
            chrono::system_clock::now().time_since_epoch()).count() +
                                        (mt19937::result_type) chrono::duration_cast<chrono::microseconds>(
                                                chrono::high_resolution_clock::now().time_since_epoch()).count());
    mt19937 gen(seed);
    uniform_int_distribution<unsigned> distrib(0, 1);
    generate(m_board.begin(), m_board.end(), [&]() {
        return distrib(gen) * 255;
    });
}

void Board::reset()
{
    fillWithRandom();
}

void Board::toNext()
{
    vector<unsigned char> tmpBoard=m_board;
    unsigned short nbNeighbours;
    for(unsigned short i=0; i<m_boardSize; i++)
    {
        for(unsigned short j=0; j<m_boardSize; j++)
        {
            nbNeighbours=numberOfCellNeighbours(i, j);
            if(nbNeighbours < 2 || nbNeighbours > 3)
            {
                tmpBoard[(i*m_boardSize)+j]=255;
            }
            else if(nbNeighbours == 3)
            {
                tmpBoard[(i*m_boardSize)+j]=0;
            }
        }
    }
    copy(tmpBoard.begin(), tmpBoard.end(), m_board.begin());
    for_each(m_observers.cbegin(), m_observers.cend(), [this](BoardObserver *observer){
        observer->update(this);
    });
}

const unsigned short Board::numberOfCellNeighbours(short x, short y)
{
    unsigned short nbNeighbours = 0;
    for (unsigned short i = x - 1; i < x + 2; i++)
    {
        if (i < 0 || i >= m_boardSize)
        {
            continue;
        }
        for (unsigned short j = y - 1; j < y + 2; j++)
        {
            if (j < 0 || j >= m_boardSize || (x == i && y == j))
            {
                continue;
            }
            nbNeighbours += (m_board[(i*m_boardSize)+j] == 0);
        }
    }
    return nbNeighbours;
}

const void *Board::rawData()
{
    return m_board.data();
}

size_t Board::getBoardSize() const
{
    return m_boardSize;
}
