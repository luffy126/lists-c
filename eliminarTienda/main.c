#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    char *nombre;
    float precio;
    int cantidad;
};

struct NodoProducto {
    struct Producto *producto;
    struct NodoProducto *sig;
};

struct Tienda {
    char *nombre;
    char *direccion;
    struct NodoProducto *productos;
};

struct NodoTiendas {
    struct Tienda *tiendas;
    struct NodoTiendas *sig;
};

struct ToysNUs {
    struct NodoTiendas *tiendas;
};

int verificarTienda(struct NodoTiendas *rec, char *productoPeligroso) {
    struct NodoProducto *rec2 = rec->tiendas->productos;
    while (rec2 != NULL) {
        if (strcmp(rec2->producto->nombre, productoPeligroso) == 0) {
            return 1;
        }
        rec2 = rec2->sig;
    }
    return 0;
}

int eliminarTiendaProductoPeligroso(struct ToysNUs *tnu, char *productoPeligroso) {
    struct NodoTiendas *rec, *ant;
    rec = tnu->tiendas;
    ant = NULL;
    int esPeligrosa = 0, contador = 0;

    if(tnu == NULL || tnu->tiendas == NULL || tnu->tiendas->tiendas == NULL || tnu->tiendas->tiendas->productos == NULL) {
        return 0;
    }

    while (rec != NULL) {
        esPeligrosa = verificarTienda(rec, productoPeligroso);
        if(esPeligrosa == 1) {
            if(ant == NULL) {
                tnu->tiendas = rec->sig;
            } else {
                ant->sig = rec->sig;
            }
            contador += 1;
            rec = rec->sig;
        } else {
            ant = rec;
            rec = rec->sig;
        }
    }

    if (contador > 0) {
        return 1;
    }
    return 0;
}

int main() {
    struct ToysNUs *tnu;
    printf("Hello, World!\n");
    return 0;
}
