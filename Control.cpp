#include "Control.h"

Control::Control() {
    hospital = new Hospital();
}
Control::~Control() {
    delete hospital;
}

void Control::menuOpcion() {
    int op = -1;

    do {
        limpiaPantalla();
        menuPrincipal();
        imprimeCadena("\nIngrese la opcion: ");cin >> op;

        if (op != 0) {
            manejarSubMenu(op);
        }


    } while (op != 0);


    imprimeCadena("\n\n\tGracias por usar el programa!\n\n");

}

void Control::manejarSubMenu(int op) {
    int op2 = -1;

    while (op2 != 0) {
        limpiaPantalla();

        switch (op) {
        case 1:
            menuAdministrativo();
            break;
        case 2:
            menuCitas();
            break;
        case 3:
            menuBusquedasListados();
            break;
        default:
            imprimeCadena("Opcion no valida, regresando al menu principal.\n");
            return;
        }

        imprimeCadena("\nIngrese la opcion: ");
        cin >> op2;

        // Procesar la opción del submenú
        switch (op) {
        case 1:
            manejarOpcionAdministrativo(op2);
            break;
        case 2:
            manejarOpcionCitas(op2);
            break;
        case 3:
            manejarOpcionBusquedas(op2);
            break;
        }
    }
}

void Control::manejarOpcionAdministrativo(int op2) {
    switch (op2) {
    case 1:
        limpiaPantalla();
        hospital->ingresarEspecialidad();
        break;
    case 2:
        limpiaPantalla();
        hospital->ingresarDoctor();
        break;
    case 3:
        limpiaPantalla();
        hospital->ingresarDueno();
        break;
    case 4:
        limpiaPantalla();
        hospital->ingresarMascota();
        break;
    default:
        imprimeCadena("Opcion no valida.\n");
        break;
    }
}

void Control::manejarOpcionCitas(int op2) {
    switch (op2) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
}

void Control::manejarOpcionBusquedas(int op2) {
    switch (op2) {
    case 1:
        limpiaPantalla();
        hospital->mostrarEspecialidades();
        esperandoEnter();
        break;
    case 2:
        limpiaPantalla();
        hospital->mostrarDoctor();
        esperandoEnter();
        break;
    case 3:
        limpiaPantalla();
        hospital->mostrarDuenos();
        esperandoEnter();
        break;
    case 4:
        limpiaPantalla();
        hospital->mostrarMascotas();
        esperandoEnter();
        break;
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
}



void Control::menuPrincipal() {
    imprimeCadena("\n\tMenu Principal\n\n");
    imprimeCadena("1- Submenu Administracion\n");
    imprimeCadena("2- Submenu Control de Citas\n");
    imprimeCadena("3- Submenu Busquedas y Listados\n");
    imprimeCadena("0- Salir\n");
}
void Control::menuAdministrativo() {
    imprimeCadena("\n\tSubmenu Administracion\n\n");
    imprimeCadena("(1) Ingresar Especialidades\n");
    imprimeCadena("(2) Ingresar Doctor (por especialidad)\n");
    imprimeCadena("(3) Ingresar Dueno\n");
    imprimeCadena("(4) Ingresar Mascota (por dueno)\n");
    imprimeCadena("(0) Regresar al Menu Principal\n");
}
void Control::menuCitas() {
    imprimeCadena("\n\tSubmenu Control Citas\n\n");
    imprimeCadena("(1) Sacar Cita\n");
    imprimeCadena("(2) Cancelar Cita\n");
    imprimeCadena("(3) Mostrar Calendario de Citas por Doctor\n");
    imprimeCadena("(4) Mostrar Citas por Dueno\n");
    imprimeCadena("(0) Regresar al Menu Principal\n");
}
void Control::menuBusquedasListados() {
    imprimeCadena("\n\tBusquedas y Listados\n\n");
    imprimeCadena("(1) Mostrar Listado de Especialidades\n");
    imprimeCadena("(2) Mostrar Listado de Doctores por Especialidad\n");
    imprimeCadena("(3) Mostrar Duenos con sus Mascotas\n");
    imprimeCadena("(4) Mostrar Pacientes por Doctor\n");
    imprimeCadena("(0) Regresar al Menu Principal\n");
}
