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


void Personaje::Atacar(Personaje& enemigo)
{
	enemigo.RecibirDaño(ataque);

	if (enemigo.vida <= 0)
	{
		enemigo.Destruir();
	}
}


int Personaje::Scan(const vector<Personaje>& personajes)
{
	for (int i = 0; i < personajes.size(); i++)
	{
		const Personaje& p = personajes[i];
		if (&p == this) continue;
		// detectar arriba
		if (p.x == x - 1 && p.y == y)
			return i;
		// detectar abajo
		if (p.x == x + 1 && p.y == y)
			return i;
		// detectar ala izquierda
		if (p.x == x && p.y == y - 1)
			return i;
		// detectar a la derecha
		if (p.x == x && p.y == y + 1)
			return i;
	}
	return -1; // no hay enemigo cerca
}

void Personaje::RecibirDaño(int daño) 
{
	vida -= daño;
}

void Personaje::Destruir() 
{
	void Personaje::Destruir()
	{
		vida = 0;
		//cout << el personaje << " ha sido eliminado.\n";
	}
}

void Personaje::AumentarVida(int cantVida) 
{
	vida += cantVida;
}

void Personaje::Moverse()
{
	//Lógica de movimiento
	int dir = rand() % 4; // 0=arriba, 1=abajo, 2=izq, 3=der

	switch (dir)
	{
	case 0: // ir para arriba
		if (x > 1) x--;
		break;
	case 1: // ir para abajo
		if (x < 23) x++;
		break;
	case 2: // ir para la izquierda
		if (y > 1) y--;
		break;
	case 3: // ir para al derecha
		if (y < 38) y++;
		break;
	}
	//Si ha recibido daño, aumentar vida al moverse
	if (vida < vidaMax) 
	{
		AumentarVida(1);
	}
}

void Personaje::AsignarEquipamiento(int equip)
{
	equipamiento = equip;
}
