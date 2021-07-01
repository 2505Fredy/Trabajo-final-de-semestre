#include "Almacen.h"
int contarProductos(string directorio){
    fstream registro(directorio.c_str(), ios::in);
    int valor=-1;
    string a;
    while(!registro.eof()){
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        valor++;
    }
    registro.close();
    return valor;
}

int contarEmpleados(){
    fstream registro("Data\134DataUsuarios\134DataEmpleados.txt", ios::in);
    int valor=-1;
    string a;
    while(!registro.eof()){
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        valor++;
    }
    registro.close();
    return valor;
}

int contarHistorial(string directorio){
    ifstream registro(directorio.c_str());
    int valor=-1;
    string a;
    while(!registro.eof()){
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        getline(registro, a);
        valor++;
    }
    registro.close();
    return valor;
}

void Almacen::mostrarInfo(){
    cout << "==============================================INFORMACI\340N GENERAL DEL ALMAC\220N===========================================\n";
    PersonaJuridica::mostrarInfo();
    cout << "SECTOR             : " << sector << endl;
    cout << "NRO. DE EMPLEADOS  : " << getSizeEmpleados() << endl;
    cout << "NRO. DE PRODUCTOS  : " << getSizeAbarrotes()+getSizeBebidas()+ getSizeLimpieza() << endl;
    cout << "========================================================================================================================\n";
    system("pause");
}

//Gets
int Almacen::getSizeAbarrotes(){
    return listProductos[0].size();
}
int Almacen::getSizeBebidas(){
    return listProductos[1].size();
}
int Almacen::getSizeLimpieza(){
    return listProductos[2].size();
}
int Almacen::getSizeEmpleados(){
    return listEmpleados.size();
}

void Almacen::registrarFlujoDeProducto(int indiceEmpleado, int indiceProducto, string &tipo, string &cantidad,  string &seccionProducto){
    int valor=0;
    if (seccionProducto=="Bebidas") valor=1;
    else if (seccionProducto=="P. Limpieza") valor=2;
    string descripcion= listProductos[valor][indiceProducto].getDescripcion(), codigoEmpleado= listEmpleados[indiceEmpleado].getCodigo();
    Orden orden(tipo, seccionProducto, descripcion, cantidad, codigoEmpleado);
    cargarHistorialAdmin();
    administrador[0].addOrdenHistorialInicio(orden);
    guardarHistorialAdmin();
    cargarHistorialEmpleado(indiceEmpleado);
    listEmpleados[indiceEmpleado].addOrdenHistorialInicio(orden);
    guardarHistorialEmpleado(indiceEmpleado);
}


//Lista de empleados
void Almacen::mostrarListEmpleados(){
    int valor= listEmpleados.size();
    printf("CODIGO \t NOMBRE USUARIO  NOMBRE COMPLETO  \t\t DNI \t\t DIRECCI\340N \n");
    cout << "========================================================================================================================\n";
    for(int i=0; i<valor; i++){
        listEmpleados[i].mostrarInfo("table");
    }
    cout << "========================================================================================================================\n";
    system("pause");
}


