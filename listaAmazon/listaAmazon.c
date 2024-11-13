#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBOLETAS 1000

struct Usuario {
    int id;
    char *nombre;
    struct NodoProducto *carrito;
    char **boletas;
};

struct NodoUsuarios {
    struct Usuario *usuario;
    struct NodoUsuarios *ant, *sig;
};

struct Producto {
    int id;
    char *nombre;
    float precio;
};

struct NodoProducto {
    struct Producto *producto;
    struct NodoProducto *ant, *sig;
};

struct Amazonas {
    struct NodoUsuarios *usuarios;
    struct NodoProducto *productos;
};

int contarProductosCarrito(struct NodoProducto *carrito) {
    int contador = 0;
    struct NodoProducto *rec = carrito;

    while (rec != NULL) {
        contador++;
        rec = rec->sig;
    } 

    return contador;
}

struct Usuario *usuarioCarritoMasGrande(struct Amazonas *amazonas) {
    int contadorCarritoMasGrande = -1;
    int contador;
    struct Usuario *usuarioCarritoMasGrande = NULL;
    struct NodoUsuarios *rec = amazonas->usuarios;

    if (amazonas == NULL || amazonas->usuarios == NULL) {
        return NULL;
    }

    do {
        if (rec->usuario->carrito != NULL) {
            contador = contarProductosCarrito(rec->usuario->carrito);
            if(contador > contadorCarritoMasGrande) {
                contadorCarritoMasGrande = contador;
                usuarioCarritoMasGrande = rec->usuario;
            }
        }
        rec = rec->sig;
    } while (rec != amazonas->usuarios);

    if (contadorCarritoMasGrande == -1) {
        return NULL;
    }

    return usuarioCarritoMasGrande;
}

float promedioPrecioProductos(struct Amazonas *amazonas) {
    float promedio = 0;
    int contador = 0;
    struct NodoProducto *rec;

    if (amazonas == NULL || amazonas->productos == NULL) {
        return -1;
    }

    rec = amazonas->productos;

    while (rec != NULL) {
        promedio += rec->producto->precio;
        contador++;
        rec = rec->sig;
    } 

    if (contador == 0) {
        return -1;
    }

    return promedio / contador;
}

void recorrerBoletas(struct Amazonas *amazonas) {
    struct NodoUsuarios *rec;
    int i;

    if (amazonas == NULL || amazonas->usuarios == NULL) {
        return;
    }

    rec = amazonas->usuarios;

    do {

        if(rec->usuario->nombre == NULL) {
            printf("Usuario sin nombre\n");
        }
        else {
            printf("Usuario: %s\n", rec->usuario->nombre);
        }

        if (rec->usuario->boletas != NULL) {
            for (i = 0; rec->usuario->boletas[i] != NULL || i < MAXBOLETAS; i++) {
                printf("Boleta: %s\n", rec->usuario->boletas[i]);
            }
        } else {
            printf("Usuario sin boletas\n");
        }

        rec = rec->sig;
    } while (rec != amazonas->usuarios);

}
int main() {
    struct Amazonas *amazonas = NULL;
    printf("ete sech");
    return 0;
}

