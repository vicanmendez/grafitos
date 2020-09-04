#include <stdio.h>


#define N 5
//Definimos un una constante que simplemente sea la cantidad de vérices
#define TAM  N+1
//Definimos nuestro grafo como matriz de enteros
typedef int grafo[TAM][TAM];

//Recibe un grafo POR REFERENCIA y lo inicializa con ceros
void inicializarGrafo(grafo &g) {
    for(int i=1; i<=N; i++) {
        for(int k=1; k<=N; k++) {
            g[i][k] = 0;
        }
    }
}


//Muestra todo el contenido de un grafo en pantalla
void cargarGrafo(grafo g) {
    for(int i=1; i<=N; i++) {
        //Separamos una fila si estamos sobre el final de la matriz
        printf("\n");
        for(int k=1; k<=N; k++) {
            printf("%d  -  ", g[i][k]);
        }
    }
}

void crearArista(grafo &g, int v1, int v2) {
    g[v1][v2] = 1;
}



int main(void) {
  grafo g;
  inicializarGrafo(g);
  int op, a, b;
  do {
      printf("\nGRAFITOS\n");
      printf("1-Ingresar una arista \n");
      printf("2- Mostrar toda la matriz del grafo \n");
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
