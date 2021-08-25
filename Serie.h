//
// Created by jmcg0 on 8/24/2021.
//

#ifndef SITUACIONPROBLEMAOOP2_SERIE_H
#define SITUACIONPROBLEMAOOP2_SERIE_H

#include "Video.h"
#include "Episodio.h"

class Serie : public Video {
private:
    // Arreglo de Episodio
    Episodio episodios[5];
    int cantidad;
public:
    // Constructores
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacionPromedio, int _cantidad);

    // Setters
    void setEpisodio(Episodio _episodios, int index);
    void setCantidad(int _cantidad);

    // Getters
    Episodio getEpisodio(int index);
    int getCantidad();

    // Calcula promedio de una serie con base en episodios
    double calculaPromedio();

    // Metodo str()
    string str();

    // Sobrecarga de operador <<
    friend std::ostream& operator<< (std::ostream &out, const Serie &serie);
};

#endif //SITUACIONPROBLEMAOOP2_SERIE_H
