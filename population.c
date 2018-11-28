#include "a4.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

PIXEL *generate_random_image(int width, int height, int max_color){
  srand(time(NULL));
  int size = width*height;
  PIXEL *array1;
  array1 = malloc(sizeof(PIXEL) * size);
  for (int i = 0; i < size; i++){
    array1[i].r = rand()%(max_color+1);
    array1[i].g = rand()%(max_color+1);
    array1[i].b = rand()%(max_color+1);
  }
  return array1;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
  Individual *array2;
  array2 = malloc(sizeof(Individual) * population_size);
  for (int i = 0; i < population_size; i++){
    array2[i]->image->data = generate_random_image(width, height, max_color);
    array2[i]->image->max_color = max_color;
    array2[i]->image->width = width;
    array2[i]->image->height = height;
  }
}
