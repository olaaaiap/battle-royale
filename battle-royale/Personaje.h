#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Personaje
{
	int id;
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
	void SetId(int i) 
	{ 
		id = i; 
	}

	int x;
	int y;
	bool atacando = false;
	
	Personaje(string, string, int, int, int);
	void Atacar(Personaje& enemigo, string matriz[25][40]);
	int Scan(const vector<Personaje>& personajes);
	bool ScanIndividual(string matriz[25][40], const vector<Personaje>& personajes, int& idColindante);
	bool ScanIndividualInicial(string matriz[25][40]);
	void RecibirDaño(int);
	void Destruir(string matriz[25][40]);
	void AumentarVida(int);
	std::string** Moverse(std::string matriz[25][40]);
	void AsignarEquipamiento(int);
};

