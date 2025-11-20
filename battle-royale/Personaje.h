#pragma once


#include <string>
#include <iostream>

using namespace std;


class Personaje
{
	string nombre;
	string alias;
	int ataque;
	int vida;
	int vidaMax;
	int equipamiento;
public:
	int x;
	int y;
	
	Personaje(string, string, int, int, int);
	void Atacar();
	void RecibirDaño(int);
	void Destruir();
	void AumentarVida(int);
	void Moverse();
	void AsignarEquipamiento(int);
};

