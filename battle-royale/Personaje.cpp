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

bool Personaje::ScanIndividual(string matriz[25][40])
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
	vida = 0;
	//cout << el personaje << " ha sido eliminado.\n";
	
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



//std::string(&Personaje::Moverse(std::string matriz[25][40], int xInicial, int yInicial))[25][40]
//{
//	bool hayAlgo = true;
//	int cantIntentos = 0;
//	while (hayAlgo) {
//		//Lógica de movimiento
//		int dir = rand() % 4; // 0=arriba, 1=abajo, 2=izq, 3=der
//
//		switch (dir)
//		{
//		case 0: // ir para arriba
//			if (x > 1) x--;
//			break;
//		case 1: // ir para abajo
//			if (x < 23) x++;
//			break;
//		case 2: // ir para la izquierda
//			if (y > 1) y--;
//			break;
//		case 3: // ir para al derecha
//			if (y < 38) y++;
//			break;
//		}
//
//		if (matriz[x][y] == "  ") {
//			hayAlgo = false;
//		}
//
//		if (cantIntentos > 10) {
//			//no se mueve
//			hayAlgo = false;
//		}
//		cantIntentos++;
//	}
//
//	if (cantIntentos <= 10) {
//		matriz[x][y] = " " + alias;
//		matriz[xInicial][yInicial] = "  ";
//	}
//	//Si ha recibido daño, aumentar vida al moverse
//	if (vida < vidaMax) 
//	{
//		AumentarVida(1);
//	}
//
//
//
//	return matriz;
//}




void Personaje::AsignarEquipamiento(int equip)
{
	equipamiento = equip;
}
