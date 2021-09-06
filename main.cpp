#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Board.h"

using namespace std;
using namespace cv;


int main()
{
    const double zoom=5;
    const size_t boardSize=100;
    const unsigned short delay=1;
    Board board(boardSize);
    board.fillWithRandom();
    Mat CVBoard(boardSize, boardSize, CV_8U);
    Mat CVBoardDisp;
    char key;
    while(1)
    {
        memcpy(CVBoard.data, board.rawData(), boardSize * boardSize * sizeof(unsigned char));
        resize(CVBoard, CVBoardDisp, Size(CVBoard.cols * zoom, CVBoard.rows * zoom));
        imshow("Life game", CVBoardDisp);
        key = (char)waitKey(delay);
        if(key==27)
        {
            break;
        }
        if(key==114) // 'r'
        {
            board.fillWithRandom();
            continue;
        }
        board.toNext();
    }
    return 0;
}