/*
 *  sphere.c
 *  e1
 *
 *  Created by Philip Rhodes on 1/15/07.
 *  Copyright 2007 Philip J Rhodes. All rights reserved.
 *
 */

#include "sphere.h"

#include <math.h>


/* Return the surface area of the sphere parameter. */
float sphere_area(sphere s){

   return 4.0 * M_PI * s.radius * s.radius;
}

/* Return the volume of the sphere parameter. */
float sphere_volume(sphere s){

   return 4.0 / 3.0 * M_PI * s.radius * s.radius * s.radius;
}

