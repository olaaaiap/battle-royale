#include "Personaje.h"



Personaje::Personaje(std::string nombreP, std::string aliasP, int ataqueP, int vidaP, int equipamientoP) {
	id = -1;
	nombre = nombreP;
	alias = aliasP;
	ataque = ataqueP;
	vida = vidaP;
	vidaMax = vidaP;
	equipamiento = equipamientoP;

	x = 0;
	y = 0;
}


void Personaje::Atacar(Personaje& enemigo, std::string matriz[25][40])
{
	enemigo.RecibirDaño(ataque);
}


bool Personaje::ScanIndividual(int matrizDeIds[25][40], int& idColindante)
{
	idColindante = -1;
	

	if(matrizDeIds[x + 1][y] != -1 && matrizDeIds[x + 1][y] != -2) {
		idColindante = matrizDeIds[x + 1][y];
		return true;
	}

	if (matrizDeIds[x][y + 1] != -1 && matrizDeIds[x][y + 1] != -2) {
		idColindante = matrizDeIds[x][y + 1];
		return true;
	}
	
	if (matrizDeIds[x - 1][y] != -1 && matrizDeIds[x - 1][y] != -2) {
		idColindante = matrizDeIds[x - 1][y];
		return true;
	}
	
	
	if (matrizDeIds[x][y - 1] != -1 && matrizDeIds[x][y - 1] != -2) {
		idColindante = matrizDeIds[x][y - 1];
		return true;
	}
	
	
	return false;
}


bool Personaje::ScanIndividualInicial(int matrizDeIds[25][40])
{
	if (matrizDeIds[x][y] != -1) {
		return true;
	}
	if (matrizDeIds[x + 1][y] != -1) {
		return true;
	}
	if (matrizDeIds[x][y + 1] != -1) {
		return true;
	}
	if (matrizDeIds[x - 1][y] != -1) {
		return true;
	}
	if (matrizDeIds[x - 1][y] != -1) {
		return true;
	}

	return false;
}


void Personaje::RecibirDaño(int daño) 
{
	vida -= daño;
}

void Personaje::Destruir(std::string matriz[25][40], int matrizDeIds[25][40])
{
	vida = 0;
	matriz[x][y] = "  ";
	matrizDeIds[x][y] = -1;
}

void Personaje::AumentarVida(int cantVida) 
{
	vida += cantVida;
}

void Personaje::Moverse(std::string matriz[25][40], int matrizDeIds[25][40], int idPersonaje) {
	
	int xInicial = x;
	int yInicial = y;
	bool hayAlgo = true;
	int cantIntentos = 0;

	
	while (hayAlgo) {
		x = xInicial;
		y = yInicial;
		int dir = rand() % 4;


		switch (dir) {
		case 0: if (x > 1) x--; break;
		case 1: if (x < 23) x++; break;
		case 2: if (y > 1) y--; break;
		case 3: if (y < 38) y++; break;
		}

		if (matrizDeIds[x][y] == -1) {
			hayAlgo = false;
		}

		if (cantIntentos > 10) {
			x = xInicial;
			y = yInicial;
			hayAlgo = false;
		}

		cantIntentos++;
	}

	if (cantIntentos <= 10) {
		matriz[x][y] = " " + alias;
		matrizDeIds[x][y] = idPersonaje;
		matriz[xInicial][yInicial] = "  ";
		matrizDeIds[xInicial][yInicial] = -1;
	}

	if (vida < vidaMax) {
		AumentarVida(1);
	}

}


void Personaje::MoverseHacia(int direccionX, int direccionY, std::string matriz[25][40], int matrizDeIds[25][40], int idPersonaje) {
	if (vida <= 0) return;

	int movimientoX = 0;
	int movimientoY = 0;
	if (x < direccionX) movimientoX = 1;
	else if (x > direccionX) movimientoX = -1;
	if (y < direccionY) movimientoY = 1;
	else if (y > direccionY) movimientoY = -1;
	
	if (movimientoX != 0) {
		int nuevoX = x + movimientoX;
		if (nuevoX > 0 && nuevoX < 24 && y > 0 && y < 39 && matrizDeIds[nuevoX][y] == -1) {
			matrizDeIds[x][y] = -1;
			matriz[x][y] = "  ";
			x = nuevoX;
			matriz[x][y] = " " + alias;
			matrizDeIds[x][y] = idPersonaje;
			return;
		}
	}

	if (movimientoY != 0) {
		int nuevoY = y + movimientoY;
		if (x > 0 && x < 24 && nuevoY > 0 && nuevoY < 39 && matrizDeIds[x][nuevoY] == -1) {

			matrizDeIds[x][y] = -1;
			matriz[x][y] = "  ";
			y = nuevoY;
			matriz[x][y] = " " + alias;
			matrizDeIds[x][y] = idPersonaje;
			return;
		}
	}

}




void Personaje::AsignarEquipamiento(int equip)
{
	equipamiento = equip;
}
