#include <stdlib.h>
#include <time.h>
#include "lib/array.h"
#include "lib/variables.h"
#include "lib/number.h"

void setFromTo(int x[], int s){
  x[0] = s;
  x[NODES - 1] = s;
}

void createParents(int x[], int startNode){
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

void mergeNoPersisting(int parent[], int child[], int persist){
  int j = persist + 1;
  for(int i = 1; i < NODES - 1; i++){
    if(includes(child, parent[i], NODES)){
      continue;
    }else{
      child[j] = parent[i];
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

  mergeNoPersisting(y, a, persist);
  mergeNoPersisting(x, b, persist);
}

void mutate(int x[]){
  //sorry for this :/
  int aux = x[1];
  int aux2 = x[3];
  x[3] = aux;
  x[1] = aux2;
}

void mutateChildren(){
  for(int i = 0; i < PARENTS; i++){
    int m = rand() % 10;
    if(m <= 8){
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

void printGeneration(int generation, int index){
  printf("result: %d fitness: %d\n", index, fitness(results[index]));
  printArray(results[index], NODES);
 }

int main(){
  //creating parents
  for(int i = 0; i < PARENTS; i++){
    createParents(parents[i], 1);
  }

  clock_t start, end;
  start = clock();
  for(int i = 0; i < GENERATIONS; i++){

    //merging
    for(int i = 0; i < PARENTS; i = i + 2){
      merge(parents[i], parents[i + 1], 2, children[i], children[i + 1]);
    }

    //applying mutation
    mutateChildren();

    //comparing and creating a new population
    for(int i = 0; i < PARENTS; i++){
      //take the minor fitness and keep it in the new population 
      if(fitness(parents[i]) < fitness(children[i]) ){
        copyArray(parents[i], results[i], NODES);
      }else{
        copyArray(children[i], results[i], NODES);
      }
    }

    //now the results become the new parents
    for(int i = 0; i < PARENTS; i++){
      copyArray(results[i], parents[i], NODES);
    }

  }//GENERATIONS

  //print last results...
  puts("--------------------------HERE----------------------------------------------------");
  for(int i = 0; i < PARENTS; i++){
    printf("result[%d] fitness: %d\n", i, fitness(results[i]));
    printArray(results[i], NODES);
  }

  end = clock();
  printf("Elapsed time: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}
