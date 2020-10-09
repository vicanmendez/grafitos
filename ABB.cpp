#include <stdio.h>


//Definimos un tipo de datos NODO que contendrá la base de un ABB, un puntero a nodo para su sub árbol IZQUIERDO y otro puntero a nodo para su sub árbol DERECHO
typedef struct nodo{
    int base;
    nodo * izq;
    nodo * der;
}*ABB;


void crear(ABB &arbol) {
    arbol = NULL;
}

//Determina si un árbol es vacío
bool esVacio(ABB a) {

   return (a == NULL);
}

//Recibe un ABB por referencia y un elemento, e inserta ese elemento en el ABB
void insertarElemento(ABB &arbol, int e) {
    if(esVacio(arbol)) { //Si el árbol es vacío, añadimos la base y definimos nulos los sub árboles izquierdo y derecho
        arbol = new nodo;
        arbol->base = e;
        arbol->der = NULL;
        arbol->izq = NULL;

    } else { //Si no es vacío, realizamos el mismo procedimiento sobre el sub árbol correspondiente
        if(e > (arbol->base)) { //Si el elemento es mayor a la base, va para el lado derecho
            insertarElemento(arbol->der, e);
        } else {
            insertarElemento(arbol->izq, e); //Si es menor a la base, va, para el lado izquierdo
        }
    }
}

/*
La recorrida en preOrden visita la base, luego el sub árbol izquierdo y luego el derecho
*/
void preOrden(ABB a) {
    if(a != NULL) {
        printf("%d - ", a->base);
        preOrden(a->izq);
        preOrden(a->der);
    }
}

/*
En inOrden, visitamos primero el subárbol izquierdo, luego la base y luego el derecho
*/
void inOrden(ABB a) {
    if(!esVacio(a)) {
        if(a->izq != NULL) {
            inOrden(a->izq);
            }
        printf("%d - ", a->base);
        if(a->der != NULL) {
            inOrden(a->der);
        }

    } 
}


/*
En postOrden, visitamos primero el subárbol izquierdo, luego el derecho y por último la base
*/
void postOrden(ABB a) {
    if(!esVacio(a)) {
        if(a->izq != NULL) {
            postOrden(a->izq);
            }
        if(a->der != NULL) {
            postOrden(a->der);
        }
        printf("%d - ", a->base);


    } 

}

/* 
Recibe un ABB y un elemento, y retorna TRUE si el elemento pertenece al ABB, FALSE en caso contrario
*/
bool buscarElemento(ABB a, int elemento) {
    bool pertenece = false;
    if(!esVacio(a)) { //Si el árbol no es vacío
        if(a->base == elemento) { //Si el elemento es la raíz, ya lo encontramos
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
