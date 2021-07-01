#include "Evento.h"

string dimension= "========================================================================================================================\n";

void Evento::limpiar(){
    system("cls");
}
void Evento::pausar(){
    system("pause");
}

void Evento::salir(){
    guardarInfo();
    exit(0);
}

int Evento::modo(){
    int valor;
    do{
        limpiar();
        cout << "==================================================MODO DE NAVEGACI\340N====================================================\n";
        cout << "Ingrese la opci\242n de navegaci\242n: \n";
        cout << "1. ADMINISTRADOR\n2. EMPLEADO\n3. VER INFORMACI\340N GENERAL DEL ALMAC\220N\n4. SALIR\n";
        cout << dimension;
        cin >> valor;
    }while(valor<1 || 4<valor);
    return valor;
}

int Evento::menu(string modo){
    int valor;
    if (modo=="Administrador"){
        do{
            limpiar();
            cout << "===================================================MEN\351 PRINCIPAL=======================================================\n";
            cout << "Ingrese una opci\242n: \n";
            cout << "1. ADMINISTRAR INFORMACI\340N PERSONAL\n2. ADMINISTRAR PRODUCTOS\n3. ADMINISTRAR EMPLEADOS\n4. VER HISTORIAL\n5. CERRAR SESI\340N\n6. SALIR\n";
            cout << dimension;
            cin >> valor;
        }while(valor<1 || 6<valor);
    }
    else if (modo=="Empleado"){
        do{
            limpiar();
            cout << "===================================================MEN\351 PRINCIPAL=======================================================\n";
            cout << "Ingrese una opci\242n: \n";
            cout << "1. RETIRAR PRODUCTO DEL ALMAC\220N\n2. INGRESAR PRODUCTO AL ALMAC\220N\n3. ADMINISTRAR INFORMACI\340N PERSONAL\n4. VER HISTORIAL\n5. VER INFORMACI\340N PERSONAL\n6. CERRAR SESI\340N\n7. SALIR\n";
            cout << dimension;
            cin >> valor;
        }while(valor<1 || 7<valor);
    }
    return valor;
}

int Evento::menuAdminPersonal(){
    int valor;
    do{
        limpiar();
        cout << "==================================================ADMINISTRAR INFORMACI\340N PERSONAL======================================\n";
        cout << "Ingrese una opci\242n: \n";
        cout << "1. VER INFORMACI\340N PERSONAL\n2. EDITAR INFORMACI\340N PERSONAL\n3. REGRESAR\n4. SALIR\n";
        cout << dimension;
        cin >> valor;
    }while(valor<1 || 4<valor);
    return valor;
}

int Evento::menuAdminProductos(string &seccion){
    int valor;
    string title;
    if (seccion=="Abarrotes") title= "===========================================ADMINISTRAR INFORMACI\340N DE LOS  ABARROTES====================================\n";
    else if (seccion=="Bebidas") title= "============================================ADMINISTRAR INFORMACI\340N DE LAS BEBIDAS======================================\n";
    else if (seccion=="P. Limpieza") title= "======================================ADMINISTRAR INFORMACI\340N DE LOS PRODUCTOS DE LIMPIEZA==============================\n";
    do{
        limpiar();
        cout << title;
        cout << "Ingrese una opci\242n:\n";
        cout << "1. VER INFORMACI\340N DE TODOS LOS PRODUCTOS EXISTENTES\n2. BUSCAR UN PRODUCTO EXISTENTE DENTRO DEL ALMAC\220N\n3. MODIFICAR LA INFORMACI\340N DE UN PRODUCTO\n4. REGISTRAR PRODUCTO\n5. REGRESAR\n";
        cout << dimension;
        cin >> valor;
    } while(valor<1 || 5<valor);
    return valor;
}

int Evento::menuModificarDatosProductos(string &seccion){
    string title;
    int valor;
    if (seccion=="Abarrotes") title= "============================================MODIFICAR DATOS DE LOS ABARROTES============================================\n";
    else if (seccion=="Bebidas") title= "=============================================MODIFICAR DATOS DE LAS BEBIDAS=============================================\n";
    else if (seccion=="Bebidas") title= "=======================================MODIFICAR DATOS DE LOS PRODUCTOS DE LIMPIEZA=====================================\n";
    do{
        limpiar();
        cout << title;
        cout << "Ingrese una opci\242n:\n";
        cout << "1. MODIFICAR DESCRIPCI\340N DEL PRODUCTO\n2. MODIFICAR PRESENTACI\340N DEL PRODUCTO\n3. MODIFICAR PRECIO\n4. ELIMINAR PRODUCTO\n5. REGRESAR\n";
        cout << dimension;
        cin >> valor;
    }while (valor<1 || 5<valor);
    return valor;
}

