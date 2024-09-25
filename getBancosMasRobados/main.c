#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BandaCriminal {
    char *nombre;
    struct NodoLadron *headLadrones;
    struct NodoBanco *headBancos;
};

struct NodoLadron { /* lista simplemente enlazada circular */
    struct Ladron *datosLadron;
    struct NodoLadron *sig;
};

struct Ladron {
    char *apodo;
    char *rut;
    int maxRobos;
    struct Robo **robos;
    int pLibreRobos;
};

struct Robo {
    char *fecha;
    int monto;
    struct Banco *bancoRobado;
};

struct NodoBanco { /* lista doblemente enlazada */
    struct Banco *datosBanco;
    struct NodoBanco *ant, *sig;
};

struct Banco {
    char *nombre;
    char *direccion;
    int saldo;
};

int contarRobosBanco(char *direccion, char *nombre, struct Robo **robosLadron, int pLibreRobos) { // cuenta la cantidad de robos a un banco especifico en el arreglo de robos de un ladron
    int contadorRobos = 0;
    int i;

    for (i = 0; i < pLibreRobos; i++) {
        if (strcmp(nombre, robosLadron[i]->bancoRobado->nombre) == 0 && strcmp(direccion, robosLadron[i]->bancoRobado->direccion)== 0) {
            contadorRobos += 1;
        }
    }
    return contadorRobos;
}

int contarRobosPorLadron (struct Banco *datosBanco, struct NodoLadron *headLadrones) { // cuenta los robos de cada ladron del sistema al banco especificado
    int contadorRobos = 0;
    struct NodoLadron *recLadrones;

    if (headLadrones != NULL) {
        recLadrones = headLadrones;

        do {
            contadorRobos += contarRobosBanco(datosBanco->direccion, datosBanco->nombre, recLadrones->datosLadron->robos, recLadrones->datosLadron->pLibreRobos);
            recLadrones = recLadrones->sig;

        } while (recLadrones != headLadrones);
    }
    return contadorRobos;
}

int getMaxRobos(struct NodoLadron *headLadrones, struct NodoBanco *headBancos) { // consigue la mayor cantidad de robos de todos los bancos del sistema
    int maxRobos = 0;
    int robosBanco = 0;
    struct NodoBanco *recBancos;

    if (headBancos != NULL) {
        recBancos = headBancos;

        while (recBancos != NULL) {
            robosBanco = contarRobosPorLadron(recBancos->datosBanco, headLadrones);

            if (robosBanco > maxRobos) {
                maxRobos = robosBanco;
            }
            recBancos = recBancos->sig;
        }
    }
    return maxRobos;
}

struct NodoBanco *agregarNodoBanco(struct NodoBanco *headBancos, struct NodoBanco *nodoNuevo) { // agrega un nodo nuevo a la lista de bancos mas robados

    if (headBancos == NULL) { // caso lista vacia 

        nodoNuevo->sig = NULL;
        nodoNuevo->ant = NULL;
        headBancos = nodoNuevo;
        return headBancos;
    }

    else { // caso lista con elementos
        struct NodoBanco *rec = headBancos;
        while (rec->sig != NULL) { 
            rec = rec->sig;
        }
        rec->sig = nodoNuevo;
        nodoNuevo->ant = rec;
        nodoNuevo->sig = NULL;

        return headBancos;
    }
}

struct NodoBanco *getBancosMasRobados(struct BandaCriminal *LCN) { // crea la lista de los bancos mas robados
    int maxRobos = 0;
    int cantRobos;
    struct NodoBanco *bancosMasRobados = NULL;
    struct NodoBanco *rec;

    if (LCN != NULL) {

        maxRobos = getMaxRobos(LCN->headLadrones, LCN->headBancos); // consigue el mayor numero de robos a un banco

        rec = LCN->headBancos;
        while (rec != NULL) {
            cantRobos = contarRobosPorLadron(rec->datosBanco, LCN->headLadrones);

            if(cantRobos == maxRobos) {
                bancosMasRobados = agregarNodoBanco(bancosMasRobados, rec);
            }
            rec = rec->sig;
        }
    }
    return bancosMasRobados;
}

int main () {
    struct BandaCriminal *LCN;
    printf("el pepe");
    return 0;
}
