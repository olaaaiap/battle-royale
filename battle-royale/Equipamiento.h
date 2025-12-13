#pragma once

#include <string>
#include <iostream>

using namespace std;



class Equipamiento
{
	int codigo;
	string nombre;
	int ataque;
	int vida;
public:
	int GetAtaque() const
	{
		return ataque;
	}
	int GetVida() const
	{
		return vida;
	}


	/// @brief Constructor de la clase Equipamiento.
	/// 
	/// @param codigoE - Codigo o id del equipamiento
	/// @param nombreE - Nombre del equipamiento
	/// @param ataqueE - Valor de ataque del equipamiento
	/// @param vidaE - Valor de defensa del equipamiento
	/// 
	Equipamiento(int codigoE, string nombreE, int ataqueE, int vidaE);
};

