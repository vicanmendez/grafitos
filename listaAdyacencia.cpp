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


//Este método debe invocarse antes de hacer cualquier operación con el grafo
void inicializarGrafo (grafo &g){
    for(int i=0; i<N; i++) {
        g[i] = new nodo;
        g[i] = NULL;
    }
}


//Método que ingresa un nuevo elemento en una lista de adyacencia, necesitamos hacer uso de una Lista auxiliar para almacenar nuestro elemento.
void ingresarElemento(ListaAdy &L, int elemento) {
    ListaAdy aux = new nodo;
    aux -> vert = elemento;
    aux -> sig = L;
    L = aux;
}

//En el vector de listas que representa nuestro grafo, debemos guardar el elemento en 2 listas, ya que cada una representa los "vecinos" de un vértice diferente
//EJEMPLO: Si existe una arista entre los vértices 2 y 3, entonces agregamos a 3 como adyacente de 2, y a su vez a 2 como adyacente de 3.
void crearArista(grafo &g, int v1, int v2) {
    ingresarElemento(g[v1], v2);
    ingresarElemento(g[v2], v1);
}

//Recorrer y mostrar una lista de adyacencia (recursivo)
void mostrarLista(ListaAdy L) {
    if(L == NULL) {
        printf(" ");
    } else {
        printf("%d - ", L->vert);
        mostrarLista(L -> sig);
    }
}


//Para mostrar el grafo, vamos mostrando cada una de las listas del vector correspondiente
void cargarGrafo(grafo g){
    for(int i=0; i<N; i++) {
        printf("Adyacentes en %d :", i);
        mostrarLista(g[i]);
        printf("\n");
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
