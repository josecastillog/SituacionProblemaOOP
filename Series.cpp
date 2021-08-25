//
// Created by jmcg0 on 8/24/2021.
//

#include "Series.h"
#include <sstream>
#include <fstream>

Series::Series()
{
    for(int iS; iS < MAX_SERIES; iS++)
        arrPtrSeries[iS] = nullptr;
}

void Series::leerArchivo()
{
    // Declaracion de variables para usar al leer cada linea
    string linea, dato, row[6];
    // Variable para llevar el contador de cantidad de series leidas del archivo
    int iRow{}, iS{}, cantEpisodios{};
    // Declaracion de variable para el archivo
    fstream lectura;
    Episodio *episodio;
    // --------------Leer Series----------------
    lectura.open("C:\\Users\\jmcg0\\CLionProjects\\SituacionProblemaOOP2\\serie.csv", ios::in);
    // Inicializar el atributo cantidad de Series con 0
    cantidad = 0;
    // Ciclo para leer todoo el archivo
    while(getline(lectura, linea))
    {
        // cout << linea << endl; // BORRAR
        stringstream registro(linea);
        iRow = 0;
        // Ciclo para separar los elementos de la Serie (string)
        while(getline(registro, dato, ','))
        {
            // Sepraramos elementos de la serie leida
            //cout << dato << endl;
            row[iRow++] = dato;
        }
        // Crear un objeto de la clase Serie, new retorna un pointer
        arrPtrSeries[cantidad] = new Serie(row[0], row[1], stoi(row[2]), row[3],
                                           stod(row[4]), 0);
        // Para verificar si se incializo correctamente el objeto
        arrPtrSeries[cantidad]->str(); // BORRAR
        // Vamos por la siguiente serie del archivo, se incrementa para la siguiente
        cantidad++;
    }
    lectura.close();

    // ------------ Leer los Episodios de las Series ------------
    lectura.open("C:\\Users\\jmcg0\\CLionProjects\\SituacionProblemaOOP2\\episodio.csv", ios::in);
    // Ciclo para leer todo el archivo
    while(getline(lectura, linea))
    {
        // Desplegar el episodio leido - solo para corroborar
        // cout << linea << endl; // BORRAR
        stringstream registro(linea);

        iRow = 0;
        while(getline(registro, dato, ',')) // Separar los datos del episodio
            {
            row[iRow++] = dato;
            }
        // Al salir de aqui separa toda la linea

        // iD - convertir int - sacar la posicion de la serie 500 - 0, 501 - 1, 502
        iS = stoi(row[0]) - 500; // posicion del arreglo donde esta el ptr de la serie pertenece
        // el episodio
        // Crear el Episodio
        episodio = new Episodio(row[1], stoi(row[2]), stod(row[3]));
        // Traer la cantidad de episodios de la serie iS - la 1a vez retorna 0
        cantEpisodios = arrPtrSeries[iS]->getCantidad();
        // Verificar si todavia podemos anadir otro Episodio al arreglo
        if(cantEpisodios < 5)
        {
            arrPtrSeries[iS]->setEpisodio(*(episodio), cantEpisodios);
            arrPtrSeries[iS]->setCantidad(++cantEpisodios);
        }
        // cout << arrPtrSeries[iS]->str() << endl; // BORRAR

    }
    lectura.close();

    // Desplegar todas las series con sus episodios BORRAR
    // Manda llamar al metodo str() de la clase Serie BORRAR
    // for(int iS = 0; iS < cantidad; iS++) // BORRAR
    //    cout << arrPtrSeries[iS]->str() << endl; // BORRAR

} // Cierra leerArchivo

// Setters
void Series::setPtrSerie(Serie *_ptrSerie)
{
    arrPtrSeries[cantidad] = _ptrSerie;
}
void Series::setCantidadSeries(int _cantidad)
{
    cantidad = _cantidad;
}

// Getters
Serie* Series::getPtrSerie(string sId)
{
    for(int iR = 0; iR < cantidad; iR++)
    {
        if(arrPtrSeries[iR]->getId() == sId)
            return arrPtrSeries[iR];
    }
    return nullptr;
}
int Series::getCantidadSerie()
{
    return cantidad;
}

// Reportes para desplegar en consola
void Series::reporteTodasLasSeries()
{
    double promedio = 0;
    for(int iR = 0; iR < cantidad; iR++)
    {
        cout << *arrPtrSeries[iR] << endl;
        promedio = promedio + arrPtrSeries[iR]->getCalificacion();
    }
    cout << "Promedio Series:" << promedio/cantidad << endl;
}
void Series::reporteConCalificacion(double _cal)
{
    for(int iR = 0; iR < cantidad; iR++)
    {
        if(arrPtrSeries[iR]->getCalificacion() == _cal)
            cout << *arrPtrSeries[iR] << endl;
    }
}
void Series::reporteGenero(string _genero)
{
    for(int iR = 0; iR < cantidad; iR++)
    {
        if(_genero == arrPtrSeries[iR]->getGenero())
            cout << *arrPtrSeries[iR] << endl;
    }
}
void Series::calcularCalificacionSeries()
{
    for(int iR = 0; iR < cantidad; iR++)
    {
        arrPtrSeries[iR]->calculaPromedio();
    }
}
