#include <stdlib.h>
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

void mutateChildren(){
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
  //creating parents
  for(int i = 0; i < PARENTS; i++){
    createParents(parents[i], 1);
  }

  //merging
  for(int i = 0; i < PARENTS; i = i + 2){
    merge(parents[i], parents[i + 1], 2, children[i], children[i + 1]);
  }

  //aplying mutation
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
  
  //testing, attention please, feel the tension...
  for(int i = 0; i < PARENTS; i++){
    printf("parent [%d] fitness: %d\n", i, fitness(parents[i]));
    printArray(parents[i], NODES);

    printf("child [%d] fitness: %d\n", i, fitness(children[i]));
    printArray(children[i], NODES);

    printf("result [%d]\n", i);
    printArray(results[i], NODES);

    puts("");
  }
}
