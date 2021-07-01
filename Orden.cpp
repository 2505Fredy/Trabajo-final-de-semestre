#include "Orden.h"

//Gets
string Orden::getCantidad(){
    return cantidad;
}
string Orden::getHora(){
    return hora;
}
string Orden::getFecha(){
    return fecha;
}
string Orden::getTipo(){
    return tipo;
}
string Orden::getSeccion(){
    return seccion;
}
string Orden::getDescripcion(){
    return descripcion;
}
string Orden::getCodigoEmpl(){
    return codigoEmpleado;
}

void Orden::mostrarInfo(string &modo){//hora, fecha, tipo, seccion, descripcion, cantidad, nombre;
    if (modo=="Administrador"){
        printf("%s     %s   %-6s \t %-11s \t %-25.25s \t %-5s \t %-10s\n", hora.c_str(), fecha.c_str(), tipo.c_str(), seccion.c_str(), descripcion.c_str(), cantidad.c_str(), codigoEmpleado.c_str());
    }
    else if (modo=="Empleado"){
        printf("%s     %s   %-6s \t %-11s \t %-25.25s \t %-5s\n", hora.c_str(), fecha.c_str(), tipo.c_str(), seccion.c_str(), descripcion.c_str(), cantidad.c_str());
    }
}
