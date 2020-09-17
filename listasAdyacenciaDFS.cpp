#include <stdio.h>


//definimos un nodo
typedef struct nodo {
    int vert;
    nodo * sig;
}*ListaAdy;
//Definimos la lista de adyacencia

//definimos el tamaño del grafo
#define N 6

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

//Determina si un elemento pertenece a una Lista
bool pertenece(ListaAdy l, int elemento) {
    bool existe = false;
    //Si la lista no es nula, pasamos a ver si contiene al elemento
    if(l != NULL) {
        //Si el vértice del nodo es el que buscamos, entonces pertenece a la lista, si no, buscamos en los elementos siguientes
        if(l->vert == elemento) {
            existe = true;
        } else {
            existe = pertenece(l->sig, elemento);
        }
    }
    return existe;
}


//Determina si un vértice v1 y un v2 inciden en una misma arista de un grafo g
bool esAdyacente(grafo g, int v1, int v2) {
    bool esAdy = false;
    //Si el elemento v2 pertenece a la lista g[v1] entonces es porque el vértice v2 es adyacente a v1
    if(pertenece(g[v1], v2)) {
        esAdy = true;
    }
    return esAdy;
}

void inicializarArray(bool arreglo[N]) {
    for(int i=0; i<N; i++) {
        arreglo[i] = false;
    }
}

//ALGORITMO DFS IMPLEMENTADO EN EL MATERIAL ORIGINAL
void DFS (grafo G, int verticeActual, bool visitado[N]){
    /* marco el vértice actual como visitado */
    visitado[verticeActual] = true;
    /* aquí va el procesamiento ANTES de recorrer la lista de vecinos */
    printf("A la ida: %d \n", verticeActual);
    /* recorremos los vecinos del vértice actual */
    ListaAdy aux = G[verticeActual];
    while (aux != NULL) {
        /* si aux->vert no fue visitado, sigo por la
        subrama que parte desde él */
        if (!visitado[aux->vert]) {
        	printf("El vértice actual es: %d \n", verticeActual);
        	printf("El valor del array de visitados sobre el siguiente vértice: %b \n", visitado[aux->vert]);
        	printf("Ahora recorreremos sobre el vértice %d \n", aux->vert);
            DFS(G, aux->vert, visitado);
   		 }
        aux = aux->sig;
    }
    /* aquí va el procesamiento DESPUÉS de visitar las subramas del vértice */
    printf("A la vuelta: %d \n", verticeActual);

}

void dfs(grafo g, int verticeactual, bool visitados[N]) {
    //Marcamos el vértice actual como visitado
    visitados[verticeactual] = true;

    //Procesamiento ANTES de lanzar el DFS sobre sus subramas de vecinos
    printf("DFS a la ida: %d   \n", verticeactual);

    //Recorremos con dfs los vecinos del vertice actual
    for(int i=0; i<N; i++) {
        //Si el vértice i es adyacente al vértice actual, entonces el dfs puede tomar un camino ahí
        if(esAdyacente(g, i, verticeactual)) {
            //Si el vértice i no ha sido visitado, lanzamos el DFS sobre él
            if(!visitados[i]) {
                dfs(g, i, visitados);
            }
        }
    }

    //Procesamiento DESPUÉS de lanzar el DFS sobre sus subramas de vecinos
    printf("DFS a la vuelta: %d   \n", verticeactual);

}


int main(void) {
  grafo g;
  inicializarGrafo(g);
  int op, a, b;
  //Array de booleanos que servirán para identificar los visitados por DFS
  bool visitados[N];
  do {
      inicializarArray(visitados);
      printf("\nGRAFITOS\n");
      printf("1-Ingresar una arista \n");
      printf("2- Mostrar todo el grafo \n");
      printf("3- Recorrer con DFS \n");
      printf("4- Recorrer con DFS (predefinido)");
      printf("0-Salir \n");
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
          case 3:
            dfs(g, 0, visitados);
            break;
         case 4:
            DFS(g, 0, visitados);
            break;
          default:
            break;
    	}
	}while(op != 0);
	
	return 0;
}
