/*
 *  sphere.h
 *  e1
 *
 *  Created by Philip Rhodes on 1/15/07.
 *  Copyright 2007 Philip J Rhodes. All rights reserved.
 *
 *  This file defines a sphere type and describes two functions
 *  that can be used with spheres.
 *
 */
 
#ifndef CIRCLE_H
#define CIRCLE_H 

typedef struct {
   float radius;
} sphere;

/* Return the surface area of the sphere parameter. */
float sphere_area(sphere s);

/* Return the volume of the sphere parameter. */
float sphere_volume(sphere s);

#endif

