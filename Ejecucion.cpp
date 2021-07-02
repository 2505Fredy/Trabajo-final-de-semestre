#include "Ejecucion.h"

void ejecutar(){
    Evento *evento= Evento::getInstancia();
    evento->cargarInfo();
    cout << "Hola";
    int candado=1;
    while (candado){
        switch(evento->modo()){
            case 1:{//Modo Admin
                evento->verificarContrasenha("Administrador", 0);
                int candado2=1;
                while(candado2){
                    switch(evento->menu("Administrador")){
                        case 1:{//Admin info personal
                            int candado3=1;
                            while(candado3){
                                switch(evento->menuAdminPersonal()){
                                    case 1:{//Ver info personal
                                        evento->mostrarInfoAdmin();
                                        break;
                                    }
                                    case 2:{//Editar info personal
                                        int candado4=1;
                                        while(candado4){
                                            switch(evento->menuModificarDatos("Administrador")){
                                                case 1:{//Mod nombre
                                                    evento->modificarDatosUsuario("nombre");
                                                    break;
                                                }
                                                case 2:{//Mod nombreUsuario
                                                    evento->modificarDatosUsuario("nombreUsuario");
                                                    break;
                                                }
                                                case 3:{//Mod direccion
                                                    evento->modificarDatosUsuario("direccion");
                                                    break;
                                                }
                                                case 4:{//Mod contrasenha
                                                    evento->modificarDatosUsuario("contrasenha");
                                                    break;
                                                }
                                                case 5:{
                                                    candado4=0;
                                                    break;
                                                }
                                                case 6:{
                                                    evento->salir();
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
                                        evento->salir();
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:{//Admin producto
                            while(true){
                                string seccion;
                                int valor= evento->escogerSeccion();
                                if (valor==1) seccion= "Abarrotes";
                                else if (valor==2) seccion= "Bebidas";
                                else if (valor==3) seccion= "P. Limpieza";
                                else if (valor==4){
                                    break;
                                }
                                int candado3=1;
                                while(candado3){
                                    switch(evento->menuAdminProductos(seccion)){
                                        case 1:{//Ver info Prod
                                            evento->mostrarListProductos(seccion);
                                            break;
                                        }
                                        case 2:{//Buscar prod
                                            int candado4=1;
                                            while(candado4){
                                                switch(evento->menuBuscarProductos(seccion)){
                                                    case 1:{//Busq Codigo
                                                        evento->buscarProductos("codigo", seccion);
                                                        break;
                                                    }
                                                    case 2:{//Busq Descripcion
                                                        evento->buscarProductos("descripcion", seccion);
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
                                                switch(evento->menuModificarDatosProductos(seccion)){
                                                    case 1:{//Mod descripcion
                                                        evento->modificarDatosProductos(seccion, "descripcion");
                                                        break;
                                                    }
                                                    case 2:{//Mod presentacion
                                                        evento->modificarDatosProductos(seccion, "presentacion");
                                                        break;
                                                    }
                                                    case 3:{//Mod precio
                                                        evento->modificarDatosProductos(seccion, "precio");
                                                        break;
                                                    }
                                                    case 4:{//Eliminar producto
                                                        evento->modificarDatosProductos(seccion, "delete");
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
                                            evento->dataRegistrarProducto(seccion);
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
                                switch(evento->menuAdminEmpleados()){
                                    case 1:{//Ver tabla empleados
                                        evento->mostrarListEmpleados();
                                        break;
                                    }
                                    case 2:{//Admin especifico
                                        int especifico=evento->escogerEmpleadoEspecifico(), candado4=1;
                                        while(candado4){
                                            switch(evento->menuAdminEmpleadoEspecifico(especifico)){
                                                case 1:{//Ver historial
                                                    evento->cargarHistorialEmpleado(especifico);
                                                    evento->mostrarHistorialEmpleado(especifico);
                                                    evento->guardarHistorialEmpleado(especifico);
                                                    break;
                                                }
                                                case 2:{//Ver info
                                                    evento->mostrarInfoEmpleado(especifico);
                                                    break;
                                                }
                                                case 3:{//Despedirlo
                                                    evento->eliminarEmpleadoValidacion(especifico);
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
                                        evento->dataRegistrarEmpleado();
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
                            evento->cargarHistorialAdmin();
                            evento->mostrarHistorialAdmin();
                            break;
                        }
                        case 5:{
                            candado2=0;
                            break;
                        }
                        case 6:{
                            evento->salir();
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{//Modo Empleado
                int empleado= evento->escogerEmpleadoEspecifico(), candado2=1;
                evento->verificarContrasenha("Empleado", empleado);
                while(candado2){
                    switch(evento->menu("Empleado")){
                        case 1:{//Salir producto
                            int candado3=1;
                            while(candado3){
                                switch(evento->menuSacarProducto(empleado)){
                                    case 1:{//sacar
                                        evento->sacarProducto(empleado);
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
                                switch(evento->menuEntrarProducto(empleado)){
                                    case 1:{//entrar
                                        evento->entrarProducto(empleado);
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
                                switch(evento->menuModificarDatos("Empleado")){
                                    case 1:{//Mod nombre
                                        evento->modificarDatosUsuario("nombre", empleado);
                                        break;
                                    }
                                    case 2:{//Mod nombreUsuario
                                        evento->modificarDatosUsuario("nombreUsuario", empleado);
                                        break;
                                    }
                                    case 3:{//Mod direccion
                                        evento->modificarDatosUsuario("direccion", empleado);
                                        break;
                                    }
                                    case 4:{//Mod contrasenha
                                        evento->modificarDatosUsuario("contrasenha", empleado);
                                        break;
                                    }
                                    case 5:{
                                        candado4=0;
                                        break;
                                    }
                                    case 6:{
                                        evento->salir();
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4:{//ver historial
                            evento->cargarHistorialEmpleado(empleado);
                            evento->mostrarHistorialEmpleado(empleado);
                            evento->guardarHistorialEmpleado(empleado);
                            evento->cargarHistorialAdmin();
                            evento->guardarHistorialAdmin();
                            break;
                        }
                        case 5:{
                            evento->mostrarInfoEmpleado(empleado);
                            break;
                        }
                        case 6:{
                            candado2=0;
                            break;
                        }
                        case 7:{
                            evento->salir();
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{//Ver info general
                evento->mostrarInfo();
                break;
            }
            case 4:{//Salir
                evento->salir();
                break;
            }
        }
    }


}
