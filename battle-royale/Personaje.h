#pragma once
#include <string>
#include <iostream>
#include <vector>


/// @class Personaje
/// @brief Clase que representa a un personaje en el juego.
class Personaje
{
	int id;
	std::string nombre;
	std::string alias;
	int ataque;
	int vida;
	int vidaMax;
	int equipamiento;
	int x;
	int y;
	bool atacando = false;
	bool irAlCentro = false;

public:
	int GetId() const
	{
		return id;
	}
	std::string GetAlias() 
	{ 
		return alias; 
	}
	int GetAtaque() const
	{ 
		return ataque; 
	}
	int GetVida() const
	{ 
		return vida; 
	}
	int GetX() const
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}
	int GetAtacando() const
	{
		return atacando;
	}
	int GetIrAlCentro() const
	{
		return irAlCentro;
	}
	void SetId(int i) 
	{ 
		id = i; 
	}
	void SetX(int posx)
	{
		x = posx;
	}
	void SetY(int posy)
	{
		y = posy;
	}
	void SetAtacando(bool newAtacando)
	{
		atacando = newAtacando;
	}
	void SetIrAlCentro(bool newIrAlCentro)
	{
		irAlCentro = newIrAlCentro;
	}

	/// @brief Constructor de la clase Personaje.
	/// 
	/// @param nombreP - Nombre del personaje
	/// @param aliasP - Alias del personaje
	/// @param ataqueP - Valor de ataque del personaje
	/// @param vidaP - Cantidad de vidas del personaje
	/// @param equipamientoP - El id del equipamiento del personaje.
	/// 
	Personaje(std::string nombreP, std::string aliasP, int ataqueP, int vidaP, int equipamientoP);
	
	/// @brief Reduce la vida del enemigo al ser atacado.
	/// 
	/// @param enemigo - Referencia al objeto del enemigo.
	/// @param matriz - Matriz del juego.
	void Atacar(Personaje& enemigo, std::string matriz[25][40]);
	
	/// @brief Escanea alrededor del personaje para encontrar personajes colindantes.
	/// 
	/// @param matrizDeIds - Matriz de IDs de personajes.
	/// @param idColindante - Referencia para guardar el valor del id del personaje colindante.
	/// @return true si hay un personaje colindante, false si no.
	bool ScanIndividual(int matrizDeIds[25][40], int& idColindante);
	
	/// @brief Comprueba si la posición inicial del personaje y sus casillas adyacentes están libres.
	/// 
	/// @param matrizDeIds - Matriz de IDs de personajes.
	/// @return true si hay algo en la posición o adyacentes, false si está libre.
	bool ScanIndividualInicial(int matrizDeIds[25][40]);
	
	/// @brief Reduce la vida del personaje.
	/// 
	/// @param daño - Cantidad de daño a recibir.
	void RecibirDaño(int daño);
	
	/// @brief Mata al personaje y lo elimina de la matriz.
	/// 
	/// @param matriz - Matriz del juego.
	/// @param matrizDeIds - Matriz de IDs de personajes.
	void Destruir(std::string matriz[25][40], int matrizDeIds[25][40]);
	
	/// @brief Aumenta la vida del personaje.
	/// 
	/// @param cantVida - Cantidad de vida a aumentar.
	void AumentarVida(int cantVida);
	
	/// @brief Mueve al personaje a una posición adyacente aleatoria si está libre.
	/// 
	/// @param matriz - Matriz del juego.
	/// @param matrizDeIds - Matriz de IDs de personajes.
	/// @param idPersonaje - ID del personaje que se va a mover.
	void Moverse(std::string matriz[25][40], int matrizDeIds[25][40], int idPersonaje);
	
	/// @brief Mueve al personaje a una posición adyacente en dirección hacia las coordenadas dadas.
	/// 
	/// @param direccionX - Coordenada X de la dirección.
	/// @param direccionY - Coordenada Y de la dirección.
	/// @param matriz - Matriz del juego.
	/// @param matrizDeIds - Matriz de IDs de personajes.
	/// @param idPersonaje - ID del personaje que se va a mover.
	void MoverseHacia(int direccionX, int direccionY, std::string matriz[25][40], int matrizDeIds[25][40], int idPersonaje);
	
	/// @brief Asigna el equipamiento al personaje.
	/// 
	/// @param equip - ID del equipamiento a asignar.
	void AsignarEquipamiento(int equip);
};

