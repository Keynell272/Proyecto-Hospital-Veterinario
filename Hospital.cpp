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
        limpiaPantalla();
		imprimeCadena("Ingresando especialidad.\n\n");
        imprimeCadena("Escriba el nombre de la especialidad: ");esp = leerCadena();

		vecEspecialidades->agregarEspecialidad(new Especialidad(esp));

        do {
            imprimeCadena("\nDesea ingresar otra especialidad (1- Si / 2- No): ");res = leerEntero();
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
        esperandoEnter();
    }
    else {
        do {
            limpiaPantalla(); 
            imprimeCadena("Ingresando doctor.\n\n");
            imprimeCadena("Cual es el nombre del doctor: ");nombre = leerCadena();

            imprimeCadena("\nEscoja una especialidad: \n");
            vecEspecialidades->imprimeContenedor();

            
            bool especialidadValida = false;
            do {
                imprimeCadena("\nDigite el numero de la especialidad: ");esp = leerEntero();

                if (esp >= 0 && esp < vecEspecialidades->getCantidad()) {
                    especialidadValida = true;
                }
                else {
                    imprimeCadena("\nEspecialidad no valida. Intente nuevamente.");
                }
            } while (!especialidadValida);
            
            vecDoctores->agregarDoctor(new Doctor(nombre, vecEspecialidades->getVec(esp)));

            do {
                imprimeCadena("\nDesea ingresar otro doctor (1- Si / 2- No): ");res = leerEntero();
            } while (respuestaValida(res) == false);

        } while (res == 1);
    }
}


