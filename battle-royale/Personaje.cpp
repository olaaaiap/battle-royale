#include "Personaje.h"



Personaje::Personaje(string nombreP, string aliasP, int ataqueP, int vidaP, int equipamientoP) {
	nombre = nombreP;
	alias = aliasP;
	ataque = ataqueP;
	vida = vidaP;
	vidaMax = vidaP;
	equipamiento = equipamientoP;
}


void Personaje::Atacar() 
{

}

void Personaje::RecibirDaño(int daño) 
{
	vida -= daño;
}

void Personaje::Destruir() 
{

}

void Personaje::AumentarVida(int cantVida) 
{
	vida += cantVida;
}

void Personaje::Moverse()
{
	//Lógica de movimiento

	//Si ha recibido daño, aumentar vida al moverse
	if (vida < vidaMax) {
		AumentarVida(1);
	}
}

void Personaje::AsignarEquipamiento(int equip)
{
	equipamiento = equip;
}
