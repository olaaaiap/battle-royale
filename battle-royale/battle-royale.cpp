
#include <iostream>
#include "Equipamiento.h"
#include "Personaje.h"
#include "TiposDePersonajes.h"
#include "TiposDeEquipamientos.h"

#include <vector>
#include <algorithm>
#include <string>

#include <chrono>
#include <thread>

using namespace std;

int limSuperior = 1;
int limInferior = 23;
int limIzquierda = 1;
int limDerecha = 38;

int ronda = 1;
const int rondasParaCierre = 8;
const int rondasParaAviso = 3;


/// @brief Lee, valida y devuelve el texto introducido por el usuario.
/// 
/// Esta función solicita al usuario un numero a través de la entrada estándar 
/// y comprueba que sea un número entero.
/// Si el usuario inserta un valor no válido, se le vuelve a solicitar hasta que lo haga correctamente.
/// 
/// @return El número entero introducido por el usuario.
static int leetInputEntero() {
	int x;
	while (true) {
		if (cin >> x) {
			return x;
		}
		cout << "Opcion no valida, elige otra: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

/// @brief Imprime el menú inicial del juego.
/// 
static void imprimirMenuInicial() {
	cout << R"(

		______  ___ _____ _____ _      _____  ______ _______   _____   _      _____ 
		| ___ \/ _ \_   _|_   _| |    |  ___| | ___ \  _  \ \ / / _ \ | |    |  ___|
		| |_/ / /_\ \| |   | | | |    | |__   | |_/ / | | |\ V / /_\ \| |    | |__  
		| ___ \  _  || |   | | | |    |  __|  |    /| | | | \ /|  _  || |    |  __| 
		| |_/ / | | || |   | | | |____| |___  | |\ \\ \_/ / | || | | || |____| |___ 
		\____/\_| |_/\_/   \_/ \_____/\____/  \_| \_|\___/  \_/\_| |_/\_____/\____/ 
                                                                            
                                                                            
                                                                                                                                                                                                                                                                                      
    )" << endl;

	cout << "Bienvenido al campo de batalla, valiente jugador!\n\n"
		<< "Aqui podras organizar tu ejercito y decidir la disposicion inicial de tus personajes.\n"
		<< "Como buen comandante, sabras que la estrategia es la clave para determinar quien se lleva la victoria\n"
		<< "Ten en cuenta que si el campo de batalla se reduce demasiado, cabe la posibilidad de que todos mueran!\n"
		<< "Tip: juega en pantalla completa para la mejor experiencia.\n\n"
		<< "Que empiece la aventura!\n\n";


	cout << " \n------------------------ CONFIGURA LA PARTIDA ------------------------ " << endl;
}

/// @brief Imprime la información del personaje y solicita la cantidad deseada por cada uno.
/// @param nombre - Nombre del personaje.
/// @param ataque - Valor de ataque del personaje.
/// @param vida - Cantidad de vidas que tiene el personaje
/// @param max - Cantidad máxima permitida por cada tipo de personaje.
/// @return Cantidad de personajes seleccionados.
static int imprimirRequestPersonaje(string nombre, int ataque, int vida, int max) {
	int x;

	string nombreUpper = nombre;
	transform(nombreUpper.begin(), nombreUpper.end(), nombreUpper.begin(), ::toupper);

	cout << "\n\n" << nombreUpper << "\n";
	cout << "  Ataque: " << ataque << "\n";
	cout << "  Vida:   " << vida << "\n\n";

	cout << "Cuantos quieres? ";
	x = leetInputEntero();

	while (x > max) {
		cout << "El numero maximo por cada tipo es " << max << "!!\n";
		cout << "\n\n" << nombreUpper << "\n";
		cout << "  Ataque: " << ataque << "\n";
		cout << "  Vida:   " << vida << "\n\n";

		cout << "Cuantos quieres? ";
		x = leetInputEntero();
	}

	return x;
}

/// @brief Imprime las opciones de equipamiento y solicita una opción para aplicar al personaje.
/// @param listaUsados - Vector con los índices de los equipamientos ya utilizados.
/// @return Índice del equipamiento seleccionado.
static int imprimirRequestEquipamiento(const vector<int>& listaUsados) {
	int x;

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

	for (int i = 0; i < opciones.size(); i++) {
		if (find(listaUsados.begin(), listaUsados.end(), i + 1) == listaUsados.end()) {
			cout << " " << i + 1 << ". " << opciones[i] << "\n";
		}
	}

	x = leetInputEntero();

	while (x < 1 || x > opciones.size() ||
		find(listaUsados.begin(), listaUsados.end(), x) != listaUsados.end()) {
		cout << "Opcion no valida, elige otra: ";
		x = leetInputEntero();
	}

	return x;
}

/// @brief Imprime la matriz en la consola.
/// @param matriz - Matriz a imprimir.
static void imprimirMatriz(std::string matriz[25][40]) {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 40; j++) {
			std::cout << matriz[i][j];
		}
		std::cout << std::endl;  
	}
}

