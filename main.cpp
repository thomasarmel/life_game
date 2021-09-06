#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

template<size_t taillePlateau>
void remplirPlateauRand(array<array<unsigned char, taillePlateau>, taillePlateau> &plateau);
template<size_t taillePlateau>
unsigned short nbVoisins(array<array<unsigned char, taillePlateau>, taillePlateau> &plateau, unsigned short x, unsigned short y);
template<size_t taillePlateau>
void jouer(array<array<unsigned char, taillePlateau>, taillePlateau> &plateau);

int main()
{
    const size_t taillePlateau=100;
    const double zoom=5;
    const unsigned short delai=1;
    Mat plateauCV(taillePlateau, taillePlateau, CV_8U);
    Mat plateauCVDisp;
    array<array<unsigned char, taillePlateau>, taillePlateau> plateau;
    remplirPlateauRand(plateau);
    char key;
    while(1)
    {
        memcpy(plateauCV.data, (void*)plateau.data(), taillePlateau*taillePlateau*sizeof(unsigned char));
        resize(plateauCV, plateauCVDisp, Size(plateauCV.cols*zoom, plateauCV.rows*zoom));
        imshow("Life game", plateauCVDisp);
        key = (char)waitKey(delai);
        if(key==27)
        {
            break;
        }
        if(key==114)
        {
            remplirPlateauRand(plateau);
            continue;
        }
        jouer(plateau);
    }
    return 0;
}

template<size_t taillePlateau>
void remplirPlateauRand(array<array<unsigned char, taillePlateau>, taillePlateau> &plateau)
{
    srand(time(0));
    for(unsigned short i=0; i<plateau.size(); i++)
    {
        for(unsigned short j=0; j<plateau[i].size(); j++)
        {
            plateau[i][j]=(rand()%2)*255;
        }
    }
}

template<size_t taillePlateau>
unsigned short nbVoisins(array<array<unsigned char, taillePlateau>, taillePlateau> &plateau, unsigned short x, unsigned short y)
{
    unsigned short retour=0;
    for(unsigned short i=x-1; i<x+2; i++)
    {
        if(i<0 || i>=plateau.size())
        {
            continue;
        }
        for(unsigned short j=y-1; j<y+2; j++)
        {
            if(j<0 || j>=plateau[i].size() || (x==i && y==j))
            {
                continue;
            }
            retour+=(plateau[i][j]==0);
        }
    }
    return retour;
}

template<size_t taillePlateau>
void jouer(array<array<unsigned char, taillePlateau>, taillePlateau> &plateau)
{
    array<array<unsigned char, taillePlateau>, taillePlateau> plateauTmp=plateau;
    unsigned short _nbVoisins;
    for(unsigned short i=0; i<plateauTmp.size(); i++)
    {
        for(unsigned short j=0; j<plateauTmp[i].size(); j++)
        {
            _nbVoisins=nbVoisins(plateauTmp, i, j);
            if(_nbVoisins < 2 || _nbVoisins > 3)
            {
                plateau[i][j]=255;
            }
            else if(_nbVoisins==3)
            {
                plateau[i][j]=0;
            }
        }
    }
}
