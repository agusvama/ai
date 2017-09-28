#include <stdio.h>

int first(int x[]){
  return x[0];
}

int last(int x[], int size){
  return x[size - 1];
}

void printArray(int x[], int size){
  for(int i = 0; i < size; i++){
    printf("%d, ", x[i]);
  }
  printf("\n");
}
