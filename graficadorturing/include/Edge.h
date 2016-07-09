#ifndef EDGE_H
#define EDGE_H

#include "Transicion.h"

/*
**
4/11/14
autor: daniel ulate
*
*/

using namespace std;

//es la clase que lleva los arcos entre ls vértices grafo
class Edge
{
private:
    string readChar;
    string writtenChar;
    int direction; // -1: left; 0:stay; 1: right;
    string destiny;

public:
    Edge () {}

    Edge (Transicion transition)
    {
        readChar    = transition.getCaracterLeido();
        writtenChar = transition.getCaracterEscrito();
        direction   = transition.getMovimientoCabeza();
        destiny     = transition.getEstadoDestino();
    }

    void setReadChar (string pReadChar) {readChar = pReadChar;}

    string getReadChar ( ) {return readChar;}

    void setWrittenChar (string pWrittenChar) {writtenChar = pWrittenChar;}

    string getWrittenChar ( ) {return writtenChar;}

    void setDirection (int pDirection) {direction = pDirection;}

    int getDirection ( ) {return direction;}

    void setDestiny(string pDestiny) {destiny = pDestiny;}

    string getDestiny ( ) {return destiny;}
};

#endif // Edge_H
