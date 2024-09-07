#ifndef HOSPITAL_H
#define HOSPITAL_H
#pragma once
#include "vEspecialidades.h"
#include "vDoctores.h"
#include "vDuenos.h"
#include "vMascotas.h"
#include "vCitas.h"

class Hospital {
private:
	vEspecialidades* vecEspecialidades;
	vDoctores* vecDoctores;
	vDuenos* vecDuenos;
	vMascotas* vecMascotas;
	vCitas* vecCitas;
public:
	Hospital();
	~Hospital();
	
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
