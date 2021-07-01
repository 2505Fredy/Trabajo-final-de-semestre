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
    cout << "NACIONALIDAD          : " << nacionalidad << endl;
    cout << "NOMBRE COMERCIAL      : " << nombreComercial << endl;
    cout << "RAZ\340N SOCIAL          : " << razonSocial << endl;
    cout << "DOMICILIO FISCAL      : " << domicilioFiscal << endl;
    cout << "N\351MERO DE " << tipoIdentificacion << "         : " << nroRUC << endl;
    cout << "FINALIDAD             : " << fin << endl;
}

void PersonaNatural::mostrarInfo(){
    cout << "NACIONALIDAD          : " << nacionalidad << endl;
    cout << "NOMBRES Y APELLIDOS   : " << nombresyApellidos << endl;
    cout << "N\351MERO DE " << tipoIdentificacion << "         : " << nroDNI << endl;
    cout << "EDAD                  : " << edad << endl;
}

//Gets Persona
string Persona::getTipoIdentificacion(){
    return tipoIdentificacion;
}
//Gets PersonaJuridica
string PersonaJuridica::getNombreComercial(){
    return nombreComercial;
}
string PersonaJuridica::getRazonSocial(){
    return razonSocial;
}
string PersonaJuridica::getDomicilioFiscal(){
    return nroRUC;
}
string PersonaJuridica::getNroRUC(){
    return nroRUC;
}
string PersonaJuridica::getFin(){
    return fin;
}
//Sets PersonaJuridica
void PersonaJuridica::setNombreComercial(string &nombreComercial_){
    nombreComercial= nombreComercial_;
}
void PersonaJuridica::setRazonSocial(string &razonSocial_){
    razonSocial= razonSocial_;
}
void PersonaJuridica::setDomicilioFiscal(string &domicilioFiscal_){
    domicilioFiscal= domicilioFiscal_;
}
//Gets PersonaNatural
string PersonaNatural::getNombresyApellidos(){
    return nombresyApellidos;
}
string PersonaNatural::getNroDNI(){
    return nroDNI;
}
string PersonaNatural::getDomicilio(){
    return domicilio;
}
int PersonaNatural::getEdad(){
    return edad;
}
//Sets PersonaNatural
void PersonaNatural::setNombresyApellidos(string &nombresyApellidos_){
    nombresyApellidos= nombresyApellidos_;
}
void PersonaNatural::setNroDNI(string &nroDNI_){
    nroDNI= nroDNI_;
}
void PersonaNatural::setDomicilio(string &domicilio_){
    domicilio= domicilio_;
}
void PersonaNatural::setEdad(int edad_){
    edad= edad_;
}
