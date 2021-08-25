//
// Created by jmcg0 on 8/24/2021.
//

#include "Episodio.h"

#include "Episodio.h"
// Constructores
Episodio::Episodio()
{
    titulo = "";
    temporada = 0;
    calificacion = 0;
}
Episodio::Episodio(string _titulo, int _temporada, double _calificacion)
{
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Setters
void Episodio::setTitulo(string _titulo)
{
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada)
{
    temporada = _temporada;
}
void Episodio::setCalificacion(double _calificacion)
{
    calificacion = _calificacion;
}

// Getters
string Episodio::getTitulo()
{
    return titulo;
}
int Episodio::getTemporada()
{
    return temporada;
}
double Episodio::getCalificacion()
{
    return calificacion;
}

// Str()
string Episodio::str()
{
    return 'E' + titulo + ',' + to_string(temporada) + ',' + to_string(calificacion);
}

// Sobre carga de operador <<
std::ostream& operator<< (std::ostream &out, const Episodio &episodio)
{
    out << 'E' + episodio.titulo + ',' + to_string(episodio.temporada) + ',' + to_string(episodio.calificacion);
    return out;
}
