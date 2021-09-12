#ifndef LIFE_GAME_BOARDTEST_H
#define LIFE_GAME_BOARDTEST_H

#include "gtest/gtest.h"
#include "Board.h"

class BoardTest : public ::testing::Test
{
public:
    BoardTest()
    {
        board = new Board(5);
    }
    void SetUp()
    {
    }

    void TearDown( )
    {
    }

    ~BoardTest()
    {
    }

    Board *board;
};


#endif //LIFE_GAME_BOARDTEST_H
