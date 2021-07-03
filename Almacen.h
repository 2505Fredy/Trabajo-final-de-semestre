#ifndef ALMACEN_H
#define ALMACEN_H
#include <algorithm>
#include "Usuario.h"
#include "Producto.h"
#include "Persona.h"

class Almacen: public PersonaJuridica{
protected:
    string sector;
    vector <Usuario> listEmpleados;
    vector <Usuario> administrador;
    vector <vector<Producto>> listProductos;
    explicit Almacen(string &_nombreComercial, string &_razonSocial, string &_domicilioFiscal, string &_nroRUC, string &_fin):PersonaJuridica(_nombreComercial, _razonSocial, _domicilioFiscal, _nroRUC, _fin){
        sector= "PRIMARIO (PRODUCTOS DE PRIMERA NECESIDAD)";
        vector <Producto> lista;
        listProductos.push_back(lista);
        listProductos.push_back(lista);
        listProductos.push_back(lista);
    }
public:
    static Almacen *getInstancia(){//SINGLETON
        string nombreComercial_="ALMACEN LAS MERCEDES", razonSocial_="E.I.R.L.", domicilioFiscal_="Jr. Ramon Castilla No. 1023- Juliaca", nroRUC_= "65234525345", fin_= "Con fines de lucro";
        static Almacen almacen(nombreComercial_, razonSocial_, domicilioFiscal_, nroRUC_, fin_);
        return &almacen;
    }

    void mostrarInfo();

    int getSizeAbarrotes();
    int getSizeBebidas();
    int getSizeLimpieza();
    int getSizeEmpleados();
    string getMostrarAtributosEmpleado(int indice, string atributo);
    string getMostrarAtributosProducto(int seccion, int indice, string atributo);
    int getMostrarStockProducto(int seccion, int indice);
    void setStockProducto(int seccion, int indice, int cantidad);
    //Lista de Empleados
    void mostrarListEmpleados();
    void registrarEmpleado(Usuario &empleado);
    void eliminarEmpleado(int indice);
    void registrarFlujoDeProducto(int indiceEmpleado, int indiceProducto, string &tipo, string &cantidad,  string &seccionProducto);
    void ordenarListaEmpleados();

    //Empleado
    void mostrarInfoEmpleado(int indice);
    void cargarHistorialEmpleado(int indice);
    void mostrarHistorialEmpleado(int indice);
    void guardarHistorialEmpleado(int indice);
    void modificarDatosEmpleado(int indice, string seccionMod, string &cadena);

    //Administrador
    void mostrarInfoAdmin();
    void cargarHistorialAdmin();
    void mostrarHistorialAdmin();
    void guardarHistorialAdmin();
    void modificarDatosAdmin(string seccionMod, string &cadena);
    bool verificarContrasenhaAdmin(string &contrasenha);

    //Generalizados
    void cargarInfo();
    void guardarInfo();
    void registrarHistorial();


    //Listas de Productos
    void registrarProducto(Producto &producto);
    void eliminarProducto(int indice, string &seccion);
    void retirarProducto(int cantidad, int indiceEmpleado, int indiceProducto, string seccion);
    void ingresarProducto(int cantidad, int indiceEmpleado, int indiceProducto, string seccion);
    void mostrarListProductos(string seccion);
    void modificarDatosProductoAtrib(int indice, string &seccion, string atributo, string &cadena);
    void modificarDatosProductoPrecio(int indice, string &seccion, float numero);
    void mostrarListProductosTotal();
    void ordenarListaProductos(int seccion);
    void mostrarInfoProducto(int seccion, int indice, string modo);
    bool verificarContrasenhaEmpleado(int indice, string &contrasenha);


};

#endif // ALMACEN_H
