#include "Graph.h"
#include "VirtualTuringMachine.h"

void Graph::initVertices()
{
    LinkedList<string>* states = virtualTuringMachine->getEstados( );
    verticesQuantity = states->getSize();
    vertices = new string[verticesQuantity];
    int i = 0;
    for (states->goToStart(); states->getPos() < states->getSize(); states->next())
    {
        vertices[i++] = states->getElement();
    }
}

//crea los arcos del grafo y los agrega a la lista de adyacencia
//obtiene los datos de los arcos de la VTM
void Graph::initEdges()
{
    LinkedList<Transicion>* transitions = virtualTuringMachine->getTransiciones();
    adjacencyList = new LinkedList<Edge>[verticesQuantity];
    for (transitions->goToStart(); transitions->getPos() < transitions->getSize(); transitions->next())
    {
        addEdge(transitions->getElement());
    }
}

void Graph::addEdge(Transicion transition)
{
    int originVertex; //index of the array where the name of the origin vertex is
    originVertex  = getPosInVerticesArray(transition.getEstadoOrigen());

    Edge edge (transition);

    adjacencyList[originVertex].append(edge);
}

///recibe el nombre de un vertice
///retorna el indice de dicho vérrtice (retorna -1 si no existe)
int Graph::getPosInVerticesArray(string vertexName) throw (runtime_error)
{
    for (int i = 0; i < verticesQuantity; i++)
    {
        if (vertices[i] == vertexName) return i;
    }
    throw runtime_error ("in Graph::getPosInVerticesArray:\n Non-existant vertex");
}


// se encarga de crear una transicion (de VTM) a partir de un arco
Transicion* Graph::toTransition(Edge edge)
{
    Transicion* transition = new Transicion();
    transition->setCaracterEscrito(edge.getWrittenChar());
    transition->setMovimientoCabeza((edge.getDirection() > 0 ? ">" : "<" ));
    transition->setEstadoDestino(edge.getDestiny());
    return transition;
}

Graph::Graph(){}

Graph::~Graph(){
    delete [] vertices;
}

Graph::Graph(VirtualTuringMachine* pVirtualTuringMachine)
{
    virtualTuringMachine = pVirtualTuringMachine;
    initVertices();
    initEdges();
}

Transicion* Graph::getTransition(string vertexName, string readChar)
{
    int pos = getPosInVerticesArray(vertexName);
    LinkedList<Edge>* vertexEdges = &adjacencyList[pos];
    for (vertexEdges->goToStart(); vertexEdges->getPos() < vertexEdges->getSize(); vertexEdges->next())
    {
        Edge edge;
        edge = vertexEdges->getElement();
        if (edge.getReadChar() == readChar)
        {
            return toTransition(edge);
        }
    }
    return NULL;
}

LinkedList<Edge>* Graph::getEdges()
{
    return adjacencyList;
}

Transicion* Graph::transitionBetween(string origin, string destiny)
{
    LinkedList<Edge> vertexTransitions = adjacencyList[getPosInVerticesArray(origin)];
    Edge edge;
    for (vertexTransitions.goToStart(); vertexTransitions.getPos() < vertexTransitions.getSize(); vertexTransitions.next())
    {
        edge = vertexTransitions.getElement();
        if (edge.getDestiny() == destiny)
            {return toTransition(edge);}
    }
    return NULL;

}