void Hospital::ingresarDueno() {
    string nom;
    int auxID;
    int res;

    do {
        limpiaPantalla();
        imprimeCadena("Ingresando dueno.\n\n");
        imprimeCadena("Escriba el nombre del dueno: ");nom = leerCadena();
        imprimeCadena("Escriba el ID del dueno: ");auxID = leerEntero();

        vecDuenos->agregarDueno(new Dueno(nom, auxID));

        do {
            imprimeCadena("\nDesea ingresar otro dueno (1- Si / 2- No): ");res = leerEntero();
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
        esperandoEnter();
    }
    else {
        do {
            limpiaPantalla();
            imprimeCadena("Ingresando mascota.\n\n");
            imprimeCadena("Cual es el nombre de la mascota: ");nombre = leerCadena();

            imprimeCadena("\nEscoja un dueno: \n");
            vecDuenos->imprimeContenedor();


            bool duenoValido = false;
            do {
                imprimeCadena("\nDigite el numero de Dueno: ");dueno = leerEntero();

                if (dueno >= 0 && dueno < vecDuenos->getCantidad()) {
                    duenoValido = true;
                }
                else {
                    imprimeCadena("\nDueno no valida. Intente nuevamente.");
                }
            } while (!duenoValido);

            vecMascotas->agregarMascota(new Mascota(nombre, vecDuenos->getVec(dueno)));

            do {
                imprimeCadena("\nDesea ingresar otra mascota (1- Si / 2- No): ");res = leerEntero();
            } while (respuestaValida(res) == false);

        } while (res == 1);
    }
}

void Hospital::mostrarDoctor() {
    limpiaPantalla();
	if (vecDoctores->estaVacio() == true) {
	    imprimeCadena("\nNo hay doctores registrados\n.");
		esperandoEnter();
	    return;
	}
    imprimeCadena("\nMostrar Listado de Doctores por Especialidad.\n");
    vecEspecialidades->imprimeContenedor();
    int p;
    bool verificarEsp = false;
    do {
        imprimeCadena("\nIngrese la posicion de la especialidad que desea: ");p = leerEntero();

        if (p >= 0 && p < vecEspecialidades->getCantidad() && vecDoctores->tieneEspecialidad(vecEspecialidades->getVec(p)) == true) {
            verificarEsp = true;
        }
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
            if (vecDoctores->tieneEspecialidad(vecEspecialidades->getVec(p)) == false)
                imprimeCadena("\nLa especialidad no tiene doctores registrados.");
        }

    } while (!verificarEsp);
    imprimeCadena(vecDoctores->doctoresPorEspecialidad(vecEspecialidades->getVec(p)->getEspecialidad()));
    
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

void Hospital::asignarCita() {
    limpiaPantalla();

    if (vecMascotas->estaVacio() == true && vecDoctores->estaVacio() == true) {
        imprimeCadena("\nDebe ingresar duenos/mascotas y especialidades/doctores antes de sacar una cita.\n");
        esperandoEnter();
        return;
    }

    //1. Pedir el ID

    imprimeCadena("\n\tDuenos.\n\n");
    vecDuenos->imprimeContenedor();
    int id;
    bool validarID = false;
    do {
        imprimeCadena("\n\nIngrese el numero de identificacion del dueno: ");id = leerEntero();

       if (vecDuenos->verificarID(id) == true && vecMascotas->tieneMascota(id) == true) {
           validarID = true;
       }
       else {
           imprimeCadena("\nID no valido. Intente nuevamente.");
           if (vecMascotas->tieneMascota(id) == false)
               imprimeCadena("\nEl dueno no tiene mascotas registradas.");
       }
    }while (!validarID);
    esperandoEnter();


    //2. Escoger mascota
    limpiaPantalla();
    imprimeCadena(vecMascotas->mascotasPorDueno(id));
    int pos;
    bool posValida = false;
    do{
        imprimeCadena("\n\nIngrese la posicion de la mascota para la cita: ");pos = leerEntero();

        if (vecMascotas->verificarPosicion(id, pos) == true){
            posValida = true;
        }
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
        }
    } while (!posValida);
    esperandoEnter();
    
    //3. Escoger especialidad
    limpiaPantalla();
    vecEspecialidades->imprimeContenedor();
    int p;
    bool verificarEsp = false;
    do {
        imprimeCadena("\nIngrese la posicion de la especialidad que desea: ");p = leerEntero();

        if (p >= 0 && p < vecEspecialidades->getCantidad() && vecDoctores->tieneEspecialidad(vecEspecialidades->getVec(p)) == true) {
            verificarEsp = true;
        } 
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
            if (vecDoctores->tieneEspecialidad(vecEspecialidades->getVec(p)) == false)
                imprimeCadena("\nLa especialidad no tiene doctores registrados.");
        }
       
    } while (!verificarEsp);
    esperandoEnter();
    

    //4. Escoger doctor
    limpiaPantalla();
    imprimeCadena("\n\tDoctores\n");
    imprimeCadena(vecDoctores->doctoresPorEspecialidad(vecEspecialidades->getVec(p)->getEspecialidad())); //muestra doctores
    int doc;
    bool docValido = false;
    do{
        imprimeCadena("\nIngrese la posicion del doctor con el que desea agendar la cita: ");doc = leerEntero();
        if (vecDoctores->verificarPosicion(vecEspecialidades->getVec(p)->getEspecialidad(), doc)) {
            docValido = true;
        }
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
        }
    }while (!docValido);
    esperandoEnter();
   

    //5. Seleccionar horario
    limpiaPantalla();
    imprimeCadena(vecDoctores->getVec(doc)->toStringHorarios()); //muestra horario
    int dia;
    bool validarDia = false;
    do{            
        imprimeCadena("\nSeleccione el dia en el siguiente formato: \n(0 = Lunes, 1 = Martes, 2 = Miercoles, 3 = Jueves, 4 = Viernes, 5 = Sabado): ");dia = leerEntero();

        if(dia >= 0 && dia <= 5){
            validarDia = true;
        }
        else {
            imprimeCadena("\nDia no valido. Intente nuevamente.");
        }
    }while(!validarDia);
    

    int hora;
    bool validarHora = false;
    do{
        imprimeCadena("\nEscoja la hora en la que desea su cita, de acuerdo al siguiente formato (de 8 a 19): ");hora = leerEntero();

        if (hora >= 8 && hora <= 19 && vecDoctores->getVec(doc)->getHorario(dia)->getHora(hora - 8)->getEscogida() == false) {
            validarHora = true;
        }
        else {
            imprimeCadena("\nHora no valida. Intente nuevamente.");
        }
    }while (!validarHora);
    
    vecDoctores->getVec(doc)->getHorario(dia)->getHora(hora - 8)->setEscogida(true);

    //.6 Hacer cita 
    bool citaValida = vecCitas->agregarCita(new Cita(vecMascotas->getVec(pos), vecDoctores->getVec(doc), dia, hora));
    if (citaValida == true) {
        limpiaPantalla();
        imprimeCadena("\nCita agendada con exito.\n");
        esperandoEnter();
    }
    else {
        limpiaPantalla();
        imprimeCadena("\nNo se pudo agendar la cita. Intente de nuevo.\n");
        esperandoEnter();
    }

}

