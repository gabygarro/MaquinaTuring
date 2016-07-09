#ifndef TIRA_H
#define TIRA_H
#include "LinkedList.h"
#include <iostream>


using namespace std;

/*
Autor: Giovanni Villalobos
11/11/14
Es la clase que lleva control de la tira que la maquina de turing va leyendo
se carga en la maquina de turing.
Se crea a partir de iuns tring ingresado en consola.

*/

class Tira
{
private:
    LinkedList<string> tira;
    string textoTira;
public:
//Inicializa la tira para el programa
    Tira(){}

    Tira (string texto)
    {
        setTira(texto);
    }

    //retorna un string que es el texto 
    //que se insertó originalmente en la consola
    string getTextoTira()
    {return textoTira;}

    void setTira(string texto) throw (std::runtime_error)
    {
        textoTira = texto;
        for(unsigned int a=0;  a < texto.length(); a++)
        {
            if(texto[a] != ' ')
            {
                tira.append(string(1, texto[a]));
            }
        }
    }

    //devuelve la tira que se va a imprimir en consola y en la ventana grafica
    //el caracter actual que se está leyendo va entre [ ]
    string getTira()
    {
        //devuelve la tira como un string para ser impreso en la pantalla
        int pos = tira.getPos();
        string texto;
        for(tira.goToStart(); tira.getPos() < tira.getSize(); tira.next())
        {
            texto =  texto + "  ";
            if(tira.getPos() == pos)
            {
                texto = texto + " [ ";
                texto =  texto + tira.getElement();
                texto = texto + " ] ";
            }
            else
            {
                texto =  texto + tira.getElement();
            }
        }
        texto =  texto + "  ";
        tira.goToPos(pos);
        return texto;
    }
    void avanzarTira(string caracter)
    {
        if (tira.getPos() == tira.getSize()-1) tira.append(caracter);
            return tira.next();
    }
    void retrocederTira(string caracter)
    {
        if (tira.getPos() == 0){
             tira.insert(caracter);
             tira.previous();
        }
        tira.previous();
    }

    //cambia el caracter que se lee actualmetne por pElement
    void cambiarElemento(string pElement)
    {
        tira.setElement(pElement);
    }

    //devuelve el caracter leido actualmetne
    string getCurrentElement() throw (runtime_error)
    {
            return tira.getElement();
    }


};

#endif // TIRA_H
