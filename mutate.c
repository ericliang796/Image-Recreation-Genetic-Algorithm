#include "a4.h"
#include <stdio.h>
#include <math.h>

void mutate(Individual *individual, double rate){
  int size = individual->image->width*individual->image->height;
  int pixels = rate/(100*size);
  int i;
  for (i = 0;i < pixels;i++){
    int randH = rand()%individual->image->height;
    int randW = rand()%individual->image->width;
    individual->data[randH*individual->image->width+randW].r = rand()%(255+1);
    individual->data[randH*individual->image->width+randW].g = rand()%(255+1);
    individual->data[randH*individual->image->width+randW].b = rand()%(255+1);
  }
}

void mutate_population(Individual *individual, int population_size, double rate){
  int i;
  int size = population_size/4;
  for (i = size; i < population_size; i++){
    mutate(&individual[i], rate);
  }
}
