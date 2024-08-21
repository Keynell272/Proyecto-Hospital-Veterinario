#ifndef VMASCOTAS_H
#define VMASCOTAS_H
#pragma once
#include "Mascota.h"

class vMascotas {
private:
	Mascota ** vec;
	int cantidad;
public:
	vMascotas();
	~vMascotas();

	void agregarMascota(Mascota*);
	void imprimeContenedor();
	void eliminarMascotaPorNombre(string);
};

#endif // VMASCOTAS_H
