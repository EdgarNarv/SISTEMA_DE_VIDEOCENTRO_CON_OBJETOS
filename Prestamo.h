#ifndef PRESTAMO_H
#define PRESTAMO_H


class Prestamo
{
    public:
        Prestamo();
        Prestamo(int,int,char[]);
        int consultarUsuario();
        int consultarPelicula();
        int consultarEstado();
        void devolver(char[]);
        void consultarPrestamo();
    private:
        int user;
        int peli;
        char fechaPrestamo[100];
        char fechaDevolucion[100];
        int prestar=0;
};

#endif // PRESTAMO_H
