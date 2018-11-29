#include <stdio.h>
#include <stdlib.h>
#include "a4.h"
PPM_IMAGE *read_ppm(const char *file_name){
	PPM_IMAGE *inMage;
	char pType[10];
	int i;
	FILE *iIMAGE;
	inMage=malloc(1*sizeof(PPM_IMAGE));
	iIMAGE=fopen(file_name, "r");
	if(iIMAGE!=NULL){
		fscanf(iIMAGE, "%s%d%d%d", &pType, &(inMage->width), &(inMage->height), &(inMage->max_color));
		inMage->data=malloc((*inMage).width*(*inMage).height*sizeof(PIXEL));
		i=0;
		while(fscanf(iIMAGE, "%hhu", &(inMage->data[i].r))==1 && fscanf(iIMAGE, "%hhu", &(inMage->data[i].g))==1 && fscanf(iIMAGE, "%hhu", &(inMage->data[i].b))==1)
			i++;
		}
	fclose(iIMAGE);
	return inMage;
}


void write_ppm(const char *file_name, const PPM_IMAGE *image){
	FILE *outMage;
	int i;
	outMage=fopen(file_name, "w");
	fprintf(outMage, "P3\n%d %d\n%d\n", image->width, image->height, image->max_color);
	for(i=0;i<image->height*image->width;i++){
		if((i+1)%image->width==0) fprintf(outMage, "%d %d %d\n", image->data[i].r, image->data[i].g, image->data[i].b);
		else fprintf(outMage, "%d %d %d ", image->data[i].r, image->data[i].g, image->data[i].b);
		}
	fclose(outMage);

}
