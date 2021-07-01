#include "Ejecucion.h"

int main(){
    string nombreAlmacen="LAS MERCEDES", razonSocial= "E.I.R.L.", domicilioFiscal= "Jr. Ramon Castilla No. 1023- Juliaca", nroRUC= "65234525345", fin= "Con fines de lucro";
    Evento evento(nombreAlmacen, razonSocial, domicilioFiscal, nroRUC, fin);
    cout << "Hola";
    ejecutar(evento);
}
