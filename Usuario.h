#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <fstream>
#include "Orden.h"
#include "Persona.h"

using namespace std;

class Usuario: public PersonaNatural{
private:
    string cadena;//mandar informacion
protected://string &_nombresyApellidos, string &_nroDNI, string &_domicilio, int _edad
    string codigo, nombreUsuario, contrasenha, directorio, rol;
    vector<Orden> historial;
public:
    explicit Usuario(string &nombresyApellidos_, string &nroDNI_, string &domicilio_, int edad_, string &codigo_, string &nombreUsuario_, string &contrasenha_, string &directorio_, string rol_): PersonaNatural(nombresyApellidos_, nroDNI_, domicilio_, edad_){
        this->codigo= codigo_;
        this->nombreUsuario= nombreUsuario_;
        this->contrasenha= contrasenha_;
        this->directorio= directorio_;
        this->rol= rol_;
        fstream registro(directorio.c_str(), ios::app);
        registro.close();
    }
    explicit Usuario(string &nombresyApellidos_, string &nroDNI_, string &domicilio_, int edad_, string &codigo_, string &nombreUsuario_, string &contrasenha_, string rol_): PersonaNatural(nombresyApellidos_, nroDNI_, domicilio_, edad_){
        this->codigo= codigo_;
        this->nombreUsuario= nombreUsuario_;
        this->contrasenha= contrasenha_;
        this->directorio= "Data\134DataUsuarios\134Historial\134Historial"+nombreUsuario+".txt";
        this->rol= rol_;
        fstream registro(directorio.c_str(), ios::app);
        registro.close();
    }

    string getNombreUsuario();
    string getCodigo();
    string getContrasenha();
    string getDirectorio();
    int getDimensionHistorial();
    string getDataHistorial(int indice, string seccionOrden);

    void setNombreUsuario(string &cadena);
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
