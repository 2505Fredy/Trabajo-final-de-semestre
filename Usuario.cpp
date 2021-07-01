#include "Usuario.h"

void Usuario::mostrarInfo(string modo){
    if (modo=="table"){
        printf("%s \t %-12s \t %-27s \t %s \t %-20s \n", codigo.c_str(), nombreUsuario.c_str(), nombre.c_str(), DNI.c_str(), direccion.c_str());
    }
    else if (modo=="unit"){
        string cadena;
        if (rol=="Administrador"){
            cadena= "========================================INFORMACI\340N DEL ADMINISTRADOR===================================================\n";
        }
        else if (rol=="Empleado"){
            cadena= "==========================================INFORMACI\340N DEL EMPLEADO======================================================\n";
        }
        cout << cadena;
        cout << "C\340DIGO             : " << codigo << endl;
        cout << "NOMBRES Y APELLIDOS: " << nombre << endl;
        cout << "DNI                : " << DNI << endl;
        cout << "DIRECCI\340N          : " << direccion << endl;
        cout << "NOMBRE DE USUARIO  : " << nombreUsuario << endl;
        cout << "CONTRASE\245A         : " << contrasenha << endl;
        cout << "========================================================================================================================\n";
        system("pause");
    }

}
//Gets
string Usuario::getNombre(){
    return nombre;
}
string Usuario::getNombreUsuario(){
    return nombreUsuario;
}
string Usuario::getDireccion(){
    return direccion;
}
string Usuario::getCodigo(){
    return codigo;
}
string Usuario::getContrasenha(){
    return contrasenha;
}
string Usuario::getDNI(){
    return DNI;
}
string Usuario::getDirectorio(){
    return directorio;
}
int Usuario::getDimensionHistorial(){
    return historial.size();
}
string Usuario::getDataHistorial(int indice, string seccionOrden){
    if (seccionOrden=="hora") cadena= historial[indice].getHora();
    else if (seccionOrden=="fecha") cadena= historial[indice].getFecha();
    else if (seccionOrden=="tipo") cadena= historial[indice].getTipo();
    else if (seccionOrden=="seccion") cadena= historial[indice].getSeccion();
    else if (seccionOrden=="descripcion") cadena= historial[indice].getDescripcion();
    else if (seccionOrden=="cantidad") cadena= historial[indice].getCantidad();
    else if (seccionOrden=="codigo") cadena= historial[indice].getCodigoEmpl();
    return cadena;
}


//Sets
void Usuario::setNombre(string &cadena){
    nombre= cadena;
}
void Usuario::setNombreUsuario(string &cadena){
    nombreUsuario= cadena;
}
void Usuario::setDireccion(string &cadena){
    direccion= cadena;
}
void Usuario::setCodigo(string &cadena){
    codigo= cadena;
}
void Usuario::setContrasenha(string &cadena){
    contrasenha= cadena;
}
void Usuario::addOrdenHistorialInicio(Orden &orden){
    historial.insert(historial.begin(), orden);
}
void Usuario::addOrdenHistorialFinal(Orden &orden){
    historial.push_back(orden);
}

void Usuario::borrarHistorial(){
    historial.clear();
}

void Usuario::mostrarHistorial(){
    int valor= historial.size();
    string title= "HORA         FECHA        ORDEN \t SECCI\340N \t DESCRIPCION \t\t\t CANT. \t C\340D. EMPLEADO\n";
    if (rol=="Empleado") title= "HORA         FECHA        ORDEN \t SECCI\340N \t DESCRIPCION \t\t\t CANT. \n";
    if (valor==0){
        cout << "HISTORIAL VAC\326O!\n";
        system("pause");
        return;
    }
    cout << "========================================================================================================================\n";
    cout << title;
    cout << "========================================================================================================================\n";
    for (int i=0; i<valor; i++){
        historial[i].mostrarInfo(rol);
    }
    cout << "========================================================================================================================\n";
    system("pause");
}

bool Usuario::verificarContrasenha(string &cadena){
    if (cadena==contrasenha) return true;
    return false;
}

