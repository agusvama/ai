#include <stdio.h>
#include "lib/array.h"
#include "lib/variables.h"
#include "lib/matrixFunctions.h"

int visited[12] = {};
int DEPTH = 11;

void recursive(int actual, int next, int depth){
  if(depth == DEPTH){
    if(canTravel(actual, 1)){ //magic number for end node, same as start node
      visited[depth] = 1;
      /* printf("final: -> "); */
      /* printArray(visited, NODES); */
      return;
    }  
  }
  if(canTravel(actual, next)){
    if(includes(visited, next, NODES)){ //next node visited already
      recursive(actual, next + 1, depth); 
      return;
    }else{ //next node not visited yet
      visited[depth] = actual;
      printArray(visited, NODES);
      recursive(next, 1, depth + 1); //magic number for start node
      return;
    }
  }else{ //can't travel
    recursive(actual, next + 1, depth);
    return;
  }
}

int main(){
  recursive(1, 1, 0);
  printArray(visited, NODES);
}
