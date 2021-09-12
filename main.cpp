#include "Board.h"
#include "BoardDisplayer.h"

using namespace std;
using namespace cv;

int main()
{
    const size_t boardSize=1000;
    Board board(boardSize);
    board.fillWithRandom();
    BoardDisplayer displayer(1, 1);
    board.addObserver(&displayer);
    for(;;)
    {
        board.toNext();
    }
    return 0;
}



/**
 * TODO: Uni test
*   const size_t boardSize=5;
    Board board(boardSize);
    uchar * const data = (uchar*)board.rawData();
    memset((void *)data, 255, 25);
    data[7] = 0;
    data[12] = 0;
    data[17] = 0;
    //board.fillWithRandom();
    BoardDisplayer displayer(50, 0);
    board.addObserver(&displayer);
    displayer.update(&board);
    for(;;)
    {
        board.toNext();
    }
*/