#include "Hospital.h"

Hospital::Hospital() {
	this->vecEspecialidades = new vEspecialidades(100);
	this->vecDoctores = new vDoctores(100);
	this->vecDuenos = new vDuenos(100);
	this->vecMascotas = new vMascotas(100);
	this->vecCitas = new vCitas(100);
}
Hospital::~Hospital() {
	delete vecEspecialidades;
	delete vecDoctores;
	delete vecDuenos;
	delete vecMascotas;
	delete vecCitas;
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
