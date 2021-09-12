#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "Board.h"

using namespace std;

Board::Board(size_t boardSize) : m_boardSize(boardSize)
{
    m_board.resize(m_boardSize*m_boardSize);
    m_tmpBoard.resize(m_boardSize*m_boardSize);
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
    m_simulationIsPAused ? std::this_thread::sleep_for (std::chrono::milliseconds (1)) : calculateNext();
    updateAllObservers();
}

void Board::calculateNext()
{
    unsigned short nbNeighbours;
    for(unsigned short i=0; i<m_boardSize; i++)
    {
        for(unsigned short j=0; j<m_boardSize; j++)
        {
            nbNeighbours=numberOfCellNeighbours(i, j, 4);
            size_t arrayPos = (i*m_boardSize)+j;
            switch (nbNeighbours)
            {
                case 2:
                    m_tmpBoard[arrayPos]=m_board[arrayPos];
                    break;
                case 3:
                    m_tmpBoard[arrayPos]=0;
                    break;
                default:
                    m_tmpBoard[arrayPos]=255;
                    break;
            }
        }
    }
    m_tmpBoard.swap(m_board);
}

const unsigned short Board::numberOfCellNeighbours(short x, short y, short stopAt)
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
            if(nbNeighbours >= stopAt)
            {
                return nbNeighbours;
            }
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

void Board::pauseSimulation(bool pause)
{
    m_simulationIsPAused = pause;
}

bool Board::isSimulationPaused() const
{
    return m_simulationIsPAused;
}