int Evento::escogerEmpleadoEspecifico(){
    int valor=getSizeEmpleados(), valor2;
    do{
        limpiar();
        cout << "============================================LISTA DE EMPLEADOS EXISTENTES===============================================\n";
        cout << "Escoja un empleado:\n";
        for (int i=0; i<valor; i++){
            cout << i+1 << ".\t" << listEmpleados[i].getNombresyApellidos() << endl;
        }
        cout << "========================================================================================================================\n";
        cin >> valor2;
    } while(valor2<1 || valor<valor2);
    return (valor2-1);
}

int Evento::escogerProductoEspecifico(string &seccion){
    int valor,valor2;
    if (seccion=="Abarrotes"){
        valor= listProductos[0].size();
        valor2=0;
    }
    else if (seccion=="Bebidas"){
        valor= listProductos[1].size();
        valor2=1;
    }
    else if (seccion=="P. Limpieza"){
        valor= listProductos[2].size();
        valor2=2;
    }
    do{
        limpiar();
        cout << "===========================================LISTA DE PRODUCTOS EXISTENTES===============================================\n";
        cout << "Escoja un producto:\n";
        for (int i=0; i<valor; i++){
            cout << i+1 << ".\t" << listProductos[valor2][i].getDescripcion() << " " << listProductos[valor2][i].getPresentacion() << endl;
        }
        cout << "========================================================================================================================\n";
        cin >> valor2;
    } while(valor2<1 || valor<valor2);
    return (valor2-1);
}

void Evento::modificarDatosProductos(string &seccion, string seccionMod){
    string cadenaMod;
    int indice= escogerProductoEspecifico(seccion);
    cin.ignore(1);
    if (seccionMod=="precio"){
        float numero;
        cout << "===============================================MODIFICAR DATOS DEL PRODUCTO==============================================\n";
        cout << "Ingrese el/la nuevo/a " << seccionMod << " del producto:\n";
        cout << dimension;
        cin >> numero;
        modificarDatosProductoPrecio(indice, seccion, numero);
        cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
        pausar();
    }
    else if (seccionMod=="delete"){
        int valor;
        do{
            cout << "===================================================ELIMINAR EL PRODUCTO=================================================\n";
            cout << "En verdad quiere Ud. eliminar el producto? Se eliminar\240 el producto de forma permanente:\n1. SI\n2. NO\n";
            cout << dimension;
            cin >> valor;
        } while(valor!=1 && valor!=2);
        if (valor==1){
            eliminarProducto(indice, seccion);
            cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
            pausar();
        }
        else return;
    }
    else{
        cout << "===============================================MODIFICAR DATOS DEL PRODUCTO==============================================\n";
        cout << "Ingrese el/la nuevo/a " << seccionMod << " del producto:\n";
        cout << dimension;
        getline(cin, cadenaMod);
        modificarDatosProductoAtrib(indice, seccion, seccionMod, cadenaMod);
        cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
        pausar();
    }
}

void Evento::eliminarEmpleadoValidacion(int indice){
    int valor;
        do{
            cout << "=================================================RETIRAR AL EMPLEADO DEL SISTEMA========================================\n";
            cout << "Enserio quiere Ud. retirar al empleado? Se borrar\240n sus datos de forma permanente:\n1. SI\n2. NO\n";
            cout << dimension;
            cin >> valor;
        } while(valor!=1 && valor!=2);
        if (valor==1){
            eliminarEmpleado(indice);
            remove(listEmpleados[indice].getDirectorio().c_str());
            cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
            pausar();

        }
        else return;
}

