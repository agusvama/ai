#include <stdlib.h>
#include "lib/array.h"

//do it with N nodes
//parents
int solution1[7] = {};
int solution2[7] = {};
int solution3[7] = {};
int solution4[7] = {};
int NODES = 7;

//children
int c1[7] = {};
int c2[7] = {};
int c3[7] = {};
int c4[7] = {};

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

void merge(int x[], int y[], int persist, int a[], int b[]){
  setFromTo(a, x[0]);
  setFromTo(b, y[0]);
  int ja = persist + 1;
  int jb = persist + 1;

  for(int i = 0; i <= persist; i++){
    a[i] = x[i];
    b[i] = y[i];
  }
  for(int i = 1; i < NODES - 1; i++){
    if(includes(a, y[i], NODES)){
      continue;
    }else{
      a[ja] = y[i];
      ja = ja + 1;
    }
  }
  for(int i = 1; i < NODES - 1; i++){
    if(includes(b, x[i], NODES)){
      continue;
    }else{
      b[jb] = x[i];
      jb = jb + 1;
    }
  }
}

int main(){
  clearArrayWith(solution1, 0, NODES);
  clearArrayWith(solution2, 0, NODES);
  clearArrayWith(solution3, 0, NODES);
  clearArrayWith(solution4, 0, NODES);

  createSolution(solution1, 1);
  createSolution(solution2, 1);
  createSolution(solution3, 1);
  createSolution(solution4, 1);

  puts("parents");
  printArray(solution1, NODES);
  printArray(solution2, NODES);
  puts("\nhijos");
  merge(solution1, solution2, 2, c1, c2);
  printArray(c1, NODES);
  printArray(c2, NODES);

  puts("parents");
  printArray(solution3, NODES);
  printArray(solution4, NODES);
  puts("\nhijos");
  merge(solution3, solution4, 2, c3, c4);
  printArray(c3, NODES);
  printArray(c4, NODES);
}
