#include "BoardTest.h"

TEST_F(BoardTest, SinglePixel)
{
    Board board(5);
    board.pauseSimulation(false);
    unsigned char* data = (unsigned char*)board.rawData();
    memset((void *)data, 255, 25);
    board[2][2] = 0;
    board();
    EXPECT_EQ((int)board[2][2], 255);
}

TEST_F(BoardTest, ThreeAlignedPixels)
{
    Board board(5);
    board.pauseSimulation(false);
    unsigned char* data = (unsigned char*)board.rawData();
    memset((void *)data, 255, 25);
    board[1][2] = 0;
    board[2][2] = 0;
    board[3][2] = 0;

    board();
    EXPECT_EQ((int)board[2][1], 0);
    EXPECT_EQ((int)board[2][2], 0);
    EXPECT_EQ((int)board[2][3], 0);

    board();
    EXPECT_EQ((int)board[1][2], 0);
    EXPECT_EQ((int)board[2][2], 0);
    EXPECT_EQ((int)board[3][2], 0);
}

TEST_F(BoardTest, PausedBoard)
{
    Board board(5);
    board.pauseSimulation(true);
    unsigned char* data = (unsigned char*)board.rawData();
    memset((void *)data, 255, 25);
    board[2][2] = 0;
    board();
    EXPECT_EQ((int)board[2][2], 0);
}

TEST_F(BoardTest, Square)
{
    Board board(5);
    board.pauseSimulation(true);
    unsigned char* data = (unsigned char*)board.rawData();
    memset((void *)data, 255, 25);
    board[1][1] = 0;
    board[1][2] = 0;
    board[2][1] = 0;
    board[2][2] = 0;
    board();
    EXPECT_EQ((int)board[1][1], 0);
    EXPECT_EQ((int)board[1][2], 0);
    EXPECT_EQ((int)board[2][1], 0);
    EXPECT_EQ((int)board[2][2], 0);
}