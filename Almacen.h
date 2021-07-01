#ifndef ALMACEN_H
#define ALMACEN_H
#include "Usuario.h"
#include "Producto.h"
#include "Persona.h"

class Almacen: public PersonaJuridica{
protected:
    string sector;
    vector <Usuario> listEmpleados;
    vector <Usuario> administrador;
    vector <vector<Producto>> listProductos;
public:
    explicit Almacen(string &_nombreComercial, string &_razonSocial, string &_domicilioFiscal, string &_nroRUC, string &_fin):PersonaJuridica(_nombreComercial, _razonSocial, _domicilioFiscal, _nroRUC, _fin){
        sector= "PRIMARIO (PRODUCTOS DE PRIMERA NECESIDAD)";
        vector <Producto> lista;
        listProductos.push_back(lista);
        listProductos.push_back(lista);
        listProductos.push_back(lista);
    }

    void mostrarInfo();

    int getSizeAbarrotes();
    int getSizeBebidas();
    int getSizeLimpieza();
    int getSizeEmpleados();


    //Lista de Empleados
    void mostrarListEmpleados();
    void registrarEmpleado(Usuario &empleado);
    void eliminarEmpleado(int indice);
    void registrarFlujoDeProducto(int indiceEmpleado, int indiceProducto, string &tipo, string &cantidad,  string &seccionProducto);

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


};

#endif // ALMACEN_H
