//
// Created by jmcg0 on 8/24/2021.
//

#ifndef SITUACIONPROBLEMAOOP2_VIDEO_H
#define SITUACIONPROBLEMAOOP2_VIDEO_H


#include <string>
using namespace std;

class Video {
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacionPromedio;
public:
    // Constructores
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacionPromedio);

    // Setters
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    // Getters
    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    // Metodo str(), virtual porque es clase padre
    virtual string str();
};

#endif //SITUACIONPROBLEMAOOP2_VIDEO_H
