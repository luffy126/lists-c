#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jugador {
    char *nombre;
    int edad;
    char *pais;
    char *posicion;
    int numero;
    int cantGoles;
};

struct NodoJugador { /* Lista Simple */
    struct Jugador *jugador;
    struct NodoJugador *sig;
};

struct Equipo { 
    char *nombre;
    char *pais;
    struct NodoJugador *jugadores;
};

struct NodoEquipo { /* Lista Circular */
    struct Equipo *equipo;
    struct NodoEquipo *sig;
    struct NodoEquipo *ant;
};

struct Competicion {
    char *nombre;
    struct NodoEquipo *equipos;
};

struct NodoCompeticion { /* Lista Simple */
    struct Competicion *competicion;
    struct NodoCompeticion *sig;
};

struct Fifa {
    struct NodoCompeticion *competiciones;
};

int recorrerJugadores(struct NodoJugador *head) {
    int contadorJugadores = 0;
    struct NodoJugador *rec = head;

    while (rec != NULL) {
        contadorJugadores += rec->jugador->cantGoles;
        rec = rec->sig;
    }

    return contadorJugadores;
}

int recorrerEquipos(struct NodoEquipo *head) {
    int contadorEquipos = 0;
    struct NodoEquipo *rec = head;

    do {
        contadorEquipos += recorrerJugadores(rec->equipo->jugadores);
        rec = rec->sig;
    } while (rec != head);
    
    return contadorEquipos;
}

int recorrerCompeticiones(struct NodoCompeticion *head) {
    int contadorCompeticiones = 0;
    struct NodoCompeticion *rec = head;

    while (rec != NULL) {
        contadorCompeticiones += recorrerEquipos(rec->competicion->equipos);
        rec = rec->sig;
    }

    return contadorCompeticiones;
}

int cantGolesMundiales(struct Fifa *fifa) {
    int contadorGoles = recorrerCompeticiones(fifa->competiciones);
    return contadorGoles;
}

///////////////////////////////////////////////////////////////////////

struct Equipo *equipoMasGoles(struct Competicion *competicion) {
    int contador = 0;
    int contadorGanador = 0;
    struct Equipo *equipoGoleador = NULL;
    struct NodoEquipo *rec = competicion->equipos;
    struct NodoEquipo *inicio = rec;

    do {
        contador = recorrerJugadores(rec->equipo->jugadores);
        if(equipoGoleador == NULL || contador > contadorGanador) {
            equipoGoleador = rec->equipo;
            contadorGanador = contador;
        }
        rec = rec->sig;
    } while (rec != inicio);

    return equipoGoleador;
}

int main() {
    struct Fifa *fifa;
    printf("el pepe");
    return 0;
}
