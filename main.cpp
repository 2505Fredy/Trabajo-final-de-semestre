#include "Ejecucion.h"

int main(){
    int numero;
    Evento *evento= Evento::getInstancia();
    cout << "Desea ejecutar el programa?\n-. SI\n2. NO\n";
    cin >> numero;
    if (numero==2) evento->salir();
    evento->mostrarInfo();
    evento->pausar();
    ejecutar();
}