/// @brief Imprime las cantidades totales de personajes vivos.
/// @param cantidadGuerreros - Cantidad de guerreros vivos.
/// @param cantidadMagos - Cantidad de magos vivos.
/// @param cantidadOgros - Cantidad de ogros vivos.
/// @param cantidadArqueras - Cantidad de arqueras vivas.
/// @param cantidadDragones - Cantidad de dragones vivos.
/// @param cantidadVampiros - Cantidad de vampiros vivos.
static void imprimirTotales(int& cantidadGuerreros, int& cantidadMagos, int& cantidadOgros,
	int& cantidadArqueras, int& cantidadDragones, int& cantidadVampiros) {
	cout << "\n------------------------ Cantidad de personajes vivos ------------------------\n\n";
	cout << "Guerreros: " << cantidadGuerreros << "    Magos: " << cantidadMagos << "    Ogros: " << cantidadOgros << "    Arqueras: " << cantidadArqueras << "    Dragones: " << cantidadDragones << "    Vampiros: " << cantidadVampiros << endl;
	cout << "TOTAL: " << cantidadGuerreros + cantidadMagos + cantidadOgros + cantidadArqueras + cantidadDragones + cantidadVampiros << endl;

}

/// @brief Imprime el contador de ronda actual.
/// @param ronda - La ronda actual.
static void imprimirContadorRonda(int& ronda) {
	cout << " ---------------------------\n";
	cout << "          Ronda " << ronda << "         \n";
	cout << " ---------------------------\n";
}

/// @brief Comprueba y realiza los ataques entre personajes colindantes.
/// 
/// La función obtiene datos de la partida y por cad apersonaje analiza si está colindante a otro.
/// Si es así, realiza el ataque y actualiza las cantidades de personajes vivos (solo si el enemigo ha muerto).
/// 
/// @param matriz - Matriz del juego.
/// @param personajes - Vector de personajes en el juego.
/// @param matrizDeIds - Matriz de IDs de personajes.
/// @param cantidadGuerreros - Cantidad de guerreros vivos.
/// @param cantidadMagos - Cantidad de magos vivos.
/// @param cantidadOgros - Cantidad de ogros vivos.
/// @param cantidadArqueras - Cantidad de arqueras vivas.
/// @param cantidadDragones - Cantidad de dragones vivos.
/// @param cantidadVampiros - Cantidad de vampiros vivos.
/// 
static void comprobarAtaque(string matriz[25][40], vector<Personaje>& personajes, int matrizDeIds[25][40], int& cantidadGuerreros, int& cantidadMagos, int& cantidadOgros,
	int& cantidadArqueras, int& cantidadDragones, int& cantidadVampiros) {
	
	int idcolindante = -1;
	for (auto& p : personajes)
	{
		if (p.GetVida() <= 0) continue; 
		p.SetAtacando(p.ScanIndividual(matrizDeIds, idcolindante));
		if (idcolindante != -1 && idcolindante != -2) {
			Personaje& enemigo = personajes[idcolindante - 1];
			int vidaAntes = enemigo.GetVida();
			p.Atacar(enemigo, matriz);
			if (vidaAntes > 0 && enemigo.GetVida() <= 0) {
				if (enemigo.GetAlias() == "G") cantidadGuerreros--;
				else if (enemigo.GetAlias() == "M") cantidadMagos--;
				else if (enemigo.GetAlias() == "O") cantidadOgros--;
				else if (enemigo.GetAlias() == "A") cantidadArqueras--;
				else if (enemigo.GetAlias() == "D") cantidadDragones--;
				else if (enemigo.GetAlias() == "V") cantidadVampiros--;

				enemigo.Destruir(matriz, matrizDeIds);
			}
		}
	}
}

