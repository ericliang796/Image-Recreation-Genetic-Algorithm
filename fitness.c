#include "a4.h"
#include <stdlib.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
	int i;
	double DST=0;
	for(i=0;i<image_size;i++)
		DST+=(A[i].r-B[i].r)^2+(A[i].g-B[i].g)^2+(A[i].b-B[i].b)^2;
	return sqrt(DST);
}


void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
	int i;
	for(i=0;i<population_size;i++)
		individual[i].fitness=comp_distance(image, individual[i].image.data, individual[i].image.width*individual[i].image.height);

}
