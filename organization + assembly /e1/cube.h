/*
 *  cube.h
 *  e1
 *
 *  Created by Philip Rhodes on 1/15/07.
 *  Copyright 2007 Philip J Rhodes. All rights reserved.
 *
 *  This file defines a cube type and describes two functions
 *  that can be used with cubes.
 *
 *
 */

#ifndef SQUARE_H
#define SQUARE_H

typedef struct {
   float sidelen;
} cube;


/* Return the surface area of the cube parameter. */
float cube_area(cube c);

/* Return the volume of the cube parameter. */
float cube_volume(cube c);

#endif