/// @brief Reduce el área de juego y elimina los personajes que se hayan quedado fuera de los límites.
/// 
/// La función cambia la matriz general y la matriz de ids para reflejar el nuevo area de juego. 
/// También destruye los personajes que se hayan quedado fuera y actualiza los totales.
/// 
/// @param matriz - Matriz del juego.
/// @param personajes - Vector de personajes en el juego.
/// @param matrizDeIds - Matriz de IDs de personajes.
/// @param cantidadGuerreros - Cantidad de guerreros vivos.
/// @param cantidadMagos - Cantidad de magos vivos.
/// @param cantidadOgros - Cantidad de ogros vivos.
/// @param cantidadArqueras - Cantidad de arqueras vivas.
/// @param cantidadDragones - Cantidad de dragones vivos.
/// @param cantidadVampiros - Cantidad de vampiros vivos.
/// 
static void cerrarArea(string matriz[25][40], vector<Personaje>& personajes,
	int matrizDeIds[25][40], int& cantidadGuerreros, int& cantidadMagos, int& cantidadOgros,
	int& cantidadArqueras, int& cantidadDragones, int& cantidadVampiros) {

	for (int i = 1; i < 24; i++) {
		for (int j = 1; j < 39; j++) {
			if ((i < limSuperior || i > limInferior || j < limIzquierda || j > limDerecha)) {
				matriz[i][j] = "##";
				matrizDeIds[i][j] = -2;
			}
		}
	}

	for (auto& p : personajes) {
		if (p.GetVida() <= 0) continue;
		if (p.GetX() < limSuperior || p.GetX() > limInferior || p.GetY() < limIzquierda || p.GetY() > limDerecha) {
			p.Destruir(matriz, matrizDeIds);


			if (p.GetX() >= 1 && p.GetX() <= 23 && p.GetY() >= 1 && p.GetY() <= 38) {
				matriz[p.GetX()][p.GetY()] = "##";
				matrizDeIds[p.GetX()][p.GetY()] = -2;
			}

			string alias = p.GetAlias();
			if (alias == "G") cantidadGuerreros--;
			else if (alias == "M") cantidadMagos--;
			else if (alias == "O") cantidadOgros--;
			else if (alias == "A") cantidadArqueras--;
			else if (alias == "D") cantidadDragones--;
			else if (alias == "V") cantidadVampiros--;
		}
	}
}


