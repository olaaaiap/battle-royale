
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
	int equipamientoG;
	int equipamientoM;
	int equipamientoO;
	int equipamientoA;
	int equipamientoD;
	int equipamientoV;

	
	vector<int> usados = {}; // espada y capa ya usadas


	cantidadGuerreros = imprimirRequestPersonaje("Guerrero", 4, 16, 40);
	equipamientoG = imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoG);

	cantidadMagos = imprimirRequestPersonaje("Mago", 5, 10, 40);
	equipamientoM= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoM);

	cantidadOgros = imprimirRequestPersonaje("Ogro", 4, 20, 40);
	equipamientoO= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoO);

	cantidadArquera = imprimirRequestPersonaje("Arquera", 4, 11, 40);
	equipamientoA= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoA);

	cantidadDragones = imprimirRequestPersonaje("Dragones", 5, 18, 40);
	equipamientoD= imprimirRequestEquipamiento(usados);
	usados.push_back(equipamientoD);

	cantidadVampiros = imprimirRequestPersonaje("Vampiro", 4, 13, 40);
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

	vector<Personaje> personajes;

	srand(time(NULL)); //esto es la semilla aleatoria
	//esto es para asignar las posiciones de los personajes(borrar si ya lo ha hecho Olaia)
	for (auto& p : personajes)
	{
		p.x = rand() % 23 + 1; // entre 1 y 23
		p.y = rand() % 38 + 1; // entre 1 y 38
	}
	//esto es el bucle de turnos donde todos se mueven, vali?
	while (personajes.size() > 1)
	{
		// Mover a todos
		for (auto& p : personajes)
		{
			p.Moverse();
		}
		cout << "\n--- TURNO ---\n";
		for (auto& p : personajes)
		{
			cout << p.GetAlias() << " -> (" << p.x << "," << p.y << ")\n";
		}
		system("pause");
	}

	// COMBATE: revisar cada personaje PERO NECESITO ACCEDER A LA VIDA
	//for (int i = 0; i < personajes.size(); i++)
	//{
	//	Personaje& p = personajes[i];
	//	int enemigoIndex = p.Scan(personajes);
	//	if (enemigoIndex != -1)
	//	{
	//		Personaje& enemigo = personajes[enemigoIndex];
	//		while (p.vida > 0 && enemigo.vida > 0)
	//		{
	//			p.Atacar(enemigo);
	//			if (enemigo.vida <= 0) break;
	//			enemigo.Atacar(p);
	//		}
	//		// eliminar a los muertos del vector
	//		personajes.erase(remove_if(personajes.begin(), personajes.end(),[](const Personaje& pj) { return pj.vida <= 0; }),personajes.end());
	//	}
	//}


	for (int i = 0; i < cantidadGuerreros; i++) personajes.push_back(guerrero);
	for (int i = 0; i < cantidadMagos; i++) personajes.push_back(mago);
	for (int i = 0; i < cantidadOgros; i++) personajes.push_back(ogro);
	for (int i = 0; i < cantidadArquera; i++) personajes.push_back(arquera);
	for (int i = 0; i < cantidadDragones; i++) personajes.push_back(dragon);
	for (int i = 0; i < cantidadVampiros; i++) personajes.push_back(vampiro);


	return 0;
}

