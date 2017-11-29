#include <stdio.h>
#include "../lib/array.h"
#include "../lib/number.h"

int patterns [4][3]= {
  {0, 0, 0},
  {0, 1, 0},
  {1, 0, 0},
  {1, 1, 1}
};

float THETA = 0.3;
float ALPHA = 0.25;

int zeroToThree(int x){
  if(x == 3){
    return 0;
  }
  return x + 1;
}

int training(
  int p, //which pattern we are on (0 >= p <= 3)
  float w1,
  float w2,
  float a,
  int y,
  float alphaByTminusY,
  float dw1,
  float dw2,
  float bias,
  int iterations
){
  if(iterations == 0){
    return 1;
  }else{
    printf("x1  x2  w1   w2  θ    a    t  y  α(t - y)  dw1  dw2  dθ\n");
    printf("%d   %d   %.1f  %.1f %.1f %.1f  %d  %d   %.2f     %.2f %.2f %.2f \n",
            patterns[p][0], 
            patterns[p][1], 
            w1, 
            w2, 
            THETA, 
            (w1 * patterns[p][0] + w2 * patterns[p][1]) - THETA, //a
            patterns[p][2], //t
            ( (w1 * patterns[p][0] + w2 * patterns[p][1]) - THETA ) > 0, //y
            ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)),
            ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)) * patterns[p][0],
            ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)) * patterns[p][1],
            ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0))
            );
    /* printf("--------------------------------------------------------------------\n"); */
    return training(
      zeroToThree(p),
      w1 + ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)),
      w2 + ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)),
      (w1 * patterns[p][0] + w2 * patterns[p][1]) - THETA, //a
      ( (w1 * patterns[p][0] + w2 * patterns[p][1]) - THETA ) > 0, //y
      ALPHA * (patterns[p][2] - ( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0) ),
      ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)) * patterns[p][0],
      ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)) * patterns[p][1],
      ALPHA*(patterns[p][2]-( (w1 * patterns[p][0] + w2 * patterns[p][1])-THETA > 0)),
      previous(iterations)
      );
  }
}

int main(){
  //training(p  w1   w2    a    y    alphaByTminusY dw1  dw2  bias iterations
  training(
      0,
      0.0, //w1
      0.0, //w2
      (0.0 * patterns[0][0] + 0.0 * patterns[0][1]) - THETA, //a
      ( (0.0 * patterns[0][0] + 0.0 * patterns[0][1]) - THETA ) > 0, //y
      ALPHA * ( patterns[0][2] - ( (0.0 * patterns[0][0] + 0.0 * patterns[0][1]) - THETA > 0)), //alpha by t minus y
      ALPHA * ( patterns[0][2] - ( (0.0 * patterns[0][0] + 0.0 * patterns[0][1]) - THETA > 0)) * patterns[0][0], // dw1
      ALPHA * ( patterns[0][2] - ( (0.0 * patterns[0][0] + 0.0 * patterns[0][1]) - THETA > 0)) * patterns[0][1], //dw2
      ALPHA * ( patterns[0][2] - ( (0.0 * patterns[0][0] + 0.0 * patterns[0][1]) - THETA > 0)), //bias
      12 //iterations
      );
}
