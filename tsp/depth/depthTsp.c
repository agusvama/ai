#include <stdio.h>
#include "lib/array.h"
#include "lib/variables.h"

int route[12] = {};
int DEPTH = 11;

int fillingIt(int actual, int depth, int x[]){
  if(depth == DEPTH){
    x[depth] = 1; //magic number for the end node
    return 1;
  }else{
    x[depth] = actual;
    return fillingIt(actual, depth + 1, x);
  }
}

int recursive(int actual, int depth, int x[]){
  printArray(route, NODES);
  if(depth == DEPTH){
    return 1;
  }
  if(countElement(x, actual, NODES) > 1){
    fillingIt(actual + 1, depth, x);
    return recursive(actual + 1, depth + 1, x);
  }
}

int main(){
  recursive(0, 0, route);
  printArray(route, NODES);
}
