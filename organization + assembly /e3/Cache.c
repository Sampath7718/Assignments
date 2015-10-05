/*
 *  Cache.c
 *  CSCI 223 Exercise 3
 *
 *
 */

#include "Cache.h"
#include <stdlib.h>

#define NUM_BLOCKS_IN_FILE 16


// These are prototypes for functions used only inside this file. 
// You'll probably need to add some for your own functions.
void loadCacheBlockFromFile(Cache c, int slotNumber, int blockNumber);
unsigned char readDataFromCache(Cache c, int address);
void writeDataToCache(Cache c, int address, unsigned char data);
void writeCacheBlockToFile(Cache c, int slotNumber);





// You have to implement these next two.
// A quick list of C "gotchas":
//
//  C doesn't allow a variable declaration inside a for loop, as in:
//   for (int i=0; ...
//  Instead, declare i outside the loop. You probably don't need a loop
//  for this assignment, though.
//
//  C puts variables and functions in the same "namespace", so you
//  may have trouble using a function with the same name as a local
//  variable.
//
//  C has no "byte" type.  Instead, use "char" or "unsigned char" for
//  this data type.



//returns the data at the specified address of the cache
//if a block is dirty, then it is written to the disk before it is evicted

unsigned char readDataFromCache(Cache c, int address){
 
  int offset  = (address % 512);
  unsigned char result; 
  int block = (address/ 512);
  int slot = (block % 4);
 
 
  if (c.slots[slot].blockNumber != block)
  {
    if (c.slots[slot].dirty == 1)
    {  writeCacheBlockToFile( c, slot);
        c.slots[slot].dirty = 0;
    }
    loadCacheBlockFromFile( c, slot, block);
  }

  
  result = readDataFromCacheBlock (c.slots[slot], offset);

  return result; 

}



//very similar to readDataFromCache, but this function 
//writes data to a cache block and then sets the block to dirty

void writeDataToCache(Cache c, int address, unsigned char result){
  
  int offset = (address % 512);
  int block = (address/ 512);  
  int slot = (block % 4);
 

  if (c.slots[slot].blockNumber != block)
  { 

  if (c.slots[slot].dirty == 1)
    {
        writeCacheBlockToFile( c, slot);
        c.slots[slot].dirty = 0;
    }
    loadCacheBlockFromFile( c, slot, block);
  }

  writeDataToCacheBlock (c.slots[slot], offset, result);
  c.slots[slot].dirty = 1;  
}
   




// These next several functions are provided for you.  You don't 
// have to change them, but you certainly have to use the first two.
// However, You'll want to examine the definition of the Cache data
// structure in Cache.h, and how that relates to some of the syntax
// below. Pay particular attention to lines containing "c.slots" or
// c.blockLength, for example.  You'll probably find the syntax rather
// familiar.


/* Reads the data from the file corresponding to the blockNumber argument
   into the CacheBlock located in the specified slot.
 */
void loadCacheBlockFromFile(Cache c, int slotNumber, int blockNumber){

   
   int startAddress = blockNumber * c.blockLength;
   
   fseek(c.file, startAddress, SEEK_SET);
   
   int numread = fread(c.slots[slotNumber].data, 
                        sizeof(char), 
                        c.blockLength,
                        c.file);
   
   if (numread != c.blockLength){
   
      printf("Error: loadCacheBlockFromFile(): fread() tried to read %d bytes,"
              "but returned %d\n", c.blockLength, numread);
      printf("     : ferror() returns %d\n", ferror(c.file));
      printf("     : feof() returns %d\n", feof(c.file));
      
   }
   
   c.slots[slotNumber].dirty = 0;
   c.slots[slotNumber].blockNumber = blockNumber;
}


/* Writes the Cache block data found in the specified slot back to the file in the
 * appropriate location.
*/
void writeCacheBlockToFile(Cache c, int slotNumber){

   int startAddress = c.slots[slotNumber].blockNumber * c.blockLength;

   fseek(c.file, startAddress, SEEK_SET);
   int numwritten=fwrite(c.slots[slotNumber].data,
                        sizeof(char), 
                        c.blockLength, 
                        c.file);

   if (numwritten != c.blockLength){
   
      printf("Error: writeCacheBlockToFile(): fwrite() tried to write %d bytes,"
             "but returned %d\n", c.blockLength, numwritten);
      printf("     : ferror() returns %d\n", ferror(c.file));
      printf("     : feof() returns %d\n", feof(c.file));

   }
}


// These last two functions are being called in main(), so you
// don't need to call or modify them. 

/* Create a Cache with the specified number of slots, and blocks 
   with the specified length. The Cache is associated with a file
   on disk, which is also created and initialized with zeros. */
Cache createCache(int numSlots, int blockLength){

   Cache c;
   
   int i;
   c.slots = (CacheBlock *) malloc(numSlots * sizeof(CacheBlock));
   for(i=0; i<numSlots; i++){
   
      c.slots[i]=createCacheBlock(blockLength);
   }
   
   c.numSlots = numSlots;
   c.blockLength = blockLength;

   c.file = fopen("diskfile", "w+");
   
   if(c.file == NULL){
   
      printf("Error: createCache(): couldn't open file.\n");
   }
   
   int fileSize = blockLength * NUM_BLOCKS_IN_FILE;
   char * dummy = (char *) calloc(fileSize, sizeof(char));
   
   fwrite(dummy, sizeof(char), fileSize, c.file);
   free(dummy);
   return c;
}



/* Print the contents of the Cache block found in the specified slot to the 
 * screen.
 */
void dumpSlot(Cache c, int slotNumber){

   if(slotNumber < c.numSlots){
   
      printf("Block in slot %d:\n", slotNumber);
      dumpCacheBlock(c.slots[slotNumber]);
   } else {
   
      printf("slot number %d too large.\n", slotNumber);
   }
}