void Evento::dataRegistrarProducto(string &seccion){
    int valor, valor2=0, valor3=getSizeAbarrotes();
    if (seccion=="Bebidas"){
        valor2=1;
        valor3= getSizeBebidas();
    }
    else{
        valor2=2;
        valor3=getSizeLimpieza();
    }
    do{
        limpiar();
        cout << "==========================================REGISTRAR PRODUCTO DENTRO DEL ALMAC\220N=========================================\n";
        cout << "Enserio quiere Ud. registrar el producto dentro del almac\202n?:\n1. SI\n2. NO\n";
        cout << dimension;
        cin >> valor;
    } while (valor!=1 && valor!=2);
    if (valor==1){
        string codigo, descripcion, presentacion;
        int cantidad; float precio;
        limpiar();
        int candado=1;
        while(candado){
            cout << "==========================================REGISTRAR PRODUCTO DENTRO DEL ALMAC\220N=========================================\n";
            cout << "C\340DIGOS USADOS:\n";
            for (int i=0; i<valor3; i++) cout << listProductos[valor2][i].getCodigo() << "; ";
            cout << "\nIngrese el c\242digo del producto a registrar: \nEl c\242digo no debe ser igual al de los productos registrados anteriormente.\n";
            cout << dimension;
            cin >> codigo;
            int contador=0;
            for (int i=0; i<getSizeEmpleados(); i++){
                if (listProductos[valor2][i].getCodigo()==codigo){
                    contador++;
                }
            }
            if (contador==0) candado=0;
            limpiar();
            cout << "EL CODIGO YA EST\265 EN USO, ELIJA OTRO.\n";
        }
        cin.ignore(1);
        cout << "==========================================REGISTRAR PRODUCTO DENTRO DEL ALMAC\220N=========================================\n";
        cout << "C\242digo: " << codigo << endl;
        cout << "Ingrese la descripci\242n del producto: \n";
        getline(cin,descripcion);
        cout << "Ingrese la presentaci\242n del producto: \n";
        getline(cin,presentacion);
        cout << "Ingrese la cantidad del producto: \n";
        cin >> cantidad;
        cout << "Ingrese el precio por presentaci\242n del producto: \n";
        cin >> precio;
        Producto nuevo(seccion, codigo, descripcion, presentacion, cantidad, precio);
        limpiar();
        cout << "==========================================REGISTRAR EMPLEADO DENTRO DEL ALMAC\220N=========================================\n";
        cout << "El empleado a registrar ser\240:\n";
        nuevo.mostrarInfo("unit");
        registrarProducto(nuevo);
        cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
        pausar();
    }
    else return;
}

void Evento::dataRegistrarEmpleado(){
    int valor;
    do{
        limpiar();
        cout << "==========================================REGISTRAR EMPLEADO DENTRO DEL ALMAC\220N=========================================\n";
        cout << "Enserio quiere Ud. registrar un empleado dentro del almac\202n?:\n1. SI\n2. NO\n";
        cout << dimension;
        cin >> valor;
    } while (valor!=1 && valor!=2);
    if (valor==1){
        string nombre, nombreCompleto, direccion, DNI, codigo, contrasenha, rol="Empleado";
        int edad;
        limpiar();
        int candado=1;
        while(candado){
            cout << "==========================================REGISTRAR EMPLEADO DENTRO DEL ALMAC\220N=========================================\n";
            cout << "C\340DIGOS USADOS:\n";
            for (int i=0; i<getSizeEmpleados(); i++) cout << listEmpleados[i].getCodigo() << ". ";
            cout << "\nIngrese el c\242digo del empleado a registrar: \nEl c\242digo no debe ser igual al de los empleados registrados anteriormente.\n";
            cout << dimension;
            cin >> codigo;
            int contador=0;
            for (int i=0; i<getSizeEmpleados(); i++){
                if (listEmpleados[i].getCodigo()==codigo){
                    contador++;
                }
            }
            if (contador==0) candado=0;
            limpiar();
            cout << "EL CODIGO YA EST\265 EN USO, ELIJA OTRO.\n";
        }
        cin.ignore(1);
        cout << "==========================================REGISTRAR EMPLEADO DENTRO DEL ALMAC\220N=========================================\n";
        cout << "C\242digo: " << codigo << endl;
        cout << "Ingrese los nombres y apellidos del empleado: \n";
        getline(cin,nombreCompleto);
        cout << "Ingrese la direcci\242n del empleado: \n";
        getline(cin,direccion);
        cout << "Ingrese el documento de identidad del empleado: \n";
        cin >> DNI;
        cout << "Ingrese la edad del empleado: \n";
        cin >> edad;
        cout << "Ingrese el nombre de usuario del empleado: \n";
        cin >> nombre;
        cout << "Ingrese la contrase\244a del empleado: \n";
        cin >> contrasenha;
        Usuario nuevo(nombreCompleto, DNI, direccion, edad, codigo, nombre, contrasenha, rol);
        limpiar();
        cout << "==========================================REGISTRAR EMPLEADO DENTRO DEL ALMAC\220N=========================================\n";
        cout << "El empleado a registrar ser\240:\n";
        nuevo.mostrarInfo("unit");
        registrarEmpleado(nuevo);
        cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
        pausar();
    }
    else return;
}

