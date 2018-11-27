#include "a4.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

PIXEL *generate_random_image(int width, int height, int max_color){
  srand(time(NULL));
  int size = width*height;
  PIXEL *array;
  array = malloc(sizeof(PIXEL) * size);
  for (int i = 0; i < size; i++){
    array[i].r = rand()%(max_color+1);
    array[i].g = rand()%(max_color+1);
    array[i].b = rand()%(max_color+1);
  }
  return array
}

Individual *generate_population(int population_size, int width, int height, int max_color){
  srand(time(NULL));
  Individual *array2;
  array2 = malloc(sizeof(Individual) * population_size);
  
}