//Empleado
void Almacen::mostrarInfoEmpleado(int indice){
    listEmpleados[indice].mostrarInfo("unit");
}
void Almacen::cargarHistorialEmpleado(int indice){
    listEmpleados[indice].borrarHistorial();
    string hora, fecha, tipo, seccion, descripcion, cantidad, nombre;
    ifstream registro(listEmpleados[indice].getDirectorio().c_str());
    for (int i=0; i<contarHistorial(listEmpleados[indice].getDirectorio()); i++){
        getline(registro, hora);
        getline(registro, fecha);
        getline(registro, tipo);
        getline(registro, seccion);
        getline(registro, descripcion);
        getline(registro, cantidad);
        getline(registro, nombre);
        Orden orden(hora, fecha, tipo, seccion, descripcion, cantidad, nombre);
        listEmpleados[indice].addOrdenHistorialFinal(orden);
    }
    registro.close();
}
void Almacen::mostrarHistorialEmpleado(int indice){
    cargarHistorialEmpleado(indice);
    listEmpleados[indice].mostrarHistorial();
}
void Almacen::guardarHistorialEmpleado(int indice){
    int valor= listEmpleados[indice].getDimensionHistorial();
    ofstream registro(listEmpleados[indice].getDirectorio().c_str());
    for (int i=0; i<valor; i++){
        registro << listEmpleados[indice].getDataHistorial(i, "hora") << endl;
        registro << listEmpleados[indice].getDataHistorial(i, "fecha") << endl;
        registro << listEmpleados[indice].getDataHistorial(i, "tipo") << endl;
        registro << listEmpleados[indice].getDataHistorial(i, "seccion") << endl;
        registro << listEmpleados[indice].getDataHistorial(i, "descripcion") << endl;
        registro << listEmpleados[indice].getDataHistorial(i, "cantidad") << endl;
        registro << listEmpleados[indice].getDataHistorial(i, "codigo") << endl;
    }
    registro.close();
    listEmpleados[indice].borrarHistorial();
}
void Almacen::modificarDatosEmpleado(int indice, string seccionMod, string &cadena){
    if (seccionMod=="nombre") listEmpleados[indice].setNombre(cadena);
    else if (seccionMod=="nombreUsuario") listEmpleados[indice].setNombreUsuario(cadena);
    else if (seccionMod=="direccion") listEmpleados[indice].setDireccion(cadena);
    else if (seccionMod=="contrasenha") listEmpleados[indice].setContrasenha(cadena);
}

//Administrador
void Almacen::mostrarInfoAdmin(){
    administrador[0].mostrarInfo("unit");
}
void Almacen::cargarHistorialAdmin(){
    administrador[0].borrarHistorial();
    string hora, fecha, tipo, seccion, descripcion, cantidad, nombre;
    ifstream registro(administrador[0].getDirectorio().c_str());
    for (int i=0; i<contarHistorial(administrador[0].getDirectorio()); i++){
        getline(registro, hora);
        getline(registro, fecha);
        getline(registro, tipo);
        getline(registro, seccion);
        getline(registro, descripcion);
        getline(registro, cantidad);
        getline(registro, nombre);
        Orden orden(hora, fecha, tipo, seccion, descripcion, cantidad, nombre);
        administrador[0].addOrdenHistorialFinal(orden);
    }
    registro.close();
}
void Almacen::mostrarHistorialAdmin(){
    cargarHistorialAdmin();
    administrador[0].mostrarHistorial();
}
void Almacen::guardarHistorialAdmin(){
    int valor= administrador[0].getDimensionHistorial();
    ofstream registro(administrador[0].getDirectorio().c_str());
    for (int i=0; i<valor; i++){
        registro << administrador[0].getDataHistorial(i, "hora") << endl;
        registro << administrador[0].getDataHistorial(i, "fecha") << endl;
        registro << administrador[0].getDataHistorial(i, "tipo") << endl;
        registro << administrador[0].getDataHistorial(i, "seccion") << endl;
        registro << administrador[0].getDataHistorial(i, "descripcion") << endl;
        registro << administrador[0].getDataHistorial(i, "cantidad") << endl;
        registro << administrador[0].getDataHistorial(i, "codigo") << endl;
    }
    registro.close();
    administrador[0].borrarHistorial();
}
void Almacen::modificarDatosAdmin(string seccionMod, string &cadena){
    if (seccionMod=="nombre") administrador[0].setNombre(cadena);
    else if (seccionMod=="nombreUsuario") administrador[0].setNombreUsuario(cadena);
    else if (seccionMod=="direccion") administrador[0].setDireccion(cadena);
    else if (seccionMod=="contrasenha") administrador[0].setContrasenha(cadena);
}



void Almacen::registrarEmpleado(Usuario &empleado){
    listEmpleados.push_back(empleado);
}

