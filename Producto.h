#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <vector>
#include <iostream>
#include <cstring>
#include "Orden.h"

using namespace std;

class Producto{
protected:
    string codigo, descripcion, presentacion, seccion;
    int stock;
    float precio;
public:
    Producto(string seccion, string &codigo, string &descripcion, string &presentacion, int stock, float precio){
        this->seccion= seccion;
        this->codigo= codigo;
        this->descripcion= descripcion;
        this->presentacion= presentacion;
        this->stock= stock;
        this->precio= precio;
    };
    string getCodigo();
    string getSeccion();
    string getDescripcion();
    string getPresentacion();
    int getStock();
    float getPrecio();

    void setDescripcion(string &cadena);
    void setPresentacion(string &cadena);
    void setPrecio(float numero);
    void setStock(int numero);

    void mostrarInfo(string modo);

};


#endif
