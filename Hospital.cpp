#include "Hospital.h"
#include "utiles.h"

void Hospital::ingresarEspecialidad() {
	string esp;
	Especialidad* espe;
	char res = ' ';
	
	while (res != 'n') {
		imprimeCadena("Ingresando especialidad.\n\n");
		imprimeCadena("Escriba el nombre de la especialidad: ");cin >> esp;

		espe = new Especialidad(esp);

		vecEspecialidades->agregarEspecialidad(espe);

		imprimeCadena("Desea ingresar otra especialidad (s/n): ");cin >> res;
	}

}

void Hospital::ingresarDoctor() {

}

void Hospital::ingresarDueno() {

}

void Hospital::ingresarMascota() {

}


void Hospital::menuPrincipal() {


	
}
void Hospital::menuAdministrativo() {

}
void Hospital::menuCitas() {

}
void Hospital::menuBusquedasListados() {

}
