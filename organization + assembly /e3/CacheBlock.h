/*
 *  CacheBlock.h
 *  CSCI 223 Exercise 3
 *
 *
 */

#ifndef CACHEBLOCK_H
#define CACHEBLOCK_H

typedef struct {
   int blockNumber;
   char dirty;
   int length;
   unsigned char * data;
   
} CacheBlock;



CacheBlock createCacheBlock(int size);

unsigned char readDataFromCacheBlock(CacheBlock c, int offset);

void writeDataToCacheBlock(CacheBlock c, int offset, unsigned char value);

void dumpCacheBlock(CacheBlock c);

#endif

