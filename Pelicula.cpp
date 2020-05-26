#include "Pelicula.h"
#include <iostream>
#include <cstring>

using namespace std;
Pelicula::Pelicula()
{
    //ctor
}

Pelicula::Pelicula(char titulo[100],char director[100],int annio,char genero[100],char productora[100],int minutos)
{
    strcpy(this->titulo,titulo);
    strcpy(this->director,director);
    this->annio=annio;
    strcpy(this->genero,genero);
    strcpy(this->productora,productora);
    this->minutos=minutos;
}

void Pelicula::consultarPelicula()
{
    cout<<endl;
    cout<<".............PELICULA..........."<<endl;
    cout<<"Titulo: "<<this->titulo<<endl;
    cout<<"Director: "<<this->director<<endl;
    cout<<"Annio: "<<this->annio<<endl;
    cout<<"Genero: "<<this->genero<<endl;
    cout<<"Productora: "<<this->productora<<endl;
    cout<<"Minutos: "<<this->minutos<<endl;
}
