#include <stdio.h>
#include <stdbool.h>
#include "lib/array.h"

int matrix[12][12] = {
      /*----------------------TO---------------------*/
      /* 0  , 1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 10  , 11*/

  /*SINCE*/
  /*0*/  {0  , 0   , 0   , 0   , 0   , 0   , 0   , 0   , 0   , 0   , 0   , 0}   ,
  /*1*/  {0  , 0   , 190 , 180 , 0   , 330 , 0   , 0   , 180 , 345 , 0   , 0}   ,
  /*2*/  {0  , 190 , 0   , 0   , 170 , 317 , 0   , 0   , 0   , 299 , 0   , 0}   ,
  /*3*/  {0  , 180 , 0   , 0   , 0   , 230 , 275 , 198 , 314 , 0   , 0   , 0}   ,
  /*4*/  {0  , 0   , 170 , 0   , 0   , 415 , 0   , 0   , 0   , 310 , 0   , 0}   ,
  /*5*/  {0  , 330 , 317 , 230 , 415 , 0   , 300 , 0   , 0   , 0   , 0   , 0}   ,
  /*6*/  {0  , 0   , 0   , 275 , 0   , 300 , 0   , 225 , 0   , 0   , 0   , 450} ,
  /*7*/  {0  , 0   , 0   , 198 , 0   , 0   , 225 , 0   , 267 , 0   , 0   , 280} ,
  /*8*/  {0  , 180 , 0   , 314 , 0   , 0   , 0   , 0   , 0   , 450 , 230 , 255} ,
  /*9*/  {0  , 345 , 299 , 0   , 310 , 0   , 0   , 0   , 450 , 0   , 250 , 0}   ,
  /*10*/ {0 , 0   , 0   , 0   , 0   , 0   , 0   , 0   , 230 , 250 , 0   , 312} ,
  /*11*/ {0 , 0   , 0   , 0   , 0   , 0   , 450 , 280 , 255 , 0   , 312 , 0}
};

//no node 0, starts from 1 to 11
int visitedNodes[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int NODES = 12;

bool travel(int since, int to){
  return matrix[since][to] != 0;
}

int traveling(int startNode){
  int total = 0;
  // condition < NODES because you can only do 11 travels
  for(int i = 1; i < NODES; i++){ //i means TO 
    if(includes(visitedNodes, i, NODES)){ //is i in visitedNodes?
      continue;
    }
    if(travel(startNode, i)){
      printf("traveling from %d to %d\n", startNode, i);
      total = total + matrix[startNode][i];
      visitedNodes[startNode] = startNode;
      startNode = i; //successful travel
      i = 1;
    }
  }
  printf("%d\n", total);
  printArray(visitedNodes, NODES);
  return total;
}