int Evento::menuBuscarProductos(string &seccion){
    int valor;
    do{
        limpiar();
        cout << "=======================================BUSCAR PRODUCTOS DENTRO DE LA LISTA EXISTENTE====================================\n";
        cout << "Ingrese una opci\242n de b\243squeda:\n";
        cout << "1. B\351SQUEDA POR C\340DIGO\n2. B\351SQUEDA POR DESCRIPCI\340N\n3. REGRESAR\n";
        cout << dimension;
        cin >> valor;
    } while(valor<1 || 3<valor);
    return valor;
}

void Evento::buscarProductos(string metodo, string &seccion){
    int valor, valor2, encontrados=0;
    string title, buscado;
    if (metodo=="codigo") title= "===================================BUSCAR PRODUCTOS POR EL M\220TODO DE B\351SQUEDA POR C\340DIGO================================\n";
    else if (metodo=="descripcion") title= "=========================BUSCAR PRODUCTOS POR EL M\220TODO DE B\351SQUEDA POR DESCRIPCI\340N=====================================\n";
    limpiar();
    cout << title;
    cout << "Ingrese el/la " << metodo << " del producto:\n";
    cout << dimension;
    cin >> buscado;
    if (seccion=="Abarrotes") {
        valor=0;
        valor2= getSizeAbarrotes();}
    else if (seccion=="Bebidas") {
        valor=1;
        valor2= getSizeBebidas();}
    else if (seccion=="P. Limpieza") {
        valor=2;
        valor2=getSizeLimpieza();}
    if (metodo=="codigo"){
        for (int i=0; i<valor2; i++){
            if (listProductos[valor][i].getCodigo().find(buscado) != string::npos){
                listProductos[valor][i].mostrarInfo("unit");
                encontrados++;
            }
        }
    }
    else if (metodo=="descripcion"){
        for (int i=0; i<valor2; i++){
            if (listProductos[valor][i].getDescripcion().find(buscado) != string::npos){
                listProductos[valor][i].mostrarInfo("unit");
                encontrados++;
            }
        }

    }
    cout << "SE ENCONTRARON " << encontrados << " PRODUCTOS.\n";
    pausar();
}

int Evento::escogerSeccion(){
    int valor;
    do{
        limpiar();
        cout << "=========================================================ESCOGER SECCI\340N================================================\n";
        cout << "Escoja la secci\242n a emplear:\n";
        cout << "1. ABARROTES\n2. BEBIDAS\n3. PRODUCTOS DE LIMPIEZA\n4. REGRESAR\n";
        cout << dimension;
        cin >> valor;
    }while(valor<1 || 4<valor);
    return valor;
}

int Evento::menuModificarDatos(string modo){
    int valor;
    string title;
    if (modo=="Administrador") title= "============================================MODIFICAR DATOS DEL ADMINISTRADOR===========================================\n";
    else if (modo=="Empleado") title= "===============================================MODIFICAR DATOS DEL EMPLEADO=============================================\n";
    do{
        limpiar();
        cout << title;
        cout << "Ingrese una opci\242n:\n";
        cout << "1. MODIFICAR NOMBRES Y APELLIDOS DEL USUARIO\n2. MODIFICAR NOMBRE DE USUARIO\n3. MODIFICAR DIRECCION DEL USUARIO\n4. MODIFICAR CONTRASE\245A DEL USUARIO\n5. REGRESAR\n";
        cout << dimension;
        cin >> valor;
    }while (valor<1 || 5<valor);
    return valor;
}

