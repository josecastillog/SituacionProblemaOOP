//
// Created by jmcg0 on 8/24/2021.
//

#ifndef SITUACIONPROBLEMAOOP2_PELICULA_H
#define SITUACIONPROBLEMAOOP2_PELICULA_H

#include "Video.h"

class Pelicula : public Video {
private:
    int oscares;
public:
    // Constructores
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Setters y getters
    void setOscares(int _oscares);
    int getOscares();

    // Metodo str()
    string str();

    // Sobrecarga operador <<
    friend std::ostream& operator<< (std::ostream &out, const Pelicula &pelicula);
};

#endif //SITUACIONPROBLEMAOOP2_PELICULA_H
