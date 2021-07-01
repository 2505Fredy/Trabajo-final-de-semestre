#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Usuario.h"

class Empleado:public Usuario{
protected:
    string codigo, username;
    string registDirect;
public:
    explicit Empleado(string code, string name, string user, string doc, string password):Usuario(name, doc, password){
        codigo= code;
        username= user;
        registDirect="DataEmpleados\134regist"+name+".txt";
        fstream registro(registDirect.c_str(), ios::app);
        registro.close();
    }
    explicit Empleado(string code, string name, string user, string doc, string password, string direc):Usuario(name, doc, password){
        codigo= code;
        username= user;
        registDirect=direc;
        fstream registro(registDirect.c_str(), ios::app);
        registro.close();
    }
    void imprimir(string mode);
    void modificar(string mode);
    void mostrarHistorial();
    void eliminarHistorial();
    void cargarHistorial();
    void guardarHistorial();
    void borrarHistorial();
    int contR();
};

#endif // EMPLEADO_H
