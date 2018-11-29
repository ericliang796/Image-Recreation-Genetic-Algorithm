#include "a4.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

void mutate(Individual *individual, double rate){
	int mutN, mutP, RDr, maxC, i, N=individual->image.width*individual->image.height;
	int mutInd[N];
	srand(time(NULL));
	mutN=(int)(N*rate/100);
	maxC=individual->image.max_color;
	for(i=0;i<N;i++) mutInd[i]=0;
	for(i=0;i<mutN;i++){
		mutP=rand()%N;
		RDr=0;
		while(mutInd[mutP]==1 && RDr<5){
			mutP=rand()%N;
			RDr++;
			}
		individual->image.data[mutP].r=rand()%(1+maxC);
		individual->image.data[mutP].g=rand()%(1+maxC);
		individual->image.data[mutP].b=rand()%(1+maxC);
		mutInd[mutP]=1;
	}
}

void mutate_population(Individual *individual, int population_size, double rate){
	int i, mutST=(int)(population_size/4);
	for(i=mutST;i<population_size;i++){
		mutate(&(individual[i]),rate);
	}

}
