/*
 *  cube.c
 *  e1
 *
 *  Created by Philip Rhodes on 1/15/07.
 *  Copyright 2007 Philip J Rhodes. All rights reserved.
 *
 */

#include "cube.h"


/* Return the surface area of the cube parameter. */
float cube_area(cube c){

   return 6.0 * c.sidelen * c.sidelen;

}

/* Return the volume of the cube parameter. */
float cube_volume(cube c){

   return c.sidelen * c.sidelen * c.sidelen;
}


