#include "Dueno.h"

Dueno::Dueno(string nom, int ident){
  nombre = nom;
  ID = ident;
}

Dueno::Dueno(){
  nombre = "";
  ID = 0;
}

Dueno::~Dueno() {}

void Dueno::setNombre(string nom) { 
  nombre = nom; 
}

void Dueno::setID(int identidad){
  ID = identidad;
}

string Dueno::getNombre() {
  return nombre; 
}

int Dueno::getID(){
  return ID;
}

string Dueno::toString(){
  stringstream s;
  s << "Nombre del dueno: " << nombre << endl;
  s<< "Numero de identidad: "<< ID<<endl;
  return s.str();
}
