#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <cstring>

using namespace std;

class Persona{
protected:
    string nacionalidad, tipoIdentificacion;
public:
    virtual void mostrarInfo() = 0;
    string getTipoIdentificacion();
};

class PersonaJuridica: public Persona{
protected:
    string nombreComercial, razonSocial, domicilioFiscal, nroRUC, fin;
public:
    PersonaJuridica(string&, string&, string&, string&, string&);
    virtual void mostrarInfo();
    string getNombreComercial();
    string getRazonSocial();
    string getDomicilioFiscal();
    string getNroRUC();
    string getFin();

    void setNombreComercial(string &nombreComercial_);
    void setRazonSocial(string &razonSocial_);
    void setDomicilioFiscal(string &domicilioFiscal_);
};

class PersonaNatural: public Persona{
protected:
    string nombresyApellidos, nroDNI, domicilio;
    int edad;
public:
    PersonaNatural(string&, string&, string&, int);
    virtual void mostrarInfo();
    string getNombresyApellidos();
    string getNroDNI();
    string getDomicilio();
    int getEdad();

    void setNombresyApellidos(string &nombresyApellidos_);
    void setNroDNI(string &nroDNI_);
    void setDomicilio(string &domicilio_);
    void setEdad(int edad_);
};



#endif // PERSONA_H
