#include <iostream>
#include "Prestamo.h"
#include "Usuario.h"
#include "Pelicula.h"

using namespace std;
/*Las opciones del programa son las siguientes:
·Administrar usuarios (registrar, editar, consultar, eliminar).
·Administrar películas (registrar, editar, consultar [ mostrar los prestamos ], eliminar).
·Administrar prestamos (realizar préstamo, devolver películas).*/
void menuPrincipal()
{
    cout<<".........MENU PRINCIPAL........"<<endl;
    cout<<".                             ."<<endl;
    cout<<".    1.-Administrar Usuarios  ."<<endl;
    cout<<".    2.-Administrar Peliculas ."<<endl;
    cout<<".    3.-Administrar Prestamos ."<<endl;
    cout<<".                             ."<<endl;
    cout<<"..............................."<<endl;

}
void menuPeliculas()
{
    cout<<".........MENU PELICULAS........"<<endl;
    cout<<".                             ."<<endl;
    cout<<".    1.-Registrar Pelicula    ."<<endl;
    cout<<".    2.-Editar Pelicula       ."<<endl;
    cout<<".    3.-Consultar Pelicula    ."<<endl;
    cout<<".    4.-Eliminar Pelicula     ."<<endl;
    cout<<".                             ."<<endl;
    cout<<"..............................."<<endl;

}
void menuUsuarios()
{
    cout<<".........MENU USUARIOS........."<<endl;
    cout<<".                             ."<<endl;
    cout<<".    1.-Registrar Usuario     ."<<endl;
    cout<<".    2.-Editar Usuario        ."<<endl;
    cout<<".    3.-Consultar Usuario     ."<<endl;
    cout<<".    4.-Eliminar Usuario      ."<<endl;
    cout<<".                             ."<<endl;
    cout<<"..............................."<<endl;

}
void menuPrestamos()
{
    cout<<".........MENU PRESTAMOS........"<<endl;
    cout<<".                             ."<<endl;
    cout<<".    1.-Realizar Prestamo     ."<<endl;
    cout<<".    2.-Devolver Pelicul      ."<<endl;
    cout<<".    3.-Consultar Prestam     ."<<endl;
    cout<<".                             ."<<endl;
    cout<<"..............................."<<endl;

}
Usuario registrarUsuario()
{
    char nombre[100],nacionalidad[100];
    int edad;
    cout<<"Nombre:"<<endl;
    cin>>nombre;
    cout<<"Edad:"<<endl;
    cin>>edad;
    cout<<"Nacionalidad:"<<endl;
    cin>>nacionalidad;

    return Usuario(nombre,edad,nacionalidad);
}
Prestamo registroPrestamos(int peli)
{
    int user=0;
    char fechaPrestamo[100];

    cout<<"No. de usuario"<<endl;
    cin>>user;
    cout<<"Fecha en la que se presta el libro"<<endl;
    cin>>fechaPrestamo;

    return Prestamo(user,peli,fechaPrestamo);
}
void mostrarPeliculas(Pelicula peliculas[10],int peliculasC){
    cout<<"........Peliculas Disponibles......."<<endl;
    for (int x = 0; x < peliculasC; ++x)
    {
        cout<<"Libro "<<x<<":"<<endl;
        peliculas[x].consultarPelicula();
    }
    cout<<"...................................."<<endl;
}
Pelicula registrarPelicula()
{
    char titulo[100],director[100],genero[100],productora[100];
    int annio,minutos;
    cout<<"Titulo:"<<endl;
    cin>>titulo;
    cout<<"Director:"<<endl;
    cin>>director;
    cout<<"Annio:"<<endl;
    cin>>annio;
    cout<<"Genero: "<<endl;
    cin>>genero;
    cout<<"Productora:"<<endl;
    cin>>productora;
    cout<<"Minutos:"<<endl;
    cin>>minutos;

    return Pelicula(titulo,director,annio,genero,productora,minutos);
}
int main()
{
    /*char titulo[100];
        char director[100]:
        char genero[100];
        char productora[100];
        char nombre[100];
        char nacionalidad[100];*/
    int op,num,user,prestar,peliculasC=0,usuariosC=0,prestamoC=0,tP;

    char fechaPrestamo[100],fechaDevolucion [100];

    Pelicula peliculas[10];
    Usuario usuarios[10];
    Prestamo prestamos[100];

    bool on=true,temporal=true;
    while (on==true)
    {
        menuPrincipal();
        cin>>op;
        switch (op)
        {
            case 1:
                menuUsuarios();
                cin>>op;
                switch(op)
                {
                    case 1:
                        cout<<".......REGISTRAR USUARIO......"<<endl;
                        cout<<endl;

                        usuarios[usuariosC]=registrarUsuario();
                        cout<<endl;
                        cout<<"......Usuario Registrado......."<<endl;
                        cout<<"No. Usuario: "<<usuariosC<<endl;

                        usuariosC++;
                        break;
                    case 2:
                        cout<<"........EDITAR USUARIO........."<<endl;
                        cout<<endl;
                        cout<<"Ingrese el numero de usuario:"<<endl;
                        cin>>num;
                        usuarios[num]=registrarUsuario();
                        cout<<endl;
                        cout<<"........Usuario Editado........"<<endl;
                        break;
                    case 3:
                        cout<<".......CONSULTAR USUARIO......."<<endl;
                        cout<<endl;
                        cout<<"Ingrese el numero de usuario:"<<endl;
                        cin>>num;
                        cout<<endl;
                        cout<<".........USUARIO "<<num<<"........"<<endl;
                        usuarios[num].consultarUsuario();
                        cout<<endl;
                        cout<<"..............................."<<endl;
                        for (int i = 0; i < prestamoC; ++i) {
                            if(prestamos[i].consultarUsuario() == num){

                                tP = prestamos[num].consultarPelicula();
                                peliculas[tP].consultarPelicula();

                                prestamos[i].consultarPrestamo();
                            }
                        }
                        break;
                    case 4:
                        cout<<"........ELIMINAR USUARIO........"<<endl;
                        cout<<endl;
                        cout<<"Ingrese el numero de usuario:"<<endl;
                        cin>>num;

                        temporal=true;
                        for (int x=0;x<prestamoC;x++){
                            if (num==prestamos[x].consultarUsuario() && prestamos[x].consultarEstado()==1){
                                temporal=false;
                            }
                        }
                        if (temporal==true){
                            usuarios[num]=Usuario();
                            cout<<"Usuario eliminado con exito"<<endl;


                        }else{
                            cout<<"Este usuario no puede ser eliminado"<<endl;
                            cout<<"     Tiene un prestamo activo"<<endl;
                        }

                        break;

                    default:
                        cout<<"............MENU PRINCIPAL........."<<endl;
                        break;
                }

                break;
            case 2:
                menuPeliculas();
                cin>>op;
                switch (op)
                {
                    case 1:
                        cout<<".......REGISTRAR PELICULA......"<<endl;
                        cout<<endl;

                        peliculas[peliculasC]=registrarPelicula();
                        cout<<endl;
                        cout<<"......Pelicula Registrado......."<<endl;
                        cout<<"No. Pelicula: "<<peliculasC<<endl;

                        peliculasC++;
                        break;
                    case 2:
                        cout<<"........EDITAR PELICULA........."<<endl;
                        cout<<endl;
                        cout<<"Ingrese el numero de pelicula:"<<endl;
                        cin>>num;
                        peliculas[num]=registrarPelicula();
                        cout<<endl;
                        cout<<"........Pelicula Editado........"<<endl;
                        break;
                    case 3:
                        cout<<".......CONSULTAR Pelicula......."<<endl;
                        cout<<endl;
                        cout<<"Ingrese el numero de pelicula:"<<endl;
                        cin>>num;
                        cout<<endl;
                        cout<<".........PELICULA "<<num<<"........"<<endl;
                        peliculas[num].consultarPelicula();
                        cout<<endl;
                        cout<<"..............................."<<endl;
                        cout << "Informacion de prestamos"<<endl;
                        for (int i = 0; i < prestamoC; ++i) {
                            if(prestamos[i].consultarPelicula() == num){

                                //imprime el detalle del libro
                                tP = prestamos[num].consultarUsuario();
                                usuarios[tP].consultarUsuario();

                                //imprime el detalle del prestamo
                                prestamos[i].consultarPrestamo();
                            }
                        }
                        break;
                    case 4:
                        cout<<"........ELIMINAR PELICULA........"<<endl;
                        cout<<endl;
                        cout<<"Ingrese el numero de pelicula:"<<endl;
                        cin>>num;

                        temporal=true;
                        for (int x=0;x<prestamoC;x++){
                            if (num==prestamos[x].consultarPelicula() && prestamos[x].consultarEstado()==1){
                                temporal=false;
                            }
                        }
                        if (temporal==true){
                            peliculas[num]=Pelicula();
                            cout<<"Pelicula eliminado con exito"<<endl;


                        }else{
                            cout<<"Esta pelicula no puede ser eliminada"<<endl;
                            cout<<"     Esta prestada actualmente"<<endl;
                        }
                        break;

                    default:
                        cout<<"............MENU PRINCIPAL........."<<endl;
                        break;
                }
                break;
            case 3:
                menuPrestamos();
                cin>>op;
                switch(op){
                    case 1:
                        cout<<"...............PRESTAMOS............"<<endl;

                        mostrarPeliculas(peliculas,peliculasC);
                        cout<<endl;
                        cout<<"Ingrese el numero de pelicula"<<endl;
                        cin>>num;

                        temporal=true;
                        for (int x=0;x<prestamoC;x++){
                            if (num==prestamos[x].consultarPelicula() && prestamos[x].consultarEstado()==1){
                                temporal=false;
                            }
                        }
                        if (temporal==true){
                            prestamos[prestamoC]=registroPrestamos(num);
                            cout<<"..........Prestamo Realizado.........."<<endl;
                            cout<<"No. Prestamo: "<<prestamoC<<endl;
                            prestamoC++;
                        }else{
                            cout<<"Este pelicula ya ha sido prestado"<<endl;
                        }

                        break;
                    case 2:
                        cout<<".............DEVOLUCION.............."<<endl;
                        cout<<"No. Prestamo"<<endl;
                        cin>>num;
                        cout<<endl;

                        peliculas[prestamos[num].consultarPelicula()].consultarPelicula();

                        cout<<endl;

                        prestamos[num].consultarPrestamo();
                        cout<<endl;
                        cout<<"....................................."<<endl;

                        if (prestamos[num].consultarEstado()==1){
                            cout<<"Fecha devolucion"<<endl;
                            cin>>fechaDevolucion;

                            prestamos[num].devolver(fechaDevolucion);

                            cout<<".........Libro Devuelto........"<<endl;

                        }else{
                            cout<<"..El libro ya ha sido devuelto.."<<endl;
                        }
                        break;
                    case 3:
                        cout<<"........Consultar Prestamos........."<<endl;
                        cout<<"Numero de prestamo:"<<endl;
                        cin>>num;
                        cout<<"...................................."<<endl;
                        cout<<endl;
                        cout<<"...................................."<<endl;
                        usuarios[prestamos[num].consultarUsuario()].consultarUsuario();
                        cout<<"...................................."<<endl;
                        cout<<endl;
                        cout<<"...................................."<<endl;
                        peliculas[prestamos[num].consultarPelicula()].consultarPelicula();
                        cout<<"...................................."<<endl;
                        cout<<endl;
                        cout<<"...................................."<<endl;
                        prestamos[num].consultarPrestamo();
                        cout<<"...................................."<<endl;
                        break;
                    default:
                        cout<<".............Menu principal............."<<endl;
                        break;

                }
                break;
            default:
                cout<<".....Vuelva Pronto....."<<endl;
                on=false;
                break;
            }
    }
    return 0;
}
