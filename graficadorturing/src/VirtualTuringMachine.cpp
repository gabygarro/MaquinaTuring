#include "VirtualTuringMachine.h"
#include "Graph.h"


VirtualTuringMachine::VirtualTuringMachine(){}

void VirtualTuringMachine::dibujar()
{

}

void VirtualTuringMachine::stop(string estado, string caracter) throw (vtm_indetermination_error, runtime_error)
{
    if (estadosRechazo.contains(estadoActual) || estadosAceptacion.contains(estadoActual)) throw runtime_error("");
	throw vtm_indetermination_error ("MACHINE HAS STOPPED IN STATE " +estado + " WITH SYMBOL " + caracter);
}
void VirtualTuringMachine::init()
{
    estadoActual = estadoInicial;
    grafo = new Graph(this);
}

void VirtualTuringMachine::step() throw (std::runtime_error)
{
    Transicion* transicion = grafo->getTransition(estadoActual, tira->getCurrentElement());
    if (transicion == NULL) stop(estadoActual, tira->getCurrentElement());
    tira->cambiarElemento(transicion->getCaracterEscrito());
    if (transicion->getMovimientoCabeza() > 0)
    	tira->avanzarTira(caracterBlanco);
    else{
    	tira->retrocederTira(caracterBlanco);
    }
    estadoActual = transicion->getEstadoDestino();

}

void VirtualTuringMachine::cargarTira(Tira* pTira) throw (std::runtime_error)
{
    cout << "tira " << pTira->getTextoTira() << " cargada en la maquina" <<endl;
    validarTira(pTira->getTextoTira());
    tira = pTira;
}

void VirtualTuringMachine::getCurrentStatus()
{
    cout << "CURRENT MACHINE STATUS:\n";
    cout << "current state: " << estadoActual << "\n";
    cout << "stream: " << tira->getTira() << endl;
}

void VirtualTuringMachine::appendEstado(string pEstado)
{ estados.append(pEstado); }

int VirtualTuringMachine::getCantidadEstados()
{ return estados.getSize();}

void VirtualTuringMachine::appendSimboloEntrada(string pSimbolo)
{simbolosDeEntrada.append(pSimbolo);}

void VirtualTuringMachine::appendSimboloMaquina(string pSimbolo)
{simbolosDeMaquina.append(pSimbolo);}

void VirtualTuringMachine::appendTransicion(Transicion pTransicion)
{   validarTransicion(&pTransicion); //lanza una excepcion si alguno de los datos de pTransicion no es valido
    transiciones.append(pTransicion);
}

void VirtualTuringMachine::appendEstadoAceptacion(string pEstado) throw (runtime_error)
{
    if (!estados.contains(pEstado))
        throw runtime_error ("El estado de aceptacion " + pEstado + " no se encuentra definido");
    estadosAceptacion.append(pEstado);
}

void VirtualTuringMachine::appendEstadoRechazo(string pEstado) throw (runtime_error)
{
    if (!estados.contains(pEstado))
        throw runtime_error ("El estado de rechazo " + pEstado + " no se encuentra definido");
    estadosRechazo.append(pEstado);
}

LinkedList<string>* VirtualTuringMachine::getEstados ( )
{return &estados;}

LinkedList<string> VirtualTuringMachine::getSimbolosDeEntrada ( )
{return simbolosDeEntrada;}

LinkedList<string> VirtualTuringMachine::getSimbolosDeMaquina ( )
{return simbolosDeMaquina;}

LinkedList<Transicion>* VirtualTuringMachine::getTransiciones ( )
{return &transiciones;}

void VirtualTuringMachine::setEstadoInicial(string pEstadoInicial) throw (runtime_error)
{
    if (!estados.contains(pEstadoInicial))
        throw runtime_error ("El estado inicial no existe entre la lista de estados definida");
    estadoInicial = pEstadoInicial;
}

string VirtualTuringMachine::getEstadoInicial ( )
{return estadoInicial;}

void VirtualTuringMachine::setCaracterBlanco(string pCaracterBlanco)
{caracterBlanco = pCaracterBlanco;}

string VirtualTuringMachine::getCaracterBlanco ( )
{return caracterBlanco;}

LinkedList<string>* VirtualTuringMachine::getEstadosAceptacion ( )
{return &estadosAceptacion;}

LinkedList<string>* VirtualTuringMachine::getEstadosRechazo ( )
{return &estadosRechazo;}

string VirtualTuringMachine::getEstadoActual ( )
{return estadoActual;}

void VirtualTuringMachine::validarTransicion (Transicion* transicion) throw (runtime_error)
{
    string enLaTransicion = " en la transicion T:" + transicion->getTransicion() + " no es valido.\n";
    if (!estados.contains(transicion->getEstadoOrigen()))
        throw runtime_error ("El estado de origen" + enLaTransicion);

    else if (!simbolosDeEntrada.contains(transicion->getCaracterLeido())
             && !simbolosDeMaquina.contains(transicion->getCaracterLeido()))
        throw runtime_error ("El simbolo de entrada" + enLaTransicion);

    else if (!simbolosDeMaquina.contains(transicion->getCaracterEscrito()))
        throw runtime_error ("El simbolo escrito " + enLaTransicion);

    else if ((transicion->getMovimientoCabeza() == 0))
        throw runtime_error ("El simbolo de direccion del movimiento de la cabeza" + enLaTransicion);
}

void VirtualTuringMachine::validarTira(string tira) throw (std::runtime_error)
{
    for (unsigned int i = 0; i < tira.length(); i++)
    {
        if ((!simbolosDeEntrada.contains(string(1, tira[i])) && (tira[i] != ' ')))
            throw std::runtime_error("Invalid symbol in stream");
    }
}

Transicion* VirtualTuringMachine::getTransicionEntre(string origen, string destino)
{
    Transicion t;
    LinkedList<Transicion>* transicioness = &transiciones;
    for (transicioness->goToStart(); transicioness->getPos() < transicioness->getSize(); transicioness->next())
    {
        t = transicioness->getElement();
        if ((t.getEstadoOrigen() == origen) && (t.getEstadoDestino() == destino))
            return &t;
    }
    return NULL;
}

string VirtualTuringMachine::getTira()
{
    return tira->getTira();
}