void Almacen::eliminarEmpleado(int indice){
    listEmpleados.erase(listEmpleados.begin()+indice);
}

void Almacen::registrarProducto(Producto &producto){
    if (producto.getSeccion()=="Abarrotes"){
        listProductos[0].push_back(producto);
    }
    else if (producto.getSeccion()=="Bebidas"){
        listProductos[1].push_back(producto);
    }
    else if (producto.getSeccion()=="Limpieza"){
        listProductos[2].push_back(producto);
    }
}

void Almacen::eliminarProducto(int indice, string &seccion){
    int valor;
    if (seccion=="Abarrotes") valor=0;
    else if (seccion=="Bebidas") valor=1;
    else if (seccion=="P. Limpieza") valor=2;
    listProductos[valor].erase(listProductos[valor].begin()+indice);
}

void Almacen::mostrarListProductos(string seccion){
    int valor;
    cout << "========================================================================================================================\n";
    printf("C\340DIGO \t DESCRIPCI\340N \t\t\tPRESENTACI\340N \t\t\t STOCK \t PRECIO\n");
    cout << "========================================================================================================================\n";
    if (seccion=="Abarrotes"){
        valor= listProductos[0].size();
        for (int i=0; i<valor; i++){
            listProductos[0][i].mostrarInfo("table");
        }
        cout << "========================================================================================================================\n";
    }
    else if (seccion=="Bebidas"){
        valor= listProductos[1].size();
        for (int i=0; i<valor; i++){
            listProductos[1][i].mostrarInfo("table");
        }
        cout << "========================================================================================================================\n";
    }
    else if (seccion=="P. Limpieza"){
        valor= listProductos[2].size();
        for (int i=0; i<valor; i++){
            listProductos[2][i].mostrarInfo("table");
        }
        cout << "========================================================================================================================\n";
    }
    system("pause");
}

void Almacen::modificarDatosProductoAtrib(int indice, string &seccion, string atributo, string &cadena){
    int valor;
    if (seccion=="Abarrotes") valor=0;
    else if (seccion=="Bebidas") valor=1;
    else if (seccion=="P. Limpieza") valor=2;

    if (atributo=="descripcion") listProductos[valor][indice].setDescripcion(cadena);
    else if (atributo=="presentacion") listProductos[valor][indice].setPresentacion(cadena);
}

void Almacen::modificarDatosProductoPrecio(int indice, string &seccion, float numero){
    int valor;
    if (seccion=="Abarrotes") valor=0;
    else if (seccion=="Bebidas") valor=1;
    else if (seccion=="P. Limpieza") valor=2;
    listProductos[valor][indice].setPrecio(numero);
}




