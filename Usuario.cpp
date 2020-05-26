#include "Usuario.h"
#include <iostream>
#include <cstring>
using namespace std;

Usuario::Usuario()
{
    //ctor
}

Usuario::Usuario(char nombre[100],int edad,char nacionalidad[100])
{
    strcpy(this->nombre,nombre);
    this->edad=edad;
    strcpy(this->nacionalidad,nacionalidad);
}

void Usuario::consultarUsuario()
{
    cout<<endl;
    cout<<"...........USUARIO............"<<endl;
    cout<<"Nombre: "<<this->nombre<<endl;
    cout<<"Edad: "<<this->edad<<endl;
    cout<<"Nacionalidad: "<<this->nacionalidad<<endl;
}
