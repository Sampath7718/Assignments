#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "timing.h"
#include "mul.h"



void mul(float c[], float a[], float b[], int n);
int pmul(int nthreads, float c[], float a[], float b[], int n);

void initMatrix(float *matrix, int n, char flag);
void initializeToIdentity(float m[], int n);
void initializeToRandom(float *matrix, int n);

void printMatrix(float m[], int nr, int nc);
void usage();


void *processRows( void * args);




int main (int argc, const char * argv[]) {

   if(argc < 5){
      usage();
   }

   int nthreads = atoi(argv[1]);
   int n = atoi(argv[2]);
   printf("Using %d by %d matrices.\n", n, n);
   
   
   //Allocate n^2 floats for all three matrices.
   float *m1 = (float *) malloc (n * n *sizeof(float));
   float *m2 = (float *) malloc (n * n *sizeof(float));
   float *r  = (float *) malloc (n * n *sizeof(float));
   
   // initialize matrix values
   initMatrix(m1, n, argv[3][0]);
   initMatrix(m2, n, argv[4][0]);
   
   
   if(nthreads > 1){
  
      printf("Running parallel version. %d threads available.\n", nthreads);
             
      // start the clock
      double then = currentTime();
      
      // do the matrix multiplication
      pmul(nthreads, (float *) r, (float *) m1, (float *) m2, n);
      
      double now = currentTime();
      printf("%%%%%% paralleltime %f\n", now - then);
   } else {
   
      printf("Running Serial version.\n");
      
      // start the clock
      double then = currentTime();
      
      // do the matrix multiplication.
      // the serial version is now defined in mul.o
      mul((float *) r, (float *) m1, (float *) m2, n);
      
      double now = currentTime();
      printf("%%%%%% serialtime %f\n", now - then);
   }
   
   if(argc == 6 && argv[5][0]=='p'){
   
      printMatrix((float *)r, n, n);
   }
    
   return 0;
}




/* Multiply the nxn matrices a and b, placing the result in c. Matrices
 * are passed as 1D arrays of floats, because we don't know the dimensions
 * of the matrices at compile time. The last argument specifies the length
 * of one side of the matrix.
 *  This implementation uses threads, and
 * the first argument tells how many threads to use.
 */
int pmul(int nthreads, float c[], float a[], float b[], int n){

   
   // Write Me

   return EXIT_SUCCESS;
}

void *processRows( void * args){

   // Write Me   
   
   return NULL;
}



/* Initialize the nxn matrix to either the identity matrix or a random
 * matrix. if flag == 'i', then the matrix is initialized to the identity. 
 * if flag == 'r', the matrix is initialized to random values.
 */
void initMatrix(float *matrix, int n, char flag){

   switch (flag) {
      case 'i':
      case 'I':
         initializeToIdentity(matrix, n);
         break;

      case 'r':
      case 'R':
         initializeToRandom(matrix, n);
         break;
      default:
         fprintf(stderr, "Unrecognized command line flag: '%c'\n", flag);
         usage();
         break;
   }
}

/* Print the matrix with nr rows and nc columns to standard output.*/
void printMatrix(float m[], int nr, int nc){

   int i,j;
   
   for(i=0; i<nr; i++){
      for(j=0; j<nc; j++){
      
         printf("%8.2f ", m[i *nc + j]);
      }
      
      printf("\n");
   }
}

/* Initialize the nxn matrix to the identity. */
void initializeToIdentity(float m[], int n){
   int i, j;
   
   for(i=0; i<n; i++){
      for(j=0; j<n; j++){
      
         if (i == j) {
         
            m[i * n + j] = 1.0f;
         } else {
         
            m[i * n + j] = 0.0f;
         }
      }

   }
}

/* Initialize elements of the nxn matrix to random values in the range 0..1 */
void initializeToRandom(float *matrix, int n){
   int i, j;
   
   for(i=0; i<n; i++){
      for(j=0; j<n; j++){
      
         matrix[i * n + j] = rand() / (float) RAND_MAX;
      }
   }
}


/* Read a matrix from a file. Untested. Not used in the assignment.*/
void readMatrix(char *filename, float **matrix, int *n){

   FILE *infile = fopen(filename, "r");
   
   if(infile) {
   
      fscanf(infile, "%d", n);
      
      *matrix = (float *) malloc( (*n) * (*n) * sizeof(float));
      
      int i, j;
      
      for(i=0; i < *n; i++){
         for(j=0; j < *n; j++){
      
            fscanf(infile, "%f", *matrix + i * (*n) + j );
         }
      }
   
      fclose(infile);
   } else {
      fprintf(stderr, "Couldn't open file %s for reading.\n", filename);
   }

}



void usage(){

   printf("Usage: pmul nthreads n i|r i|r [p]\n");
   exit(1); 
}

