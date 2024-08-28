#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#pragma once
#include "utiles.h"

class Especialidad{
private:
    string especialidad;
public:
    Especialidad();
    Especialidad(string);
    ~Especialidad();

    void setEspecialidad(string);
    string getEspecialidad();

    string toString();
};

#endif // !ESPECIALIDAD_H
