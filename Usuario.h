#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <fstream>
#include "Orden.h"
#include "Persona.h"

using namespace std;

class Usuario{
private:
    string cadena;//mandar informacion
protected:
    string codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio, rol;
    vector<Orden> historial;
public:
    explicit Usuario(string &codigo, string &nombre, string &nombreUsuario, string &direccion, string &DNI, string &contrasenha, string &directorio, string rol){
        this->codigo= codigo;
        this->nombre=  nombre;
        this->nombreUsuario= nombreUsuario;
        this->direccion= direccion;
        this->DNI= DNI;
        this->contrasenha= contrasenha;
        this->directorio= directorio;
        this->rol= rol;
        fstream registro(directorio.c_str(), ios::app);
        registro.close();
    }
    explicit Usuario(string &codigo, string &nombre, string &nombreUsuario, string &direccion, string &DNI, string &contrasenha, string rol){
        this->codigo= codigo;
        this->nombre=  nombre;
        this->nombreUsuario= nombreUsuario;
        this->direccion= direccion;
        this->DNI= DNI;
        this->contrasenha= contrasenha;
        this->directorio= "Data\134DataUsuarios\134Historial\134Historial"+nombreUsuario+".txt";
        this->rol= rol;
        fstream registro(directorio.c_str(), ios::app);
        registro.close();
    }

    string getNombre();
    string getNombreUsuario();
    string getDireccion();
    string getCodigo();
    string getContrasenha();
    string getDNI();
    string getDirectorio();
    int getDimensionHistorial();
    string getDataHistorial(int indice, string seccionOrden);

    void setNombre(string &cadena);
    void setNombreUsuario(string &cadena);
    void setDireccion(string &cadena);
    void setCodigo(string &cadena);
    void setContrasenha(string &cadena);
    void addOrdenHistorialInicio(Orden &orden);
    void addOrdenHistorialFinal(Orden &orden);

    void borrarHistorial();
    void mostrarInfo(string modo);
    void mostrarHistorial();
    bool verificarContrasenha(string &cadena);
};

#endif // USUARIO_H
