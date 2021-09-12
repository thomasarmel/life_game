#include "BoardTest.h"

TEST_F(BoardTest, ThreeAlignedPixels) {
    Board board(5);
    board.pauseSimulation(false);
    unsigned char* data = (unsigned char*)board.rawData();
    memset((void *)data, 255, 25);
    data[7] = 0;
    data[12] = 0;
    data[17] = 0;

    board();
    data = (unsigned char*)board.rawData();
    EXPECT_EQ((int)data[11], 0);
    EXPECT_EQ((int)data[12], 0);
    EXPECT_EQ((int)data[13], 0);

    board();
    data = (unsigned char*)board.rawData();
    EXPECT_EQ((int)data[7], 0);
    EXPECT_EQ((int)data[12], 0);
    EXPECT_EQ((int)data[17], 0);
}