
#include <iostream>
#include "Equipamiento.h"
#include "Personaje.h"

#include <vector>
#include <algorithm>
#include <string>

#include <chrono>
#include <thread>

using namespace std;

void imprimirMenuInicial() {
	cout << R"(

		______  ___ _____ _____ _      _____  ______ _______   _____   _      _____ 
		| ___ \/ _ \_   _|_   _| |    |  ___| | ___ \  _  \ \ / / _ \ | |    |  ___|
		| |_/ / /_\ \| |   | | | |    | |__   | |_/ / | | |\ V / /_\ \| |    | |__  
		| ___ \  _  || |   | | | |    |  __|  |    /| | | | \ /|  _  || |    |  __| 
		| |_/ / | | || |   | | | |____| |___  | |\ \\ \_/ / | || | | || |____| |___ 
		\____/\_| |_/\_/   \_/ \_____/\____/  \_| \_|\___/  \_/\_| |_/\_____/\____/ 
                                                                            
                                                                            
                                                                                                                                                                                                                                                                                      
    )" << endl;


	cout << " \n\n------------------------ CONFIGURA LA PARTIDA ------------------------ \n\n" << endl;
}
int imprimirRequestPersonaje(string nombre, int ataque, int vida, int max) {
	int x;

	// Convertir nombre a mayúsculas
	string nombreUpper = nombre;
	transform(nombreUpper.begin(), nombreUpper.end(), nombreUpper.begin(), ::toupper);

	cout << "\n\n" << nombreUpper << "\n";
	cout << "  Ataque: " << ataque << "\n";
	cout << "  Vida:   " << vida << "\n\n";

	cout << "Cuantos quieres? ";
	cin >> x;

	while (x > max) {
		cout << "El numero maximo por cada tipo es " << max << "!!\n";
		cout << "\n\n" << nombreUpper << "\n";
		cout << "  Ataque: " << ataque << "\n";
		cout << "  Vida:   " << vida << "\n\n";

		cout << "Cuantos quieres? ";
		cin >> x;
	}

	//cout << "Cantidad de " << nombre << "s: " << x << "\n\n";
	return x;
}

int imprimirRequestEquipamiento(const vector<int>& listaUsados) {
	int x;

	// Lista de textos
	vector<string> opciones = {
		"Espada (Ataque 2)",
		"Escudo (Defensa 3)",
		"Capa ignifuga (Defensa 1)",
		"Red antiflechas (Defensa 2)",
		"Arco encantado (Ataque 1)",
		"Mazo (Ataque 2)",
		"Amuleto (Defensa 1)",
		"Pocion de rabia (Ataque 2)"
	};

	cout << "\nElige su equipamiento:\n";

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
		cout << "Opcion no valida, elige otra: ";
		cin >> x;
	}

	return x;
}

void imprimirMatriz(std::string matriz[25][40]) {
	for (int i = 0; i < 25; i++) {//col
		for (int j = 0; j < 40; j++) {

			std::cout << matriz[i][j];
		}
		std::cout << std::endl;  // Salto de línea al terminar cada fila
	}
	
}

