#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Personaje.h"
#include "TiposDePersonajes.h"
#include "Equipamiento.h"

class Partida {
private:
    int limSuperior = 1;
    int limInferior = 23;
    int limIzquierda = 1;
    int limDerecha = 38;

    int maxPersonajes = 40;

    int ronda = 1;
    const int rondasParaCierre = 8;
    const int rondasParaAviso = 3;

    std::string matriz[25][40];
    int matrizDeIds[25][40];

    std::vector<Personaje> personajes;

    int cantidadGuerreros = 0;
    int cantidadMagos = 0;
    int cantidadOgros = 0;
    int cantidadArqueras = 0;
    int cantidadDragones = 0;
    int cantidadVampiros = 0;


    /// @brief Lee, valida y devuelve el texto introducido por el usuario.
    /// 
    /// Esta función solicita al usuario un numero a través de la entrada estándar 
    /// y comprueba que sea un número entero.
    /// Si el usuario inserta un valor no válido, se le vuelve a solicitar hasta que lo haga correctamente.
    /// 
    /// @return El número entero introducido por el usuario.
    static int leetInputEntero();

    /// @brief Imprime el menú inicial del juego.
    void imprimirMenuInicial();

    /// @brief Imprime la información del personaje y solicita la cantidad deseada por cada uno.
    /// @param nombre - Nombre del personaje.
    /// @param ataque - Valor de ataque del personaje.
    /// @param vida - Cantidad de vidas que tiene el personaje
    /// @param max - Cantidad máxima permitida por cada tipo de personaje.
    /// @return Cantidad de personajes seleccionados.
    int imprimirRequestPersonaje(string nombre, int ataque, int vida, int max);

    /// @brief Imprime las opciones de equipamiento y solicita una opción para aplicar al personaje.
    /// @param listaUsados - Vector con los índices de los equipamientos ya utilizados.
    /// @return Índice del equipamiento seleccionado.
    int imprimirRequestEquipamiento(const vector<int>& listaUsados);

    /// @brief Imprime la matriz en la consola.
    /// @param matriz - Matriz a imprimir.
    void imprimirMatriz(std::string matriz[25][40]);

    /// @brief Imprime las cantidades totales de personajes vivos.
    /// @param cantidadGuerreros - Cantidad de guerreros vivos.
    /// @param cantidadMagos - Cantidad de magos vivos.
    /// @param cantidadOgros - Cantidad de ogros vivos.
    /// @param cantidadArqueras - Cantidad de arqueras vivas.
    /// @param cantidadDragones - Cantidad de dragones vivos.
    /// @param cantidadVampiros - Cantidad de vampiros vivos.
    void imprimirTotales(int& cantidadGuerreros, int& cantidadMagos, int& cantidadOgros, int& cantidadArqueras, int& cantidadDragones, int& cantidadVampiros);

    /// @brief Imprime el contador de ronda actual.
    /// @param ronda - La ronda actual.
    void imprimirContadorRonda(int& ronda);

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
    void comprobarAtaque(string matriz[25][40], vector<Personaje>& personajes, int matrizDeIds[25][40], int& cantidadGuerreros, int& cantidadMagos, int& cantidadOgros, int& cantidadArqueras, int& cantidadDragones, int& cantidadVampiros);

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
    void cerrarArea(string matriz[25][40], vector<Personaje>& personajes, int matrizDeIds[25][40], int& cantidadGuerreros, int& cantidadMagos, int& cantidadOgros, int& cantidadArqueras, int& cantidadDragones, int& cantidadVampiros);


public:
	/// @brief Configura la partida inicializando matrices, personajes y equipamientos.
	/// Esta función pedirá al usuario que eliga la cnatidad de personajes y sus equipamientos.
	/// La partida se iniciará con los valores seleccionados.
    void configurarPartida();

	/// @brief Inicia la partida y gestiona el desarrollo de las rondas hasta que haya un ganador o todos mueran.
    void iniciarPartida();

};