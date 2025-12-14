#pragma once
#include "Personaje.h"

class Guerrero : public Personaje {
public:
    Guerrero(int ataque, int vida) : Personaje("Guerrero", "G", ataque, vida, 0) {}
};

class Mago : public Personaje {
public:
    Mago(int ataque, int vida) : Personaje("Mago", "M", ataque, vida, 0) {}
};

class Ogro : public Personaje {
public:
    Ogro(int ataque, int vida) : Personaje("Ogro", "O", ataque, vida, 0) {}
};

class Arquera : public Personaje {
public:
    Arquera(int ataque, int vida) : Personaje("Arquera", "A", ataque, vida, 0) {}
};

class Dragon : public Personaje {
public:
    Dragon(int ataque, int vida) : Personaje("Dragon", "D", ataque, vida, 0) {}
};

class Vampiro : public Personaje {
public:
    Vampiro(int ataque, int vida) : Personaje("Vampiro", "V", ataque, vida, 0) {}
};