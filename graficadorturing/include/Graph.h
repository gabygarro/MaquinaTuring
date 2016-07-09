#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"
#include "Transicion.h"
#include "Edge.h"
//#include "Edge.h"

/*
**
4/11/14
Autor: Daniel Ulate
Grafo usado por la máquina de turing para llevar las relaciones entre estados.
Se implementa con lista deadyacencia.
Los vértices son un arreglo de strings
*/

using namespace std;

class VirtualTuringMachine;

class Graph
{
private:
    typedef LinkedList<Edge> edgelist;
    int verticesQuantity;
    edgelist* adjacencyList;
    string* vertices;
    VirtualTuringMachine* virtualTuringMachine;

    //crea los vertices del grafo a partir de los estados de la VTM
    void initVertices();

    //crea los arcos del grafo y los agrega a la lista de adyacencia
    //obtiene los datos de los arcos de la VTM
    void initEdges();

    void addEdge(Transicion transition);

    ///recibe el nombre de un vertice
    ///retorna el indice de dicho vérrtice (retorna -1 si no existe)
    int getPosInVerticesArray(string vertexName) throw (runtime_error);

    // se encarga de crear una transicion (de VTM) a partir de un arco
    Transicion* toTransition(Edge edge);

public:
    Graph();

    ~Graph();

    Graph(VirtualTuringMachine* pVirtualTuringMachine);

    //recibe el nombre de un vertice del grafoy el simbolo de entrada
    // y devuelve una transicion con los demas datos (simbolo salida, direccion y siguiente vertice)
    Transicion* getTransition(string vertexName, string readChar);

    LinkedList<Edge>* getEdges();

    //recibe los nombres de dos estado
    //si hay una transicion del origen al destino la retorna
    //si no la hay, retorna NULL
    Transicion* transitionBetween(string origin, string destiny);
};

#endif // GRAPH_Hs
