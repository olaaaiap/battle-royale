#pragma once

#include <string>
#include <iostream>

using namespace std;



class Equipamiento
{
	int codigo;
	string nombre;
public:
	int ataque;
	int vida;
	Equipamiento(int, string, int, int);
};

