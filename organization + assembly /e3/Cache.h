/*
 *  Cache.h
 *  CSCI 223 Exercise 3
 *
 *
 */

#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include "CacheBlock.h"


typedef struct {

   CacheBlock * slots;
   int numSlots;
   int blockLength;
   FILE * file;
} Cache;

/* create a Cache with the specified number of slots, and blocks 
   with the specified length. The Cache is associated with a file
   on disk, which is also created and initialized with zeros. */
Cache createCache(int numslots, int sizeblocks);


/* Return the byte corresponding to the specified address from 
 * the given Cache.
 */
unsigned char readDataFromCache(Cache c, int address);


/* Write the byte found in the third argument to the specified address
 * in the given Cache.
 */
void writeDataToCache(Cache c, int address, unsigned char data);



/* Print the contents of the CacheBlock found in the specified slot to the 
 * screen.
 */
void dumpSlot(Cache c, int slotNumber);

#endif

