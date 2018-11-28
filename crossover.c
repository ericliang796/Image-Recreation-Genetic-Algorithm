// File crossover.c
#include "a4.h"
#include <stdlib.h>

void recombine(Individual *parent1, Individual *parent2, Individual *child1, Individual *child2) {
  // Generate a random number between 0 and image size-1
  int image_size = parent1->image.width * parent1->image.height;
  int crossover = rand() % image_size;
  int i;

  // Up to crossover child1 "inherits" from parent1 and child2 inherits
  // from parent2
  for (i = 0; i < crossover; i++) {
    child1->image.data[i] = parent1->image.data[i];
    child2->image.data[i] = parent2->image.data[i];
  }
  // After that child1 "inherits" from parent2 and child2 inherits
  // from parent1
  for (i = crossover; i < image_size; i++) {
    child1->image.data[i] = parent2->image.data[i];
    child2->image.data[i] = parent1->image.data[i];
  }
}

void crossover(Individual *population, int population_size) {
  
  for (int i = 0; i < population_size / 2; i += 2)
    // parent i and i+1 produce children population_size/2+i and
    // population_size/2+i+1.
    recombine(population + i, population + i + 1,
              population + population_size / 2 + i,
              population + population_size / 2 + i + 1);
}
