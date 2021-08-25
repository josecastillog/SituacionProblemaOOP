//
// Created by jmcg0 on 8/24/2021.
//

#ifndef SITUACIONPROBLEMAOOP2_SERIES_H
#define SITUACIONPROBLEMAOOP2_SERIES_H

#include "Serie.h"
#include <iostream>
const int MAX_SERIES = 50;

class Series {
private:
    Serie *arrPtrSeries[MAX_SERIES];
    int cantidad;
public:
    // Constructor
    Series();

    // Leer archivos .csv
    void leerArchivo();

    // Setters
    void setPtrSerie(Serie*);
    void setCantidadSeries(int _cantidad);

    // Getters
    Serie* getPtrSerie(string);
    int getCantidadSerie();

    // Reportes para desplegar en consola
    void reporteTodasLasSeries();
    void reporteConCalificacion(double);
    void reporteGenero(string);
    void calcularCalificacionSeries();
};


#endif //SITUACIONPROBLEMAOOP2_SERIES_H
