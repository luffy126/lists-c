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

void recorrerJugadoresEnOrden(struct NodoJugador *nodo) {
    int contador = 0;
    if (nodo == NULL) {
        return;
    }
    recorrerJugadoresEnOrden(nodo->enlace1); // Recorrer el subárbol izquierdo
    contador += contarMedallasJugador(nodo->jugador->medallas); // Procesar el nodo actual
    recorrerJugadoresEnOrden(nodo->enlace2); // Recorrer el subárbol derecho
    
    return contador;
}

struct Jugador *jugadorConMasMedallas(struct SistemaJuegos *ps5) {
    struct Jugador *jugador = NULL;
    struct NodoJugador *nodo = ps5->jugadores;
    int medallas = 0;

    if (ps5 == NULL || ps5->jugadores == NULL || ps5->jugadores->jugador == NULL || ps5->jugadores->jugador->medallas == NULL) {
        return NULL;
    }

}

int main() {
    struct SistemaJuegos *ps5 = NULL;
    printf("el pepe\n");
    return 0;
}
