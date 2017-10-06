#include <stdlib.h>
#include "lib/array.h"
#include "lib/variables.h"

void setFromTo(int x[], int s){
  x[0] = s;
  x[NODES - 1] = s;
}

void createSolution(int x[], int startNode){
  if(startNode == 0){
    startNode = 1;
  }

  setFromTo(x, startNode);

  for(int i = 1; i < NODES - 1; i++){
    int rnd = rand() % NODES;
    if(includes(x, rnd, NODES)){
      i = i - 1;
      continue;
    }else{
      x[i] = rnd;
    }
  }
}

void mergeNoPersisting(int a[], int y[], int persist){
  int j = persist + 1;
  for(int i = 1; i < NODES - 1; i++){
    if(includes(a, y[i], NODES)){
      continue;
    }else{
      a[j] = y[i];
      j = j + 1;
    }
  }
}

void merge(int x[], int y[], int persist, int a[], int b[]){
  setFromTo(a, x[0]);
  setFromTo(b, y[0]);

  for(int i = 0; i <= persist; i++){
    a[i] = x[i];
    b[i] = y[i];
  }

  mergeNoPersisting(a, y, persist);
  mergeNoPersisting(b, x, persist);
}

void mutate(int x[]){
  int aux = x[2];
  x[2] = x[3];
  x[3] = aux;
}

void copyArray(int x[], int y[], int arrSize){
  for(int i = 0; i < arrSize; i++){
    y[i] = x[i];
  }
}

void newPopulation(){
  for(int i = 0; i < PARENTS; i++){
    int m = rand() % 10;
    if(m <= 4){
      mutate(children[i]);
    }else{
      continue;
    }
  }
}

int distance(int x, int y){
  return matrix[x][y];
}

int fitness(int x[]){
  int total = 0;
  for(int i = 0; i < NODES; i++){
    total = total + distance(x[i], x[i + 1]);
  }
  return total;
};

int main(){
  //creating solution
  for(int i = 0; i < PARENTS; i++){
    createSolution(parents[i], 1);
  }

  //merging
  for(int i = 0; i < PARENTS; i = i + 2){
    merge(parents[i], parents[i + 1], 2, children[i], children[i + 1]);
  }

  //aplying mutation
  newPopulation();
  printArray(parents[0], NODES);
  printf("fitness of parent[0] is %d", fitness(parents[0]));
}
