#include "Almacen.h"


void limpiar();
void pausar();
void salir();

//Funciones impresión
void verificarContrasenha(string rol, int indice);
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
