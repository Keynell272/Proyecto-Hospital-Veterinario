#pragma once
#include "Especialidad.h"

class vEspecialidades {
private:
	Especialidad* vec[100];
	int cantidad;
public:
	vEspecialidades();
	~vEspecialidades();

	void agregarEspecialidad(Especialidad&);
	void imprimeContenedor();
	void eliminarEspecialidadPorNombre(string);
};
