#pragma once
#include "Equipamiento.h"

class Espada : public Equipamiento {
public:
    Espada() : Equipamiento(1, "Espada", 2, 0) {}
};

class Escudo : public Equipamiento {
public:
    Escudo() : Equipamiento(2, "Escudo", 0, 3) {}
};

class CapaIgnifuga : public Equipamiento {
public:
    CapaIgnifuga() : Equipamiento(3, "Capa ignifuga", 0, 1) {}
};

class RedAntiflechas : public Equipamiento {
public:
    RedAntiflechas() : Equipamiento(4, "Red antiflechas", 0, 3) {}
};

class ArcoEncantado : public Equipamiento {
public:
    ArcoEncantado() : Equipamiento(5, "Arco encantado", 1, 0) {}
};

class Mazo : public Equipamiento {
public:
    Mazo() : Equipamiento(6, "Mazo", 2, 0) {}
};

class Amuleto : public Equipamiento {
public:
    Amuleto() : Equipamiento(7, "Amuleto", 0, 1) {}
};

class PocionDeRabia : public Equipamiento {
public:
    PocionDeRabia() : Equipamiento(8, "Pocion de rabia", 2, 0) {}
};
