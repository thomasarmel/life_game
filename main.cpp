#include "Board.h"
#include "BoardDisplayer.h"

using namespace std;
using namespace cv;

int main()
{
    const size_t boardSize=500;
    Board board(boardSize);
    board.fillWithRandom();
    BoardDisplayer displayer(2, 1);
    board.addObserver(&displayer);
    for(;;)
    {
        board.toNext();
    }
    return 0;
}