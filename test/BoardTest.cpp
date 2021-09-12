#include "BoardTest.h"

TEST_F(BoardTest, ThreeAlignedPixels) {
    Board board(5);
    unsigned char* const data = (unsigned char*)board.rawData();
    memset((void *)data, 255, 25);
    data[7] = 0;
    data[12] = 0;
    //data[17] = 0;
    //board.pauseSimulation(false);
    board();
    for(int i=0; i<25; i++)
    {
        std::cout << i << " " <<  (int)data[i] << std::endl;
    }
    EXPECT_EQ((int)data[7], 255);
    EXPECT_EQ((int)data[12], 0);
}