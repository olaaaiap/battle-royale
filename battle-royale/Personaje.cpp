#include "Personaje.h"



Personaje::Personaje(string nombreP, string aliasP, int ataqueP, int vidaP, int equipamientoP) {
	nombre = nombreP;
	alias = aliasP;
	ataque = ataqueP;
	vida = vidaP;
	vidaMax = vidaP;
	equipamiento = equipamientoP;

	x = 0;
	y = 0;
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
	//cout << el personaje << " ha sido eliminado.\n";
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
