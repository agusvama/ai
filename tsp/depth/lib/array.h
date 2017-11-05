#include <stdio.h>
#include <stdbool.h>

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

bool includes(int x[], int element, int arraySize){
  for(int i = 0; i < arraySize; i++){
    if(x[i] == element){
      return true;
    }else{
      continue;
    }
  }return false;
}

void clearArrayWith(int x[], int element, int arraySize){
  for(int i = 0; i < arraySize; i++){
    x[i] = element;
  }
}

void copyArray(int x[], int y[], int arrSize){
  for(int i = 0; i < arrSize; i++){
    y[i] = x[i];
  }
}
