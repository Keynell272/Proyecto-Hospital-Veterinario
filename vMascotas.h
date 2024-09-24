#ifndef VMASCOTAS_H
#define VMASCOTAS_H
#pragma once
#include "Mascota.h"

class vMascotas {
private:
	Mascota ** vec;
	int cantidad;
	int tamano;
public:
	vMascotas(int);
	~vMascotas();

	void setCantidad(int);
	int getCantidad();	
	Mascota* getVec(int);

	void agregarMascota(Mascota*);
	void imprimeContenedor();

	bool estaVacio();

	string mascotasPorDueno(int);
	int cantidadMascotasPorDueno(int);
	bool verificarPosicion(int, int);
	bool tieneMascota(int);
};

#endif // !VMASCOTAS_H
