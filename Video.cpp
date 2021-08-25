//
// Created by jmcg0 on 8/24/2021.
//

#include "Video.h"

#include "Video.h"

// Constructores
Video::Video()
{
    iD = "000";
    titulo = "___";
    duracion = 0;
    genero = "XXX";
    calificacionPromedio = 0;
}
Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacionPromedio)
{
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacionPromedio = _calificacionPromedio;
}

// Setters
void Video::setId(string _iD)
{
    iD = _iD;
}
void Video::setTitulo(string _titulo)
{
    titulo = _titulo;
}
void Video::setDuracion(int _duracion)
{
    duracion = _duracion;
}
void Video::setGenero(string _genero)
{
    genero = _genero;
}
void Video::setCalificacion(double _calificacion)
{
    calificacionPromedio = _calificacion;
}

// Getters
string Video::getId()
{
    return iD;
}
string Video::getTitulo()
{
    return titulo;
}
int Video::getDuracion()
{
    return duracion;
}
string Video::getGenero()
{
    return genero;
}
double Video::getCalificacion()
{
    return calificacionPromedio;
}

// Metodo str(), virtual porque es clase padre
string Video::str()
{
    return iD + ',' + titulo + ',' + to_string(duracion) + ',' + genero + ',' + to_string(calificacionPromedio);
}