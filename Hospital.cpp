#include "Hospital.h"

Hospital::Hospital() {
	this->vecEspecialidades = new vEspecialidades(100);
	this->vecDoctores = new vDoctores(100);
	this->vecDuenos = new vDuenos(100);
	this->vecMascotas = new vMascotas(100);
}
Hospital::~Hospital() {
	delete vecEspecialidades;
	delete vecDoctores;
	delete vecDuenos;
	delete vecMascotas;
}



void Hospital::menuOpcion() {
    int op = -1;

    do {
        system("cls");
        menuPrincipal();
        imprimeCadena("\nIngrese la opcion: ");cin >> op;

        if (op != 0) {
            manejarSubMenu(op);
        }

    } while (op != 0);


    imprimeCadena("\n\n\tGracias por usar el programa!\n");

}

void Hospital::manejarSubMenu(int op) {
    int op2 = -1;

    while (op2 != 0) {
        system("cls");

        
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
            cout << "Opcion no valida, regresando al menu principal.\n";
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

void Hospital::manejarOpcionAdministrativo(int op2) {
    switch (op2) {
    case 1:
        system("cls");
        ingresarEspecialidad();
        break;
    case 2:
        system("cls");
        ingresarDoctor();
        break;
    case 3:
        system("cls");
        ingresarDueno();
        break;
    case 4:
        system("cls");
        ingresarMascota();
        break;
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
}

void Hospital::manejarOpcionCitas(int op2) {
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

void Hospital::manejarOpcionBusquedas(int op2) {
    switch (op2) {
    case 1:
        system("cls");
        mostrarEspecialidades();
        system("pause");
        break;
    case 2:
        system("cls");
        mostrarDoctor();
        system("pause");
        break;
    case 3:
        system("cls");
        mostrarDuenos();
        system("pause");
        break;
    case 4:
        system("cls");
        mostrarMascotas();
        system("pause");
        break;
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
}



void Hospital::menuPrincipal() {
    imprimeCadena("\n\tMenu Principal\n\n");
    imprimeCadena("1- Submenu Administracion\n");
    imprimeCadena("2- Submenu Control de Citas\n");
    imprimeCadena("3- Submenu Busquedas y Listados\n");
    imprimeCadena("0- Salir\n");
}
void Hospital::menuAdministrativo() {
    imprimeCadena("\n\tSubmenu Administracion\n\n");
    imprimeCadena("(1) Ingresar Especialidades\n");
    imprimeCadena("(2) Ingresar Doctor (por especialidad)\n");
    imprimeCadena("(3) Ingresar Dueno\n");
    imprimeCadena("(4) Ingresar Mascota (por dueno)\n");
    imprimeCadena("(0) Regresar al Menu Principal\n");
}
void Hospital::menuCitas() {
    imprimeCadena("\n\tSubmenu Control Citas\n\n");
    imprimeCadena("(1) Sacar Cita\n");
    imprimeCadena("(2) Cancelar Cita\n");
    imprimeCadena("(3) Mostrar Calendario de Citas por Doctor\n");
    imprimeCadena("(4) Mostrar Citas por Dueno\n");
    imprimeCadena("(0) Regresar al Menu Principal\n");
}
void Hospital::menuBusquedasListados() {
    imprimeCadena("\n\tBusquedas y Listados\n\n");
    imprimeCadena("(1) Mostrar Listado de Especialidades\n");
    imprimeCadena("(2) Mostrar Listado de Doctores por Especialidad\n");
    imprimeCadena("(3) Mostrar Duenos con sus Mascotas\n");
    imprimeCadena("(4) Mostrar Pacientes por Doctor\n");
    imprimeCadena("(0) Regresar al Menu Principal\n");
}



void Hospital::ingresarEspecialidad() {
	string esp;
	int res = 0;

	do {
		system("cls");
		imprimeCadena("Ingresando especialidad.\n\n");
    		cin.ignore();
    		imprimeCadena("Escriba el nombre de la especialidad: ");getline(cin, esp);

    		Especialidad* espe = new Especialidad(esp);

		vecEspecialidades->agregarEspecialidad(espe);

    		do {
        		imprimeCadena("\nDesea ingresar otra especialidad (1- Si / 2- No): ");cin >> res;
    		} while (respuestaValida(res) == false);
	} while (res == 1);

}
void Hospital::ingresarDoctor() {
    string nombre;
    int esp = 0;
    int res = 0; 



    if (vecEspecialidades->estaVacio()) {
	limpiaPantalla();
        imprimeCadena("No hay especialidades registradas\nDebe de ingresar alguna especialidad primero.");
	system("pause");
    }
    else {
        do {
            system("cls");
            cin.ignore(); 
            imprimeCadena("Cual es el nombre del doctor: ");
            getline(cin, nombre);

            imprimeCadena("\nEscoja una especialidad: \n");
            vecEspecialidades->imprimeContenedor();

            
            bool especialidadValida = false;
            do {
                imprimeCadena("\nDigite el numero de la especialidad: ");
                cin >> esp;

                if (esp > 0 && esp <= vecEspecialidades->getCantidad()) {
                    especialidadValida = true;
                }
                else {
                    imprimeCadena("\nEspecialidad no valida. Intente nuevamente.");
                }
            } while (!especialidadValida);
            
            Doctor* doc = new Doctor(nombre, vecEspecialidades->getVec(esp));
            vecDoctores->agregarDoctor(doc);

           
            do {
                imprimeCadena("\nDesea ingresar otro doctor (1- Si / 2- No): ");cin >> res;   
            } while (respuestaValida(res) == false);

        } while (res == 1);
    }
}


void Hospital::ingresarDueno() {
    string nom;
    int auxID = 0;
    int res = 0;

    do {
        system("cls");
        imprimeCadena("Ingresando dueno.\n\n");
        cin.ignore();
        imprimeCadena("Escriba el nombre del dueno: ");getline(cin, nom);
        imprimeCadena("Escriba el ID del dueno: ");cin >> auxID;

        Dueno* due = new Dueno(nom, auxID);

        vecDuenos->agregarDueno(due);

        do {
            imprimeCadena("\nDesea ingresar otro dueno (1- Si / 2- No): ");cin >> res;
        } while (respuestaValida(res) == false);
    } while (res == 1);
}

void Hospital::ingresarMascota() {
    string nombre;
    int dueno = 0;
    int res = 0;


    if (vecDuenos->estaVacio()) {
	limpiaPantalla();
        imprimeCadena("No hay duenos registrados\nDebe de ingresar algun dueno primero.");
	system("pause");
    }
    else {
        do {
            system("cls");
            cin.ignore();
            imprimeCadena("Cual es el nombre de la mascota: ");
            getline(cin, nombre);

            imprimeCadena("\nEscoja un dueno: \n");
            vecDuenos->imprimeContenedor();


            bool duenoValido = false;
            do {
                imprimeCadena("\nDigite el numero de la especialidad: ");
                cin >> dueno;

                if (dueno > 0 && dueno <= vecDuenos->getCantidad()) {
                    duenoValido = true;
                }
                else {
                    imprimeCadena("\Dueno no valida. Intente nuevamente.");
                }
            } while (!duenoValido);

            Mascota* mas = new Mascota(nombre, vecDuenos->getVec(dueno));
            vecMascotas->agregarMascota(mas);


            do {
                imprimeCadena("\nDesea ingresar otra mascota (1- Si / 2- No): ");cin >> res;
            } while (respuestaValida(res) == false);

        } while (res == 1);
    }
}

void Hospital::mostrarDoctor() {
	vecDoctores->imprimeContenedor();
}

void Hospital::mostrarEspecialidades() {
    vecEspecialidades->imprimeContenedor();
}

void Hospital::mostrarDuenos() {
    vecDuenos->imprimeContenedor();
}

void Hospital::mostrarMascotas() {
    vecMascotas->imprimeContenedor();
}
