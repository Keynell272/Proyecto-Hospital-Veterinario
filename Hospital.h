#ifndef HOSPITAL_H
#define HOSPITAL_H
#pragma once
#include "vEspecialidades.h"
#include "vDoctores.h"
#include "vDuenos.h"
#include "vMascotas.h"

class Hospital {
private:
	vEspecialidades* vecEspecialidades;
	vDoctores* vecDoctores;
	vDuenos* vecDuenos;
	vMascotas* vecMascotas;
public:
	Hospital();
	~Hospital();

	void menuOpcion();
	void manejarSubMenu(int);           
	void manejarOpcionAdministrativo(int);  
	void manejarOpcionCitas(int);         
	void manejarOpcionBusquedas(int);
	
	void menuPrincipal();
	void menuAdministrativo();
	void menuCitas();
	void menuBusquedasListados();
	
	void ingresarEspecialidad();
	void ingresarDoctor();
	void ingresarDueno();
	void ingresarMascota();

	void mostrarDoctor();
	void mostrarEspecialidades();
	void mostrarDuenos();
	void mostrarMascotas();
};

#endif // !HOSPITAL_H