void Evento::verificarContrasenha(string rol, int indice){
    string contrasenha;
    limpiar();
    if (rol=="Administrador"){
        while(true){
            cout << "===============================================VERIFICACI\340N DE CONTRASE\245A===============================================\n";
            cout << "Ingrese su contrase\244a actual:\nCaso contrario digite 'exit'.\n";
            cout << dimension;
            cin >> contrasenha;
            if (!administrador[0].verificarContrasenha(contrasenha)){
                if (contrasenha=="exit"){
                    salir();
                }
                limpiar();
                cout << "LA CONTRASE\245A INGRESADA NO ES CORRECTA! INTENTE DE NUEVO\n";
            }
            else break;
        }
    }
    else if (rol=="Empleado"){
        while(true){
            cout << "===============================================VERIFICACI\340N DE CONTRASE\245A===============================================\n";
            cout << "Ingrese su contrase\244a actual:\nCaso contrario digite 'exit'.\n";
            cout << dimension;
            cin >> contrasenha;
            if (!listEmpleados[indice].verificarContrasenha(contrasenha)){
                if (contrasenha=="exit"){
                    salir();
                }
                limpiar();
                cout << "LA CONTRASE\245A INGRESADA NO ES CORRECTA! INTENTE DE NUEVO\n";
            }
            else break;
        }
    }
    return;
}

void Evento::modificarDatosUsuario(string seccion){
    string cadenaMod;
    cin.ignore(1);
    cout << "============================================MODIFICAR DATOS DEL ADMINISTRADOR===========================================\n";
    cout << "Ingrese el/la nuevo/a " << seccion << " a modificar:\n";
    cout << dimension;
    getline(cin, cadenaMod);
    modificarDatosAdmin(seccion, cadenaMod);
    cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
    pausar();
}

void Evento::modificarDatosUsuario(string seccion, int indice){
    string cadenaMod;
    cin.ignore(1);
    cout << "===============================================MODIFICAR DATOS DEL EMPLEADO=============================================\n";
    cout << "Ingrese el/la nuevo/a " << seccion << " a modificar:\n";
    cout << dimension;
    getline(cin, cadenaMod);
    modificarDatosEmpleado(indice, seccion, cadenaMod);
    cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
    pausar();
}

int Evento::menuAdminEmpleados(){
    int valor;
    do{
        limpiar();
        cout << "============================================ADMINISTRAR DATOS DE LOS EMPLEADOS==========================================\n";
        cout << "Ingrese una opci\242n:\n";
        cout << "1. VER INFORMACI\340N DE LOS EMPLEADOS EXISTENTES\n2. ADMINISTRAR UN EMPLEADO EN ESPEC\326FICO\n3. REGISTRAR EMPLEADO\n4. REGRESAR\n";
        cout << dimension;
        cin >> valor;
    } while(valor<1 || 4<valor);
    return valor;
}

int Evento::menuAdminEmpleadoEspecifico(int numero){
    int valor;
    do{
        limpiar();
        cout << "==================================================ADMINISTRAR AL EMPLEADO===============================================\n";
        cout << "C\340DIGO DEL EMPLEADO: " << listEmpleados[numero].getCodigo() << endl;
        cout << "NOMBRES Y APELLIDOS: " << listEmpleados[numero].getNombresyApellidos() << endl;
        cout << "Qu\202 desea hacer con el empleado?:\n";
        cout << "1. VER SU HISTORIAL\n2. VER INFORMACI\340N\n3. RETIRARLO DEL SISTEMA\n4. REGRESAR\n";
        cout << dimension;
        cin >> valor;
    } while(valor<1 || 4<valor);
    return valor;
}


//
int Evento::menuSacarProducto(int indiceEmpleado){
    int validar;
    do{
        limpiar();
        cout << "==============================================RETIRAR PRODUCTO DEL ALMACEN==============================================\n";
        cout << "NOMBRES Y APELLIDOS: " << listEmpleados[indiceEmpleado].getNombresyApellidos() << endl;
        cout << "Desea retirar cierta cantidad de un producto?:\nSe le a\244adir\240 el orden de SALIDA a su historial.\n";
        cout << "1. SI\n2. NO\n";
        cout << dimension;
        cin >> validar;
    } while (validar!=1 && validar!=2);
    return validar;
}

