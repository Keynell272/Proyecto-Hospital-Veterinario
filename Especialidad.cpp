#include "Especialidad.h"

Especialidad::Especialidad(): especialidad(""){}
Especialidad::Especialidad(string esp): especialidad(esp){}
Especialidad::~Especialidades() {}

void Especialidad::setEspecialidad(string esp) { especialidad = esp; }
string Especialidad::getEspecialidad() { return especialidad; }

string Especialidad::toString(){
  stringstream s;
  s << "Especialidad: " << especialidad << endl;
  return s.str();
}