void Almacen::cargarInfo(){
        ifstream registro("Data\134DataUsuarios\134DataAdmin.txt");
        string codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio;
        getline(registro, codigo);
        getline(registro, nombre);
        getline(registro, nombreUsuario);
        getline(registro, direccion);
        getline(registro, DNI);
        getline(registro, contrasenha);
        getline(registro, directorio);
        administrador.push_back(Usuario{codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio, "Administrador"});
        registro.close();

        registro.open("Data\134DataUsuarios\134DataEmpleados.txt");
        for (int i=0; i<contarEmpleados(); i++){
            getline(registro, codigo);
            getline(registro, nombre);
            getline(registro, nombreUsuario);
            getline(registro, direccion);
            getline(registro, DNI);
            getline(registro, contrasenha);
            getline(registro, directorio);
            listEmpleados.push_back(Usuario{codigo, nombre, nombreUsuario, direccion, DNI, contrasenha, directorio, "Empleado"});
        }
        registro.close();

        //Cargar Abarrotes
        registro.open("Data\134DataProductos\134DataAbarrotes.txt");
        string descripcion, presentacion, cantidad, precio;
        for (int i=0; i<contarProductos("Data\134DataProductos\134DataAbarrotes.txt"); i++){
            getline(registro, codigo);
            getline(registro, descripcion);
            getline(registro, presentacion);
            getline(registro, cantidad);
            getline(registro, precio);
            int stock= stoi(cantidad); float price= stof(precio);
            listProductos[0].push_back(Producto{"Abarrotes", codigo, descripcion, presentacion, stock, price});
        }
        registro.close();
        //Cargar Bebidas
        registro.open("Data\134DataProductos\134DataBebidas.txt");
        for (int i=0; i<contarProductos("Data\134DataProductos\134DataBebidas.txt"); i++){
            getline(registro, codigo);
            getline(registro, descripcion);
            getline(registro, presentacion);
            getline(registro, cantidad);
            getline(registro, precio);
            int stock= stoi(cantidad); float price= stof(precio);
            listProductos[1].push_back(Producto{"Bebidas", codigo, descripcion, presentacion, stock, price});
        }
        registro.close();
        //Cargar Limpieza
        registro.open("Data\134DataProductos\134DataLimpieza.txt");
        for (int i=0; i<contarProductos("Data\134DataProductos\134DataLimpieza.txt"); i++){
            getline(registro, codigo);
            getline(registro, descripcion);
            getline(registro, presentacion);
            getline(registro, cantidad);
            getline(registro, precio);
            int stock= stoi(cantidad); float price= stof(precio);
            listProductos[2].push_back(Producto{"P. Limpieza", codigo, descripcion, presentacion, stock, price});
        }
        registro.close();

}

void Almacen::guardarInfo(){
    ofstream registro("Data\134DataUsuarios\134DataAdmin.txt");
    registro << administrador[0].getCodigo() << endl;
    registro << administrador[0].getNombre() << endl;
    registro << administrador[0].getNombreUsuario() << endl;
    registro << administrador[0].getDireccion() << endl;
    registro << administrador[0].getDNI() << endl;
    registro << administrador[0].getContrasenha() << endl;
    registro << administrador[0].getDirectorio() << endl;
    registro.close();
    registro.open("Data\134DataUsuarios\134DataEmpleados.txt");
    int valor= listEmpleados.size();
    for (int i=0; i<valor; i++){
        registro << listEmpleados[i].getCodigo() << endl;
        registro << listEmpleados[i].getNombre() << endl;
        registro << listEmpleados[i].getNombreUsuario() << endl;
        registro << listEmpleados[i].getDireccion() << endl;
        registro << listEmpleados[i].getDNI() << endl;
        registro << listEmpleados[i].getContrasenha() << endl;
        registro << listEmpleados[i].getDirectorio() << endl;
    }
    registro.close();
    registro.open("Data\134DataProductos\134DataAbarrotes.txt");
    valor= listProductos[0].size();
    for (int i=0; i<valor; i++){
        registro << listProductos[0][i].getCodigo() << endl;
        registro << listProductos[0][i].getDescripcion() << endl;
        registro << listProductos[0][i].getPresentacion() << endl;
        registro << listProductos[0][i].getStock() << endl;
        registro << listProductos[0][i].getPrecio() << endl;
    }
    registro.close();
    registro.open("Data\134DataProductos\134DataBebidas.txt");
    valor= listProductos[1].size();
    for (int i=0; i<valor; i++){
        registro << listProductos[1][i].getCodigo() << endl;
        registro << listProductos[1][i].getDescripcion() << endl;
        registro << listProductos[1][i].getPresentacion() << endl;
        registro << listProductos[1][i].getStock() << endl;
        registro << listProductos[1][i].getPrecio() << endl;
    }
    registro.close();
    registro.open("Data\134DataProductos\134DataLimpieza.txt");
    valor= listProductos[2].size();
    for (int i=0; i<valor; i++){
        registro << listProductos[2][i].getCodigo() << endl;
        registro << listProductos[2][i].getDescripcion() << endl;
        registro << listProductos[2][i].getPresentacion() << endl;
        registro << listProductos[2][i].getStock() << endl;
        registro << listProductos[2][i].getPrecio() << endl;
    }
    registro.close();
    return;
}