void Hospital::cancelarCita() {
    int id;
    int num;
    int mas;

    limpiaPantalla();
	if (vecCitas->estaVacio() == true) {
    imprimeCadena("\nDebe ingresar citas antes.\n");
    esperandoEnter();
    return;
}
    imprimeCadena("\n\tCancelar cita.\n");   
    vecDuenos->imprimeContenedor();
    //1. Pedir ID
    bool validarID = false;
    do {
        
        imprimeCadena("\n\nIngrese el numero de identificacion del dueno: ");id = leerEntero();

        if (vecDuenos->verificarID(id) == true && vecMascotas->tieneMascota(id) == true) {
            validarID = true;
        }
        else {
            imprimeCadena("\nID no valido. Intente nuevamente.");
            if (vecMascotas->tieneMascota(id) == false)
                imprimeCadena("\nEl dueno no tiene mascotas registradas.");
        }

    } while (!validarID);
    
    //2. Escoger Doctor
    limpiaPantalla();
    imprimeCadena("\n\tCancelar cita.\n");
    imprimeCadena(vecCitas->toStringDoctoresXDueno(id));
    
    bool docValido = false;
    do{
        imprimeCadena("\nIngrese la posicion del Doctor: ");num = leerEntero();


        if (vecCitas->verificarPosicion(id, num) == true) {
            docValido = true;
        }
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
        }

    } while (!docValido);
    
    //3. Escoger Mascota
    limpiaPantalla();
    imprimeCadena("\n\tCancelar cita.\n");
    imprimeCadena(vecCitas->toStringMascotasXDoctor(vecCitas->getVec(num)->getDoctor(), id));
    
    bool mascotaValido = false;
    do {
        imprimeCadena("Ingrese la posicion de la mascota: ");mas = leerEntero();


        if (mas >=0 && mas < vecCitas->getCantidad()) {
            mascotaValido = true;
        }
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
        }

    } while (!mascotaValido);

    (vecCitas->eliminarCitaXMascota(mas) == true ? imprimeCadena("\nCita eliminada exitosamente.\n") : imprimeCadena("\nCita NO pudo ser eliminada.\n"));
    esperandoEnter();
}

void Hospital::citaXDueno() {
    int id;

    limpiaPantalla();
	if (vecDuenos->estaVacio() == true) {
    imprimeCadena("\nNo hay duenos registrados.");
    return;
}
    imprimeCadena("\n\n\tMostrar Citas por Dueno.\n");
    vecDuenos->imprimeContenedor();
    //1. Pedir ID
    bool validarID = false;
    do {
        
        imprimeCadena("\n\nIngrese el numero de identificacion del dueno: ");id = leerEntero();

        if (vecDuenos->verificarID(id) == true && vecMascotas->tieneMascota(id) == true) {
            validarID = true;
        }
        else {
            imprimeCadena("\nID no valido. Intente nuevamente.");
            if (vecMascotas->tieneMascota(id) == false)
                imprimeCadena("\nEl dueno no tiene mascotas registradas.");
        }

    } while (!validarID);

    limpiaPantalla();
    imprimeCadena(vecCitas->toStringCitasXDueno(id));
    esperandoEnter();
}

void Hospital::citaXDoctor() {
    int num;

    limpiaPantalla();
	if (vecDoctores->estaVacio() == true) {
    imprimeCadena("\nNo hay doctores registrados.");
    return;
}
    imprimeCadena("\n\n\tMostrar Calendario de Citas por Doctor.\n");
    vecDoctores->imprimeContenedor();

    bool validarPos = false;
    do {
        
        imprimeCadena("\n\nIngrese la posicion del doctor: ");num = leerEntero();

        if (num >= 0 && num < vecDoctores->getCantidad()) {
            validarPos = true;
        }
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
        }

    } while (!validarPos);

    limpiaPantalla();
    imprimeCadena(vecCitas->toStringCitasXDoctor(vecDoctores->getVec(num)));
    esperandoEnter();

}

void Hospital::pacienteXDoctor() {
    int num;

    limpiaPantalla();
	if (vecDoctores->estaVacio() == true) {
    imprimeCadena("\nNo hay doctores registrados.");
    return;
}
    imprimeCadena("\n\n\tMostrar Pacientes por Doctor.\n");
    vecDoctores->imprimeContenedor();

    bool validarPos = false;
    do {

        imprimeCadena("\n\nIngrese la posicion del doctor: ");num = leerEntero();

        if (num >= 0 && num < vecDoctores->getCantidad()) {
            validarPos = true;
        }
        else {
            imprimeCadena("\nPosicion no valida. Intente nuevamente.");
        }

    } while (!validarPos);

    limpiaPantalla();
    imprimeCadena(vecCitas->toStringPacienteXDoctor(vecDoctores->getVec(num)));

}
