#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pelicula {
    char *titulo;
    int duracion; // en minutos
    char *genero;
    int clasificacion; // edad mínima recomendada
};

struct NodoPelicula { /* Lista Simple */
    struct Pelicula *pelicula;
    struct NodoPelicula *sig;
};

struct Sala { 
    int numero;
    struct NodoPelicula *peliculas;
};

struct NodoSala { /* Lista Circular */
    struct Sala *sala;
    struct NodoSala *sig;
    struct NodoSala *ant;
};

struct Cine {
    char *nombre;
    struct NodoSala *salas;
};

struct NodoCine { /* Lista Simple */
    struct Cine *cine;
    struct NodoCine *sig;
};

struct CadenaCines {
    struct NodoCine *cines;
};

double getPromedio(struct NodoPelicula *head) {

    if(head == NULL) {
        return 0;
    }

    double promedio = 0;
    int contador = 0;
    struct NodoPelicula *rec = head;

    while (rec != NULL) {
        promedio += rec->pelicula->duracion;
        contador++;
        rec = rec->sig;
    }

    return promedio / contador;
}

double recorrerSalas(struct NodoSala *head) {

    if (head == NULL) {
        return 0;
    }

    double promedioSalas = 0;
    int contador = 0;
    struct NodoSala *rec = head;
    
    do {
        promedioSalas += getPromedio(rec->sala->peliculas);
        contador++;
        rec = rec->sig;
    } while (rec != head);
    
    return promedioSalas / contador;
}

double recorrerCines (struct NodoCine *head) {

    if (head == NULL) {
        return 0;
    }

    double promedioCine = 0;
    int contador = 0;
    struct NodoCine *rec = head;

    while (rec != NULL) {
        promedioCine += recorrerSalas(rec->cine->salas);
        contador++;
        rec = rec->sig;
    }

    return promedioCine / contador;
}

double promedioDuracionPeliculas(struct CadenaCines *cadena) {

    if (cadena == NULL) {
        return 0;
    }

    double promedioDuracionPeliculas = 0;
    int contador = 0;
    struct NodoCine *rec = cadena->cines;

    while (rec != NULL) {
        promedioDuracionPeliculas += recorrerCines(rec);
        contador++;
        rec = rec->sig;
    }

    return promedioDuracionPeliculas / contador;
}

// recorrer los cines dentro de la cadena //
// en ese cine recorrer las salas //
// recorrer cada pelicula sumando los minutos //
// sacar promedio con los minutos //

int main() {
    struct CadenaCines *cadena;
    printf("el pepe");
    return 0;
}
