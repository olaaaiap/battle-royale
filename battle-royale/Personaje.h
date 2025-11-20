#pragma once
#include <string>
#include <iostream>
#include <vector>

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

	/*int GetVida() const;
	int GetAtaque() const;
	void SetVida(int v);
	*/


	int GetVida() 
	{ 
		return vida; 
	}
	int GetAtaque() 
	{ 
		return ataque; 
	}
	string GetAlias() 
	{ 
		return alias; 
	}

	int x;
	int y;
	
	Personaje(string, string, int, int, int);
	void Atacar(Personaje& enemigo);
	int Scan(const vector<Personaje>& personajes);
	void RecibirDaño(int);
	void Destruir();
	void AumentarVida(int);
	void Moverse();
	void AsignarEquipamiento(int);
};