void comprobarAtaque(string matriz[25][40], vector<Personaje>& personajes, int& cantidadGuerreros, int& cantidadMagos, int& cantidadOgros,
	int& cantidadArquera, int& cantidadDragones, int& cantidadVampiros) {
	
	int idcolindante = -1;
	for (auto& p : personajes)
	{
		if (p.GetVida() <= 0) continue; //si está muerto no ataca
		p.atacando = p.ScanIndividual(matriz, personajes, idcolindante);
		if (idcolindante != -1) {
			Personaje& enemigo = personajes[idcolindante - 1];
			int vidaAntes = enemigo.GetVida();
			p.Atacar(enemigo, matriz);
			if (vidaAntes > 0 && enemigo.GetVida() <= 0) { // acaba de morir
				if (enemigo.GetAlias() == "G") cantidadGuerreros--;
				else if (enemigo.GetAlias() == "M") cantidadMagos--;
				else if (enemigo.GetAlias() == "O") cantidadOgros--;
				else if (enemigo.GetAlias() == "A") cantidadArquera--;
				else if (enemigo.GetAlias() == "D") cantidadDragones--;
				else if (enemigo.GetAlias() == "V") cantidadVampiros--;
			}
		}
	}
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
		}
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
	imprimirMenuInicial();
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



	system("cls");

	Equipamiento espada = Equipamiento(1, "Espada", 2, 0);
	Equipamiento escudo = Equipamiento(2, "Escudo", 0, 3);
	Equipamiento capaIgnifuga = Equipamiento(3, "Capa ignífuga", 0, 1);
	Equipamiento redAntiflechas = Equipamiento(4, "Red antiflechas", 0, 3);
	Equipamiento arcoEncantado = Equipamiento(5, "Arco encantado", 1, 0);
	Equipamiento mazo = Equipamiento(6, "Mazo", 2, 0);
	Equipamiento amuleto = Equipamiento(7, "Amuleto", 0, 1);
	Equipamiento pocionDeRabia = Equipamiento(8, "Poción de rabia", 2, 0);

	Equipamiento equipamientos[] = {
		espada,
		escudo,
		capaIgnifuga,
		redAntiflechas,
		arcoEncantado,
		mazo,
		amuleto,
		pocionDeRabia
	};

	Equipamiento equipGObj = equipamientos[equipamientoG - 1];
	Equipamiento equipMObj = equipamientos[equipamientoM - 1];
	Equipamiento equipOObj = equipamientos[equipamientoO - 1];
	Equipamiento equipAObj = equipamientos[equipamientoA - 1];
	Equipamiento equipDObj = equipamientos[equipamientoD - 1];
	Equipamiento equipVObj = equipamientos[equipamientoV - 1];


	Personaje guerrero = Personaje("Guerrero","G", 4 + equipGObj.ataque, 16 + equipGObj.vida, 0);
	Personaje mago = Personaje("Mago", "M", 5 + equipMObj.ataque, 10 + equipMObj.vida, 0);
	Personaje ogro = Personaje("Ogro", "O", 4 + equipOObj.ataque, 20 + equipOObj.vida, 0);
	Personaje arquera = Personaje("Arquera","A", 4 + equipAObj.ataque, 11 + equipAObj.vida, 0);
	Personaje dragon = Personaje("Dragon","D", 5 + equipDObj.ataque, 18 + equipDObj.vida, 0);
	Personaje vampiro = Personaje("Vampiro","V", 4 + equipVObj.ataque, 13 + equipVObj.vida, 0);

	vector<Personaje> personajes;

	int idHelper = 1;

	for (int i = 0; i < cantidadGuerreros; i++) {
		guerrero.SetId(idHelper); 
		idHelper++; 
		personajes.push_back(guerrero);
	}
	for (int i = 0; i < cantidadMagos; i++) {
		mago.SetId(idHelper); 
		idHelper++; 
		personajes.push_back(mago);
	}

	for (int i = 0; i < cantidadOgros; i++) {
		ogro.SetId(idHelper);
		idHelper++;
		personajes.push_back(ogro);
	}
	for (int i = 0; i < cantidadArquera; i++) {
		arquera.SetId(idHelper);
		idHelper++;
		personajes.push_back(arquera);
	}
	for (int i = 0; i < cantidadDragones; i++) {
		dragon.SetId(idHelper);
		idHelper++;
		personajes.push_back(dragon);
	}
	for (int i = 0; i < cantidadVampiros; i++) {
		vampiro.SetId(idHelper);
		idHelper++;
		personajes.push_back(vampiro);
	}

	
	//////////// ASIGNAR POSICIONES INICIALES /////////////

	for (auto& p : personajes)
	{
		bool hayAlgo = true;

		// Buscar una posición vacía
		while (hayAlgo)
		{
			p.x = rand() % 23 + 1; // entre 1 y 23
			p.y = rand() % 38 + 1; // entre 1 y 38

			hayAlgo = p.ScanIndividualInicial(matriz);
		}

		// Si sale del while, la posición está libre
		matriz[p.x][p.y] = " " + p.GetAlias();
	}

	//Dibujar matriz inicial
	imprimirMatriz(matriz);

	std::this_thread::sleep_for(std::chrono::seconds(5));

	//////////// END ASIGNAR POSICIONES INICIALES /////////////
	
	


	///////////// EMPEZAR MOVIMIENTO /////////////
	while (true) {
		system("cls");

		
		//movimiento
		for (auto& p : personajes)
		{
			if (p.atacando == false) {
				p.Moverse(matriz);
			}
		}

		//Si hay alguien al lado atacar hasta que se muera. Si no hay nadie, se mueve
		comprobarAtaque(matriz, personajes,cantidadGuerreros, cantidadMagos, cantidadOgros, cantidadArquera, cantidadDragones, cantidadVampiros);

		
		imprimirMatriz(matriz);

		cout << "\n------------------------ Cantidad de personajes vivos ------------------------\n\n";
		cout << "Guerreros: " << cantidadGuerreros << "    Magos: " << cantidadMagos << "    Ogros: " << cantidadOgros << "    Arqueras: " << cantidadArquera << "    Dragones: " << cantidadDragones << "    Vampiros: " << cantidadVampiros <<  endl;
	
		int totalVivos = cantidadGuerreros + cantidadMagos + cantidadOgros +
			cantidadArquera + cantidadDragones + cantidadVampiros;

		if (totalVivos <= 1) {
			cout << "\n¡El juego ha terminado!\n";

			// Mostrar quién ganó
			if (cantidadGuerreros) cout << "Ganador: Guerrero\n";
			else if (cantidadMagos) cout << "Ganador: Mago\n";
			else if (cantidadOgros) cout << "Ganador: Ogro\n";
			else if (cantidadArquera) cout << "Ganador: Arquera\n";
			else if (cantidadDragones) cout << "Ganador: Dragón\n";
			else if (cantidadVampiros) cout << "Ganador: Vampiro\n";

			break;  // rompe el while(true)
		}
		else {
			//esperar 5s
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}


	}
	//////////// END MOVIMIENTO /////////////
	



	 
	 
	
	return 0;
}



