#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NUMBER_OF_WORDS 300000
#define MAX_SIZE_WORD 250
#define _FILE_OFFSET_BITS 64


FILE *file;

typedef struct {
	int size, lines_per_thread, current_location, current_word, current_char; 
	char **words;
	int *count; 
	pthread_mutex_t mutex; 
} word_counter;


int same(char *str, word_counter* counter){
	int i; 
	
	
	for(i = 0; i < counter->current_word; i++){
		
		if(strcmp(counter->words[i], str) ==0){
	//	printf("str: %s, word[i]: %s\n", str, counter->words[i]); 
		counter->count[i] ++; 
		return 0;
		}
	} 
	return 1; 
}

int main(int argc, char **argv)
{	
	
	int size,i, j, found ;
 file = fopen("test.txt", "r"); 
	int ch, number_of_lines = 0;
	word_counter counter;
	do 
	{
		ch = fgetc(file);
		if(ch == '\n')
			number_of_lines++;
	} while (ch != EOF);
	
	// last line doesn't end with a new line!
	// but there has to be a line at least before the last line
	if(ch != '\n' && number_of_lines != 0) 
		number_of_lines++;

	fclose(file);
	
	file = fopen("test.txt", "r"); 
	counter.current_location = 0; 

	counter.current_location = 0; 
	counter.current_char = 0; 
	counter.current_word = 0; 
	counter.count = (int*)calloc(MAX_NUMBER_OF_WORDS, sizeof(int)); 
	counter.words = (char**) calloc(MAX_NUMBER_OF_WORDS, sizeof(char*));

for ( i = 0; i < MAX_SIZE_WORD; i++ )
{
    counter.words[i] = (char*) calloc(MAX_NUMBER_OF_WORDS, sizeof(char));
}


int found_word = 0, c, found_apostrophe = 0, current_char = 0, current_word = 0;
char **str = (char**) calloc(MAX_NUMBER_OF_WORDS, sizeof(char*));
for ( i = 0; i < MAX_SIZE_WORD; i++ )
{
    str[i] = (char*) calloc(MAX_NUMBER_OF_WORDS, sizeof(char));
}


  while ((c =fgetc(file)) != EOF ){
		
		characters ++; 
	
    else {
		characters++; 
        if (found_apostrophe) {
			counter.words[counter.current_word][counter.current_char] = '\'';
			counter.current_char ++;
            found_apostrophe == 0;
        }
        found_word = 1;
        c = tolower(c);
		str[current_word][current_char] = c; 
		current_char++;
    }

        }
    free(str); 


	
	
	
	
//sort words in counter array
char* temp; 
for (i = 0; i < 2 ; i++) {
      for (j = 0; j < counter.current_location - 1; j++) {
         if (temp && counter.words[j] && counter.words[j+1] && strcmp(counter.words[j], counter.words[j + 1]) > 0) {
            strcpy(temp, counter.words[j]);
            strcpy(counter.words[j], counter.words[j + 1]);
            strcpy(counter.words[j + 1], temp);
         }
      }
   }
 
fclose(file); 




printf("current word: %i ", counter.current_word); 
//print words and their occurrences 
for(i = 0; i < counter.current_word; ++i){
	
	printf("%s %i\n", counter.words[i], counter.count[i]);  
	
	}
	fflush(stdout);
 
return 0;

}