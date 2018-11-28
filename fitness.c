#include "a4.h"
#include <stdio.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double d;
  double sum;
  double dist;
  for (int i = 0;i < image_size;i++){
    d = (A[i].r - B[i].r)*(A[i].r - B[i].r) + (A[i].g - B[i].g)*(A[i].g - B[i].g) + (A[i].b - B[i].b)*(A[i].b - B[i].b);
    sum += d;
  }
  dist = sqrt(sum);

  return dist;
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){

}
