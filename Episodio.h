//
// Created by jmcg0 on 8/24/2021.
//

#ifndef SITUACIONPROBLEMAOOP2_EPISODIO_H
#define SITUACIONPROBLEMAOOP2_EPISODIO_H

#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    double calificacion;
public:
    // Constructores
    Episodio();
    Episodio(string _titulo, int _temporada, double _calificacion);

    // Setters
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(double _calificacion);

    // Getters
    string getTitulo();
    int getTemporada();
    double getCalificacion();

    // Str()
    string str();

    // Sobrecarga con friends
    friend std::ostream& operator<< (std::ostream &out, const Episodio &episodio);
};

#endif //SITUACIONPROBLEMAOOP2_EPISODIO_H
