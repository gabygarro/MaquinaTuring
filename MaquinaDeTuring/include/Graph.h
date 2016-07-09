#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include "Edge.h"
#include "VirtualTuringMachine.h"
#include <stdexcept>


/*
**
4/11/14
Autor: Daniel Ulate
Grafo usado por la máquina de turing para llevar las relaciones entre estados.
Se implementa con lista deadyacencia.
Los vértices son un arreglo de strings
*/

using namespace std;

class Graph
{
private:
    typedef Transicion Transition;
    typedef LinkedList<Edge> edgelist;
    int verticesQuantity;
    edgelist* adjacencyList;
    string* vertices;
    VirtualTuringMachine virtualTuringMachine;

    void initVertices()
    {
        LinkedList<string> states = virtualTuringMachine.getEstados( );
        verticesQuantity = states.getSize();
        vertices = new string [verticesQuantity];
        for (states.goToStart(); states.getPos() < states.getSize(); states.next())
        {
            vertices[verticesQuantity]  = states.getElement();
        }
    }


    //crea los arcos del grafo y los agrega a la lista de adyacencia
    //obtiene los datos de los arcos de la VTM
    void initEdges()
    {
        LinkedList<Transition> transitions = virtualTuringMachine.getTransiciones();
        adjacencyList = new LinkedList<Edge>[verticesQuantity];
        for (transitions.goToStart(); transitions.getPos() < transitions.getSize(); transitions.next())
        {
            addEdge(transitions.getElement());
        }
    }

    void addEdge(Transicion transition)
    {
        int originVertex; //index of the array where the name of the origin vertex is
        int destinyVertex; //index of the array where the name of the destiny vertex is
        originVertex  = getPosInVerticesArray(transition.getEstadoOrigen());
        destinyVertex = getPosInVerticesArray(transition.getEstadoDestino());

        Edge edge (transition);
        edge.setDestiny(destinyVertex);

        adjacencyList[originVertex].append(edge);
    }

    ///recibe el nombre de un vertice
    ///retorna el indice de dicho vérrtice (retorna -1 si no existe)
    int getPosInVerticesArray(string vertexName) throw (runtime_error)
    {
        for (int i = 0; i < verticesQuantity; i++)
        {
            if (vertices[i] == vertexName) return i;
        }
        throw runtime_error ("in Graph::getPosgetPosInVerticesArray:\n Non-existant vertex");
    }


    // se encarga de crear una transicion (de VTM) a partir de un arco
    Transition* toTransition(Edge edge)
    {
        Transition* transition = new Transition();
        transition->setCaracterEscrito(""+edge.getWrittenChar());
        transition->setMovimientoCabeza((edge.getDirection() > 0 ? ">" : "<" ));
        transition->setEstadoDestino(vertices[edge.getDestiny()]);
        return transition;
    }

public:
    Graph(VirtualTuringMachine pVirtualTuringMachine)
    {
        virtualTuringMachine = pVirtualTuringMachine;
        initVertices();
        initEdges();
    }



    Transition* getTransition(string vertexName, char readChar)
    {

        int pos = getPosInVerticesArray(vertexName);
        if (pos == -1) return NULL;
        LinkedList<Edge> vertexEdges = adjacencyList[pos];
        for (vertexEdges.goToStart(); vertexEdges.getPos() < vertexEdges.getSize(); vertexEdges.next())
        {
            Edge edge = vertexEdges.getElement();
            if (edge.getReadChar() == readChar)
            {
                return toTransition(edge);
            }
        }
        return NULL;
    }

};

#endif // GRAPH_Hs
