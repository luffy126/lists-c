/* Nombres: Simón Andrés Ledezma Sepúveda, 21.836.882-4 // Tomás Alonso Monge Dubreuil, 20.991.997-4 */

// Enunciado: Implemente struct Jugador *jugadorConMasMedallas(struct SistemaJuegos *ps5);

/*  Recibe por parámetro un puntero al sistema de juegos y deberá retornar el jugador que tiene la mayor cantidad de medallas. 
    Asuma que sólo existe un mayor. En caso de fracaso retorna NULL. 
    No puede asumir una variable "mayor = 0". 
    No puede hacer cambios en la definición de los structs. 
*/

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

int contarMedallasSistema(struct SistemaJuegos *ps5) { // cuenta todas las medallas del sistema
    int contador = 0;
    struct NodoMedalla *nodo = NULL;

    if (ps5 == NULL || ps5->medallas == NULL) {
        return -1;  // en caso de error retorna -1
    }

    nodo = ps5->medallas;

    do {
        contador++;
        nodo = nodo->sig;
    } while (nodo != ps5->medallas || nodo != NULL);
    
    return contador;
}

int contarMedallasJugador(struct Jugador *jugador, int totalMedallas) { // cuenta medallas de un jugador
    int contador = 0;
    int i;
    
    if (jugador == NULL || jugador->medallas == NULL) {
        return 0;  // retorna 0 en caso de error
    }

    for (i = 0; contador < totalMedallas; i++) {
        if (jugador->medallas[i] != NULL) {
            contador++;
        }
    }
    
    return contador;
}

void recorrerJugadoresEnOrden(struct NodoJugador *nodo, struct Jugador **jugadorMasMedallas, int totalMedallas, int *contadorMasMedallas) { // void pero modifica el puntero original
    if (nodo == NULL) {
        return;
    }
    
    // recorrer izq
    recorrerJugadoresEnOrden(nodo->enlace1, jugadorMasMedallas, totalMedallas, contadorMasMedallas);

    // procesar jugador actual
    int contador = contarMedallasJugador(nodo->jugador, totalMedallas);
    
    if (contador > *contadorMasMedallas) {
        *contadorMasMedallas = contador;
        *jugadorMasMedallas = nodo->jugador;
    }

    // recorrer der
    recorrerJugadoresEnOrden(nodo->enlace2, jugadorMasMedallas, totalMedallas, contadorMasMedallas);
}

struct Jugador *jugadorConMasMedallas(struct SistemaJuegos *ps5) { // encuentra el jugador con más medallas
    int totalMedallas = -1;
    int contadorMasMedallas = -1;
    struct Jugador *jugadorMasMedallas = NULL;

    if (ps5 == NULL || ps5->jugadores == NULL) {
        return NULL;
    }

    totalMedallas = contarMedallasSistema(ps5); // contador total de medallas
    
    if (totalMedallas < 0) {
        return NULL;
    }  

    recorrerJugadoresEnOrden(ps5->jugadores, &jugadorMasMedallas, totalMedallas, &contadorMasMedallas); // recorrer jugadores y modificar el puntero al que tenga mas medallas
    
    return jugadorMasMedallas;
}

int main() {
    struct SistemaJuegos *ps5 = NULL;
    printf("el pepe\n");
    return 0;
}
