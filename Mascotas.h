#ifndef MASCOTA_H
#define MASCOTA_H

#include "Dueno.h"

class Mascota {
private:
    string nombre;
    Dueno* dueno;

public:
    Mascota(string, Duenio*);
};

#endif // MASCOTA_H

