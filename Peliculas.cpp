//
// Created by jmcg0 on 8/24/2021.
//

#include "Peliculas.h"
#include <sstream>
#include <fstream>

// Constructor
Peliculas::Peliculas()
{
    for(int iR = 0; iR < MAX_PEL; iR++)
        arrPtrPeliculas[iR] = nullptr;
}

// Leer archivo .csv o .txt
void Peliculas::leerArchivo()
{
    // fin - file input
    fstream fin;
    // Para almacenar los datos leidos del archivo :arreglo de strings
    string row[6];
    // line almacena la linea leida, y word la palabra que se saca de line
    string line, word;

    // Abrir archivo de entrada
    fin.open("C:\\Users\\jmcg0\\CLionProjects\\SituacionProblemaOOP2\\peliculas.csv", ios::in);

    // Inicializar el atributo cantidad con 0
    cantidad = 0;

    // Lee una linea del archivo y la almacena en line
    while(getline(fin, line))
    {
        // Despliega en consola la linea - BORRAR O COMENTAR cout's
        // cout << cantidad << line << endl;

        // Usado para separar palabras split()
        stringstream s(line);

        // Read every column data of a row and
        // store it in a string variable, 'word'
        int iR = 0;

        // Extrae caracteres de s y los almacena en word hasta
        // que encuentra el delimitador ','

        while(getline(s, word, ','))
        {
            // Añade la word al arreglo row e incrementa iR p/la proxima palabra
            row[iR++] = word;
        }

        // [0] 100,[1]Pulp Fiction, [2]178, [3]accion, [4]9.2, [5]1
        // Operador new crear objeto del tipo Pelicula - mem dinamica - HEAP
        // stoi - funcion que convierte un string a int
        // stod - funcion que convierte string a double
        arrPtrPeliculas[cantidad] = new Pelicula(row[0], row[1], stoi(row[2]),
                                                 row[3], stod(row[4]), stoi(row[5]));

        // Se muestra en consola la separacion - BORRAR o COMENTAR cout's
        // cout << "iD: " << row[0] << "\n";
        // cout << "Titulo: " << row[1] << "\n";
        // cout << "Duracion: " << row[2] << "\n";
        // cout << "Genero: " << row[3] << "\n";
        // cout << "Calificacion: " << row[4] << "\n";
        // cout << "Oscares : " << row[5] << "\n";

        // Desplegamos en consola la pelicula con el metodo str() de
        // pelicula - BORRAR o COMENTAR cout's
        // cout << "Dentro del objeto:" << arrPtrPeliculas[cantidad]->str() << endl;

        // Incrementar el atributo cantidad para la siguiente pelicula
        cantidad = cantidad + 1;
    }

    fin.close();

    // Sale del ciclo cuando ya no existen mas lineas en el archivo

    // Desplegar todas las peliculas leidas - BORRAR o COMENTAR ciclo con cout's
    //for(int iR = 0; iR < cantidad; iR++) {
    //    cout << iR << "-" << arrPtrPeliculas[iR]->str() << endl;
    //}
}

// Setters
// DUDA EN FIRMA
void Peliculas::setPtrPelicula(Pelicula *ptr, int iS)
{
    arrPtrPeliculas[iS] = ptr;
}

void Peliculas::setCantidadPeliculas(int _cantidad)
{
    cantidad = _cantidad;
}

// Getters
Pelicula* Peliculas::getPtrPelicula(string sId)
{
    for(int iR = 0; iR < cantidad; iR++)
    {
        if(arrPtrPeliculas[iR]->getId() == sId)
            return arrPtrPeliculas[iR];
    }
    return nullptr;
}

int Peliculas::getCantidadPeliculas()
{
    return cantidad;
}

// Reportes etc

void Peliculas::reporteTodasLasPeliculas()
{
    double acum = 0;

    for(int iR = 0; iR < cantidad; iR++)
    {
        cout << *arrPtrPeliculas[iR] << endl;
        acum = acum + arrPtrPeliculas[iR]->getCalificacion();
    }
    // Verificar si existen videos
    if(cantidad > 0)
    {
        cout << "Promedio:" << acum / cantidad << endl;
    }
}

void Peliculas::reporteConCalificacion(double _calificacion)
{
    for(int iR = 0; iR < cantidad; iR++)
    {
        if(_calificacion == arrPtrPeliculas[iR]->getCalificacion())
            cout << *arrPtrPeliculas[iR] << '\n';
    }
}

void Peliculas::reporteGenero(string _genero)
{
    for(int iR = 0; iR < cantidad; iR++)
    {
        if(_genero == arrPtrPeliculas[iR]->getGenero())
            cout << *arrPtrPeliculas[iR] << '\n';
    }
}

