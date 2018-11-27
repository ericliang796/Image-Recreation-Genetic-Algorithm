#include "a4.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

PPM_IMAGE *read_ppm(const char *file_name){

  PPM_IMAGE * Pimage;
  PIXEL **imagePix;
  int wid, len, mxc;
  char pType[10];
  char a;
  int i;
  FILE *fpointer;
  fpointer = fopen(file_name, "r");

//Check if file is opened
  if (fpointer == NULL){
    printf("Unable to open the file\n");
    exit(1);
  }

  if (fscanf(fpointer, "%s", &pType) == 1){
    printf("%s\n", pType);
  }

  imagePix = malloc (wid * len * sizeof(PIXEL));
  else  printf("hello\n");
  while (fscanf(fpointer, "%d", &i)==1){
    printf("%d\n", i);
  }

  return Pimage;
}
int main(){
  return 0;
}
