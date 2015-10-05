/* E1  
 * A simple program meant to provide practice in editing, compiling and running 
 * a C program in the linux environment.
 */

#include <stdio.h>
#include <stdlib.h>

#include "sphere.h"
#include "cube.h"



void usage();

int main (int argc, const char * argv[]) {
    
   sphere s;
   cube c;

   if (argc != 2) {

      usage();
      return 1;
   }
   
   float d = strtod(argv[1], NULL);
   
   s.radius = d;
   c.sidelen = d;

   printf("The surface area of a sphere with radius %5.3f is %5.3f\n", d, sphere_area(s));
   printf("The volume of a sphere with radius %5.3f is %5.3f\n", d, sphere_volume(s));

   printf("\n");

   printf("The surface area of a cube with sidelength %5.3f is %5.3f\n", d, cube_area(c));
   printf("The volume of a cube with sidelength %5.3f is %5.3f\n", d, cube_volume(c));

   return 0;
}


/* Print a short message on how to use this program from the command line.*/
void usage(){

   printf("Usage: e1 f\n     where f is a floating point number representing the size of a cube or sphere.\n");
}



