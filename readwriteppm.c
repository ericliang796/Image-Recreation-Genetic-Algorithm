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
  for (int i = 0; i < (size); i++){
    fscanf(fpointer,"%d %d %d", data[i].r, data[i].g, data[i].b);
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
