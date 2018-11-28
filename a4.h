#ifndef INCLUDED_A4_H
#define INCLUDED_A4_H

typedef struct { unsigned char r, g, b; } PIXEL;

typedef struct {
  PIXEL *data;       // pointer to an array of width*height PIXELs
  int width, height; // width and height of image
  int max_color;     // largest value of a color
} PPM_IMAGE;

typedef struct {
  PPM_IMAGE image; // image
  double fitness;  // fitness
} Individual;

// Read and write PPM file
PPM_IMAGE *read_ppm(const char *file_name);
void write_ppm(const char *file_name, const PPM_IMAGE *image);

// Random image and population
PIXEL *generate_random_image(int width, int height, int max_color);
Individual *generate_population(int population_size, int width, int height, int max_color);

// Fitness
double comp_distance(const PIXEL *A, const PIXEL *B, int image_size);
void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size);

// Crossover
void crossover(Individual *individual, int population_size);

// Mutation
void mutate(Individual *individual, double rate);
void mutate_population(Individual *individual, int population_size, double rate);

// Compute image
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate);

// Free image
void free_image(PPM_IMAGE *p);

#endif
