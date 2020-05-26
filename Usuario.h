#ifndef USUARIO_H
#define USUARIO_H


class Usuario
{
    public://metodo
        Usuario();
        Usuario(char[],int,char[]);
        void consultarUsuario();
    private://atributos
        char nombre[100];
        int edad;
        char nacionalidad[100];
};

#endif // USUARIO_H
