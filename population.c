#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

PIXEL *generate_random_image(int width, int height, int max_color){
	PIXEL *rndImg;
	int i;
	rndImg=malloc(width*height*sizeof(PIXEL));
	for(i=0;i<width*height;i++){
		rndImg[i].r=rand()%(1+max_color);
		rndImg[i].g=rand()%(1+max_color);
		rndImg[i].b=rand()%(1+max_color);
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
