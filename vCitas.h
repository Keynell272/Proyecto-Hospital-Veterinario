#ifndef VCITAS_H
#define VCITAS_H
#pragma once
#include "Cita.h"

class vCitas {
private:
	Cita** vec;
	int cantidad;
	int tamano;
public:
	vCitas(int);
	~vCitas();

	void setCantidad(int);
	int getCantidad();
	Cita* getVec(int);

	bool agregarCita(Cita*);
	void imprimeContenedor();
	void eliminarCitaPorDia(string);

	bool estaVacio();
};

#endif // !VCITAS_H
