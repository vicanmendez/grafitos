
#include <stdio.h>


#define N 5
//Definimos un una constante que simplemente sea la cantidad de vérices

typedef int grafo[N][N];

//Recibe un grafo POR REFERENCIA y lo inicializa con ceros
void inicializarGrafo(grafo &g) {
    for(int i=0; i<N; i++) {
        for(int k=0; k<N; k++) {
            g[i][k] = 0;
        }
    }
}


//Muestra todo el contenido de un grafo en pantalla
void cargarGrafo(grafo g) {
    for(int i=0; i<N; i++) {
        //Separamos una fila si estamos sobre el final de la matriz
        printf("\n");
        for(int k=0; k<N; k++) {
            printf("%d  -  ", g[i][k]);
        }
    }
}

void crearArista(grafo &g, int v1, int v2) {
    g[v1][v2] = 1;
}

void dfs(grafo g, bool visitados[N], int verticeactual) {
    //Marcamos el vértice actual como visitado
    visitados[verticeactual] = true;
    //Procesamiento antes de recorrer sus vecinos
    printf("DFS a la ida: %d \n", verticeactual);

    //Recorremos su listado de vecinos
    for(int i=0; i<N; i++) {
        //Si existe un adyacente al vértice actual
        if(g[verticeactual][i] == 1) {
            //Si el adyacente no ha sido visitado por el DFS, lo visitamos
            if(!visitados[i]) {
                dfs(g, visitados, i);
            }
        }
    }
    //Procedimiento al terminar de recorrer el grafo por DFS
    printf("A la vuelta: %d, \n", verticeactual);
}



int main(void) {
  grafo g;
  inicializarGrafo(g);
  int op, a, b;
  bool visitados[N];
  do {
      printf("\nGRAFITOS\n");
      printf("1-Ingresar una arista \n");
      printf("2- Mostrar toda la matriz del grafo \n");
      printf("3- Recorrer por DFS \n");
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

          case 3:
            dfs(g, visitados, 1);
          break;

          default:
            break;
      }
  } while(op != 0);

  return 0;
}
