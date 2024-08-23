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
	void ingresarEspecialidad();
	void ingresarDoctor();
	void ingresarDueno();
	void ingresarMascota();

	void menuPrincipal();
	void menuAdministrativo();
	void menuCitas();
	void menuBusquedasListados();
};

#endif // !HOSPITAL_H
