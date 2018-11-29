#include "a4.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

PPM_IMAGE *read_ppm(const char *file_name){

  PPM_IMAGE *Pimage;
  PIXEL *data;
  int width, length, maximum;
  FILE *fpointer;
  fpointer = fopen(file_name, "r");

//Check if file is opened
  if (fpointer == NULL){
    printf("Unable to open the file\n");
    exit(1);
  }

  // read the rest of the header
  fscanf(fpointer, "%*s\n%d %d\n%d\n", &width, &length, &maximum);

  //Set structure for PIXEL
  Pimage->width = width;
  Pimage->height = length;
  Pimage->max_color = maximum;

  //Setting aside memory for data
  int size = width * length;
  data = malloc (size * sizeof(PIXEL));

  int widthCounter;
  int i;
  for (i = 0; i < (size); i++){
    fscanf(fpointer,"%hhu %hhu %hhu", &(data[i].r), &(data[i].g), &(data[i].b));
    widthCounter++;
  //goes to next line once width is met
    if(widthCounter == width){
      fscanf(fpointer, "\n");
      widthCounter = 0;
    }
  }
  //Sets data for PIXEL structure
  Pimage->data = data;
  return Pimage;
}

void write_ppm ( const char * file_name , const PPM_IMAGE * image ){

  FILE *fpointer;
  fpointer = fopen(file_name, "w");
  fprintf(fpointer, "P3\n%d %d\n%d\n", image->width, image->height, image->max_color);
  int size = image->width * image->height;
  int i;
  int width = image->width;
  int widthCounter;
  for (i = 0; i < (size); i++){
    fprintf(fpointer, "%d %d %d", image->data[i].r, image->data[i].g, image->data[i].b);
    widthCounter++;
  //goes to next line once width is met
    if(widthCounter == width){
      fprintf(fpointer, "\n");
      widthCounter = 0;
    }
  }

}