int main()
{
	srand(time(NULL));
	string matriz[25][40];
	int matrizDeIds[25][40];


	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 40; j++) {
			matrizDeIds[i][j] = -1;
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

	int x;
	int max = 40;
	int cantidadGuerreros;
	int cantidadMagos;
	int cantidadOgros;
	int cantidadArqueras;
	int cantidadDragones;
	int cantidadVampiros;
	int equipamientoG;
	int equipamientoM;
	int equipamientoO;
	int equipamientoA;
	int equipamientoD;
	int equipamientoV;

	
	vector<int> usados = {}; 
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

	cantidadArqueras = imprimirRequestPersonaje("Arquera", 4, 11, 40);
	cantidadTotal += cantidadArqueras;
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

	Espada espada = Espada();
	Escudo escudo = Escudo();
	CapaIgnifuga capaIgnifuga = CapaIgnifuga();
	RedAntiflechas redAntiflechas = RedAntiflechas();
	ArcoEncantado arcoEncantado = ArcoEncantado();
	Mazo mazo = Mazo();
	Amuleto amuleto = Amuleto();
	PocionDeRabia pocionDeRabia = PocionDeRabia();

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


	Guerrero guerrero = Guerrero( 4 + equipGObj.GetAtaque(), 16 + equipGObj.GetVida());
	Mago mago = Mago( 5 + equipMObj.GetAtaque(), 10 + equipMObj.GetVida());
	Ogro ogro = Ogro( 4 + equipOObj.GetAtaque(), 20 + equipOObj.GetVida());
	Arquera arquera = Arquera(4 + equipAObj.GetAtaque(), 11 + equipAObj.GetVida());
	Dragon dragon = Dragon( 5 + equipDObj.GetAtaque(), 18 + equipDObj.GetVida());
	Vampiro vampiro = Vampiro( 4 + equipVObj.GetAtaque(), 13 + equipVObj.GetVida());

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
	for (int i = 0; i < cantidadArqueras; i++) {
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


	for (auto& p : personajes)
	{
		bool hayAlgo = true;

		while (hayAlgo)
		{
			p.SetX(rand() % 23 + 1);
			p.SetY(rand() % 38 + 1);

			hayAlgo = p.ScanIndividualInicial(matrizDeIds);
		}

		matrizDeIds[p.GetX()][p.GetY()] = p.GetId(); 
		
		matriz[p.GetX()][p.GetY()] = " " + p.GetAlias();
	}

	imprimirContadorRonda(ronda);

	imprimirMatriz(matriz);

	imprimirTotales(cantidadGuerreros, cantidadMagos, cantidadOgros, cantidadArqueras, cantidadDragones, cantidadVampiros);

	std::this_thread::sleep_for(std::chrono::seconds(3));
	

	while (true) {
		system("cls");

		ronda++;

		imprimirContadorRonda(ronda);


		int modulo = ronda % rondasParaCierre;

		if (modulo == (rondasParaCierre - rondasParaAviso)) { 
			int nuevoLimSuperior = limSuperior + 1;
			int nuevoLimIzquierda = limIzquierda + 1;
			int nuevoLimInferior = limInferior - 1;
			int nuevoLimDerecha = limDerecha - 1;

			for (auto& p : personajes) {
				if (p.GetVida() <= 0) continue;
				if (p.GetX() < nuevoLimSuperior || p.GetX() > nuevoLimInferior || p.GetY() < nuevoLimIzquierda || p.GetY() > nuevoLimDerecha) {
					p.SetIrAlCentro(true);
				}
			}
		}

		if (modulo == 0 && ronda != 0) {
			limSuperior += 1;
			limIzquierda += 1;
			limInferior -= 1;
			limDerecha -= 1;

			cerrarArea(matriz, personajes, matrizDeIds, cantidadGuerreros, cantidadMagos, cantidadOgros, cantidadArqueras, cantidadDragones, cantidadVampiros);

			for (auto& p : personajes) {
				p.SetIrAlCentro(false);
			}

		}

		for (auto& p : personajes) {
			if (p.GetVida() <= 0) continue;
			if (p.GetAtacando() == false) {
				if (p.GetIrAlCentro()) {
					int centroX = (limSuperior + limInferior) / 2;
					int centroY = (limIzquierda + limDerecha) / 2;
					p.MoverseHacia(centroX, centroY, matriz, matrizDeIds, p.GetId()); // ver implementación propuesta abajo
				}
				else {
					p.Moverse(matriz, matrizDeIds, p.GetId());
				}
			}
		}


		comprobarAtaque(matriz, personajes, matrizDeIds, cantidadGuerreros, cantidadMagos, cantidadOgros, cantidadArqueras, cantidadDragones, cantidadVampiros);

		imprimirMatriz(matriz);

		imprimirTotales(cantidadGuerreros, cantidadMagos, cantidadOgros, cantidadArqueras, cantidadDragones, cantidadVampiros);

		int totalVivos = cantidadGuerreros + cantidadMagos + cantidadOgros + cantidadArqueras + cantidadDragones + cantidadVampiros;

		if (totalVivos <= 1) {
			cout << "\nEl juego ha terminado!\n\n";

			if (cantidadGuerreros) cout << "Ganador: Guerrero\n\n\n";
			else if (cantidadMagos) cout << "Ganador: Mago\n\n\n";
			else if (cantidadOgros) cout << "Ganador: Ogro\n\n\n";
			else if (cantidadArqueras) cout << "Ganador: Arquera\n\n\n";
			else if (cantidadDragones) cout << "Ganador: Dragon\n\n\n";
			else if (cantidadVampiros) cout << "Ganador: Vampiro\n\n\n";
			else cout << "Todos han muerto!\n\n\n";
			
			break;  
		}
		else {
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
	}
	return 0;
}



