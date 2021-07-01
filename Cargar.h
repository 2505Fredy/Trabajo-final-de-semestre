#include "Almacen.h"
#include <fstream>

int contarProductos(string &directorio){
    fstream registro(directorio.c_str(), ios::in);
    int valor=-1;
    string a;
    while(!registro.eof()){
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        valor++;
    }
    registro.close();
    return valor;
}

int contarEmpleados(){
    fstream registro("Data\134DataUsuarios\134DataEmpleados.txt", ios::in);
    int valor=-1;
    string a;
    while(!registro.eof()){
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        valor++;
    }
    registro.close();
    return valor;
}


void cargar(Almacen &almacen, string &seccion){
    if (seccion=="admin"){
        fstream registro("Data\134DataUsuarios\134DataAdmin.txt", ios::in);
        string codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio;
        getline(registro, codigo);
        getline(registro, nombre);
        getline(registro, nombreUsuario);
        getline(registro, direccion);
        getline(registro, DNI);
        getline(registro, contrasenha);
        getline(registro, directorio);
        almacen.administrador.push_back(Usuario{codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio, "Administrador"});
        registro.close();
    }
    else if (seccion=="productos"){
        //Cargar Abarrotes
        string cadena= "Data\134DataProductos\134DataAbarrotes.txt";
        fstream registro(cadena.c_str(), ios::in);
        string codigo, descripcion, presentacion, cantidad, precio;
        for (int i=0; i<contarProductos(cadena); i++){
            getline(registro, codigo);
            getline(registro, descripcion);
            getline(registro, presentacion);
            getline(registro, cantidad);
            getline(registro, precio);
            int cant= stoi(cantidad); float price= stof(precio);
            almacen.listProductos[0].push_back(Producto{codigo, descripcion, presentacion, cant, price});
        }
        registro.close();
        //Cargar Bebidas
        cadena= "Data\134DataProductos\134DataBebidas.txt";
        fstream registro(cadena.c_str(), ios::in);
        for (int i=0; i<contarProductos(cadena); i++){
            getline(registro, codigo);
            getline(registro, descripcion);
            getline(registro, presentacion);
            getline(registro, cantidad);
            getline(registro, precio);
            int cant= stoi(cantidad); float price= stof(precio);
            almacen.listProductos[1].push_back(Producto{codigo, descripcion, presentacion, cant, price});
        }
        registro.close();
        //Cargar Limpieza
        cadena= "Data\134DataProductos\134DataLimpieza.txt";
        fstream registro(cadena.c_str(), ios::in);
        for (int i=0; i<contarProductos(cadena); i++){
            getline(registro, codigo);
            getline(registro, descripcion);
            getline(registro, presentacion);
            getline(registro, cantidad);
            getline(registro, precio);
            int cant= stoi(cantidad); float price= stof(precio);
            almacen.listProductos[2].push_back(Producto{codigo, descripcion, presentacion, cant, price});
        }
        registro.close();
    }
    else if (seccion=="empleados"){
        fstream registro("Data\134DataUsuarios\134DataEmpleados.txt", ios::in);
        string codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio;
        for (int i=0; i<contarEmpleados(); i++){
            getline(registro, codigo);
            getline(registro, nombre);
            getline(registro, nombreUsuario);
            getline(registro, direccion);
            getline(registro, DNI);
            getline(registro, contrasenha);
            getline(registro, directorio);
            almacen.listEmpleados.push_back(Usuario{codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio, "Empleado"});
        }
        registro.close();
    }
}
