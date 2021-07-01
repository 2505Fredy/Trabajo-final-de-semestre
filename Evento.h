#ifndef EVENTO_H
#define EVENTO_H
#include "Almacen.h"


class Evento: public Almacen{
protected:
public:
    explicit Evento(string &_nombreComercial, string &_razonSocial, string &_domicilioFiscal, string &_nroRUC, string &_fin):Almacen(_nombreComercial, _razonSocial, _domicilioFiscal, _nroRUC, _fin){}
    Evento& Instancia(string &_nombreComercial, string &_razonSocial, string &_domicilioFiscal, string &_nroRUC, string &_fin){
        static Evento evento(_nombreComercial, _razonSocial, _domicilioFiscal, _nroRUC, _fin);
        return evento;
    }
    void limpiar();
    void pausar();
    void salir();

    void verificarContrasenha(string rol, int indice);
    //Menús impresión
    int modo();
    int inicio();
    int menu(string modo);
    int escogerSeccion();
    int escogerEmpleadoEspecifico();
    int menuAdminPersonal();
    int menuAdminProductos(string &seccion);
    int menuAdminEmpleados();
    int menuAdminEmpleadoEspecifico(int numero);
    void eliminarEmpleadoValidacion(int indice);
    int menuModificarDatosProductos(string &seccion);
    int escogerProductoEspecifico(string &seccion);
    void modificarDatosProductos(string &seccion, string seccionMod);
    int menuBuscarProductos(string &seccion);
    void buscarProductos(string metodo, string &seccion);
    void dataRegistrarProducto(string &seccion);
    void dataRegistrarEmpleado();

    int menuModificarDatos(string modo);
    void modificarDatosUsuario(string seccion);
    void modificarDatosUsuario(string seccion, int indice);

    int menuSacarProducto(int indiceEmpleado);
    int menuEntrarProducto(int indiceEmpleado);
    void sacarProducto(int indiceEmpleado);
    void entrarProducto(int indiceEmpleado);
};


#endif // EVENTO_H
