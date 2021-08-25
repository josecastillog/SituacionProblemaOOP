//
// Created by jmcg0 on 8/24/2021.
//

#include "Pelicula.h"

#include "Pelicula.h"

// Constructores
Pelicula::Pelicula() : Video() {
    oscares = 0;
}
Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares) :
Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    oscares = _oscares;
}

// Setters y getters
void Pelicula::setOscares(int _oscares) {
    oscares = _oscares;
}
int Pelicula::getOscares() {
    return oscares;
}

// Metodo str()
string Pelicula::str() {
    return 'P' + iD + ',' + titulo + ',' + to_string(duracion) + ',' + genero + ',' + to_string(calificacionPromedio) + ',' + to_string(oscares);
}

// Sobrecarga operador <<
std::ostream& operator<< (std::ostream &out, const Pelicula &pelicula) {
    out << 'P' + pelicula.iD + ',' + pelicula.titulo + ',' + to_string(pelicula.duracion) + ',' + pelicula.genero +
    ',' + to_string(pelicula.calificacionPromedio) + ',' + to_string(pelicula.oscares);
    return out;
}
