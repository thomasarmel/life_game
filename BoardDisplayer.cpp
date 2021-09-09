#include "BoardDisplayer.h"

using namespace std;
using namespace cv;

BoardDisplayer::BoardDisplayer(double zoom, unsigned short delay) : m_zoom(zoom), m_delay(delay)
{
    namedWindow(m_windowName, WINDOW_NORMAL);
}

void BoardDisplayer::update(ObservableBoard *observable)
{
    Board *board = (Board*)observable;
    size_t boardSize = board->getBoardSize();
    if(m_CVBoard.rows != boardSize || m_CVBoard.cols != boardSize)
    {
        m_CVBoard.release();
        m_CVBoard.create(boardSize, boardSize, CV_8U);
    }

    //memcpy(m_CVBoard.data, board->rawData(), boardSize * boardSize * sizeof(unsigned char));
    m_CVBoard.data = (uchar*)board->rawData();
    resizeWindow(m_windowName, boardSize * m_zoom, boardSize * m_zoom);
    imshow(m_windowName, m_CVBoard);
    char key = (char)waitKey(m_delay);
    if(key==27)
    {
        exit(0);
    }
    if(key==114) // 'r'
    {
        board->reset();
        return;
    }
}