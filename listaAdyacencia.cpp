#include <stdio.h>


//definimos un nodo
typedef struct nodo {
    int vert;
    nodo * sig;
}*ListaAdy;
//Definimos la lista de adyacencia

//definimos el tamaño del grafo
#define N 5

//Definimos el grafo
typedef ListaAdy grafo[N];



void inicializarGrafo (grafo &g){
    for(int i=0; i<N; i++) {
        g[i] = new nodo;
        g[i] = NULL;
    }
}

/*
void ingresarElemento(ListaAdy &L, int elemento) {
    if(L == NULL) {
        L->vert = elemento;
    } else {
        ingresarElemento(L->sig, elemento);
    }
}
*/
void ingresarElemento(ListaAdy &L, int elemento) {
    ListaAdy aux = new nodo;
    aux -> vert = elemento;
    aux -> sig = L;
    L = aux;
}

void crearArista(grafo &g, int v1, int v2) {
    ingresarElemento(g[v1], v2);
    ingresarElemento(g[v2], v1);
}

void mostrarLista(ListaAdy L) {
    if(L == NULL) {
        printf(" ");
    } else {
        printf("%d - ", L->vert);
        mostrarLista(L -> sig);
    }
}


void cargarGrafo(grafo g){
    for(int i=0; i<N; i++) {
        printf("Vecinos de %d : \n", i);
        mostrarLista(g[i]);
    }
}


int main(void) {
  grafo g;
  inicializarGrafo(g);
  int op, a, b;
  do {
      printf("\nGRAFITOS\n");
      printf("1-Ingresar una arista \n");
      printf("2- Mostrar todo el grafo \n");
      printf("0- Salir \n");
      scanf("%d", &op);
      switch(op) {
          case 1:
            printf("Ingrese un vértice adyacente  \n");
            scanf("%d", &a);
               printf("Ingrese otro vértice adyacente (si es un lazo, el mismo anterior) \n");
            scanf("%d", &b);
            crearArista(g, a, b);
          break;
          case 2:
            cargarGrafo(g);
          break;
          
          default:
            break;
      }
  } while(op != 0);
  
  return 0;
}
