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

	bool estaVacio();

	string toStringDoctoresXDueno(int);
	string toStringMascotasXDoctor(Doctor*, int);
	bool eliminarCitaXMascota(int);

	int cantidadDoctoresPorDueno(int);
	bool verificarPosicion(int, int);
	string toStringCitasXDueno(int);
	string toStringCitasXDoctor(Doctor*);
	string toStringPacienteXDoctor(Doctor*);
};

#endif // !VCITAS_H
