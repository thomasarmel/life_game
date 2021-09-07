#ifndef LIFE_GAME_BOARDDISPLAYER_H
#define LIFE_GAME_BOARDDISPLAYER_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "BoardObserver.h"
#include "Board.h"

class BoardDisplayer : public BoardObserver
{
public:
    BoardDisplayer(double zoom=1, unsigned short delay=1);
    void update(ObservableBoard *observable) override;

protected:
    double m_zoom;
    unsigned short m_delay=1;
    cv::Mat m_CVBoard, m_CVBoardDisp;;
};


#endif //LIFE_GAME_BOARDDISPLAYER_H
