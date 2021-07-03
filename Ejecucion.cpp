#include "Ejecucion.h"

void ejecutar(){
    Almacen *almacen= Almacen::getInstancia();
    almacen->cargarInfo();
    int candado=1;
    while (candado){
        switch(modo()){
            case 1:{//Modo Admin
                verificarContrasenha("Administrador", 0);
                int candado2=1;
                while(candado2){
                    switch(menu("Administrador")){
                        case 1:{//Admin info personal
                            int candado3=1;
                            while(candado3){
                                switch(menuAdminPersonal()){
                                    case 1:{//Ver info personal
                                        almacen->mostrarInfoAdmin();
                                        break;
                                    }
                                    case 2:{//Editar info personal
                                        int candado4=1;
                                        while(candado4){
                                            switch(menuModificarDatos("Administrador")){
                                                case 1:{//Mod nombre
                                                    modificarDatosUsuario("nombre");
                                                    break;
                                                }
                                                case 2:{//Mod nombreUsuario
                                                    modificarDatosUsuario("nombreUsuario");
                                                    break;
                                                }
                                                case 3:{//Mod direccion
                                                    modificarDatosUsuario("direccion");
                                                    break;
                                                }
                                                case 4:{//Mod contrasenha
                                                    modificarDatosUsuario("contrasenha");
                                                    break;
                                                }
                                                case 5:{
                                                    candado4=0;
                                                    break;
                                                }
                                                case 6:{
                                                    salir();
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    case 3:{
                                        candado3=0;
                                        break;
                                    }
                                    case 4:{
                                        salir();
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:{//Admin producto
                            while(true){
                                string seccion;
                                int valor= escogerSeccion();
                                if (valor==1) seccion= "Abarrotes";
                                else if (valor==2) seccion= "Bebidas";
                                else if (valor==3) seccion= "P. Limpieza";
                                else if (valor==4){
                                    break;
                                }
                                int candado3=1;
                                while(candado3){
                                    switch(menuAdminProductos(seccion)){
                                        case 1:{//Ver info Prod
                                            almacen->mostrarListProductos(seccion);
                                            break;
                                        }
                                        case 2:{//Buscar prod
                                            int candado4=1;
                                            while(candado4){
                                                switch(menuBuscarProductos(seccion)){
                                                    case 1:{//Busq Codigo
                                                        buscarProductos("codigo", seccion);
                                                        break;
                                                    }
                                                    case 2:{//Busq Descripcion
                                                        buscarProductos("descripcion", seccion);
                                                        break;
                                                    }
                                                    case 3:{
                                                        candado4=0;
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 3:{//Mod info
                                            int candado4=1;
                                            while(candado4){
                                                switch(menuModificarDatosProductos(seccion)){
                                                    case 1:{//Mod descripcion
                                                        modificarDatosProductos(seccion, "descripcion");
                                                        break;
                                                    }
                                                    case 2:{//Mod presentacion
                                                        modificarDatosProductos(seccion, "presentacion");
                                                        break;
                                                    }
                                                    case 3:{//Mod precio
                                                        modificarDatosProductos(seccion, "precio");
                                                        break;
                                                    }
                                                    case 4:{//Eliminar producto
                                                        modificarDatosProductos(seccion, "delete");
                                                        break;
                                                    }
                                                    case 5:{
                                                        candado4=0;
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 4:{//Registrar producto
                                            dataRegistrarProducto(seccion);
                                            break;
                                        }
                                        case 5:{
                                            candado3=0;
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 3:{//Admin empleado
                            int candado3=1;
                            while(candado3){
                                switch(menuAdminEmpleados()){
                                    case 1:{//Ver tabla empleados
                                        almacen->mostrarListEmpleados();
                                        break;
                                    }
                                    case 2:{//Admin especifico
                                        int especifico= escogerEmpleadoEspecifico(), candado4=1;
                                        while(candado4){
                                            switch(menuAdminEmpleadoEspecifico(especifico)){
                                                case 1:{//Ver historial
                                                    almacen->cargarHistorialEmpleado(especifico);
                                                    almacen->mostrarHistorialEmpleado(especifico);
                                                    almacen->guardarHistorialEmpleado(especifico);
                                                    break;
                                                }
                                                case 2:{//Ver info
                                                    almacen->mostrarInfoEmpleado(especifico);
                                                    break;
                                                }
                                                case 3:{//Despedirlo
                                                    eliminarEmpleadoValidacion(especifico);
                                                    break;
                                                }
                                                case 4:{
                                                    candado4=0;
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    case 3:{//registrar empleado
                                        dataRegistrarEmpleado();
                                        break;
                                    }
                                    case 4:{
                                        candado3=0;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4:{//Ver historial
                            almacen->cargarHistorialAdmin();
                            almacen->mostrarHistorialAdmin();
                            break;
                        }
                        case 5:{
                            candado2=0;
                            break;
                        }
                        case 6:{
                            salir();
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{//Modo Empleado
                int empleado= escogerEmpleadoEspecifico(), candado2=1;
                verificarContrasenha("Empleado", empleado);
                while(candado2){
                    switch(menu("Empleado")){
                        case 1:{//Salir producto
                            int candado3=1;
                            while(candado3){
                                switch(menuSacarProducto(empleado)){
                                    case 1:{//sacar
                                        sacarProducto(empleado);
                                        break;
                                    }
                                    case 2:{
                                        candado3=0;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:{//Entrar producto
                            int candado3=1;
                            while(candado3){
                                switch(menuEntrarProducto(empleado)){
                                    case 1:{//entrar
                                        entrarProducto(empleado);
                                        break;
                                    }
                                    case 2:{
                                        candado3=0;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 3:{//Admin info personal
                            int candado4=1;
                            while(candado4){
                                switch(menuModificarDatos("Empleado")){
                                    case 1:{//Mod nombre
                                        modificarDatosUsuario("nombre", empleado);
                                        break;
                                    }
                                    case 2:{//Mod nombreUsuario
                                        modificarDatosUsuario("nombreUsuario", empleado);
                                        break;
                                    }
                                    case 3:{//Mod direccion
                                        modificarDatosUsuario("direccion", empleado);
                                        break;
                                    }
                                    case 4:{//Mod contrasenha
                                        modificarDatosUsuario("contrasenha", empleado);
                                        break;
                                    }
                                    case 5:{
                                        candado4=0;
                                        break;
                                    }
                                    case 6:{
                                        salir();
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4:{//ver historial
                            almacen->cargarHistorialEmpleado(empleado);
                            almacen->mostrarHistorialEmpleado(empleado);
                            almacen->guardarHistorialEmpleado(empleado);
                            almacen->cargarHistorialAdmin();
                            almacen->guardarHistorialAdmin();
                            break;
                        }
                        case 5:{
                            almacen->mostrarInfoEmpleado(empleado);
                            break;
                        }
                        case 6:{
                            candado2=0;
                            break;
                        }
                        case 7:{
                            salir();
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{//Ver info general
                almacen->mostrarInfo();
                break;
            }
            case 4:{//Salir
                salir();
                break;
            }
        }
    }
}
