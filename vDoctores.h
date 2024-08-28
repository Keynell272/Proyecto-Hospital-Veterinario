#ifndef VDOCTORES_H
#define VDOCTORES_H
#pragma once
#include "Doctor.h"

class vDoctores {
private:
	Doctor ** vec;
	int cantidad;
	int tamano;
public:
	vDoctores(int);
	~vDoctores();

	void setCantidad(int);
	int getCantidad();
	Doctor* getVec(int);

	void agregarDoctor(Doctor*);
	void imprimeContenedor();
	void eliminarDoctorPorNombre(string);

	bool estaVacio();
};

#endif // !VDOCTORES_H
