#include <stdio.h>

typedef struct nodo{
    int base;
    nodo * izq;
    nodo * der;
}*ABB;

void crear(ABB &arbol) {
    arbol = NULL;
}

bool esVacio(ABB a) {

   return (a == NULL);
}

void insertarElemento(ABB &arbol, int e) {
    if(esVacio(arbol)) {
        arbol = new nodo;
        arbol->base = e;
        arbol->der = NULL;
        arbol->izq = NULL;

    } else {
        if(e > (arbol->base)) {
            insertarElemento(arbol->der, e);
        } else {
            insertarElemento(arbol->izq, e);
        }
    }
}


void preOrden(ABB a) {
    if(a != NULL) {
        printf("%d - ", a->base);
        preOrden(a->izq);
        preOrden(a->der);
    }
}

void inOrden(ABB a) {
    if(!esVacio(a)) {
        if(a->izq != NULL) {
            inOrden(a->izq);
            }
        printf("%d - ", a->base);
        if(a->der != NULL) {
            inOrden(a->der);
        }

    } //Si no es vacío

}


void postOrden(ABB a) {
    if(!esVacio(a)) {
        if(a->izq != NULL) {
            postOrden(a->izq);
            }
        if(a->der != NULL) {
            postOrden(a->der);
        }
        printf("%d - ", a->base);


    } //Si no es vacío

}

bool buscarElemento(ABB a, int elemento) {
    bool pertenece = false;
    if(!esVacio(a)) { //Si el arbol no es vacío
        if(a->base == elemento) {
            pertenece = true;
        } else if(a->base > elemento) { //Si la raíz es mayor que el elemento buscado, buscamos en la rama izquierda
            pertenece = buscarElemento(a->izq, elemento);
        } else { //Si no es igual ni la raíz es mayor, entonces la raíz es menor al elemento, y buscamos en la rama derecha
            pertenece = buscarElemento(a->der, elemento);
        }
    }
    return pertenece;
}



int main() {
    ABB arbol;
    crear(arbol);
    int opc, val = 0;
    do {
        printf("Ingrese la opcion deseada:. \n 1-Ingresar elemento \n 2-Buscar elemento \n 0-Salir \n");
        scanf("%d", &opc);
        if(opc == 1) {
            printf("Ingresar elemento al arbol \n");
            scanf("%d", &val);
            insertarElemento(arbol, val);
        } else if(opc == 2) {
            printf("ingrese el elemento a buscar \n");
            scanf("%d", &val);
            if(buscarElemento(arbol, val)) {
                printf("El elemento pertenece al ABB \n");
            } else {
                printf("El elemento NO pertenece al ABB \n");
            }
        }


    }while(opc != 0);
    printf("\n Mostrar el arbol en PREorden: \n");
    preOrden(arbol);
    printf("\n Mostrar el arbol en INorden: \n");
    inOrden(arbol);
    printf("\n Mostrar el arbol en POSTorden: \n");
    postOrden(arbol);
    getchar();

}
