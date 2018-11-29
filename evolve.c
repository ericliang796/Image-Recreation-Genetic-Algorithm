#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int cmp(const void *a, const void *b){
	if(((Individual *)a)->fitness > ((Individual *)b)->fitness) return 1;
	else if(((Individual *)a)->fitness<((Individual *)b)->fitness) return -1;
	else return 0;
}
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
	srand(time(NULL));
	int i;
	Individual *imagePopulation;
	imagePopulation=generate_population(population_size, image->width, image->height, image->max_color);

	comp_fitness_population(image->data,imagePopulation,population_size);

	qsort(imagePopulation, population_size, sizeof(Individual), cmp);

	for(i=0; i<num_generations; i++){
		crossover(imagePopulation, population_size);
		mutate_population(imagePopulation, population_size, rate);
		comp_fitness_population(image->data,imagePopulation,population_size);
		qsort(imagePopulation, population_size, sizeof(Individual), cmp);
		printf("%d  -  %f\n", i, imagePopulation[0].fitness);
		}
	return &imagePopulation[0].image;
}

void free_image(PPM_IMAGE *p){
	free(p->data);
	free(p);
}
