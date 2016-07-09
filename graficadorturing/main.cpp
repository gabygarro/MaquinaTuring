
#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GraficadorTuring.h"
#include "LectorDeArchivos.h"
#include "Tira.h"

using namespace std;

void graficar(VirtualTuringMachine* vtm)
{
    LinkedList<string>* estados= vtm->getEstados();
    //LinkedList<string> estados = *sts;
    GraficadorTuring g(500,500, estados->getSize());
    for (estados->goToStart(); estados->getPos() < estados->getSize(); estados->next())
    {
        g.asignarNombreEstado(estados->getPos(), estados->getElement());
    }
    string estadoOrigen;
    string estadoDestino;
    Transicion *transicion;
    //int j=0;
    estados->goToStart();
    for (int i = 0; i < estados->getSize(); i++)
    {
        estados->goToPos(i);
        estadoOrigen = estados->getElement();
        for (estados->goToStart(); estados->getPos() < estados->getSize(); estados->next())
        {
            estadoDestino = estados->getElement();
            transicion = vtm->getTransicionEntre(estadoOrigen, estadoDestino);
            if (transicion != NULL){
                string trans = transicion->getCaracterLeido();
                trans += " / ";
                trans += transicion->getCaracterEscrito();
                trans += " / ";
                trans += (transicion->getMovimientoCabeza() > 0 ? ">" : "<");// transicion->getTransicion();
                g.asignarTransicion(i, estados->getPos(), trans);
            }
            else {
            }
        }
    }
    g.dibujarEstados(vtm->getEstadoActual());
    g.dibujarTira(vtm->getTira());
}
int main()
{
    string nuevaTira, nombreMaquina;
    cout << "Nombre de la maquina que desea cargar: ";
    cin >> nombreMaquina;
    //nombreMaquina = "maquinaPares";
    cout << "Inserte la tira: ";
    try{
        LectorDeArchivos lector;
        lector.leerArchivo(nombreMaquina);
        VirtualTuringMachine * vtm = lector.getVirtualMachine();
        cin >> nuevaTira;
        cin.get();
        Tira tira(nuevaTira);
        vtm->cargarTira(&tira);
        cout << tira.getTira();
        cout << endl << endl << endl;
        bool salir = false;
        int ancho = 500;
        int alto = 500;
        initwindow(ancho, alto + 50);
        while (!salir)
        {
            try{
            vtm->getCurrentStatus();
            graficar(vtm);
            cin.get();
            vtm->step();
            }
            catch (vtm_indetermination_error e)
            {
                cout <<endl << endl <<"**********" << e.what() << "**********" << endl << endl;
                return 666;
            }
            catch (runtime_error e)
            {

                if (vtm->getEstadosAceptacion()->contains(vtm->getEstadoActual())){
                    cout << "LA TIRA HA SIDO ACEPTADA POR LA MAQUINA";
                    cout << "\nTIRA RESULTANTE: " << tira.getTira();
                    }
                else {
                    cout << "LA TIRA HA SIDO RECHAZADA POR LA MAQUINA";
                    cout << "\nTIRA RESULTANTE: " << tira.getTira();
                }
                salir = true;
            }
        }
    }
    catch(runtime_error e)
    {
        cout <<endl << endl <<"**********" << e.what() << "**********" << endl << endl;
        return 6;
    }

}


