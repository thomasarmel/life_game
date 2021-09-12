#include <vector>
#include <algorithm>
#include "ObservableBoard.h"

using namespace std;

void ObservableBoard::addObserver(BoardObserver *observer)
{
    m_observers.push_back(observer);
}

void ObservableBoard::updateAllObservers()
{
    for_each(m_observers.cbegin(), m_observers.cend(), [this](BoardObserver *observer){
        observer->update(this);
    });
}