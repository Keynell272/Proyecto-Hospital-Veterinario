#ifndef VESPECIALIDADES_H
#define VESPECIALIDADES_H
#pragma once
#include "Especialidad.h"

class vEspecialidades {
private:
	Especialidad ** vec;
	int cantidad;
	int tamano;
public:
	vEspecialidades();
	~vEspecialidades();

	void agregarEspecialidad(Especialidad*);
	void imprimeContenedor();
	void eliminarEspecialidadPorNombre(string);
};

#endif // !VESPECIALIDADES_H
