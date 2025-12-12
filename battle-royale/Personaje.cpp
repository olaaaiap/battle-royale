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


void Personaje::Atacar(Personaje& enemigo, string matriz[25][40])
{
	enemigo.RecibirDaño(ataque);
	if (enemigo.vida <= 0)
	{
		enemigo.Destruir(matriz);
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

bool Personaje::ScanIndividual(string matriz[25][40], const vector<Personaje>& personajes, int& idColindante)
{
	idColindante = -1;
	if (matriz[x+1][y] != "  ") {
		for (const auto& p : personajes) {
			if (p.x == x + 1 && p.y == y) {
				idColindante = p.id;   
				return true;
			}
		}
	}
	
	if (matriz[x][y+1] != "  ") {
		for (const auto& p : personajes) {
			if (p.x == x && p.y == y + 1) {
				idColindante = p.id;
				return true;
			}
		}
	}
	
	if (matriz[x-1][y] != "  ") {
		for (const auto& p : personajes) {
			if (p.x == x - 1 && p.y == y) {
				idColindante = p.id;
				return true;
			}
		}
	} 
	
	if (matriz[x][y - 1] != "  ") {
		for (const auto& p : personajes) {
			if (p.x == x && p.y == y - 1) {
				idColindante = p.id;
				return true;
			}
		}
	}
	
	return false;
}


bool Personaje::ScanIndividualInicial(string matriz[25][40])
{
	//En la posición
	if (matriz[x][y] != "  ") {
		return true;
	}
	//A la derecha
	if (matriz[x + 1][y] != "  ") {
		return true;
	}
	//Arriba
	if (matriz[x][y + 1] != "  ") {
		return true;
	}
	//Izquierda
	if (matriz[x - 1][y] != "  ") {
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

void Personaje::Destruir(string matriz[25][40])
{
	vida = 0;
	matriz[x][y] = "  ";
	
}

void Personaje::AumentarVida(int cantVida) 
{
	vida += cantVida;
}

std::string** Personaje::Moverse(std::string matriz[25][40]) {
	
	int xInicial = x;
	int yInicial = y;
	bool hayAlgo = true;
	int cantIntentos = 0;

	
	while (hayAlgo) {
		//Inicializar x e y para que no se mueva mas de 1 posición
		x = xInicial;
		y = yInicial;
		int dir = rand() % 4; // 0=arriba, 1=abajo, 2=izq, 3=der

		switch (dir) {
		case 0: if (x > 0) x--; break;
		case 1: if (x < 24) x++; break;
		case 2: if (y > 0) y--; break;
		case 3: if (y < 39) y++; break;
		}

		if (matriz[x][y] == "  ") {
			hayAlgo = false;
		}

		if (cantIntentos > 10) {
			// no se mueve
			hayAlgo = false;
		}

		cantIntentos++;
	}

	if (cantIntentos <= 10) {
		matriz[x][y] = " " + alias;
		matriz[xInicial][yInicial] = "  ";
	}

	if (vida < vidaMax) {
		AumentarVida(1);
	}

	return reinterpret_cast<std::string**>(matriz);
	

}


void Personaje::MoverseHacia(int centroX, int centroY, std::string matriz[25][40]) {
	if (vida <= 0) return;

	int movimientoX = 0;
	int movimientoY = 0;
	if (x < centroX) movimientoX = 1;
	else if (x > centroX) movimientoX = -1;
	if (y < centroY) movimientoY = 1;
	else if (y > centroY) movimientoY = -1;

	// Preferir mover en x o en y según ocupación:
	// Intentar mover en x primero
	if (movimientoX != 0) {
		int nx = x + movimientoX;
		int ny = y;
		// comprobar que la casilla esté libre (dos espacios o borde interior)
		if (matriz[nx][ny] == "  ") {
			matriz[x][y] = "  ";
			x = nx;
			y = ny;
			matriz[x][y] = " " + alias;
			return;
		}
	}

	if (movimientoY != 0) {
		int nx = x;
		int ny = y + movimientoY;
		if (matriz[nx][ny] == "  ") {
			matriz[x][y] = "  ";
			x = nx;
			y = ny;
			matriz[x][y] = " " + alias;
			return;
		}
	}

}




void Personaje::AsignarEquipamiento(int equip)
{
	equipamiento = equip;
}
