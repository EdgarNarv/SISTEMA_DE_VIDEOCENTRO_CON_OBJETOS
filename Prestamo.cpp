#include "Prestamo.h"
#include <cstring>
#include <iostream>
using namespace std;
Prestamo::Prestamo()
{
    //ctor
}

Prestamo::Prestamo(int user,int peli,char fechaPrestamo[100])
{
    this->user=user;
    this->peli=peli;
    strcpy(this->fechaPrestamo,fechaPrestamo);
    this->prestar=1;

}
int Prestamo::consultarUsuario()
{
    return this->user;
}


int Prestamo::consultarPelicula()
{
    return this->peli;
}

void Prestamo::devolver(char fechaDevolucion[100])
{
    strcpy(this->fechaDevolucion,fechaDevolucion);
    this->prestar=0;
}


void Prestamo::consultarPrestamo()
{

    cout<<"Fecha en la que se presto: "<<this->fechaPrestamo<<endl;

    if(this->prestar==1)
    {
        cout<<"Estado: Prestado"<<endl;
    }
    else{
        cout<<"Fecha en la que se devuelve: "<< this->fechaDevolucion<<endl;
        cout<<endl;
        cout<<"Estado: Devuelto"<<endl;
    }

}
int Prestamo::consultarEstado()
{
    return this->prestar;
}
