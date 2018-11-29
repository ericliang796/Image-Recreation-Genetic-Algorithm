#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int cmpfunc (const Individual *a, const Individual *b) {
  if (a->fitness > b->fitness) return 1;
  else if (a->fitness < b->fitness) return -1;
  return 0;
  // return (*(int*)a->fitness - *(int*)b->fitness);
  // if a>b
  //   return 1
  // else
  //   return -1;
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
  srand(time(NULL));
  Individual *individuals;
  int i;
  individuals = generate_population(population_size, image->width, image->height, image->max_color);
  comp_fitness_population(image, individuals, population_size);
  qsort(individuals, population_size, sizeof(Individual), cmpfunc);
  for (i = 1;i <= num_generations;i++){
    crossover(individuals, population_size);
    mutate_population(individuals, population_size, rate);
    comp_fitness_population(image, individuals, population_size);
    qsort(individuals, population_size, sizeof(Individual), cmpfunc);
    printf("%d  -  %f\n", i, individuals[0].fitness);
  }
  return &individuals[0].image;
}

void free_image(PPM_IMAGE *p){
  free(p->data);
  free(p);
}
