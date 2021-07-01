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
};

class PersonaJuridica: public Persona{
protected:
    string nombreComercial, razonSocial, domicilioFiscal, nroRUC, fin;
public:
    PersonaJuridica(string&, string&, string&, string&, string&);
    virtual void mostrarInfo();
};

class PersonaNatural: public Persona{
protected:
    string nombresyApellidos, nroDNI, domicilio;
    int edad;
    PersonaNatural(string&, string&, string&, int);
    virtual void mostrarInfo();
};



#endif // PERSONA_H
