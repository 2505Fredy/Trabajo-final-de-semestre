#include "Producto.h"

//Gets
string Producto::getSeccion(){
    return seccion;
}
string Producto::getDescripcion(){
    return descripcion;
}
string Producto::getPresentacion(){
    return presentacion;
}
string Producto::getCodigo(){
    return codigo;
}
int Producto::getStock(){
    return stock;
}
float Producto::getPrecio(){
    return precio;
}

//Gets
void Producto::setDescripcion(string &cadena){
    descripcion= cadena;
}
void Producto::setPresentacion(string &cadena){
    presentacion= cadena;
}
void Producto::setPrecio(float numero){
    precio= numero;
}
void Producto::setStock(int numero){
    stock= numero;
}

void Producto::mostrarInfo(string modo){
    if (modo=="table"){
        printf("%s \t %-27s\t%-25s \t %d \t %4.1f \n", codigo.c_str(), descripcion.c_str(), presentacion.c_str(), stock, precio);
    }
    else if (modo=="unit"){
        cout << "================================================INFORMACI\340N DEL PRODUCTO================================================\n";
        cout << "SECCI\340N                   : " << seccion << endl;
        cout << "C\340DIGO                    : " << codigo << endl;
        cout << "DESCRIPCI\340N               : " << descripcion << endl;
        cout << "PRESENTACI\340N              : " << presentacion << endl;
        cout << "STOCK                     : " << stock << endl;
        cout << "PRECIO POR PRESENTACI\340N   : " << precio << endl;
        cout << "========================================================================================================================\n";
    }
}
