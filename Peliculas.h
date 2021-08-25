//
// Created by jmcg0 on 8/24/2021.
//

#ifndef SITUACIONPROBLEMAOOP2_PELICULAS_H
#define SITUACIONPROBLEMAOOP2_PELICULAS_H


#include "Pelicula.h"
#include <iostream>
const int MAX_PEL = 50;

class Peliculas {
private:
    // Arreglo de clase Pelicula
    Pelicula *arrPtrPeliculas[MAX_PEL];
    int cantidad;
public:
    // Constructor
    Peliculas();
    // Leer archivo .csv o .txt
    void leerArchivo();

    // Setters
    void setPtrPelicula(Pelicula*, int iS); // DUDA EN FIRMA
    void setCantidadPeliculas(int _cantidad);

    // Getters
    Pelicula* getPtrPelicula(string);
    int getCantidadPeliculas();

    // Reportes etc
    void reporteTodasLasPeliculas();
    void reporteConCalificacion(double);
    void reporteGenero(string);

};

#endif //SITUACIONPROBLEMAOOP2_PELICULAS_H
