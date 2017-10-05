#include <stdlib.h>
#include "lib/array.h"

//do it with N nodes
int solution[7] = {};
int NODES = 7;

void setFromTo(int s){
  solution[0] = s;
  solution[NODES - 1] = s;
}

void createSolution(int startNode){
  if(startNode == 0){
    startNode = 1;
  }

  setFromTo(startNode);

  for(int i = 1; i < NODES - 1; i++){
    int rnd = rand() % NODES;
    if(includes(solution, rnd, NODES)){
      i = i - 1;
      continue;
    }else{
      solution[i] = rnd;
    }
  }
}

int main(){
  clearArrayWith(solution, 0, NODES);
  for(int i = 0; i < 10; i++){
    int startNode = rand() % 5;
    createSolution(startNode);
    printArray(solution, NODES);
    clearArrayWith(solution, 0, NODES);
  }
}
