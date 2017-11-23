#include <stdio.h>
#include <time.h>
#include "lib/array.h"
#include "lib/variables.h"

int route[12];
int visited[12];
int DEPTH = 11;

bool solution(int x[]){
  return countElement(x, 0, NODES) == 1;
  //if there's more than one zero, means nos every nodes have been visited yet
}

int dfs(int parent, int childNumber, int x[], int depth, int children[]){

  if(depth == DEPTH && !solution(x)){
    printf("no se ha encontrado solución\n");
    printf("no se han visitado todos los nodos en %d pasos\n", DEPTH);
    return 1;
  }
  if(solution(x)) {
    printf("se ha encontrado una solución\n");
    printf("se han visitado todos los nodos en %d pasos\n", DEPTH);
    return 1;
  }else{
    if(includes(x, graph[parent][childNumber], NODES)){
      return dfs(parent, childNumber + 1, x, depth, children);
    }else{
      x[depth] = children[childNumber];
      printArray(x, NODES);
      return dfs(children[childNumber], 0, x, depth + 1, graph[children[childNumber]]);
    }
  }
}

int main(){
  clock_t start, end;
  start = clock();

  //dfs(parent, childNumber, route[], depth, children of parent)
  route[0] = 1;
  dfs(1, 0, route, 1, graph[1]);
  printf("agregando el último nodo...\n");
  route[11] = 1; //magic number XD
  printArray(route, NODES);

  end = clock();
  printf("Elapsed time: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}
