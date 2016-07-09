#include <iostream>
#include "LectorDeArchivos.h"
//#include "Graph.h"

using namespace std;

template <typename E> void imprimir(LinkedList<E> lista);

void imprimirtransiciones(LinkedList<Transicion> transiciones)
{
    int i = 1;
    cout << "Transiciones: " << endl;
    for (transiciones.goToStart(); transiciones.getPos() < transiciones.getSize(); transiciones.next())
    {cout << i++ << ". " << transiciones.getElement().toString() << endl;}
}
int print()
{
    LectorDeArchivos lector;
    lector.leerArchivo("maquina");
    VirtualTuringMachine vtm;
    vtm = *lector.getVirtualMachine();

    LinkedList<string> estados = vtm.getEstados();
    cout <<"estados:\n";
    imprimir<string>(estados);

    LinkedList<Transicion> transiciones = vtm.getTransiciones();
    imprimirtransiciones(transiciones);

    LinkedList<char> entrada = vtm.getSimbolosDeEntrada();
    cout << "caracteres de entrada:\n";
    imprimir<char>(entrada);

    LinkedList<char> simmaquina = vtm.getSimbolosDeMaquina();
    cout << "simbolos de maquina: \n";
    imprimir<char>(simmaquina);

    cout << "estado incial : " << vtm.getEstadoInicial() << endl;
    cout << "caracter blanco: " << vtm.getCaracterBlanco() << endl;

    LinkedList<string> estadosacept = vtm.getEstadosAceptacion();
    cout << "estados aceptacion:\n";
    imprimir<string>(estadosacept);

    LinkedList<string> estadosrechazo = vtm.getEstadosRechazo();
    cout << "estados de rechazo:\n";
    imprimir<string>(estadosrechazo);

    cout << "TERMINA"<< endl;
}

template <typename E> void imprimir(LinkedList<E> lista)
{
    int i = 1;
    for (lista.goToStart(); lista.getPos() < lista.getSize(); lista.next()){
        cout << i++ << ". " << lista.getElement() << endl;
    }
}

int main()
{
    LectorDeArchivos l;
    l.leerArchivo("maquina");
    VirtualTuringMachine* vtm = l.getVirtualMachine();
    //return print();
}