int Evento::menuEntrarProducto(int indiceEmpleado){
    int validar;
    do{
        limpiar();
        cout << "==============================================INGRESAR PRODUCTO AL ALMACEN==============================================\n";
        cout << "NOMBRES Y APELLIDOS: " << listEmpleados[indiceEmpleado].getNombresyApellidos() << endl;
        cout << "Desea ingresar cierta cantidad de un producto?:\nSe le a\244adir\240 el orden de ENTRADA a su historial.\n";
        cout << "1. SI\n2. NO\n";
        cout << dimension;
        cin >> validar;
    } while (validar!=1 && validar!=2);
    return validar;
}

void Evento::entrarProducto(int indiceEmpleado){
    int seccionProd=escogerSeccion();
    seccionProd--;
    if (seccionProd==3) salir();
    string seccion="Abarrotes", tipo= "ENTRADA";
    if (seccionProd==1) seccion= "Bebidas";
    else if (seccionProd==2) seccion= "P. Limpieza";
    int prodEspecifico= escogerProductoEspecifico(seccion), cantidad, existente= listProductos[seccionProd][prodEspecifico].getStock();
    do{
        limpiar();
        cout << "==============================================INGRESAR LA CANTIDAD DEL PRODUCTO=========================================\n";
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ORDEN DE " << tipo << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout << "DESCRIPCI\340N Y PRESENTACI\340N DEL PRODUCTO: " << listProductos[seccionProd][prodEspecifico].getDescripcion() << " " <<listProductos[seccionProd][prodEspecifico].getPresentacion() << endl;
        cout << "STOCK EXISTENTE DEL PRODUCTO           : " << existente << endl;
        cout << "EMPLEADO ENCARGADO DE LA ORDEN         : " << listEmpleados[indiceEmpleado].getNombresyApellidos() << endl;
        cout << "NOTA: La cantidad a ingresar debe ser no menor a '0'.\n\nIngrese la cantidad del producto a ingresar:\n";
        cout << dimension;
        cin >> cantidad;
    } while (cantidad<1);
    string cantidadStr= to_string(cantidad);
    existente= existente+cantidad;
    listProductos[seccionProd][prodEspecifico].setStock(existente);
    registrarFlujoDeProducto(indiceEmpleado, prodEspecifico, tipo, cantidadStr, seccion);
    cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
    pausar();
}

void Evento::sacarProducto(int indiceEmpleado){
    int seccionProd=escogerSeccion();
    seccionProd--;
    if (seccionProd==3) salir();
    string seccion="Abarrotes", tipo= "SALIDA";
    if (seccionProd==1) seccion= "Bebidas";
    else if (seccionProd==2) seccion= "P. Limpieza";
    int prodEspecifico= escogerProductoEspecifico(seccion), cantidad;
    int existente= listProductos[seccionProd][prodEspecifico].getStock();
    do{
        limpiar();
        cout << "==============================================INGRESAR LA CANTIDAD DEL PRODUCTO=========================================\n";
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ORDEN DE " << tipo << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout << "DESCRIPCI\340N Y PRESENTACI\340N DEL PRODUCTO: " << listProductos[seccionProd][prodEspecifico].getDescripcion() << " " <<listProductos[seccionProd][prodEspecifico].getPresentacion() << endl;
        cout << "STOCK EXISTENTE DEL PRODUCTO           : " << existente << endl;
        cout << "EMPLEADO ENCARGADO DE LA ORDEN         : " << listEmpleados[indiceEmpleado].getNombresyApellidos() << endl;
        cout << "NOTA: La cantidad a retirar del almac\202n debe ser no menor a '0' ni mayor al stock existente del producto.\n\nIngrese la cantidad del producto a retirar:\n";
        cout << dimension;
        cin >> cantidad;
    } while (cantidad<1 || existente<cantidad);
    string cantidadStr= to_string(cantidad);
    existente= existente-cantidad;
    listProductos[seccionProd][prodEspecifico].setStock(existente);
    registrarFlujoDeProducto(indiceEmpleado, prodEspecifico, tipo, cantidadStr, seccion);
    cout << "OPERACI\340N REALIZADA CON \220XITO.\n";
    pausar();

}
