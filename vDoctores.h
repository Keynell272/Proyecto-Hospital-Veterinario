#ifndef VDOCTORES_H
#define VDOCTORES_H
#pragma once
#include "Doctor.h"

class vDoctores {
private:
	Doctor* vec[100];
	int cantidad;
public:
	vDoctores();
	~vDoctores();

	void agregarDoctor(Doctor*);
	void imprimeContenedor();
	void eliminarDoctorPorNombre(string);
};

#endif // VDOCTORES_H
