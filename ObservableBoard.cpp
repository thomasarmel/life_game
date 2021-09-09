#include <vector>
#include "ObservableBoard.h"

using namespace std;

void ObservableBoard::addObserver(BoardObserver *observer)
{
    m_observers.push_back(observer);
}