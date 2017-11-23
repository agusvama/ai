#include <stdio.h>
#include "lib/array.h"
#include "lib/variables.h"

int route[12];
int visited[12];
int DEPTH = 11;

bool solution(int x[]){
  if(x[0] == 1 && x[11] == 1){
    return true;
  }
  return false;
}

int dfs(int start, int next, int x[], int depth){
  if(depth == 11){ //sorry for this, ftw!
    x[11] = 1;
  }

  if(depth == DEPTH && !solution(x)){
    printf("no se ha encontrado solución\n");
    return 1;
  }
  if(solution(x)) {
    printf("se ha encontrado una solución\n");
    return 1;
  }else{
    if(includes(x, next, NODES)){
      return dfs(start, next + 1, x, depth);
    }else{
      x[depth] = next;
      printArray(x, NODES);
      return dfs(start, 1, x, depth + 1);
    }
  }
}

int main(){
  dfs(1, 1, route, 0);
  printArray(route, NODES);
}
