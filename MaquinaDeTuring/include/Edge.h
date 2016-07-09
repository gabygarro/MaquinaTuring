#ifndef EDGE_H
#define EDGE_H

#include "Transicion.h"

/*
**
4/11/14
@author daniel ulate
*
*/
using namespace std;


class Edge
{
private:
    char readChar;
    char writtenChar;
    int direction; // -1: left; 0:stay; 1: right;
    int destiny;

public:
    Edge () {}

    Edge (Transicion transition)
    {
        readChar    = transition.getCaracterLeido();
        writtenChar = transition.getCaracterEscrito();
        direction   = transition.getMovimientoCabeza();
    }

    void setReadChar (char pReadChar) {readChar = pReadChar;}

    char getReadChar ( ) {return readChar;}

    void setWrittenChar (char pWrittenChar) {writtenChar = pWrittenChar;}

    char getWrittenChar ( ) {return writtenChar;}

    void setDirection (int pDirection) {direction = pDirection;}

    int getDirection ( ) {return direction;}

    void setDestiny(int pDestiny) {destiny = pDestiny;}

    int getDestiny ( ) {return destiny;}
};

#endif // Edge_H
