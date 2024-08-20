#ifndef DUENO_H
#define DUENO_H

#include "Doctor.h"

class Dueno {
private:
  string nombre;
  int ID;

public:
Dueno();
Dueno(string, int);
~Dueno();

void setNombre(string);
void setID(int);

string getNombre();
int getID();

string toString();

};

#endif // DUENO_H
   

#endif // DUENO_H

