
#include <iostream>
#include "Equipamiento.h"
#include "Personaje.h"

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int imprimirRequestPersonaje(string nombre, int ataque, int vida, int max) {
	int x;

	// Convertir nombre a mayúsculas
	string nombreUpper = nombre;
	transform(nombreUpper.begin(), nombreUpper.end(), nombreUpper.begin(), ::toupper);

	cout << nombreUpper << " (Ataque: " << ataque << "; Vida: " << vida << ")\n";
	cout << "Cuantos quieres? ";
	cin >> x;

	while (x > max) {
		cout << "El numero maximo por cada tipo es " << max << "!!\n";
		cout << nombreUpper << " (Ataque: " << ataque << "; Vida: " << vida << ")\n";
		cout << "Cuantos quieres? ";
		cin >> x;
	}

	cout << "Cantidad de " << nombre << "s: " << x << "\n\n";
	return x;
}


int imprimirRequestEquipamiento(const vector<int>& listaUsados) {
	int x;

	// Lista de textos
	vector<string> opciones = {
		"Espada (Ataque 2)",
		"Escudo (Defensa 3)",
		"Capa ignífuga (Defensa 1)",
		"Red antiflechas (Defensa 2)",
		"Arco encantado (Ataque 1)",
		"Mazo (Ataque 2)",
		"Amuleto (Defensa 1)",
		"Poción de rabia (Ataque 2)"
	};

	cout << "Elige su equipamiento:\n";

	// Mostrar solo las opciones NO usadas
	for (int i = 0; i < opciones.size(); i++) {
		if (find(listaUsados.begin(), listaUsados.end(), i + 1) == listaUsados.end()) {
			cout << " " << i + 1 << ". " << opciones[i] << "\n";
		}
	}

	cin >> x;

	// Validación: que exista y que NO esté usado
	while (x < 1 || x > opciones.size() ||
		find(listaUsados.begin(), listaUsados.end(), x) != listaUsados.end()) {
		cout << "Opción no válida, elige otra: ";
		cin >> x;
	}

	return x;
}

int main()
{
	string matriz[25][40];
	

	for (int i = 0; i < 25; i++) {//col
		for (int j = 0; j < 40; j++) {
			if (j == 0 || j == 39) {
				matriz[i][j] = "|";
			}
			else if (i == 0 || i == 24) {
				matriz[i][j] = "--";
			}
			else {
				matriz[i][j] = "  ";
			}
			//std::cout << matriz[i][j];
		}
		//std::cout << std::endl;  // Salto de línea al terminar cada fila
	}

	//Input
	int x;
	int max = 40;
	int cantidadGuerreros;
	int cantidadMagos;
	int cantidadOgros;
	int cantidadArquera;
	int cantidadDragones;
	int cantidadVampiros;
	int equipamientoG;
	int equipamientoM;
	int equipamientoO;
	int equipamientoA;
	int equipamientoD;
	int equipamientoV;

	
	vector<int> usados = {}; // espada y capa ya usadas

	int cantidadTotal = 0;
	cantidadGuerreros = imprimirRequestPersonaje("Guerrero", 4, 16, 40);
	cantidadTotal += cantidadGuerreros;
	equipamientoG = imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoG);

	cantidadMagos = imprimirRequestPersonaje("Mago", 5, 10, 40);
	cantidadTotal += cantidadMagos;
	equipamientoM= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoM);

	cantidadOgros = imprimirRequestPersonaje("Ogro", 4, 20, 40);
	cantidadTotal += cantidadOgros;
	equipamientoO= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoO);

	cantidadArquera = imprimirRequestPersonaje("Arquera", 4, 11, 40);
	cantidadTotal += cantidadArquera;
	equipamientoA= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoA);

	cantidadDragones = imprimirRequestPersonaje("Dragones", 5, 18, 40);
	cantidadTotal += cantidadDragones;
	equipamientoD= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoD);

	cantidadVampiros = imprimirRequestPersonaje("Vampiro", 4, 13, 40);
	cantidadTotal += cantidadVampiros;
	equipamientoV= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoV);




	Equipamiento espada = Equipamiento(1, "Espada", 2, 0);
	Equipamiento escudo = Equipamiento(2, "Escudo", 0, 3);
	Equipamiento capaIgnifuga = Equipamiento(3, "Capa ignífuga", 0, 1);
	Equipamiento redAntiflechas = Equipamiento(4, "Red antiflechas", 0, 3);
	Equipamiento arcoEncantado = Equipamiento(5, "Arco encantado", 1, 0);
	Equipamiento mazo = Equipamiento(6, "Mazo", 2, 0);
	Equipamiento amuleto = Equipamiento(7, "Amuleto", 0, 1);
	Equipamiento pocionDeRabia = Equipamiento(8, "Poción de rabia", 2, 0);


	//Esto luego irá en un for, después de que el usuario configure la partida
	Personaje guerrero = Personaje("Guerrero","G", 4, 16, 0);
	Personaje mago = Personaje("Mago", "M", 5, 10, 0);
	Personaje ogro = Personaje("Ogro", "O", 4, 20, 0);
	Personaje arquera = Personaje("Arquera","A", 4, 11, 0);
	Personaje dragon = Personaje("Dragon","D", 5, 18, 0);
	Personaje vampiro = Personaje("Vampiro","V", 4, 13, 0);


	string simbolos[6] = { " G", " M", " O", " A", " D", " V" };

	int cantidades[6] = {
		cantidadGuerreros,
		cantidadMagos,
		cantidadOgros,
		cantidadArquera,
		cantidadDragones,
		cantidadVampiros
	};

	for (int tipo = 0; tipo < 6; tipo++) {

		for (int i = 0; i < cantidades[tipo]; i++) {

			int x = rand() % 23 + 1; 
			int y = rand() % 38 + 1; 

			matriz[x][y] = simbolos[tipo];
		}
	}


	for (int i = 0; i < 25; i++) {//col
		for (int j = 0; j < 40; j++) {
			
			std::cout << matriz[i][j];
		}
		std::cout << std::endl;  // Salto de línea al terminar cada fila
	}

	return 0;
}

