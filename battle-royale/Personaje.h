#pragma once
#include <string>
#include <iostream>
#include <vector>



class Personaje
{
	int id;
	std::string nombre;
	std::string alias;
	int ataque;
	int vida;
	int vidaMax;
	int equipamiento;
public:

	int GetVida() 
	{ 
		return vida; 
	}
	int GetAtaque() 
	{ 
		return ataque; 
	}
	std::string GetAlias() 
	{ 
		return alias; 
	}
	int GetId()
	{
		return id;
	}
	void SetId(int i) 
	{ 
		id = i; 
	}

	int x;
	int y;
	bool atacando = false;
	bool irAlCentro = false;
	
	Personaje(std::string, std::string, int, int, int);
	void Atacar(Personaje& enemigo, std::string matriz[25][40]);
	bool ScanIndividual(int matrizDeIds[25][40], int& idColindante);
	bool ScanIndividualInicial(int matrizDeIds[25][40]);
	void RecibirDaño(int);
	void Destruir(std::string matriz[25][40], int matrizDeIds[25][40]);
	void AumentarVida(int);
	void Moverse(std::string matriz[25][40], int matrizDeIds[25][40], int idPersonaje);
	void MoverseHacia(int direccionX, int direccionY, std::string matriz[25][40], int matrizDeIds[25][40], int idPersonaje);
	void AsignarEquipamiento(int);
};

