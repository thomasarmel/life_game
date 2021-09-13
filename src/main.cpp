#include "Board.h"
#include "BoardDisplayer.h"

using namespace std;
using namespace cv;

int main()
{
    const size_t boardSize=10000;
    Board board(boardSize);
    board.fillWithRandom();
    BoardDisplayer displayer(0.1, 1);
    board.addObserver(&displayer);
    for(;;)
    {
        board();
    }
    return 0;
}