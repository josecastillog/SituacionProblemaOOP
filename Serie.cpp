//
// Created by jmcg0 on 8/24/2021.
//

#include "Serie.h"

#include <iostream>
#include "Serie.h"

// Constructores
Serie::Serie() : Video()
{
    cantidad = 0;
}
Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacionPromedio, int _cantidad)
: Video(_iD, _titulo, _duracion, _genero, _calificacionPromedio)
{
    cantidad = _cantidad;
}

// Setters
void Serie::setEpisodio(Episodio _episodios, int index)
{
    episodios[index] = _episodios;
}
void Serie::setCantidad(int _cantidad)
{
    cantidad = _cantidad;
}

// Getters
Episodio Serie::getEpisodio(int index)
{
    return episodios[index];
}
int Serie::getCantidad()
{
    return cantidad;
}

// Calcula promedio de una serie con base en los episodios
double Serie::calculaPromedio()
{
    double acum = 0.0;
    if (cantidad > 0)
    {
        for (int iR = 0; iR < cantidad; iR++) {
            acum = acum + episodios[iR].getCalificacion();
        }
        calificacionPromedio = acum / cantidad;
        return calificacionPromedio;
    }
    else
    {
        calificacionPromedio = -1;
        return calificacionPromedio;
    }
}

// Metodo str()
string Serie::str()
{
    string s = "";
    for(int iR = 0; iR < cantidad; iR++)
    {
        s = s + to_string(iR) + ':' + episodios[iR].str() + '\n';
    }

    return 'S' + iD + ',' + titulo + ',' + to_string(duracion) + ',' + genero + ',' + to_string(calificacionPromedio) + ',' +
    to_string(cantidad) + '\n' + s;
}

// Sobrecarga de operador <<
std::ostream& operator<< (std::ostream &out, const Serie &serie)
{
    /*
    string s = "";
    for(int iR = 0; iR < serie.cantidad; iR++) {
        s += to_string(iR) + ':' + serie.episodios[iR].str() + '\n';
    } */

    out << 'S' + serie.iD + ',' + serie.titulo + ',' + to_string(serie.duracion) + ',' + serie.genero + ',' + to_string(serie.calificacionPromedio) + ',' +
    to_string(serie.cantidad) + '\n';

    for(int iR = 0; iR < serie.cantidad; iR++)
    {
        out << iR << ':' << serie.episodios[iR] << '\n';
    }

    return out;
}
