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
	void eliminarMascotaPorNombre(string);

	bool estaVacio();
};

#endif // !VMASCOTAS_H
