#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

PIXEL *generate_random_image(int width, int height, int max_color){
	PIXEL *rndImg;
	int i;
	int size = width*height;
	int randColor = 1+max_color;
	rndImg=malloc(size*sizeof(PIXEL));
	for(i=0;i<size;i++){
		rndImg[i].r=rand()%(randColor);
		rndImg[i].g=rand()%(randColor);
		rndImg[i].b=rand()%(randColor);
	}
	return rndImg;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
	Individual *population;
	int i;
	population=malloc(population_size*sizeof(Individual));
	for(i=0;i < population_size; i++){
		population[i].image.width=width;
		population[i].image.height=height;
		population[i].image.max_color=max_color;
		population[i].image.data=generate_random_image(width,height,max_color);
	}
	return population;
}
