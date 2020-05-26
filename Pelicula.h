#ifndef PELICULA_H
#define PELICULA_H
/*Titulo: Titanes del pacifico

Director: Guillermo del Toro

Año: 2013

Genero: Acción

Productora: Legendary pictures

Minutos: 131*/

class Pelicula
{
    public://metodos
        Pelicula();
        Pelicula(char[],char[],int,char[],char [],int);
        void consultarPelicula();
    private://atributos
        char titulo[100];
        char director[100];
        int annio;
        char genero[100];
        char productora[100];
        int minutos;

};

#endif // PELICULA_H
