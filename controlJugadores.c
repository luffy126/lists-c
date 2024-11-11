/* Nombres: Simón Andrés Ledezma Sepúveda, 21.836.882-4 // Tomás Alonso Monge Dubreuil, 20.991.997-4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medalla{
    int id;
    char *nombre;
    char *categoria;
};

struct NodoMedalla{
    struct Medalla *detalle;
    struct NodoMedalla *sig;
};

////////////////////////////////////////

struct Jugador{
    int id;
    char *nombre;
    int edad;
    struct Medalla **medallas; //Arreglo no compacto
};

struct NodoJugador{
    struct Jugador *jugador;
    struct NodoJugador *enlace1, *enlace2; //En un árbol enlace1=izquierda, enlace2=derecha; en una lista doble enlace1=ante y enlace2=sig.
};

struct SistemaJuegos{
    struct NodoJugador *jugadores; //ABB
    struct NodoMedalla *medallas; //Lista simple circular con tail
};

////////////////////////////////////////

int recorrerJugadoresEnOrden(struct NodoJugador *nodo) {
    int contador = -1;
    int contadorMasMedallas = -1;
    int idJugador = -1;

    if (nodo == NULL) {
        return -1;
    }
    recorrerJugadoresEnOrden(nodo->enlace1); // Recorrer el subárbol izquierdo

    if (nodo->jugador->medallas != NULL) {
        contador = contarMedallasJugador(nodo->jugador->medallas);

        if (contador > contadorMasMedallas) {
            contadorMasMedallas = contador;
            if(nodo->jugador != NULL) {
                idJugador = nodo->jugador->id;
            }
        }
    }
    
    recorrerJugadoresEnOrden(nodo->enlace2); // Recorrer el subárbol derecho
    
    return idJugador;
}

struct Jugador *buscarJugador(struct NodoJugador *nodo, int idJugador) { // Buscar jugador por id
    struct Jugador *jugador = NULL;

    if (nodo == NULL) {
        return NULL;
    }

    if (nodo->jugador->id == idJugador) {
        return nodo->jugador;
    }

    jugador = buscarJugador(nodo->enlace1, idJugador);
    
    if (jugador != NULL && jugador->id == idJugador) {
        return jugador;
    }

    jugador = buscarJugador(nodo->enlace2, idJugador);
    return jugador;
}

struct Jugador *jugadorConMasMedallas(struct SistemaJuegos *ps5) { // Jugador con más medallas
    struct Jugador *jugadorMasMedallas = NULL;
    struct NodoJugador *nodo = ps5->jugadores;
    int idJugadorMasMedallas = 0;

    if (ps5 == NULL || ps5->jugadores == NULL || ps5->jugadores->jugador == NULL || ps5->jugadores->jugador->medallas == NULL) {
        return NULL;
    }

    idJugadorMasMedallas = recorrerJugadoresEnOrden(nodo);

    if(idJugadorMasMedallas == -1) {
        return NULL;
    }

    jugadorMasMedallas = buscarJugador(nodo, idJugadorMasMedallas);
    return jugadorMasMedallas;
}

int main() {
    struct SistemaJuegos *ps5 = NULL;
    printf("el pepe\n");
    return 0;
}
