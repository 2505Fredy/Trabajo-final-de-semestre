#include "Ejecucion.h"

int main(){
    string cadena;
    char numero;
    fstream logo("Data\134Logo.txt", ios::in);
        for (int i=0; i<9; i++){
        getline(logo, cadena);
        cout << cadena << endl;
        }
    pausar();
    do{
        limpiar();
        cout << "DESEA CONTINUAR?:\n1. SI\n2. NO\n";
        cin >> numero;
    } while (numero!='1' && numero!='2');
    limpiar();
    if (numero=='1'){
        for (int i=0; i<18; i++){
            getline(logo, cadena);
            cout << cadena << endl;
        }
        logo.close();
        pausar();
        ejecutar();
    }
    logo.close();
    return 0;
}
