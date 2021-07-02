#ifndef EVENTO_H
#define EVENTO_H
#include "Almacen.h"


class Evento: public Almacen{
protected:
    explicit Evento(string &_nombreComercial, string &_razonSocial, string &_domicilioFiscal, string &_nroRUC, string &_fin):Almacen(_nombreComercial, _razonSocial, _domicilioFiscal, _nroRUC, _fin){}
public:
    static Evento *getInstancia(){//SINGLETON
        string nombreComercial_="ALMACEN LAS MERCEDES", razonSocial_="E.I.R.L.", domicilioFiscal_="Jr. Ramon Castilla No. 1023- Juliaca", nroRUC_= "65234525345", fin_= "Con fines de lucro";
        static Evento evento(nombreComercial_, razonSocial_, domicilioFiscal_, nroRUC_, fin_);
        return &evento;
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
