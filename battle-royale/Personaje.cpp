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

bool Personaje::Scan(const vector<Personaje>& personajes)
{
	for (const auto& p : personajes)
	{
		if (&p == this) continue;

		// Detectar arriba
		if (p.x == x - 1 && p.y == y)
			return true;

		// Detectar abajo
		if (p.x == x + 1 && p.y == y)
			return true;

		// Detectar ala izquierda
		if (p.x == x && p.y == y - 1)
			return true;

		// Detecta a la derecha
		if (p.x == x && p.y == y + 1)
			return true;
	}
	return false;
}

bool Personaje::ScanIndividual(string matriz[25][40], int x, int y)
{
	//En la posición
	if (matriz[x][y] != "  ") {
		return true;
	}
	//A la derecha
	if (matriz[x+1][y] != "  ") {
		return true;
	}
	//Arriba
	if (matriz[x][y+1] != "  ") {
		return true;
	}
	//Izquierda
	if (matriz[x-1][y] != "  ") {
		return true;
	}
	//Abajo
	if (matriz[x - 1][y] != "  ") {
		return true;
	}
	
	return false;
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
