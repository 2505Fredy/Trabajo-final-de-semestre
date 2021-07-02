#ifndef ORDEN_H
#define ORDEN_H
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

struct Orden{
private:
    string hora, fecha, tipo, seccion, descripcion, cantidad, codigoEmpleado;
public:
    explicit Orden(string &tipo, string &seccion, string &descripcion, string &cantidad, string &codigoEmpleado){
        this->tipo= tipo;
        this->seccion= seccion;
        this->descripcion= descripcion;
        this->cantidad= cantidad;
        this->codigoEmpleado= codigoEmpleado;
        time_t tiempo=time(NULL);
        struct tm *fechas= localtime(&tiempo);
        string dia=to_string(fechas->tm_mday), mes=to_string(fechas->tm_mon+1), anho=to_string(fechas->tm_year+1900);
        string segundo=to_string(fechas->tm_sec), minuto=to_string(fechas->tm_min), horas=to_string(fechas->tm_hour);
        if (dia.size()==1) dia= "0"+dia;
        if (mes.size()==1) mes= "0"+mes;
        if (horas.size()==1) horas= "0"+horas;
        if (minuto.size()==1) minuto= "0"+minuto;
        if (segundo.size()==1) segundo= "0"+segundo;
        this->fecha= dia+"/"+mes+"/"+anho;
        this->hora= horas+":"+minuto+":"+segundo;
    }

    explicit Orden(string &hora, string &fecha, string &tipo, string &seccion, string &descripcion, string &cantidad, string &codigoEmpleado){
        this->hora= hora;
        this->fecha= fecha;
        this->tipo= tipo;
        this->seccion= seccion;
        this->descripcion= descripcion;
        this->cantidad= cantidad;
        this->codigoEmpleado= codigoEmpleado;
    }
    //Gets
    string getHora();
    string getFecha();
    string getTipo();
    string getSeccion();
    string getDescripcion();
    string getCantidad();
    string getCodigoEmpl();

    void mostrarInfo(string &modo);
};

#endif // ORDEN_H
