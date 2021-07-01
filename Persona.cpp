#include "Persona.h"

PersonaJuridica::PersonaJuridica(string &_nombreComercial, string &_razonSocial, string &_domicilioFiscal, string &_nroRUC, string &_fin){
    nacionalidad= "PERUANA";
    tipoIdentificacion= "RUC";
    nombreComercial= _nombreComercial;
    razonSocial= _razonSocial;
    domicilioFiscal= _domicilioFiscal;
    nroRUC= _nroRUC;
    fin= _fin;
}

PersonaNatural::PersonaNatural(string &_nombresyApellidos, string &_nroDNI, string &_domicilio, int _edad){
    nacionalidad= "PERUANA";
    tipoIdentificacion= "DNI";
    nombresyApellidos= _nombresyApellidos;
    nroDNI= _nroDNI;
    domicilio= _domicilio;
    edad= _edad;
}

void PersonaJuridica::mostrarInfo(){
    cout << "NACIONALIDAD       : " << nacionalidad << endl;
    cout << "NOMBRE COMERCIAL   : " << nombreComercial << endl;
    cout << "RAZ\340N SOCIAL       : " << razonSocial << endl;
    cout << "DOMICILIO FISCAL   : " << domicilioFiscal << endl;
    cout << "N\351MERO DE " << tipoIdentificacion << "      : " << nroRUC << endl;
    cout << "FINALIDAD          : " << fin << endl;
}

void PersonaNatural::mostrarInfo(){
    cout << "NACIONALIDAD       : " << nacionalidad << endl;
    cout << "NOMBRES Y APELLIDOS: " << nombresyApellidos << endl;
    cout << "N\351MERO DE " << tipoIdentificacion << "   : " << endl;
    cout << "EDAD               : " << edad << endl;
}
