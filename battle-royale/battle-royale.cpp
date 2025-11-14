
#include <iostream>
#include "Equipamiento.h"
#include "Personaje.h"

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
				matriz[i][j] = " ";
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

	///////////////////////////// GUERRERO /////////////////////////////
	cout << "GUERRERO (Ataque: 4; Vida: 16) \n"; 
	cout << "Cuantos quieres? "; 
	cin >> x;
	while (x > max) {
		cout << "El numero maximo por cada tipo es 40!!\n";
		cout << "GUERRERO (Ataque: 4; Vida: 16)\n";
		cout << "Cuantos quieres? ";
		cin >> x;
	}
	cout << "Cantidad de guerreros: " << x;
	cantidadGuerreros = x;
	cout << "\n\n";

	///////////////////////////// END GUERRERO /////////////////////////////



	cout << "MAGO (Ataque: 5; Vida: 10) \n";
	cout << "Cuantos quieres? ";
	cin >> x;
	while (x > max) {
		cout << "El numero maximo por cada tipo es 40!!\n";
		cout << "MAGO (Ataque: 5; Vida: 10)\n";
		cout << "Cuantos quieres? ";
		cin >> x;
	}
	cout << "Cantidad de magos: " << x;
	cantidadMagos = x;
	cout << "\n\n";

	cout << "OGRO (Ataque: 4; Vida: 20) \n";
	cout << "Cuantos quieres? ";
	cin >> x;
	while (x > max) {
		cout << "El numero maximo por cada tipo es 40!!\n";
		cout << "OGRO (Ataque: 4; Vida: 20)\n";
		cout << "Cuantos quieres? ";
		cin >> x;
	}
	cout << "Cantidad de ogros: " << x;
	cantidadOgros = x;
	cout << "\n\n";

	cout << "ARQUERA (Ataque: 4; Vida: 11)\n";
	cout << "Cuantos quieres? ";
	cin >> x;
	while (x > max) {
		cout << "El numero maximo por cada tipo es 40!!\n";
		cout << "ARQUERA (Ataque: 4; Vida: 11)\n";
		cout << "Cuantos quieres? ";
		cin >> x;

	}
	cout << "ARQUERA: " << x;
	cantidadArquera = x;
	cout << "\n\n";


	cout << "DRAGON (Ataque: 5; Vida: 18)\n";
	cout << "Cuantos quieres? ";
	cin >> x;
	while (x > max) {
		cout << "El numero maximo por cada tipo es 40!!\n";
		cout << "DRAGON (Ataque: 5; Vida: 18)\n";
		cout << "Cuantos quieres? ";
		cin >> x;
	}
	cout << "DRAGON: " << x;
	cantidadDragones = x;
	cout << "\n\n";
	 

	cout << "VAMPIRO (Ataque: 4; Vida: 13)\n";
	cout << "Cuantos quieres? ";
	cin >> x;
	while (x > max) {
		cout << "El numero maximo por cada tipo es 40!!\n";
		cout << "VAMPIRO (Ataque: 4; Vida: 13)\n";
		cout << "Cuantos quieres? ";
		cin >> x;
	}
	cout << "VAMPIRO: " << x;
	cantidadVampiros = x;
	cout << "\n\n";

	return 0;


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


}

